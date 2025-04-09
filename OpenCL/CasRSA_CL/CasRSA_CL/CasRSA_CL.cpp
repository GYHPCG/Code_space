//
//  CasRSA_CL.c
//  CasRSA_CL
//
//  Created by Carter McCardwell on 11/18/15.
//  Copyright (c) 2015 Carter McCardwell. All rights reserved.
//
#pragma warning(disable: 4996)
#define __NO_STD_VECTOR
#define MAX_SOURCE_SIZE (0x100000)
#ifndef MAXDIGITS
#define	MAXDIGITS	500		/* maximum length bignum */
#endif

#define PLUS		1		/* positive sign bit */
#define MINUS		-1		/* negative sign bit */

#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <CL/opencl.h>

typedef struct {
    char digits[MAXDIGITS];         /* represent the number */
    int signbit;			/* 1 if positive, -1 if negative */
    int lastdigit;			/* index of high-order digit */
} bignum;

const unsigned long WordMask = 0x00000000FFFFFFFFUL;

char* stradd(const char* a, const char* b){
    size_t len = strlen(a) + strlen(b);
    char *ret = (char*)malloc(len * sizeof(char) + 1);
    *ret = '\0';
    return strcat(strcat(ret, a) ,b);
} //This function adds two string pointers together

void print_bignum(bignum *n)
{
    int i;

    if (n->signbit == MINUS) printf("- ");
    for (i=n->lastdigit; i>=0; i--)
        printf("%c",'0'+ n->digits[i]);

    printf("\n");
}

void int_to_bignum(int s, bignum *n)
{
    int i;				/* counter */
    int t;				/* int to work with */

    if (s >= 0) n->signbit = PLUS;
    else n->signbit = MINUS;

    for (i=0; i<MAXDIGITS; i++) n->digits[i] = (char) 0;

    n->lastdigit = -1;

    t = abs(s);

    while (t > 0) {
        n->lastdigit ++;
        n->digits[ n->lastdigit ] = (t % 10);
        t = t / 10;
    }

    if (s == 0) n->lastdigit = 0;
}

void initialize_bignum(bignum *n)
{
    int_to_bignum(0,n);
}

int scan_for_start_str(char* num_str)
{
    int places = MAXDIGITS;
    for (int i = 0; i < MAXDIGITS; i++)
    {
        if (num_str[i] != 0) { places = i; }
    }
    return places;
}

