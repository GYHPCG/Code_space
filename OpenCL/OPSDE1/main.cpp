#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <CL/cl.h>

using namespace std;


// config:
bool debug = false;
short int key[10] = { 0, 0, 1, 0, 0, 1, 0, 1, 1, 1 }; // encryption key; keySize = 10
bool crypt = true; // if true, plainFile will be crypted真则加密

const string plainFilename = "lipsum-500mb.txt";//命名文件

bool decrypt = false; // if true, cryptedFile will be decrypted假则解密

const string cryptedFilename = "encrypted_lipsum-500mb.txt";//命名文件


bool autoThreadsConfig = true; // automatic threads config optimal for specific GPU device. If set true, values defined below will be ignored
//自动线程配置最适合特定GPU设备。如果设置为true，下面定义的值将被忽略
unsigned long int numberOfThreads = 256*256*256; // global group size
unsigned int threadsGroupSize = 128; // local group size
// config end


// global variables
short int subKeyK1[8] = { 0 };
short int subKeyK2[8] = { 0 };


// declaration of functions
void printBlock(short int * block, short int len);
void generateSubKeys(short int * key, short int * subKeyK1, short int * subKeyK2);
void permuteKeyP10(short int * key);
void permuteSubKeyP8(short int * inBlock, short int * outBlock);
void shift1(short int * k);
void shift2(short int * k);


void generateSubKeys(short int * key, short int * subKeyK1, short int * subKeyK2)
{
	short int tmpKey[10];
	memcpy(tmpKey, key, sizeof(short int) * 10);

	// permutation
	permuteKeyP10(tmpKey);

	// shifts (applied for both subKeys):
	shift1(tmpKey);

	// get final subKey1
	permuteSubKeyP8(tmpKey, subKeyK1);

	// generate subKey2
	shift2(tmpKey);
	permuteSubKeyP8(tmpKey, subKeyK2);
}

void permuteKeyP10(short int * key)
{
	// block size = 10 elements!
	// P10 = [ 3 5 2 7 4 10 1 9 8 6 ]
	// P10 = [ 2 4 1 6 3 9 0 8 7 5 ] -> indexes starts from 0
	short int tmp[10];
	memcpy(tmp, key, sizeof(short int) * 10);

	key[0] = tmp[2];
	key[1] = tmp[4];
	key[2] = tmp[1];
	key[3] = tmp[6];
	key[4] = tmp[3];
	key[5] = tmp[9];
	key[6] = tmp[0];
	key[7] = tmp[8];
	key[8] = tmp[7];
	key[9] = tmp[5];
}

void shift1(short int * k)//置换操作
{
	// input =	[ 0 1 2 3 4 5 6 7 8 9 ]
	// output = [ 1 2 3 4 0 6 7 8 9 5 ]
	short int tmp[10];
	memcpy(tmp, k, sizeof(short int) * 10);

	k[0] = tmp[1];
	k[1] = tmp[2];
	k[2] = tmp[3];
	k[3] = tmp[4];
	k[4] = tmp[0];
	k[5] = tmp[6];
	k[6] = tmp[7];
	k[7] = tmp[8];
	k[8] = tmp[9];
	k[9] = tmp[5];
}

void shift2(short int * k)
{
	// input =	[ 0 1 2 3 4 5 6 7 8 9 ]
	// output = [ 2 3 4 0 1 7 8 9 5 6 ]
	short int tmp[10];
	memcpy(tmp, k, sizeof(short int) * 10);

	k[0] = tmp[2];
	k[1] = tmp[3];
	k[2] = tmp[4];
	k[3] = tmp[0];
	k[4] = tmp[1];
	k[5] = tmp[7];
	k[6] = tmp[8];
	k[7] = tmp[9];
	k[8] = tmp[5];
	k[9] = tmp[6];
}

void permuteSubKeyP8(short int * inBlock, short int * outBlock)
{
	// P8 = [ 6 3 7 4 8 5 10 9 ]
	// P8 = [ 5 2 6 3 7 4 9 8 ] -> indexes starts from 0
	// inBlock = 10 elements
	// outBlock = 8 elements
	outBlock[0] = inBlock[5];
	outBlock[1] = inBlock[2];
	outBlock[2] = inBlock[6];
	outBlock[3] = inBlock[3];
	outBlock[4] = inBlock[7];
	outBlock[5] = inBlock[4];
	outBlock[6] = inBlock[9];
	outBlock[7] = inBlock[8];
}

void printBlock(short int * block, short int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << block[i] << " ";
	}
	cout << endl;
}


