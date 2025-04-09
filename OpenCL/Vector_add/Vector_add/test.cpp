#include <stdio.h>
#include <stdlib.h>
#include <CL/opencl.h>

#pragma warning(disable: 4996)
#define MEM_SIZE (128)
#define MAX_SOURCE_SIZE (0x100000)

int main()
{
	cl_device_id device_id = NULL;
	cl_context context = NULL;
	cl_command_queue command_queue = NULL;
	cl_mem memobj = NULL;
	cl_program program = NULL;
	cl_kernel kernel = NULL;
	cl_platform_id platform_id = NULL;
	cl_uint ret_num_devices;
	cl_uint ret_num_platforms;
	cl_int ret;

	char string[MEM_SIZE];

	FILE* fp;
	char fileName[] = "main.cl";
	char* source_str;
	size_t source_size;

	/* Load the source code containing the kernel*/
	fp = fopen(fileName, "r");
	if (!fp) {
		fprintf(stderr, "Failed to load kernel.\n");
		exit(1);
	}
	source_str = (char*)malloc(MAX_SOURCE_SIZE);
	source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
	fclose(fp);

	/* Get Platform and Device Info */
	ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_DEFAULT, 1, &device_id, &ret_num_devices);

	/* Create OpenCL context */
	context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

	/* Create Command Queue */
	command_queue = clCreateCommandQueue(context, device_id, 0, &ret);

	/* Create Memory Buffer */
	memobj = clCreateBuffer(context, CL_MEM_READ_WRITE, MEM_SIZE * sizeof(char), NULL, &ret);
	/* Create Kernel Program from the source */
	program = clCreateProgramWithSource(context, 1, (const char**)&source_str, (const size_t*)&source_size, &ret);
	if (ret != 0)printf("error1:%d",ret);
	/* Build Kernel Program */
	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
	if (ret != CL_SUCCESS)printf("error2:%d", ret);
	/* Create OpenCL Kernel */
	kernel = clCreateKernel(program, "rsa", &ret);
	if (ret != CL_SUCCESS)printf("error3:%d", ret);
	/* Set OpenCL Kernel Parameters */
	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&memobj);

	/* Execute OpenCL Kernel */
	ret = clEnqueueTask(command_queue, kernel, 0, NULL, NULL);

	/* Copy results from the memory buffer */
	ret = clEnqueueReadBuffer(command_queue, memobj, CL_TRUE, 0,
		MEM_SIZE * sizeof(char), string, 0, NULL, NULL);

	/* Display Result */
	puts(string);

	/* Finalization */
	ret = clFlush(command_queue);
	ret = clFinish(command_queue);
	ret = clReleaseKernel(kernel);
	ret = clReleaseProgram(program);
	ret = clReleaseMemObject(memobj);
	ret = clReleaseCommandQueue(command_queue);
	ret = clReleaseContext(context);

	free(source_str);

	//getchar();
	return 0;

}
//
//  CasRSA_CL.c
//  CasRSA_CL
//
//  Created by Carter McCardwell on 11/18/15.
//  Copyright (c) 2015 Carter McCardwell. All rights reserved.
//