void initialize_bignum_with_str(char* num_str, bignum *big_num)
{
    int_to_bignum(0, big_num);
    for (int i = 0; i < MAXDIGITS; i++) { big_num->digits[i] = num_str[i]; }
    big_num->lastdigit = scan_for_start_str(num_str);
}
// char * argv[]存放命令行参数的内容，argc为char * argv[]的长度
int main(int argc, const char * argv[])
{
    printf("CasRSA_CL OpenCL 1.2 implementation of RSA\nCarter McCardwell, Northeastern University NUCAR\nhttp://coe.neu.edu/~cmccardw - mccardwell.net\n--------------------------------------\n");
    // 获取命令行参数的个数，要为3，分别为CasRSA_CL，conf_file， outfile文件
    // 显然如果参数不为3，运行必然错误，直接return 1;
    if (argc != 3)
    {
        printf("Usage: ./CasRSA_CL conf_file outfile\nWhere the conf_file is a textfile that contains: [p] [q] [e] [message]\n");
        return 1;
    }
    //测试程序运行所需要的时间
    //c_start为开始时间，c_stop为结束时间
    clock_t c_start, c_stop;
    c_start = clock(); //Create a clock to benchmark the time taken for execution

    char p_s[MAXDIGITS], q_s[MAXDIGITS], M_s[MAXDIGITS];
    char ps[MAXDIGITS], qs[MAXDIGITS], Ms[MAXDIGITS];
    bignum p, q, M, result;
    int e;

    FILE *conf_file;//配置文件
    FILE *outfile;// 输出文件
    FILE *cl_code;// kernel文件
    //命令行参数有三个，索引为0，1，2，argv[1]中的内容即命令行输入的第二个文件conf_file，打开该文件
    conf_file = fopen(argv[1], "r"); //First number
    //判断该文件是否存在
    if (conf_file == NULL) { printf("error_conf_file"); return(1); }
    // argv[3]为命令行参数的第三个文件，输出文件，打开outfile,将结果写入，判断该文件是否打开
    outfile = fopen(argv[2], "w"); //The outfile, the result will be written here
    if (outfile == NULL) { printf("error (permission error: run with sudo or in directory the user owns)"); return (1); }
    //给六个char数组赋初值
    for (int i = 0; i < MAXDIGITS; i++)
    {
        p_s[i] = 0; q_s[i] = 0; M_s[i] = 0;
        ps[i] = 0; qs[i] = 0; Ms[i] = 0;
    }

    int_to_bignum(0, &result);
    //将confile中的内容分别以“%s %s %i %s"格式输入给ps,qs,e,Ms
    fscanf(conf_file, "%s %s %i %s", &ps, &qs, &e, &Ms);
    //M_s,p_s,q_s赋值
	for (int i = 0; i < strlen(Ms); i++) { M_s[i] = Ms[strlen(Ms)-1-i] - '0'; }
	for (int i = 0; i < strlen(ps); i++) { p_s[i] = ps[strlen(ps)-1-i] - '0'; }
	for (int i = 0; i < strlen(qs); i++) { q_s[i] = qs[strlen(qs)-1-i] - '0'; }

	initialize_bignum_with_str(M_s, &M);
	initialize_bignum_with_str(p_s, &p);
	initialize_bignum_with_str(q_s, &q);

    printf("INPUT:\n\tM:"); print_bignum(&M);
    printf("\n\tp:"); print_bignum(&p);
    printf("\n\tq:"); print_bignum(&q);

    const char *cl_headers = "#pragma OPENCL EXTENSION cl_khr_byte_addressable_store : enable\n#define PLUS 1\n#define MINUS -1\n#define MAXDIGITS ";
    char num[10];
    //将 MAXDIGITS 以整数的格式写入char num数组里
    sprintf(num, "%d", MAXDIGITS);
    //将cl_headers的内容，即.cl文件中缺失的变量定义等和num数组的内容拼接到append_str中
    const char *append_str = stradd(cl_headers, num);
    //打开存放kernel的.cl文件
    cl_code = fopen("kernel_rsa.cl", "r");
    if (cl_code == NULL) { printf("\nerror: clfile, this s empty\n");
    perror("打开文件失败");
    return(1); }
    //开辟一个数组，
    char *source_str = (char *)malloc(MAX_SOURCE_SIZE);
    //从文件cl_code里每次读取1个字节，总共读取MAX_SOURCE_SIZE次到刚刚开辟的source_str数组里
    fread(source_str, 1, MAX_SOURCE_SIZE, cl_code);
    fclose(cl_code);
    //将append_str,source_str拼接，存放到append_str中，并把长度赋值给length
    append_str = stradd(append_str, source_str);
    size_t length = strlen(append_str);

    //Set OpenCL Context,创建上下文
    cl_int err;//存放函数返回编码
    cl_uint ret_num_devices;
    cl_uint ret_num_platforms;
    cl_platform_id platform = NULL;//存放平台信息
    cl_context context = NULL;//存放上下文信息
    cl_command_queue queue = NULL;//存放命令队列信息
    cl_device_id device = NULL;//存放设备信息
    //获取一个可用的平台
    err = clGetPlatformIDs(1, &platform, &ret_num_platforms);
    if (err != CL_SUCCESS) { printf("platformid"); }
    //获取一个可用的设备
    printf("platfomrs:%d\n", ret_num_platforms);
    err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_DEFAULT, 1, &device, &ret_num_devices);
    if (err != CL_SUCCESS) { printf("getdeivceid %i", err); }
    //获取设备的最多计算单元
    printf("devices:%d\n", ret_num_devices);
    //cl_uint numberOfCores;
   // clGetDeviceInfo(device, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(numberOfCores), &numberOfCores, NULL);
    //printf("\nThis GPU supports %i compute units", numberOfCores); //Utilize the maximum number of compute units
    //获取设备每个计算单元的线程数
    //cl_uint maxthreads;
    //clGetDeviceInfo(device, CL_KERNEL_WORK_GROUP_SIZE, sizeof(maxThreads), &maxThreads, NULL);
    //printf("\nRunning with %i threads per compute units", maxThreads); //Utilize the maximum number of threads/cu
    //创建上下文
    context = clCreateContext(NULL, 1, &device, NULL, NULL, &err);
    if (err != CL_SUCCESS) { printf("context"); }
    //创建命令队列
    queue = clCreateCommandQueue(context, device, 0, &err);
    if (err != CL_SUCCESS) { printf("queue"); }
    //创建主机程序
    cl_program program = clCreateProgramWithSource(context, 1,(const char**)&append_str, (const size_t*)&length, &err); //Compile program with expanded key included in the source
    if (err != CL_SUCCESS) { printf("createprogram"); }
    //编译主机程序
    printf("\nBuilding CL Kernel...");
    err = clBuildProgram(program, 1, &device, "-I ./ -cl-std=CL1.2", NULL, NULL); //The fourth parameter is specific to OpenCL 2.0
    if (err != CL_SUCCESS)printf("device is error\n");
    //如果编译主机程序失败
    //"-I ./ -cl-std=CL1.2"
    if (err == CL_BUILD_PROGRAM_FAILURE) {
        printf("\nBuild Error = %i", err);
        // Determine the size of the log
        size_t log_size;
        //检测能够获取的编译错误的信息
        clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);

        // Allocate memory for the log，分配内存用来存放编译错误的日志
        char *log = (char *) malloc(log_size);

        // Get the log，获取日志
        clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, log_size, log, NULL);

        // Print the log，输出编译的错误日志
        printf("%s\n", log);
    }
    printf("\t[Done]");

    cl_mem cl_p, cl_q, cl_M, cl_result;
    cl_int status = CL_SUCCESS;
    //创建四个内存对象，三个可读，一个可写
    cl_p = clCreateBuffer(context, CL_MEM_READ_WRITE|CL_MEM_COPY_HOST_PTR, sizeof(bignum), &p, &status);
    if (status != CL_SUCCESS || cl_p == NULL) { printf("\nCreate p: %i", status); }

    cl_q = clCreateBuffer(context, CL_MEM_READ_WRITE| CL_MEM_COPY_HOST_PTR, sizeof(bignum), &q, &status);
    if (status != CL_SUCCESS || cl_q == NULL) { printf("\nCreate q: %i", status); }

    cl_M = clCreateBuffer(context, CL_MEM_READ_WRITE| CL_MEM_COPY_HOST_PTR, sizeof(bignum), &M, &status);
    if (status != CL_SUCCESS || cl_M == NULL) { printf("\nCreate M: %i", status); }

    cl_result = clCreateBuffer(context, CL_MEM_WRITE_ONLY| CL_MEM_COPY_HOST_PTR, sizeof(bignum), &result, &status);
    if (status != CL_SUCCESS || cl_result == NULL) { printf("\nCreate result: %i", status); }
    //创建kernel
    // CL_MEM_COPY_HOST_PTR
    cl_kernel rsa_kernel = clCreateKernel(program,"rsa_cypher", &status);
    if (status != CL_SUCCESS) { printf("\nclCreateKernel: %i", status); }
    //设定kernel的参数
    status = clSetKernelArg(rsa_kernel, 0, sizeof(cl_mem), &cl_p);
    status = clSetKernelArg(rsa_kernel, 1, sizeof(cl_mem), &cl_q);
    status = clSetKernelArg(rsa_kernel, 2, sizeof(cl_mem), &cl_M);
    status = clSetKernelArg(rsa_kernel, 3, sizeof(cl_mem), &cl_result);
    status = clSetKernelArg(rsa_kernel, 4, sizeof(int), &e);
    if (status != CL_SUCCESS) { printf("\nclSetKernelArg: %i", status); }
    //配置work-item的组织形式，局部的local_work_size和全局的global_work_size都为1
    size_t local_ws = 1, global_ws = 1;
    printf("\nRun Parameters: Local: %zu - Global: %zu", local_ws, global_ws);
    //将kernel对象，和work-item的参数放入命令队列中执行
    status = clEnqueueNDRangeKernel(queue, rsa_kernel, 1, NULL, &global_ws, &local_ws, 0, NULL, NULL);
    if (status != CL_SUCCESS) { printf("\nclEnqueueNDRangeKernel: %i", status); }
    //阻塞直到命令队列中的所有命令完成
    clFinish(queue);
    //将结果读取到主机程序中
    status = clEnqueueReadBuffer(queue, cl_result, CL_TRUE, 0, sizeof(bignum), &result, 0, NULL, NULL);
    if (status != CL_SUCCESS) { printf("\nclEnqueueReadBuffer: %i", status); }

    printf("\nEncrypted Result: ");
    print_bignum(&result);
    //设备程序运行结束时间
    c_stop = clock();
    //计算设备程序运行计算总共时间，并*1000，以秒显示
    float diff = (((float)c_stop - (float)c_start) / CLOCKS_PER_SEC ) * 1000;

    printf("\nWriting result to outfile...");
    //将结果以字符的形式写到outfile里
    for (int i = result.lastdigit+1; i --> 0;)
    {
        fprintf(outfile, "%c", result.digits[i]+'0');
    }
    printf("\t[Done]");
    //输出设备程序运行时间
    printf("\nDone - Time taken: %f ms\n", diff);
    //释放OpenCL的资源
    clReleaseMemObject(cl_p);
    clReleaseMemObject(cl_q);
    clReleaseMemObject(cl_M);
    clReleaseMemObject(cl_result);
    //关闭文件
    fclose(conf_file);
    fclose(outfile);
    //释放主机内存
    free(source_str);
    //释放OpenCL的资源
    clReleaseContext(context);
    clReleaseCommandQueue(queue);
    return 0;
}
