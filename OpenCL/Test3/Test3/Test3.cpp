﻿// Test3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#include <iostream>

//int main()
//{
 //   std::cout << "Hello World!\n";
//}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <CL/cl.h>
//
//const int ARRAY_SIZE = 1000;
///*
//1. 创建平台
//2. 创建设备
//3. 根据设备创建上下文
//*/
//cl_context CreateContext(cl_device_id* device) {
//	cl_int errNum;
//	cl_uint numPlateforms;
//	cl_platform_id firstPlatformId;
//	cl_context context = NULL;
//	errNum = clGetPlatformIDs(1, &firstPlatformId, &numPlateforms);
//
//	if (errNum != CL_SUCCESS || numPlateforms <= 0) {
//		printf("Failed to find any OpenCL platforms.\n");
//		return NULL;
//	}
//	errNum = clGetDeviceIDs(firstPlatformId, CL_DEVICE_TYPE_GPU, 1, device, NULL);
//	if (errNum != CL_SUCCESS) {
//		printf("There is no GPU , trying CPU...\n");
//		errNum = clGetDeviceIDs(firstPlatformId, CL_DEVICE_TYPE_CPU, 1, device, NULL);
//
//	}
//	if (errNum != CL_SUCCESS) {
//		printf("There is NO CPU or GPU\n");
//		return NULL;
//	}
//	context = clCreateContext(NULL, 1, device, NULL, NULL, &errNum);
//	if (errNum != CL_SUCCESS) {
//		printf("Create context error\n");
//		return NULL;
//	}
//	return context;
//}
///*
//@ 在上下文可用的第一个设备中创建命令队列
//*/
//
//cl_command_queue CreateCommandQueue(cl_context context, cl_device_id device) {
//	cl_int errNum;
//	cl_command_queue commandQueue = NULL;
//	//commandQueue = clCreateCommandQueue(context, device, 0, NULL);
//	// OpenCL 2.0 的用法
//	commandQueue = clCreateCommandQueueWithProperties(context, device, 0, NULL);
//	if (commandQueue == NULL) {
//		printf("Failed to create commandQueue for device 0\n");
//		return NULL;
//	}
//	return commandQueue;
//}
//
//char* ReadKernelSourceFile(const char* filename, size_t* length) {
//	FILE* file = NULL;
//	size_t sourceLenth;
//	char* sourceString;
//	int ret;
//	file = fopen(filename, "rb");
//	if (file == NULL) {
//		printf("%s at %d : Can't open %s \n", __FILE__, __LINE__ - 2, filename);
//		return NULL;
//	}
//	//重定位到文件末尾
//	fseek(file, 0, SEEK_END);
//	sourceLenth = ftell(file);
//	//重定位到文件开头
//	fseek(file, 0, SEEK_SET);
//	sourceString = (char*)malloc(sourceLenth + 1);
//	sourceString[0] = '\0';
//	ret = fread(sourceString, sourceLenth, 1, file);
//	if (ret == 0) {
//		printf("%s at %d : Cant't read source %s\n", __FILE__, __LINE__ - 2, filename);
//		return NULL;
//	}
//	fclose(file);
//	if (length != 0) {
//		*length = sourceLenth;
//	}
//	sourceString[sourceLenth] = '\0';
//	return sourceString;
//
//
//}
//cl_program CreateProgram(cl_context context, cl_device_id device, const char* filename) {
//	cl_int errNum;
//	cl_program program;
//	//记录大小的数据类型
//	size_t program_length;
//	char* const source = ReadKernelSourceFile(filename, &program_length);
//	program = clCreateProgramWithSource(context, 1, (const char**)&source, NULL, NULL);
//
//	if (program == NULL) {
//		printf("Failed to creae CL program from source.\n");
//		return NULL;
//	}
//	errNum = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
//	if (errNum != CL_SUCCESS) {
//		char buildLog[16384];
//		clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, sizeof(buildLog), buildLog, NULL);
//		printf("Error in kernel : %s \n", buildLog);
//		clReleaseProgram(program);
//		return NULL;
//	}
//	return program;
//}
///*
//@ 创建内存对象
//*/
//bool  CreateMemObjects(cl_context context, cl_mem memObjects[3], float* a, float* b) {
//	memObjects[0] = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(float) * ARRAY_SIZE, a, NULL);
//	memObjects[1] = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(float) * ARRAY_SIZE, b, NULL);
//	memObjects[2] = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(float) * ARRAY_SIZE, NULL, NULL);
//	if (memObjects[0] == NULL || memObjects[1] == NULL || memObjects[2] == NULL) {
//		printf("Error creating memeory objects.\n");
//		return false;
//
//	}
//	return true;
//}
///*
//@ 清楚OpenCL资源
//*/
//void CleanUp(cl_context context, cl_command_queue commandQueue, cl_program program, cl_kernel kernel, cl_mem memObjects[3]) {
//	for (int i = 0; i < 3; i++) {
//		if (memObjects[i] != 0) {
//			clReleaseMemObject(memObjects[i]);
//		}
//	}
//
//	if (commandQueue != 0) {
//		clReleaseCommandQueue(commandQueue);
//	}
//	if (kernel != 0) {
//		clReleaseKernel(kernel);
//	}
//	if (program != 0) {
//		clReleaseProgram(program);
//	}
//	if (context != 0) {
//		clReleaseContext(context);
//	}
//}
//
///*main函数*/
//int main(int argc, char** agrv) {
//	cl_context context = 0;
//	cl_command_queue commandQueue = 0;
//	cl_program program = 0;
//	cl_device_id device = 0;
//	cl_kernel kernel = 0;
//	cl_mem memObjects[3] = { 0,0,0 };
//	cl_int errNum;
//	//创建OpenCL上下文
//	context = CreateContext(&device);
//	if (context == NULL) {
//		printf("Failed to create OpenCL context\n");
//		return 1;
//	}
//	//获得OpenCL设备，并创建命令队列
//	commandQueue = CreateCommandQueue(context, device);
//	if (commandQueue == NULL) {
//		CleanUp(context, commandQueue, program, kernel, memObjects);
//		return 1;
//	}
//	//创建OpenCL程序
//	program = CreateProgram(context, device, "vecAdd.cl");
//	if (program == NULL) {
//		CleanUp(context, commandQueue, program, kernel, memObjects);
//		return 1;
//	}
//	kernel = clCreateKernel(program, "vector_add", NULL);
//	if (kernel == NULL) {
//		printf("Failed to create kernel\n");
//		CleanUp(context, commandQueue, program, kernel, memObjects);
//		return 1;
//
//	}
//	//创建OpenCL内存对象
//	float result[ARRAY_SIZE];
//	float a[ARRAY_SIZE];
//	float b[ARRAY_SIZE];
//	for (int i = 0; i < ARRAY_SIZE; i++) {
//		a[i] = (float)i;
//		b[i] = (float)(i * 2);
//	}
//	if (!CreateMemObjects(context, memObjects, a, b)) {
//		CleanUp(context, commandQueue, program, kernel, memObjects);
//		return 1;
//	}
//	//设置内核参数
//	errNum = clSetKernelArg(kernel, 0, sizeof(cl_mem), &memObjects[0]);
//	errNum |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &memObjects[1]);
//	errNum |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &memObjects[2]);
//
//	if (errNum != CL_SUCCESS) {
//		printf("Error setting kernel arguments.\n");
//		CleanUp(context, commandQueue, program, kernel, memObjects);
//		return 1;
//	}
//	size_t globalWorkSize[1] = { ARRAY_SIZE };
//	size_t localWorkSize[1] = { 1 };
//	//执行内核
//	errNum = clEnqueueNDRangeKernel(commandQueue, kernel, 1, NULL, globalWorkSize, localWorkSize, 0, NULL, NULL);
//	if (errNum != CL_SUCCESS) {
//		printf("Error queueing kernel for execution\n");
//		CleanUp(context, commandQueue, program, kernel, memObjects);
//		return 1;
//	}
//	//将计算的结果拷贝到主机上
//	errNum = clEnqueueReadBuffer(commandQueue, memObjects[2], CL_TRUE, 0, ARRAY_SIZE * sizeof(float), result, 0, NULL, NULL);
//	if (errNum != CL_SUCCESS) {
//		printf("Error reading result buffer.\n");
//		CleanUp(context, commandQueue, program, kernel, memObjects);
//		return 1;
//	}
//	for (int i = 0; i < ARRAY_SIZE; i++) {
//		printf("i=%d:%f\n", i, result[i]);
//	}
//	printf("Executed program succesfully\n");
//	CleanUp(context, commandQueue, program, kernel, memObjects);
//	return 0;
//}
//#include <CL/cl.h>
//#include <stdio.h>
//#include <string.h>
//#include <malloc.h>
//
//int main() {
//	cl_platform_id* platform;
//	cl_uint num_platform;
//	cl_int err;
//	err = clGetPlatformIDs(0, NULL, &num_platform);
//	platform = (cl_platform_id*)malloc(sizeof(cl_platform_id) * num_platform);
//	err = clGetPlatformIDs(num_platform, platform, NULL);
//	for (int i = 0; i < num_platform; i++) {
//		printf("\nPlatform %d information\n", i);
//		size_t size;
//		err = clGetPlatformInfo(platform[i], CL_PLATFORM_NAME, 0, NULL, &size);
//		char* PName = (char*)malloc(size);
//		err = clGetPlatformInfo(platform[i], CL_PLATFORM_NAME, size, PName, NULL);
//		printf("CL_PLATFORM_NAME: %s\n", PName);
//		err = clGetPlatformInfo(platform[i], CL_PLATFORM_VENDOR, 0, NULL, &size);
//		char* PVendor = (char*)malloc(size);
//		err = clGetPlatformInfo(platform[i], CL_PLATFORM_VENDOR, size, PVendor, NULL);
//		printf("CL_PLATFORM_VENDOR: %s\n", PVendor);
//		err = clGetPlatformInfo(platform[i], CL_PLATFORM_VERSION, 0, NULL, &size);
//		char* PVersion = (char*)malloc(size);
//		err = clGetPlatformInfo(platform[i], CL_PLATFORM_VERSION, size, PVersion, NULL);
//		printf("CL_PLATFORM_VERSION: %s\n", PVersion);
//		err = clGetPlatformInfo(platform[i], CL_PLATFORM_PROFILE, 0, NULL, &size);
//		char* PProfile = (char*)malloc(size);
//		err = clGetPlatformInfo(platform[i], CL_PLATFORM_PROFILE, size, PProfile, NULL);
//		printf("CL_PLATFORM_PROFILE: %s\n", PProfile);
//		err = clGetPlatformInfo(platform[i], CL_PLATFORM_EXTENSIONS, 0, NULL, &size);
//		char* PExten = (char*)malloc(size);
//		err = clGetPlatformInfo(platform[i], CL_PLATFORM_EXTENSIONS, size, PExten, NULL);
//		printf("CL_PLATFORM_EXTENSIONS: %s\n", PExten);
//		free(PName);
//		free(PVendor);
//		free(PVersion);
//		free(PProfile);
//		free(PExten);
//	}
//}
//
#include <stdio.h>
#include <stdlib.h>
#define CL_TARGET_OPENCL_VERSION 110
#include <CL/opencl.h>
#include <time.h>
#pragma warning(disable: 4996)

