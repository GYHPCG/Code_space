﻿// Test4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <CL/cl.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
int main() {

	cl_platform_id* platform;
	cl_uint num_platform;
	cl_int err;

	//获取平台，两次调用，第一次获取平台数量，第二次获取一个可用的平台
	err = clGetPlatformIDs(0, NULL, &num_platform);
	platform = (cl_platform_id*)malloc(sizeof(cl_platform_id) * num_platform);
	err = clGetPlatformIDs(num_platform, platform, NULL);
	for (int i = 0; i < num_platform; i++) {
		printf("\nPlatform %d information\n", i);
		size_t size;
		err = clGetPlatformInfo(platform[i], CL_PLATFORM_NAME, 0, NULL, &size);
		char* PName = (char*)malloc(size);
		err = clGetPlatformInfo(platform[i], CL_PLATFORM_NAME, size, PName, NULL);
		printf("CL_PLATFORM_NAME: %s\n", PName);
		err = clGetPlatformInfo(platform[i], CL_PLATFORM_VENDOR, 0, NULL, &size);
		char* PVendor = (char*)malloc(size);
		err = clGetPlatformInfo(platform[i], CL_PLATFORM_VENDOR, size, PVendor, NULL);
		printf("CL_PLATFORM_VENDOR: %s\n", PVendor);
		err = clGetPlatformInfo(platform[i], CL_PLATFORM_VERSION, 0, NULL, &size);
		char* PVersion = (char*)malloc(size);
		err = clGetPlatformInfo(platform[i], CL_PLATFORM_VERSION, size, PVersion, NULL);
		printf("CL_PLATFORM_VERSION: %s\n", PVersion);
		err = clGetPlatformInfo(platform[i], CL_PLATFORM_PROFILE, 0, NULL, &size);
		char* PProfile = (char*)malloc(size);
		err = clGetPlatformInfo(platform[i], CL_PLATFORM_PROFILE, size, PProfile, NULL);
		printf("CL_PLATFORM_PROFILE: %s\n", PProfile);
		err = clGetPlatformInfo(platform[i], CL_PLATFORM_EXTENSIONS, 0, NULL, &size);
		char* PExten = (char*)malloc(size);
		err = clGetPlatformInfo(platform[i], CL_PLATFORM_EXTENSIONS, size, PExten, NULL);
		printf("CL_PLATFORM_EXTENSIONS: %s\n", PExten);
		free(PName);
		free(PVendor);
		free(PVersion);
		free(PProfile);
		free(PExten);
	}
}
