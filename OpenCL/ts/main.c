#include <stdio.h>
#include <stdlib.h>
#define CL_TARGET_OPENCL_VERSION 110
#include <CL/opencl.h>
#include <time.h>


#define TYPE long long // ** Here 64bits = long in ocl
// OpenCL kernel. Each work item takes care of one element of c
const char *kernelSource =                                       "\n" \
"#define TYPE long                    \n" \
"__kernel void cat(  const __global TYPE *a,                       \n" \
"                       __global TYPE *b,                       \n" \
"                       __global TYPE *c)                    \n" \
"{                                                               \n" \
"    //Get our global thread ID,const TYPE bb ,id2=id+bb;                                 \n" \
"    size_t id = get_global_id(0);                              \n" \
"    c[id] = a[id] + b[id];                                                      \n" \
"    //Make sure we do not go out of bounds                      \n" \
"      //  c[id2] = id2;/*a[id];*/                                  \n" \
"}                                                               \n" \
                                                                "\n" ;
//"#pragma OPENCL EXTENSION cl_khr_fp64 : enable                    \n" \


int main( int argc, char* argv[] )
{
    // Length of vectors
    unsigned int n = 3;

    // Host input vectors
    TYPE *h_a = NULL;
    TYPE *h_b = NULL;
    // Host output vector
    TYPE *h_c  = NULL;
    TYPE bb = 1;

    // Device input buffers
    cl_mem d_a;
    cl_mem d_b;
    // Device output buffer
    cl_mem d_c,d_e;

    cl_platform_id cpPlatform[3];        // OpenCL platform
    cl_device_id device_id;           // device ID
    cl_context context;               // context
    cl_command_queue queue;           // command queue
    cl_program program;               // program
    cl_kernel kernel,kernel2;                 // kernel

    // Size, in bytes, of each vector
    size_t bytes = n*sizeof(TYPE);

    // Allocate memory for each vector on host
    h_a = (TYPE*)malloc(bytes);
    h_b = (TYPE*)malloc(bytes);
    h_c = (TYPE*)malloc(bytes);

    // Initialize vectors on host
    int i;
    for( i = 0; i < n; i++ )
    {
        h_a[i] = 1;
        h_b[i] = 1;
        //printf("%d\n",h_a[i]);
    }
    for( i = 0; i < n; i++ )
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
    //��ȡһ�����õ�ƽ̨
    err = clGetPlatformIDs(3, cpPlatform, NULL);
    // Get ID for the device, change the platform number to get the correct gpu driver.
    //
    err = clGetDeviceIDs(cpPlatform[0], CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);

    // Create a context
    context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);

    // Create a command queue
    queue = clCreateCommandQueue(context, device_id, 0, &err);

    // Create the compute program from the source buffer
    program = clCreateProgramWithSource(context, 1,
                            (const char **) & kernelSource, NULL, &err);

    // Build the program executable
    clBuildProgram(program, 0, NULL, NULL, NULL, NULL);

    // Create the compute kernel in the program we wish to run
    kernel = clCreateKernel(program, "cat", &err);
   // kernel2 = clCreateKernel(program, "vecAdd", &err);


    // Create the input and output arrays in device memory for our calculation
    d_a = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes, NULL, NULL);
    d_b = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes, NULL, NULL);
    d_c = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes, NULL, NULL);
    //d_e = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes, NULL, NULL);

    //err = clEnqueueWriteBuffer(queue, d_c, CL_TRUE, 0,
                                   //3*bytes, h_c, 0, NULL, NULL);
    //err |= clEnqueueWriteBuffer(queue, d_a, CL_TRUE, 0,
                                   //bytes, h_a, 0, NULL, NULL);
    err = clEnqueueWriteBuffer(queue, d_a, CL_FALSE, 0,
                                   bytes, h_a, 0, NULL, NULL);
    err = clEnqueueWriteBuffer(queue, d_b, CL_FALSE, 0,
                                   bytes, h_b, 0, NULL, NULL);