int main(int argc, char* argv[])
{
	clock_t start_time_total = clock(); // time capture
	// OpenCL init
	cl_int status;
	cl_uint num_platforms = 0;
	status = clGetPlatformIDs(0, NULL, &num_platforms);
	if (num_platforms == 0 || status != CL_SUCCESS)
	{
		return EXIT_FAILURE;
	}
	vector<cl_platform_id> platforms(num_platforms);
	status = clGetPlatformIDs(num_platforms, &platforms.front(), NULL);
	const cl_device_type kDeviceType = CL_DEVICE_TYPE_GPU; // get GPU device获取GPU设备
	cl_device_id device;
	cl_platform_id platform;
	bool found = false;
	for (cl_uint i = 0; i < num_platforms && !found; ++i)
	{
		cl_uint count = 0;
		status = clGetDeviceIDs(platforms[i], kDeviceType, 1, &device, &count);
		if (count == 1)
		{
			platform = platforms[i];
			found = true;
		}
	}

	// generate subKeys生成注册表子项
	generateSubKeys(key, subKeyK1, subKeyK2);
	if (debug)
	{
		cout << "subKey1:\t";
		printBlock(subKeyK1, 8);
		cout << "subKey2:\t";
		printBlock(subKeyK2, 8);
		cout << endl;
	}

	if (crypt)//加密过程
	{
		cout << "S-DES encryption of file: " << plainFilename << "." << endl;
		// load file into memory
		clock_t begin_load = clock(); // time capture

		ifstream input;//输入方式打开文件
		unsigned long int fileLength = 0;
		char * inputText;
		char * outputText;
		input.open(plainFilename, ios::binary); // open input file,binary为以二进制方式打开文件。
		if (!input.is_open())
		{
			cout << "Error opening input file!" << endl;
			return 1;
		}
		input.seekg(0, input.end);			// go to the end
		fileLength = input.tellg();			// report location (this is the length)报告位置(这是长度)
		input.seekg(0, input.beg);			// go back to the beginning返回开始
		inputText = new char[fileLength];	// allocate memory for a buffer of appropriate dimension为适当大小的缓冲区分配内存
		input.read(inputText, fileLength);	// read the whole file into the buffer将整个文件读入缓冲区
		input.close();						// close file handle关闭文件句柄

		cout << "File loaded in\t\t" << double(clock() - begin_load) / CLOCKS_PER_SEC << " s" << endl;
		cout << "File size: \t\t" << fileLength << " bytes." << endl;

		outputText = new char[fileLength];


		// OpenCL part ============================================================================

		// Create context上下文
		const cl_context_properties prop[] = { CL_CONTEXT_PLATFORM, (cl_context_properties)platform, 0 };
		cl_context context = clCreateContextFromType(prop, kDeviceType, NULL, NULL, &status);

		if (status != CL_SUCCESS) {
			cout << "Creating OpenCL context failed. Error code: " << status << endl;
		}

		// create queue命令队列
		cl_command_queue cmd_queue = clCreateCommandQueue(context, device, 0, &status);

		// load opencl source加载opencl源代码
		ifstream cl_file("kernel_crypt.cl");
		if (cl_file.fail())
		{
			cout << "Error opening kernel file!" << endl;
			std::system("PAUSE");
			return 1;
		}
		string kernel_string(istreambuf_iterator<char>(cl_file), (istreambuf_iterator<char>()));
		const char *src = kernel_string.c_str();

		// create OpenCL program创建程序
		cl_program program = clCreateProgramWithSource(context, 1, (const char**)&src, NULL, NULL);

		status = clBuildProgram(program, 1, &device, "-I ./ -cl-std=CL2.0", NULL, NULL);
        printf("clBUild's et is %d\n",status);
		if (status != CL_SUCCESS) {
			char log[1024] = {};
			clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 1024, log, NULL);
			cout << "Build log:\n" << log << endl;
			return EXIT_FAILURE;
		}

		// create KERNEL创建内核
		cl_kernel kernel = clCreateKernel(program, "crypt", NULL);

		// auto threads config自动线程配置
		if (autoThreadsConfig)
		{
			size_t buf_sizet = 0;
			clGetDeviceInfo(device, CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(buf_sizet), &buf_sizet, NULL);
			threadsGroupSize = (unsigned int)buf_sizet;
			numberOfThreads = (unsigned long int)ceil(fileLength / (float)threadsGroupSize) * threadsGroupSize;
		}
		cout << "threadsGroupSize:\t" << threadsGroupSize << endl;
		cout << "numberOfThreads:\t" << numberOfThreads << endl;


		// ENCRYPTION加密
		clock_t begin_encryption = clock();  // time capture

		// memory allocation for input and output buffors输入和输出缓冲区的内存分配
		cl_mem in_text = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(cl_uchar) * fileLength, inputText, NULL);
		cl_mem in_subkey_1 = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(cl_short) * 8, subKeyK1, NULL);
		cl_mem in_subkey_2 = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(cl_short) * 8, subKeyK2, NULL);
		cl_mem out_text = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(cl_uchar) * fileLength, NULL, NULL);

		// send parameters to kernel送入参数
		const cl_ulong cl_fileLength = fileLength;
		const cl_ulong cl_numberOfThreads = numberOfThreads;
		clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&in_text);
		clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&in_subkey_1);
		clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&in_subkey_2);
		clSetKernelArg(kernel, 3, sizeof(cl_mem), (void *)&out_text);
		clSetKernelArg(kernel, 4, sizeof(cl_ulong), (void *)&cl_fileLength);
		clSetKernelArg(kernel, 5, sizeof(cl_ulong), (void *)&cl_numberOfThreads);

		// create index space创建索引空间
		const int dimensions = 1;
		size_t offset[dimensions] = { 0 };
		size_t global_threads[dimensions] = { numberOfThreads };
		size_t local_threads[dimensions] = { threadsGroupSize };

		clock_t start_compute = clock();  // time capture
		// execute kernel执行内核
		cl_event event;
		status = clEnqueueNDRangeKernel(cmd_queue, kernel, dimensions, offset, global_threads, local_threads, 0, NULL, &event);
		clWaitForEvents(1, &event); // wait for finish

		// copy results to host复制结果到主机
		status = clEnqueueReadBuffer(cmd_queue, out_text, CL_TRUE, 0, fileLength * sizeof(cl_uchar), outputText, 0, NULL, NULL);

		// finalize最终
		clFinish(cmd_queue);

		cout << "Encryption time:\t" << double(clock() - begin_encryption) / CLOCKS_PER_SEC << " s" << endl;

		// cleanup释放
		clReleaseMemObject(in_text);
		clReleaseMemObject(in_subkey_1);
		clReleaseMemObject(in_subkey_2);
		clReleaseMemObject(out_text);
		clReleaseKernel(kernel);
		clReleaseProgram(program);
		clReleaseCommandQueue(cmd_queue);
		clReleaseContext(context);

		// end of OpenCL part =====================================================================

		// Save result to file将结果保存到文件
		clock_t begin_saving = clock();  // time capture
		ofstream output;
		output.open("encrypted_" + plainFilename, ios::binary);
		if (!output.is_open())
		{
			cout << "Error opening file to save results!" << endl;
			return 1;
		}
		output.write(outputText, fileLength);
		output.close();
		cout << "File saved in\t\t" << double(clock() - begin_saving) / CLOCKS_PER_SEC << " s" << endl;

		// SUMMARY最终
		cout << "Total time elapsed:\t" << double(clock() - start_time_total) / CLOCKS_PER_SEC << " s" << endl;

		delete[] inputText;
		delete[] outputText;
	}


	if (decrypt)//解密过程,与加密过程同理
	{
		cout << "S-DES decryption of file: " << cryptedFilename << "." << endl;
		// load file into memory
		clock_t begin_load = clock(); // time capture

		ifstream input;
		unsigned long int fileLength = 0;
		char * inputText;
		char * outputText;
		input.open(cryptedFilename, ios::binary); // open input file
		if (!input.is_open())
		{
			cout << "Error opening input file!" << endl;
			return 1;
		}
		input.seekg(0, input.end);			// go to the end
		fileLength = input.tellg();			// report location (this is the length)
		input.seekg(0, input.beg);			// go back to the beginning
		inputText = new char[fileLength];	// allocate memory for a buffer of appropriate dimension
		input.read(inputText, fileLength);	// read the whole file into the buffer
		input.close();						// close file handle

		cout << "File loaded in\t\t" << double(clock() - begin_load) / CLOCKS_PER_SEC << " s" << endl;
		cout << "File size: \t\t" << fileLength << " bytes." << endl;

		outputText = new char[fileLength];


		// OpenCL part ============================================================================

		// Create context
		const cl_context_properties prop[] = { CL_CONTEXT_PLATFORM, (cl_context_properties)platform, 0 };
		cl_context context = clCreateContextFromType(prop, kDeviceType, NULL, NULL, &status);

		if (status != CL_SUCCESS) {
			cout << "Creating OpenCL context failed. Error code: " << status << endl;
		}

		// create queue
		cl_command_queue cmd_queue = clCreateCommandQueue(context, device, 0, &status);

		// load opencl source
		ifstream cl_file("kernel_decrypt.cl");
		if (cl_file.fail())
		{
			cout << "Error opening kernel file!" << endl;
			std::system("PAUSE");
			return 1;
		}
		string kernel_string(istreambuf_iterator<char>(cl_file), (istreambuf_iterator<char>()));
		const char *src = kernel_string.c_str();

		// create OpenCL program
		cl_program program = clCreateProgramWithSource(context, 1, (const char**)&src, NULL, NULL);

		status = clBuildProgram(program, 1, &device, NULL, NULL, NULL);
		if (status != CL_SUCCESS) {
			char log[1024] = {};
			clGetProgramBuildInfo(program, device, CL_PROGRAM_BUILD_LOG, 1024, log, NULL);
			cout << "Build log:\n" << log << endl;
			return EXIT_FAILURE;
		}

		// create KERNEL
		cl_kernel kernel = clCreateKernel(program, "decrypt", NULL);

		// auto threads config
		if (autoThreadsConfig)
		{
			size_t buf_sizet = 0;
			clGetDeviceInfo(device, CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(buf_sizet), &buf_sizet, NULL);
			threadsGroupSize = (unsigned int)buf_sizet;
			numberOfThreads = (unsigned long int)ceil(fileLength / (float)threadsGroupSize) * threadsGroupSize;
		}
		cout << "threadsGroupSize:\t" << threadsGroupSize << endl;
		cout << "numberOfThreads:\t" << numberOfThreads << endl;


		// ENCRYPTION
		clock_t begin_encryption = clock();  // time capture

		// memory allocation for input and output buffors
		cl_mem in_text = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(cl_uchar) * fileLength, inputText, NULL);
		cl_mem in_subkey_1 = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(cl_short) * 8, subKeyK1, NULL);
		cl_mem in_subkey_2 = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(cl_short) * 8, subKeyK2, NULL);
		cl_mem out_text = clCreateBuffer(context, CL_MEM_READ_WRITE, sizeof(cl_uchar) * fileLength, NULL, NULL);

		// send parameters to kernel
		const cl_ulong cl_fileLength = fileLength;
		const cl_ulong cl_numberOfThreads = numberOfThreads;
		clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&in_text);
		clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&in_subkey_1);
		clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&in_subkey_2);
		clSetKernelArg(kernel, 3, sizeof(cl_mem), (void *)&out_text);
		clSetKernelArg(kernel, 4, sizeof(cl_ulong), (void *)&cl_fileLength);
		clSetKernelArg(kernel, 5, sizeof(cl_ulong), (void *)&cl_numberOfThreads);

		// create index space
		const int dimensions = 1;
		size_t offset[dimensions] = { 0 };
		size_t global_threads[dimensions] = { numberOfThreads };
		size_t local_threads[dimensions] = { threadsGroupSize };

		clock_t start_compute = clock();  // time capture
		// execute kernel
		cl_event event;
		status = clEnqueueNDRangeKernel(cmd_queue, kernel, dimensions, offset, global_threads, local_threads, 0, NULL, &event);
		clWaitForEvents(1, &event); // wait for finish

		// copy results to host
		status = clEnqueueReadBuffer(cmd_queue, out_text, CL_TRUE, 0, fileLength * sizeof(cl_uchar), outputText, 0, NULL, NULL);

		// finalize
		clFinish(cmd_queue);

		cout << "Encryption time:\t" << double(clock() - begin_encryption) / CLOCKS_PER_SEC << " s" << endl;

		// cleanup
		clReleaseMemObject(in_text);
		clReleaseMemObject(in_subkey_1);
		clReleaseMemObject(in_subkey_2);
		clReleaseMemObject(out_text);
		clReleaseKernel(kernel);
		clReleaseProgram(program);
		clReleaseCommandQueue(cmd_queue);
		clReleaseContext(context);

		// end of OpenCL part =====================================================================

		// Save result to file
		clock_t begin_saving = clock();  // time capture
		ofstream output;
		output.open("decrypted_" + cryptedFilename, ios::binary);
		if (!output.is_open())
		{
			cout << "Error opening file to save results!" << endl;
			return 1;
		}
		output.write(outputText, fileLength);
		output.close();
		cout << "File saved in\t\t" << double(clock() - begin_saving) / CLOCKS_PER_SEC << " s" << endl;

		// SUMMARY
		cout << "Total time elapsed:\t" << double(clock() - start_time_total) / CLOCKS_PER_SEC << " s" << endl;

		delete[] inputText;
		delete[] outputText;
	}


	if (!crypt && !decrypt)
	{
		cout << "Hey, there's nothig to do!" << endl;
	}



	system("PAUSE");
	return 0;
}