#define TYPE long long // ** Here 64bits = long in ocl
// OpenCL kernel. Each work item takes care of one element of c
const char* kernelSource = "\n" \
"#define TYPE long                    \n" \
"__kernel void cat(  const __global TYPE *a,                       \n" \
"                       __global TYPE *c,                       \n" \
"                       const TYPE bb)                    \n" \
"{                                                               \n" \
"    //Get our global thread ID                                  \n" \
"    size_t id = get_global_id(0),id2;                                  \n" \
"    id2=id+bb;                                                        \n" \
"    //Make sure we do not go out of bounds                      \n" \
"        c[id2] = id2;/*a[id];*/                                  \n" \
"}                                                               \n" \
"\n";
//"#pragma OPENCL EXTENSION cl_khr_fp64 : enable                    \n" \


int main(int argc, char* argv[])
{
    // Length of vectors
    unsigned int n = 3;

    // Host input vectors
    TYPE* h_a;
    TYPE* h_b;
    // Host output vector
    TYPE* h_c;
    TYPE bb = 1;

    // Device input buffers
    cl_mem d_a;
    cl_mem d_b = NULL;
    // Device output buffer
    cl_mem d_c, d_e;

    cl_platform_id cpPlatform[3];        // OpenCL platform
    cl_device_id device_id;           // device ID
    cl_context context;               // context
    cl_command_queue queue;           // command queue
    cl_program program;               // program
    cl_kernel kernel, kernel2;                 // kernel

    // Size, in bytes, of each vector
    size_t bytes = n * sizeof(TYPE);

    // Allocate memory for each vector on host
    h_a = (TYPE*)malloc(bytes);
    // h_b = (TYPE*)malloc(bytes);
    h_c = (TYPE*)malloc(3 * bytes);

    // Initialize vectors on host
    int i;
    for (i = 0; i < n; i++)
    {
        h_a[i] = 1;
        //h_b[i] = 1;
    }
    for (i = 0; i < 3 * n; i++)
    {
        h_c[i] = 0;
        //h_b[i] = 1;
    }
    size_t globalSize, localSize;
    cl_int err;

    // Number of work items in each local work group
    //localSize = 64;

    // Number of total work items - localSize must be devisor
    globalSize = n;//ceil(n/(double)localSize)*localSize;

    // Bind to platform
    err = clGetPlatformIDs(3, cpPlatform, NULL);
    // Get ID for the device, change the platform number to get the correct gpu driver.
    err = clGetDeviceIDs(cpPlatform[0], CL_DEVICE_TYPE_CPU, 1, &device_id, NULL);
   
    // Create a context
    context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);

    // Create a command queue
    queue = clCreateCommandQueue(context, device_id, 0, &err);

    // Create the compute program from the source buffer
    program = clCreateProgramWithSource(context, 1,
        (const char**)&kernelSource, NULL, &err);

    // Build the program executable
    clBuildProgram(program, 0, NULL, NULL, NULL, NULL);

    // Create the compute kernel in the program we wish to run
    kernel = clCreateKernel(program, "cat", &err);
    // kernel2 = clCreateKernel(program, "vecAdd", &err);


     // Create the input and output arrays in device memory for our calculation
    d_a = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes, NULL, NULL);
    //d_b = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes, NULL, NULL);
    d_c = clCreateBuffer(context, CL_MEM_READ_WRITE, 3 * bytes, NULL, NULL);
    //d_e = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes, NULL, NULL);

    err = clEnqueueWriteBuffer(queue, d_c, CL_TRUE, 0,
        3 * bytes, h_c, 0, NULL, NULL);
    err |= clEnqueueWriteBuffer(queue, d_a, CL_TRUE, 0,
        bytes, h_a, 0, NULL, NULL);

    for (int i = 0; i < 3; i++) {
        // Write our data set into the input array in device memory


        bb = i * n;
        // Set the arguments to our compute kernel
        err = clSetKernelArg(kernel, 0, sizeof(cl_mem), &d_a);
        err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &d_c);
        err |= clSetKernelArg(kernel, 2, sizeof(TYPE), &bb);
        // Execute the kernel over the entire range of the data set
        err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, 0,
            0, NULL, NULL);
    }
    // Execute the kernel over the entire range of the data set
   // err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, 0,
   //                                                           0, NULL, NULL);