//#include <stdio.h>
//#include <stdlib.h>
//#include <fstream>
//#include <CL/cl.h>
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//	//输入数组
//	int* A = NULL;
//	int* B = NULL;
//	//输出数组
//	int* C = NULL;
//	const int elements = 2048;
//	size_t datasize = sizeof(int)*elements;
//
//	A = (int*)malloc(datasize);
//	B = (int*)malloc(datasize);
//	C = (int*)malloc(datasize);
//
//	for (int i = 0; i < elements; ++i) {
//		A[i] = i;
//		B[i] = i;
//	}
//
//	cl_int status;
//	cl_uint numPlatforms = 0;
//	cl_platform_id* platforms = NULL;
//	status = clGetPlatformIDs(0, NULL, &numPlatforms);
//	//
//	platforms = (cl_platform_id*)malloc(numPlatforms * sizeof(cl_platform_id));
//
//	status = clGetPlatformIDs(numPlatforms, platforms, NULL);
//	
//	//获取devices
//	cl_uint numDevices = 0;
//	cl_device_id* devices = NULL;
//	status = clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_ALL, 0, NULL, &numDevices);
//
//	devices = (cl_device_id*)malloc(numDevices * sizeof(cl_device_id));
//
//	status = clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_ALL, numDevices,devices, NULL);
//
//
//	//step3: creat a context
//	cl_context context = NULL;
//	context = clCreateContext(NULL, numDevices, devices, NULL, NULL, &status);
//
//	//stpe4: creat a command queue
//	cl_command_queue cmdQueue;
//	cmdQueue = clCreateCommandQueue(context, devices[0], 0, &status);
//
//	//stpe5: Creat a device buffers
//	cl_mem bufferA;
//	cl_mem bufferB;
//	cl_mem bufferC;
//	bufferA = clCreateBuffer(context, CL_MEM_READ_ONLY, datasize, NULL, &status);
//	bufferB = clCreateBuffer(context, CL_MEM_READ_ONLY, datasize, NULL, &status);
//	bufferC = clCreateBuffer(context, CL_MEM_WRITE_ONLY, datasize, NULL, &status);
//
//	//step6: write host data to device buffers
//	status = clEnqueueWriteBuffer(cmdQueue, bufferA, CL_FALSE, 0, datasize, A, 0, NULL, NULL);
//	status = clEnqueueWriteBuffer(cmdQueue, bufferB, CL_FALSE, 0, datasize, B, 0, NULL, NULL);
//
//	//step7: Creat a compile program
//	FILE* fp;
//	char fileName[] = "./main.cl";
//	char* source_str;
//	size_t source_size;
//	
//	/* Load the source code containing the kernel*/
//	fp = fopen(fileName, "r");
//	if (!fp) {
//		fprintf(stderr, "Failed to load kernel.\n");
//		exit(1);
//	}
//	source_str = (char*)malloc(MAX_SOURCE_SIZE);
//	source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
//	fclose(fp);
//	cl_program program = clCreateProgramWithSource(context, 1, (const char**)&source_str,NULL, &status);
//	//build  the program for the devices with clBuildProgram
//	status = clBuildProgram(program, numDevices, devices, NULL, NULL, NULL);
//
//	//creat the kernel
//	cl_kernel kernel = NULL;
//	kernel = clCreateKernel(program, "vecadd", &status);
//
//	//set the kernel arguments
//	status = clSetKernelArg(kernel, 0, sizeof(cl_mem), &bufferA);
//	status = clSetKernelArg(kernel, 1, sizeof(cl_mem), &bufferB);
//	status = clSetKernelArg(kernel, 2, sizeof(cl_mem), &bufferC);
//
//	//step10: configure the work-item stru
//	size_t globalWorkSize[1];
//	globalWorkSize[0] = elements;
//
//	//step11: Enqueue the kernel for execution
//	status = clEnqueueNDRangeKernel(cmdQueue, kernel, 1, NULL, globalWorkSize, NULL, 0, NULL, NULL);
//
//	//step12: Read the output buffer back to the host
//	clEnqueueReadBuffer(cmdQueue, bufferC, CL_TRUE, 0, datasize, C, 0, NULL, NULL);
//	//verify the ouput
//	bool result = true;
//	for (int i = 0; i < elements; ++i) {
//		if (C[i] != i + i) {
//			result = false;
//			break;
//		}
//	}
//	if (result) {
//		printf("Output is correct\n");
//	}
//	else {
//		printf("Output is incorrect\n");
//	}
//	//step13； realease OpenCL resources
//	clReleaseKernel(kernel);
//	clReleaseProgram(program);
//	clReleaseCommandQueue(cmdQueue);
//	clReleaseMemObject(bufferA);
//	clReleaseMemObject(bufferB);
//	clReleaseMemObject(bufferC);
//	clReleaseContext(context);
//
//	//free host resources
//	free(A);
//	free(B);
//	free(C);
//	free(platforms);
//	free(devices);
//
//	return 0;
//}