for(int i = 0;i<3;i++){
            // Write our data set into the input array in device memory


                                   bb = i*n;
    // Set the arguments to our compute kernel
    err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &d_a);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &d_b);
    err |= clSetKernelArg(kernel, 2, sizeof(cl_mem), &d_c);
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
                                bytes, h_c, 0, NULL, NULL );

    //Sum up vector c and print result divided by n, this should equal 1 within error

    double sum = 0;
    for(i=0; i< n; i++){
        printf("%d\n",h_c[i]);
        sum += h_c[i];
    }


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
    free(h_b);
    free(h_c);
    h_a = NULL;
    h_b = NULL;
    h_c = NULL;
    return 0;
}
//#include <stdio.h>
//#include <stdlib.h>
//#define CL_TARGET_OPENCL_VERSION 110
//#include <CL/cl.h>//����OpenCLͷ�ļ�
//#include <time.h>
//
//
//#define TYPE long long // ** Here 64bits = long in ocl
// OpenCL kernel. Each work item takes care of one element of c
//const char *kernelSource =                                       "\n" \
//"#define TYPE long                    \n" \
//"__kernel void cat(  const __global TYPE *a,                       \n" \
//"                       __global TYPE *c,                       \n" \
//"                       const TYPE bb)                    \n" \
//"{                                                               \n" \
//"    //Get our global thread ID���������������ά���ϵ�ǰwork_item��ȫ�ֿռ��е����� \n" \
//"    size_t id = get_global_id(0),id2;                                  \n" \
//"    id2=id+bb;                                                        \n" \
//"    //Make sure we do not go out of bounds                      \n" \
//"        c[id2] = id2;/*a[id];*/                                  \n" \
//"}                                                               \n" \
//                                                                "\n" ;
//"#pragma OPENCL EXTENSION cl_khr_fp64 : enable                    \n" \
//
//
//int main( int argc, char* argv[] )
//{
//     Length of vectors
//      n Ϊ���鳤��
//    unsigned int n = 3;
//
//     Host input vectors
//    �������������������������
//    TYPE *h_a = NULL;
//    TYPE *h_b = NULL;
//     Host output vector
//    ����һ������������������
//    TYPE *h_c  = NULL;
//    TYPE bb = 1;
//
//     Device input buffers
//     �����豸����������buffers
//    cl_mem d_a;
//    cl_mem d_b;
//     Device output buffer
//     �����豸���������buffers
//    cl_mem d_c,d_e;
//
//    cl_platform_id cpPlatform[3];        // OpenCL platform,����һ��ƽ̨���飬���3�����õ�ƽ̨��Ϣ
//    cl_device_id device_id;           // device ID������һ������豸��Ϣ�ı���
//    cl_context context;               // context������һ����������ĵı���
//    cl_command_queue queue;           // command queue������һ��������еı���
//    cl_program program;               // program������һ����������
//    cl_kernel kernel,kernel2;                 // kernel����������kernel
//
//     Size, in bytes, of each vector
//     ȷ��ÿ����������Ҫ���ֽ���
//    size_t bytes = n*sizeof(TYPE);
//
//     Allocate memory for each vector on host
//     ��������Ϊÿ�����������ڴ�
//    h_a = (TYPE*)malloc(bytes);
//    h_b = (TYPE*)malloc(bytes);
//    h_c = (TYPE*)malloc(3*bytes);
//
//     Initialize vectors on host
//     ��ʼ������������
//    int i;
//    for( i = 0; i < n; i++ )
//    {
//        h_a[i] = i;
//        h_b[i] = 1;
//    }
//    for( i = 0; i < 3*n; i++ )
//    {
//        h_c[i] = 0;
//        h_b[i] = 1;
//    }
//    ����work-item����֯��ʽ��
//    size_t globalSize, localSize;
//    cl_int err;
//
//     Number of work items in each local work group
//    localSize = 64;
//
//     Number of total work items - localSize must be devisor
//    globalSize = n;//ceil(n/(double)localSize)*localSize;
//
//     Bind to platform
//    ��ȡһ�����õ�ƽ̨
//    err = clGetPlatformIDs(3, cpPlatform, NULL);
//     Get ID for the device, change the platform number to get the correct gpu driver.
//    ��ȡһ�����õ��豸����GPU,
//    err = clGetDeviceIDs(cpPlatform[1], CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
//
//     Create a context
//     ���������ģ������豸��
//    context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
//
//     Create a command queue
//     ����һ��������У�һ���豸��Ӧһ��������У������Ľ�����͵��豸��Ӧ��������У��豸�Ϳ���ִ������������     ����
//    queue = clCreateCommandQueue(context, device_id, 0, &err);
//
//     Create the compute program from the source buffer
//      ����������󣬳������ʹ�����ĳ���Դ�ļ������������
//    program = clCreateProgramWithSource(context, 1,
//                            (const char **) & kernelSource, NULL, &err);
//
//     Build the program executable
//   	 ���������ִ�г���
//    clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
//
//     Create the compute kernel in the program we wish to run
//     �������ǵĳ�����󣬴���һ������ϣ�����е�kernel���󣬱�ʾ�豸��������
//    kernel = clCreateKernel(program, "cat", &err);
//    kernel2 = clCreateKernel(program, "vecAdd", &err);
//
//     Create the input and output arrays in device memory for our calculation
//     ���豸���ڴ��д���������������������������
//    d_a = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes, NULL, NULL);
//    d_b = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes, NULL, NULL);
//    d_c = clCreateBuffer(context, CL_MEM_READ_WRITE, 3*bytes, NULL, NULL);
//    d_e = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes, NULL, NULL);
//		��ȡ������������ݣ���д���豸��buffer�У�buffer��ʵ������c�����е�����
//    	 ������cд���豸�����buffer��
//        err = clEnqueueWriteBuffer(queue, d_c, CL_TRUE, 0,
//                                   3*bytes, h_c, 0, NULL, NULL);
//     ������aд���豸�����buffer�У�
//    err |= clEnqueueWriteBuffer(queue, d_a, CL_TRUE, 0,
//                                   bytes, h_a, 0, NULL, NULL);
//
//for(int i = 0;i<3;i++){
//             Write our data set into the input array in device memory
//			 �����ǵ����ݼ�д���豸�ڴ��е���������
//
//                                   bb = i*n;
//     Set the arguments to our compute kernel
//     Ϊ���ǵ�kernel��������ʵ��
//    err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &d_a);
//    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &d_c);
//    err |= clSetKernelArg(kernel, 2, sizeof(TYPE), &bb);
//     Execute the kernel over the entire range of the data set
//     ��kernel���󣬺�work-item�Ĳ����������������ִ��
//    err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, 0,
//                                                              0, NULL, NULL);
//}
//     Execute the kernel over the entire range of the data set
//    err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, 0,
//                                                              0, NULL, NULL);
///*
//    err  = clSetKernelArg(kernel2, 0, sizeof(cl_mem), &d_a);
//    err |= clSetKernelArg(kernel2, 1, sizeof(cl_mem), &d_b);
//    err |= clSetKernelArg(kernel2, 2, sizeof(cl_mem), &d_c);
//
//     Execute the kernel over the entire range of the data set
//    err = clEnqueueNDRangeKernel(queue, kernel2, 1, NULL, &globalSize, 0,
//                                                              0, NULL, NULL);
//*/
//     Wait for the command queue to get serviced before reading back results
//    clFinish(queue);
//
//     Read the results from the device
//
//     ���豸�ж�ȡ������
//    clEnqueueReadBuffer(queue, d_c, CL_TRUE, 0,
//                                3*bytes, h_c, 0, NULL, NULL );
//
//    Sum up vector c and print result divided by n, this should equal 1 within error
//
//    double sum = 0;
//    for(i=0; i<3*n; i++)
//        sum += h_c[i];
//    printf("final result: %f\n", sum);
//
//     release OpenCL resources
//     �ͷ�OpenCL ����Ҫ��������Դ
//     �ͷ��ڴ����d_a
//    clReleaseMemObject(d_a);
//    clReleaseMemObject(d_b);
//     �ͷ��ڴ����d_c
//    clReleaseMemObject(d_c);
//     �ͷ������������
//    clReleaseProgram(program);
//     �ͷ�kernel����
//    clReleaseKernel(kernel);
//     �ͷ��������
//    clReleaseCommandQueue(queue);
//     �ͷ�������
//    clReleaseContext(context);
//
//    release host memory
//     �ͷ��������ڴ�
//     free����h_a
//    free(h_a);
//    free(h_b);
//     free����h_c
//    free(h_c);
//    h_a = NULL;
//    h_b = NULL;
//    h_c = NULL;
//    return 0;
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