/*
    err  = clSetKernelArg(kernel2, 0, sizeof(cl_mem), &d_a);
    err |= clSetKernelArg(kernel2, 1, sizeof(cl_mem), &d_b);
    err |= clSetKernelArg(kernel2, 2, sizeof(cl_mem), &d_c);

    // Execute the kernel over the entire range of the data set
    err = clEnqueueNDRangeKernel(queue, kernel2, 1, NULL, &globalSize, 0,
                                                              0, NULL, NULL);
*/
// Wait for the command queue to get serviced before reading back results
//clFinish(queue);

// Read the results from the device
    clEnqueueReadBuffer(queue, d_c, CL_TRUE, 0,
        3 * bytes, h_c, 0, NULL, NULL);

    //Sum up vector c and print result divided by n, this should equal 1 within error

    double sum = 0;
    for (i = 0; i < 3 * n; i++)
        sum += h_c[i];
    printf("final result: %f\n", sum);

    // release OpenCL resources
    clReleaseMemObject(d_a);
    clReleaseMemObject(d_b);
    clReleaseMemObject(d_c);
    clReleaseProgram(program);
    clReleaseKernel(kernel);
    clReleaseCommandQueue(queue);
    clReleaseContext(context);

    //release host memory
    free(h_a);
    //free(h_b);
    free(h_c);

    return 0;
}
