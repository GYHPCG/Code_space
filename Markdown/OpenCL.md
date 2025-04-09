---

---

# OpenCL

## 第一章

## 第二章

### 1.Opencl程序

OpenCL程序是分成两部分的：一部分是在==设备上执行的（如GPU）==，另一部分是==在主机上运行的（CPU）==。在设备上执行的程序或许是我们比较关注的。它是OpenCL产生神奇力量的地方。为了能在设备上执行代码，程序员需要写一个==特殊的函数（kernel函数==）。这个函数需要使用OpenCL语言编写。OpenCL语言采用了C语言的一部分加上一些约束、关键字和数据类型。在主机上运行的程序提供了API，所以可以管理我们在设备上运行的程序。主机程序可以用C或者C++编写，它控制OpenCL的环境（上下文，指令队列…）。

### 2.OpenCL的名词概念

#### 一.OpenCL模型

1. **平台模型**：硬件拓扑关系的抽象描述

   - 平台模型由一个Host连接一个或多个OpenCL Devices组成；
   - OpenCL Device，可以划分成一个或多个计算单元`Compute Unit（CU）`；
   - CU可以进一步划分成一个或多个处理单元`Processing Unit（PE）`，最终的计算由PE来完成
   - OpenCL应用程序分成两部分：host代码和device kernel代码，其中Host运行host代码，并将kernel代码以命令的方式提交到OpenCL devices，由OpenCL device来运行kernel代码；

2. **执行模型**：Host如何利用OpenCL Device的计算资源完成高效的计算处理过程

   OpenCL的Execution Model由两个不同的执行单元定义：1）运行在OpenCL设备上的kernel；2）运行在Host上的Host program；其中，OpenCL使用Context代表kernel的执行环境：

   **Context包含以下资源**：

   ​	![img](https://img2020.cnblogs.com/blog/1771657/202107/1771657-20210731232529180-1750116346.png)

   * Devices：一个或多个OpenCL设备；

   * Kernel Objects：OpenCL Device的执行函数及相关的参数值，通常定义在cl文件中；

   * Program Objects：实现kernel的源代码和可执行程序，每个program可以包含多个kernel；

   * Memory Objects：Host和OpenCL设备可见的变量，kernel执行时对其进行操作；

   **NDRange**:

![img](https://img2020.cnblogs.com/blog/1771657/202107/1771657-20210731232539636-456540377.png)

   - kernel是Execution Model的核心，放置在设备上执行，当kernel执行前，需要创建一个索引空间NDRange（一维/二维/三维）；
   - 执行kernel实例的称为work-item，work-item组织成work-group，work-group组织成NDRange，最终将NDRange映射到OpenCL Device的计算单元上；

   有两种方式来找到work-item：

   1. 通过work-item的全局索引；
   2. 先查找到所在work-group的索引号，再根据局部索引号确定；

   以一维为例：

   ![img](https://img2020.cnblogs.com/blog/1771657/202107/1771657-20210731232549545-1521101489.png)

   - 上图中总共有四个work-group，每个work-group包含四个work-item，所以local_size的大小为4，而local_id都是从0开始重新计数；
   - global_size代表总体的大小，也就是16个work-item，而global_id则是从0开始计数；

   以二维为例：

   ![img](https://img2020.cnblogs.com/blog/1771657/202107/1771657-20210731232558270-1784351512.png)

   - 二维的计算方式与一维类似，也是结合global和local的size，可以得出global_id和local_id的大小，细节不表了；

3. **内存模型**：Host和OpenCL Device怎么来看待数据

   ![img](https://img2020.cnblogs.com/blog/1771657/202107/1771657-20210731232609409-1622803506.png)

   **OpenCL的内存模型中，包含以下几类类型的内存**：

   - Host memory：Host端的内存，只能由Host直接访问；
   - Global Memory：设备内存，可以由Host和OpenCL Device访问，允许Host的读写操作，也允许OpenCL Device中PE读写，Host负责该内存中Buffer的分配和释放；
   - Constant Global Memory：设备内存，允许Host进行读写操作，而设备只能进行读操作，用于传输常量数据；
   - Local Memory：单个CU中的本地内存，Host看不到该区域并无法对其操作，该区域允许内部的PE进行读写操作，也可以用于PE之间的共享，需要注意同步和并发问题；
   - Private Memory：PE的私有内存，Host与PE之间都无法看到该区域；

4. **编程模型**：

   ![img](https://img2020.cnblogs.com/blog/1771657/202107/1771657-20210731232617650-444622672.png)

   - 在编程模型中，有两部分代码需要编写：一部分是Host端，一部分是OpenCL Device端；
   - 编程过程中，核心是要维护一个Context，代表了整个Kernel执行的环境；
   - 从cl源代码中创建Program对象并编译，在运行时创建Kernel对象以及内存对象，设置好相关的参数和输入之后，就可以将Kernel送入到队列中执行，也就是Launch kernel的流程；
   - 最终等待运算结束，获取计算结果即可；

### 3.OpenCL的编程步骤

![img](https://upload-images.jianshu.io/upload_images/1835793-6a58f10d84736d52.png?imageMogr2/auto-orient/strip|imageView2/2/w/635/format/webp)

如上图所展示：

1. **Discover and initialize the patforms**

   调用两次==clGetPlatformIDS()==，第一次是获取可用的平台数量，第二次则是获取一个可用的平台

   ```c++
   	cl_int status;
   	cl_uint numPlatforms = 0;
   	cl_platform_id* platforms = NULL;
   	status = clGetPlatformIDs(0, NULL, &numPlatforms);
   	//
   	platforms = (cl_platform_id*)malloc(numPlatforms * sizeof(cl_platform_id));
   
   	status = clGetPlatformIDs(numPlatforms, platforms, NULL);
   	
   ```

   

2. **Discover and initialize the devices**

   调用两次clGetDeviceIDs函数，第一次获取可用的设备数量，第二次获取一个可用的设备。

   ```c
       cl_uint numDevices = 0;
   	cl_device_id* devices = NULL;
   	status = clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_ALL, 0, NULL, &numDevices);
   
   	devices = (cl_device_id*)malloc(numDevices * sizeof(cl_device_id));
   
   	status = clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_ALL, numDevices,devices, NULL);

3. **Create a context(调用clCreateContext函数**

   上下文context可能会管理多个设备device。

   ```c++
   	cl_context context = NULL;
   	context = clCreateContext(NULL, numDevices, devices, NULL, NULL, &status);
   ```

   

4. **Create a command queue(调用clCreateCommandQueue函数）**

   一个设备device对应一个command queue。上下文conetxt将命令发送到设备对应的command queue，设备就可以执行命令队列里的命令。

   ```c++
   	cl_command_queue cmdQueue;
   	cmdQueue = clCreateCommandQueue(context, devices[0], 0, &status);
   ```

   

5. **Create device buffers(调用clCreateBuffer函数**

   Buffer中保存的是数据对象，就是设备执行程序需要的数据保存在其中。
   Buffer由上下文conetxt创建，这样上下文管理的多个设备就会共享Buffer中的数据。

   ```c++
   	cl_mem bufferA;
   	cl_mem bufferB;
   	cl_mem bufferC;
   	bufferA = clCreateBuffer(context, CL_MEM_READ_ONLY, datasize, NULL, &status);
   	bufferB = clCreateBuffer(context, CL_MEM_READ_ONLY, datasize, NULL, &status);
   	bufferC = clCreateBuffer(context, CL_MEM_WRITE_ONLY, datasize, NULL, &status);
   ```

   

6. **Write/ Read host data to device buffers(调用clEnqueueWrite/Read Buffer函数**

   ```c++
   	buffer对象类似于c语言中的数组，由malloc()新建，数据元素在内存中是连续存储的。决定数据移动的准确时间是OpenCL运	行时。
       status = clEnqueueWriteBuffer(cmdQueue, bufferA, CL_FALSE, 0, datasize, A, 0, NULL, NULL);
   	status = clEnqueueWriteBuffer(cmdQueue, bufferB, CL_FALSE, 0, datasize, B, 0, NULL, NULL);
   ```

   

7. **Create and compile the program**

   创建程序对象，程序对象就代表你的程序源文件或者二进制代码数据。

   ```c++
   	cl_program program = clCreateProgramWithSource(context, 1, (const char**)&source_str,(const 	size_t*)source_size, &status);
   	//build  the program for the devices with clBuildProgram
   	status = clBuildProgram(program, numDevices, devices, NULL, NULL, NULL);
   ```

   

8. **Create the kernel(调用clCreateKernel函数**

    根据你的程序对象，生成kernel对象，表示设备程序的入口。

   ```c++
   	cl_kernel kernel = NULL;
   	kernel = clCreateKernel(program, "main", &status);
   ```

   

9. **Set the kernel arguments(调用clSetKernelArg函数）**

   ```c++
   	status = clSetKernelArg(kernel, 0, sizeof(cl_mem), &bufferA);
   	status = clSetKernelArg(kernel, 1, sizeof(cl_mem), &bufferB);
   	status = clSetKernelArg(kernel, 2, sizeof(cl_mem), &bufferC);
   ```

   

10. **Configure the work-item structure(设置worksize）**

     配置work-item的组织形式（维数，group组成等）

    ```c++
    	//step10: configure the work-item stru
    	size_t globalWorkSize[1];
    	globalWorkSize[0] = elements;
    ```

    

11. **Enqueue the kernel for execution(调用clEnqueueNDRangeKernel函数**

    将kernel对象，以及 work-item参数放入命令队列中进行执行。

    ```c++
    	//step11: Enqueue the kernel for execution
    	status = clEnqueueNDRangeKernel(cmdQueue, kernel, 1, NULL, globalWorkSize, NULL, 0, NULL, 		NULL);
    
    ```

    

12. **Read the output buffer back to the host(调用clEnqueueReadBuffer函数）**

    ```c++
    	//step12: Read the output buffer back to the host
    	clEnqueueReadBuffer(cmdQueue, bufferC, CL_TRUE, 0, datasize, C, 0, NULL, NULL);
    ```

    

13. **Release OpenCL resources（至此结束整个运行过程）**

    ```c++
    	//step13； realease OpenCL resources
    	clReleaseKernel(kernel);
    	clReleaseProgram(program);
    	clReleaseCommandQueue(cmdQueue);
    	clReleaseMemObject(bufferA);
    	clReleaseMemObject(bufferB);
    	clReleaseMemObject(bufferC);
    	clReleaseContext(context);
    
    	//free host resources
    	free(A);
    	free(B);
    	free(C);
    	free(platforms);
    	free(devices);
    ```

    

### 4.环境搭建

#### 1.安装OpenCL包

*  直接上github上下载按照[https://github.com/GPUOpen-LibrariesAndSDKs/OCL-SDK/releases]()

![在这里插入图片描述](https://img-blog.csdnimg.cn/20191016170329444.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2h1YXl1bmh1YWx1bw==,size_16,color_FFFFFF,t_70)

*  运行.exe文件后，你会获得==openCL==包, 在里面右个OCL_SDK_Light包，点进去里面的==include==包里面有==openCL==的头文件

![image-20221119163626271](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221119163626271.png)

![](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221119163925016.png)

**下面简单介绍一下这些文件里面的内容有什么：**

1.  **==cl.h==**头文件: 里面主要就是放各种各样的==声明和宏==，还有各种各样定义的==错误编码==（**0是成功，-1~-70全是错误**）。

   有==OpecnCL的版本的宏==，==平台信息和设备信息的宏==等，基本对应上文OpenCL编程步骤所需要的所有东西的宏。例外，其中也有各种各样的==API==: 1. 平台的API，2. 设备的API，3. 上下文的API等

   ![image-20221119170006793](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221119170006793.png)

![image-20221119171047571](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221119171047571.png)

![image-20221119170933924](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221119170933924.png)

2. ==**cl.hpp**==文件：该文件其实是C++对以前的==.h文件和.cpp文件==的一种结合，在该文件里，主要就是放了C++对不同版本的OpenCL绑定的，不同版本之间的一些区别，还有一些API都被封装在不同的命名空间里，还有C++中的STL里面的一些内容，如**vector**,**string**，**迭代器等**。

   ![image-20221120091133136](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221120091133136.png)

   ![image-20221120091148809](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221120091148809.png)

3. **cl_d3d10.h和cl_d3d11.h**:启用D3D共享时，很多OpenCL函数会有所扩展，主要就是放这些扩展函数的值和参数

   ![image-20221120092134874](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221120092134874.png)

4. **cl_dx9_medial_sharing.h**:放扩展函数，允许应用程序将媒体表面用作 OpenCL 内存对象。允许在 OpenCL 和选定的适配器 API 之间高效共享数据（目前只有 DX9）。支持此扩展，则可以从媒体表面创建 OpenCL 图像对象，并且 OpenCL API 可用于执行读取和/或写入作为媒体表面的内存对象的内核。请注意，当且仅当从适配器创建了 OpenCL 上下文时，才能从适配器介质表面创建 OpenCL 内存对象。

   ![image-20221120092648038](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221120092648038.png)

5. **cl_ext.h文件**：包含OpenCL扩展，这些扩展没有外部（OpenGL、D3D）的·依赖。

6. **cl_gl.h文件**: 主要就是放OpenGL相关的一些东西

7. **cl_gl_ext.h文件**：主要就是放OpenGL的扩展的一些内容

8. **cl_platform.h文件**: 就是放有平台信息的各种各样的 **宏和typedef**

9. **opencl.h文件**: 该文件就==include了上面的四个文件，可用理解为OpenCL的万能头文件==。

    ![image-20221120094228718](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221120094228718.png)

####2. 在code Blocks上配置OpenCL环境

1. 创建一个新项目
2. 在项目建好后，点击**Project -> Bulid Options ->Linker settings,**点击**Add**,取添加下载好的OpenCL包，如下：注意，**如果你的电脑是32位选择X86，如果是64位选择X86_64**,把该目录下的opencl.lib链接文件添加进来

![image-20221119173137655](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221119173137655.png)

3. 然后再添加头文件所在的目录，点击Search directories,然后如下添加即可

![image-20221119173628427](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221119173628427.png)

3. 运行第一个OpenCL程序

   ```c++
   #include <stdio.h>
   #include <stdlib.h>
   #define CL_TARGET_OPENCL_VERSION 110
   #include <CL/cl.h>//引入OpenCL头文件
   #include <time.h>
   //对于这个内核函数，因为globalSize为3，所以get_global_id(0)的取值范围为0~2
   //主机程序中for_loop三次，第一次中bb = 0,然后进入内核函数，也就会发生
   // c[0] = 0,c[1] = 1,c[2] = 2
   // 第二次for_loop中，bb=3，发生
   // c[3+0] = 3+0,c[3+1] = 3+1,c[3+2] = 3+2
   // 第三次for_loop中，bb = 6,发生
   // c[6] = 6,c[6+1] = 6+1,c[7+1] = 7+1,结束
   #define TYPE long long // ** Here 64bits = long in ocl
   // OpenCL kernel. Each work item takes care of one element of c
   const char *kernelSource =                                       "\n" \
   "#define TYPE long                    \n" \
   "__kernel void cat(  const __global TYPE *a,                       \n" \
   "                       __global TYPE *c,                       \n" \
   "                       const TYPE bb)                    \n" \
   "{                                                               \n" \
   "    //Get our global thread ID，返回在所请求的维度上当前work_item在全局空间中的索引 \n" \
   "    size_t id = get_global_id(0),id2;// id:0~2                                  \n" \
   "    id2=id+bb;                                                        \n" \
   "    //Make sure we do not go out of bounds                      \n" \
   "        c[id2] = id2;/*a[id];*/                                  \n" \
   "}                                                               \n" \
                                                                   "\n" ;
   //"#pragma OPENCL EXTENSION cl_khr_fp64 : enable                    \n" \
   
   
   int main( int argc, char* argv[] )
   {
       // Length of vectors
       //  n 为数组长度
       unsigned int n = 3;
   
       // Host input vectors
       //声明两个主机程序的输入数组
       TYPE *h_a = NULL;
       TYPE *h_b = NULL;
       // Host output vector
       //声明一个主机程序的输出数组
       TYPE *h_c  = NULL;
       TYPE bb = 1;
   
       // Device input buffers
       // 声明设备的两个输入buffers
       cl_mem d_a;
       cl_mem d_b;
       // Device output buffer
       // 声明设备的两个输出buffers
       cl_mem d_c,d_e;
   
       cl_platform_id cpPlatform[3];        // OpenCL platform,声明一个平台数组，存放3个可用的平台信息
       cl_device_id device_id;           // device ID，声明一个存放设备信息的变量
       cl_context context;               // context，声明一个存放上下文的变量
       cl_command_queue queue;           // command queue，声明一个命令队列的变量
       cl_program program;               // program，声明一个主机程序
       cl_kernel kernel,kernel2;                 // kernel，声明两个kernel
   
       // Size, in bytes, of each vector
       // 确定每个向量所需要的字节数
       size_t bytes = n*sizeof(TYPE);
   
       // Allocate memory for each vector on host
       // 在主机中为每个向量分配内存
       h_a = (TYPE*)malloc(bytes);
       //h_b = (TYPE*)malloc(bytes);
       h_c = (TYPE*)malloc(3*bytes);
   
       // Initialize vectors on host
       // 初始化主机的数组
       int i;
       for( i = 0; i < n; i++ )
       {
           h_a[i] = 0;
           //h_b[i] = 1;
       }
       for( i = 0; i < 3*n; i++ )
       {
           h_c[i] = 0;
           //h_b[i] = 1;
       }
       //配置work-item的组织形式（维数，group组成等）
       //globalSize是对应维度上全局工作项的数量，在此次为一维，即全局计算任务总数，work-item总数
       size_t globalSize, localSize;
       cl_int err;
   
       // Number of work items in each local work group
       //localSize = 64;// 当前维度上work-group的大小，在此处即是当前work-item内所含work-item的数量
   
       // Number of total work items - localSize must be devisor
       globalSize = n;//ceil(n/(double)localSize)*localSize;
   
       // Bind to platform
       //获取一个可用的平台
       err = clGetPlatformIDs(3, cpPlatform, NULL);
       // Get ID for the device, change the platform number to get the correct gpu driver.
       //获取一个可用的设备，即GPU,
       err = clGetDeviceIDs(cpPlatform[0], CL_DEVICE_TYPE_GPU, 1, &device_id, NULL);
   
       // Create a context
       // 创建上下文，管理设备，
       context = clCreateContext(0, 1, &device_id, NULL, NULL, &err);
   
       // Create a command queue
       // 创建一个命令队列，一个设备对应一个命令队列，上下文将命令发送到设备对应的命令队列，设备就可以执行命令队列里的     命令
       queue = clCreateCommandQueue(context, device_id, 0, &err);
   
       // Create the compute program from the source buffer
        // 创建程序对象，程序对象就代表你的程序源文件或二进制数据
       program = clCreateProgramWithSource(context, 1,
                               (const char **) & kernelSource, NULL, &err);
   
       // Build the program executable
      	// 编译这个可执行程序
       clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
   
       // Create the compute kernel in the program we wish to run
       // 根据我们的程序对象，创建一个我们希望运行的kernel对象，表示设备程序的入口
       kernel = clCreateKernel(program, "cat", &err);
      // kernel2 = clCreateKernel(program, "vecAdd", &err);
   
       // Create the input and output arrays in device memory for our calculation
       // 在设备的内存中创建我们用于输入输出计算的数组
       d_a = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes, NULL, NULL);
       //d_b = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes, NULL, NULL);
       d_c = clCreateBuffer(context, CL_MEM_READ_WRITE, 3*bytes, NULL, NULL);
       //d_e = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes, NULL, NULL);
   		//读取主机程序的数据，并写到设备的buffer中，buffer其实类似于c语言中的数组
       	// 将数组c写入设备程序的buffer中
           err = clEnqueueWriteBuffer(queue, d_c, CL_TRUE, 0,
                                      3*bytes, h_c, 0, NULL, NULL);
       // 将数组a写入设备程序的buffer中，
       err |= clEnqueueWriteBuffer(queue, d_a, CL_TRUE, 0,
                                      bytes, h_a, 0, NULL, NULL);
   
   for(int i = 0;i<3;i++){
               // Write our data set into the input array in device memory
   			// 将我们的数据集写入设备内存中的输入数组
   
                                      bb = i*n;
       // Set the arguments to our compute kernel
       // 为我们的kernel函数设置实参
       err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &d_a);
       err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &d_c);
       err |= clSetKernelArg(kernel, 2, sizeof(TYPE), &bb);
       // Execute the kernel over the entire range of the data set
       // 将kernel对象，和work-item的参数放入命令队列中执行
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
       
       // 从设备中读取计算结果,结果放在h_c数组
       clEnqueueReadBuffer(queue, d_c, CL_TRUE, 0,
                                   3*bytes, h_c, 0, NULL, NULL );
   
       //Sum up vector c and print result divided by n, this should equal 1 within error
   
       double sum = 0;
       for(i=0; i<3*n; i++)
           sum += h_c[i];
       printf("final result: %f\n", sum);
   
       // release OpenCL resources
       // 释放OpenCL 所需要的所有资源
       // 释放内存对象d_a
       clReleaseMemObject(d_a);
       //clReleaseMemObject(d_b);
       // 释放内存对象d_c
       clReleaseMemObject(d_c);
       // 释放主机程序对象
       clReleaseProgram(program);
       // 释放kernel对象
       clReleaseKernel(kernel);
       // 释放命令队列
       clReleaseCommandQueue(queue);
       // 释放上下文
       clReleaseContext(context);
   
       //release host memory
       // 释放主机的内存
       // free数组h_a
       free(h_a);
       //free(h_b);
       // free数组h_c
       free(h_c);
       h_a = NULL;
       //h_b = NULL;
       h_c = NULL;
       return 0;
   }
   
   ```
   
   运行该程序，获得如下结果，便说明你的环境搭配完毕，**注意**：一定要**return** **0**, 且结果为***36**，才说明结果正确
   
   ![image-20221120083846677](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221120083846677.png)

```c++
// “循环三次可能会造成什么变化？”，这个地方从我理解的话，貌似就只有对 h_c 数组的赋值这个作用，因为这里的
// NDRange 是一维的，而 globalSize = n = 3, 所以这里全局的总 work-item 也就是 3，所以每次循环中
// kernel 只能同时执行三个 work-item, 索引为0，1，2，如果没有三次的循环的话，那么int h_c[9]就不能赋值完
// 主机程序中for_loop三次，第一次中bb = 0,然后进入内核函数，也就会发生
// c[0] = 0,c[1] = 1,c[2] = 2
// 第二次for_loop中，bb=3，发生
// c[3+0] = 3+0,c[3+1] = 3+1,c[3+2] = 3+2
// 第三次for_loop中，bb = 6,发生
// c[6] = 6,c[6+1] = 6+1,c[7+1] = 7+1, 结束
// 如果不要for循环，一次实现同样的赋值的话，可用把 globalSize = 3 * n = 9, 这样就有 9 个全局的总 work-item
// kernel 也就一次性可以执行这 9 个work-item, 也能实现相同的对 h_c 数组的赋值结果。
```

## 第三章

### 1. RSA加密算法

1. RSA加密算法属于计算机中常用的加密技术中的==非对称加密算法==。加密和解密过程使用不同的密钥，分为公钥、私钥。公钥可用公开，而私钥不可以公开。算法的加密的地方也正是在私钥上。

2. RSA算法加密流程

   1. 随机选取两个不等的大的==素数==，==p==和==q== 

   2. 素数相乘：N = p * q

   3. 欧拉函数：对于素数，欧拉函数即为**它自身 - 1**，T  = (p - 1) * (q - 1)

   4. 选取公钥==E==，1 < ==E== < T, 且不是 **T** 的因子

      加密信息，使用 pk= (E，N)加密，对于明文 x，则密文 y = x^E % N 

   5. 计算私钥==D==，(D * E) % T = 1,

      解密信息，使用sk = (D，N)，对于密文 y，则明文 x = y^D % N;
   
      ```c++
      // 如对于 “124”字符的加密
      // step 1
      // 选取 p = 3, q = 11
      // step 2
      // N = 3 * 11 = 33
      // step 3
      // T = (3 - 1) * (11 - 1) = 20
      // step 4
      // 选取公钥 E = 3,则pk = (3,33);
      // 则 1 加密 1^3 % 33 = 1, 2 加密 2^3 % 33 = 8, 4加密 4^3 % 33 = 31, 得密文 1 8 31
      // step 5
      // 计算得 D = 7,则 sk = (7,33).解密 1 ，1^7 % 33 = 1, 解密 8，8^7 % 33 = 2，
      // 解密 31，31^7%33 = 4，则明文为 1 2 4
      ```
   
      

### 2. github项目文件说明

![image-20221127173212063](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221127173212063.png)

1. **CasRSA_CL.c文件**：就是存放主机程序的代码
2. **LICENSE文件**：关于协议和版权等的说明，
3. **README.md文件**：是用MarkDown编写的.md文件，内容主要是对整个项目的简介,运行环境和注意事项的说明。
4. **exeample_conf.txt文件**：配置文件的样例
5. **kernel_rsa.cl文件**：kernel程序的代码

### 3.对main函数的注释说明

```c++
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
    cl_platform_id platform;//存放平台信息
    cl_context context;//存放上下文信息
    cl_command_queue queue;//存放命令队列信息
    cl_device_id device;//存放设备信息
    //获取一个可用的平台
    err = clGetPlatformIDs(1, &platform, NULL);
    if (err != CL_SUCCESS) { printf("platformid"); }
    //获取一个可用的设备
    err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
    if (err != CL_SUCCESS) { printf("getdeivceid %i", err); }
    //获取设备的最多计算单元
    cl_uint numberOfCores;
    clGetDeviceInfo(device, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(numberOfCores), &numberOfCores, NULL);
    printf("\nThis GPU supports %i compute units", numberOfCores); //Utilize the maximum number of compute units
    //获取设备每个计算单元的线程数
    cl_uint maxThreads;
    clGetDeviceInfo(device, CL_KERNEL_WORK_GROUP_SIZE, sizeof(maxThreads), &maxThreads, NULL);
    printf("\nRunning with %i threads per compute units", maxThreads); //Utilize the maximum number of threads/cu
    //创建上下文
    context = clCreateContext(0, 1, &device, NULL, NULL, &err);
    if (err != CL_SUCCESS) { printf("context"); }
    //创建命令队列
    queue = clCreateCommandQueue(context, device, 0, &err);
    if (err != CL_SUCCESS) { printf("queue"); }
    //创建主机程序
    cl_program program = clCreateProgramWithSource(context, 1, &append_str,&length, &err); //Compile program with expanded key included in the source
    if (err != CL_SUCCESS) { printf("createprogram"); }
    //编译主机程序
    printf("\nBuilding CL Kernel...");
    err = clBuildProgram(program, 1, &device, "-I ./ -cl-std=CL1.2", NULL, NULL); //The fourth parameter is specific to OpenCL 2.0
    //如果编译主机程序失败
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
    cl_p = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(bignum), &p, &status);
    if (status != CL_SUCCESS || cl_p == NULL) { printf("\nCreate p: %i", status); }

    cl_q = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(bignum), &q, &status);
    if (status != CL_SUCCESS || cl_q == NULL) { printf("\nCreate q: %i", status); }

    cl_M = clCreateBuffer(context, CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(bignum), &M, &status);
    if (status != CL_SUCCESS || cl_M == NULL) { printf("\nCreate M: %i", status); }

    cl_result = clCreateBuffer(context, CL_MEM_WRITE_ONLY | CL_MEM_COPY_HOST_PTR, sizeof(bignum), &result, &status);
    if (status != CL_SUCCESS || cl_result == NULL) { printf("\nCreate result: %i", status); }
    //创建kernel
    const char* s = "h";
    cl_kernel rsa_kernel = clCreateKernel(program,s, &status);
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

```

```c++
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

	/* Build Kernel Program */
	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

	/* Create OpenCL Kernel */
	kernel = clCreateKernel(program, "rsa", &ret);
```

## 第四章

### 一.ASE加密算法

1. AES（高级加密标准）是一种对称密钥加密算法，也是一种分组加密算法，值得注意的是==加密和解密使用相同的密钥==，它可以使用128（AES128）、192（AES192)或256（AES256)位密钥对数据进行加密和解密。

2. 算法流程

   - 用户将明文输入加密系统，并且选择一个密钥。

   - 系统将明文按照一定的方式进行分组，比如每128位分一组。(如果明文位数拆分下来不足128bit的话，则会用下面几种方法进行填充，NoPadding, PKCS#5，PKCS#7，ISO10126，ANSI x9.23 和 ZerosPadding)

     输入的明文会被划分成4阶矩阵，如：

     ![image-20221212164714173](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221212164714173.png)

     ==需要注意的是，矩阵是列来排列==，得到得==矩阵要和子密钥矩阵==进行初始变化得到状态矩阵

   - 每一组明文经过一个特殊的函数，转化成密文。这个函数的计算过程包括了一系列的S盒代换（S-box）、行移位（Shift row）、列混淆（Mix column）和轮密钥加（RK）等操作。

     ```c++
     /*在加密过程中，会执行一个轮函数，如果密钥是128bit的话，则加密轮数为10次，192bit则 12 轮，256bit则14轮
     对于128bit的分析，其中前面9轮，会重复做
     	1.字节代换（S盒代换）
     	2.行位移
     	3.列混合
     	4.轮密钥加（RK）
     但是在最后一轮的时候，会不进行 列混合 操作，只进行1、2、4的操作
     */
     ```

     - **在字节代换中**，会用到 S-BOX盒，通常都是固定不变的。而后我们将上面过程得到得的==状态矩阵==，把其中的内容当成是 S-BOX盒的索引，从中获取数值，如矩阵的（00）可以看成（0，0），去代换得==63==，得到一个新的状态矩阵。

       ![image-20221212165316681](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221212165316681.png)

     - **行位移**，对于更新后的状态矩阵，第一行不动，第二行左移1位，第三行左移2位，第三行左移3位，得到新的状态矩阵。如：

       ![image-20221212170106574](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221212170106574.png)

     - **列混合**，则是通过矩阵相乘来实现，将更新后的状态矩阵与固定的矩阵相乘得到一个新的状态矩阵。**==值得注意的是：==，这里的矩阵相乘与线性代数中的矩阵相乘不太一样，线性代数里的加法在这里变成了==异或==，而乘法则变成了对于一个8位的二进制数来说，使用域上的乘法乘以(00000010)等价于左移1位(低位补0)后，再根据情况同(00011011)进行异或运算，设S1 = (a7 a6 a5 a4 a3 a2 a1 a0)，刚0x02 * S1如下图所示：**

       ![col3](https://imgconvert.csdnimg.cn/aHR0cDovL2ltZy5ibG9nLmNzZG4ubmV0LzIwMTcwMjE5MjA0ODIyNTE3?x-oss-process=image/format,png)

     - **轮密钥加**，将状态矩阵与==子密钥矩阵进行====异或==计算，得到一个一轮中的结果矩阵。

       1. **子密钥矩阵**怎么来的呢？

          1. 将初始密钥按==列==进行排列成一个4阶矩阵，矩阵的每一列的4个字节组成一个字，矩阵4列的4个字依次命名为W[0]、W[1]、W[2]和W[3]，它们构成一个以字为单位的数组W。

          2. 例如，设密钥K为"abcdefghijklmnop",则K0 = ‘a’,K1 = ‘b’, K2 = ‘c’,K3 = ‘d’,W[0] = “abcd”。
             接着，对W数组扩充40个新列，构成总共44列的扩展密钥数组。新列以如下的递归方式产生：
             1.如果i不是4的倍数，那么第i列由如下等式确定：
             ==W[i]=W[i-4]⨁W[i-1]==
             2.如果i是4的倍数，那么第i列由如下等式确定：
             ==W[i]=W[i-4]⨁T(W[i-1])==
             其中，T是一个有点复杂的函数。
             函数T由3部分组成：字循环、字节代换和轮常量异或，这3部分的作用分别如下。
             a.字循环：将1个字中的4个字节循环左移1个字节。即将输入字[b0, b1, b2, b3]变换成[b1,b2,b3,b0]。
             b.字节代换：对字循环的结果使用S盒进行字节代换。
             c.轮常量异或：将前两步的结果同轮常量Rcon[j]进行异或，其中j表示轮数。

             轮常量Rcon[j]是一个字，其值见下表。

             ![image-20221212171942886](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221212171942886.png)

   - 密文经过一系列的操作之后，就完成了加密。

   - 用户可以将加密后的密文发送给接收方，接收方再用相同的密钥对密文进行解密，得到原始的明文。

### 二.DES/A-DES加密算法

#### 算法流程

- DES算法为密码体制中的对称密码体制，属于对称加密算法中的分组加密算法。明文按64位进行分组，**密钥长64bit，但是只有56bit参与计算，其余八bit为校验位（分别为第8，16，24，32，48，56，64位），==使得每个密钥都有奇数个1==**。当n个64bit明文数据经过DES加密处理后，所得到的n个64bit密文数据块串在一起就是密文。

- **DES算法流程**：大致流程就是将64位的明文进行初始置换然后将置换后的明文进行16次的f函数迭代运算，最后再将得到的64位密文进行逆初始置换，这样子便得到了经过des算法加密后的64位密文。如下图

  ![img](https://img-blog.csdnimg.cn/20210122181135836.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxMjQ4OTAyMTEwMw==,size_16,color_FFFFFF,t_70)

其中最关键的核心就是==16轮迭代运算==的过程，==分别包括 IP分割、尔后进行**f()函数的操作，分别包括：**E扩展(32bit --> 48bit)、异或(48bit --> 48bit)、S盒(48bit --> 32bit)、P置换(32bit --> 32bit)==。==最后再异或==。

**接下来详细讲解各过程：**

1. **初始置换：**按照一定的规则，将原来的64位二进制重新排序。按照如下的==初始置换表==将顺序打乱.

   ![image-20221215001234939](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221215001234939.png)

   该图的意思为，原本的第1位要变成第58位，第2位变成50位……直到变完，即完成了初始置换。

2. **16轮迭代运算：**

   1. 分割：首先将64bit的IP分割成左右L0(32bit)和R0(32bit)。如上图，将**R0**直接赋值给**L1**，然后对**R0和子密钥K1进行f()函数操作**。

   2. f()函数的操作：

      1. **E扩展**：将R0的32位数据输入扩展为48位输出。扩展可由如下图表示出来：

         ![image-20221215002127791](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221215002127791.png)

         **注意：**中间==白色==部分的为最初的真实的32位数据，而两边==灰色==的则为所扩展的数据，其中**可以灰色的32意为此处扩展的内容为真实数据的第32位的内容。其余也是这样理解。可把真实的32数据分割成8个4位的，然后分别在每个4位数据的开头和结尾分别扩展1位来理解。**

      2. **异或**：将得到的48Bit数据与48位的子密钥进行异或运算。

      3. **S盒压缩处理**：将异或得到的结果与==8个S盒压缩处理后得到32位数据==。分成8块，每块6位，每块压缩成4位。压缩过程如下：

         将6位数据分别分成两部分来进行操作。把第一位和第6位取出来合并一起，以==十进制==读取获得==行数==，将余下的中间4位按照同样的方法，获得==列数==。如下图所示：

         ![image-20221215003754388](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221215003754388.png)

         将得到的==**行数**3**和列数**15==，到**S盒压缩表中查找获取相应的值，该表如下：**

         ![image-20221215004006990](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221215004006990.png)

         **注意**：分成8块，每块6位，第一块的内容要在==**S1**==**盒**中找，如上得13，再将结果化为二进制，即得到4位的数据1101。如图：

         ![image-20221215004413580](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221215004413580.png)

      4. **P盒置换：S盒****所得到的结果再经过**P盒**置换。至此，一次轮函数操作完毕。P盒置换也就是按照**==P盒置换表==**对**S盒**中的32位数据进行查找，即可。

         ![image-20221215004918894](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221215004918894.png)

   3. 异或：将**f(R0,K1)^L0的结果赋值给R1**

      由**L0,R0得R1，R0得L1**……然后不断循环重复，最后得**R16和L16**，再进行拼接回来成64bit,再进行逆初始置换。

3. **逆初始置换：**将获取的64bit的数据，再经过一定的顺序重新排列，逆初始置换表如下：

   ![image-20221215001731128](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221215001731128.png)

   该图的意思和操作同初始置换。

   将得到的n个64bit数据串合起来即得到了加密的密文。

#### 补充内容：

最后再补充一下子密钥生成的过程。

**密钥生成：**密钥为64位，除去8位校验证，剩余56位参与计算。同时，按照交换规则，生成16个48位的轮密钥。大致流程如下：

![image-20221215005811491](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221215005811491.png)

1. **PC1置换**：将密钥的第8、16、24……64位去掉，然后将剩下的56位按照如下的PC-1图进行置换

   ![image-20221215010332165](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221215010332165.png)

   意为，第1位置换成第57位，第2位置换为49位……最后得到新的一个56位数据。

2. **分割**：将56位数据分为Ci 28位 和 Di 28  位，然后再分别对它们进行循环左移，左移次数由**==移位次数表可得：==**。

![image-20221215010728185](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221215010728185.png)

​                  C1D1可由C0D0循环左移1次然后拼接得到，同理C2D2可由C1D1循环左移1位得到……

3. **PC2置换：**将上述得到左移得到的结果再利用**PC-2置换表进行PC2置换**，就可得到==子密钥K1,k2……k16==。一轮迭代得一轮的子密钥。

   ![image-20221215011432172](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221215011432172.png)



以上就得到了DES加密算法的密文。



### 三.SHA加密算法

#### 一.概念

(Secure Hash Algorithm)安全散列算法是一个密码散列函数家族，是FIPS所认证的安全散列算法。能计算出一个==数字信息对应到的，长度固定的字符串（又称消息摘要）的算法。当若输入的消息不同，它们对应到不同字符串的几率很高。==

#### 二.SHA-1加密算法

1. 概念：SHA1算法将输入流（0<L<2^64）按照==每块512Bit(64byte)==进行分块并产生==160Bit(20byte)的消息摘要，通常呈现形式为40个十六进制数==。

2. 加密算法流程：对于每一个512Bit块的处理非常相似。对于第一个512bit的块，会与==给定的缓冲区链接变量，进行80轮的运算操作，得到一个160bit的结果，然后该结果再与下一个512Bit的块进行相同操作，再得到一个160Bit的结果……最后得出的160的结果即为加密完成后的消息摘要。==

   1. **补位**： 因为SHA1算法要将输入明文M分为n个512bit的块来处理，当M不能满足要求时，则需要进行补位处理。**怎么补？**==第一位补1，其余位补足够的0，直到满足长度L%512=448==,剩余的512-448 = 64bit记录消息的长度。（因为记录消息的长度为64bit，所以消息的长度不能超过2^64）

      ![image-20221216164214187](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221216164214187.png)

   2. **每一个512bit的运算：**首先将512bit的块分成16份32bit，可用M[0],M[1]……M[15]记录。而后将16份扩充成80份，可用W[0],W[1]……W[79]记录。扩充的规则如下：

      ![](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221216170521590.png)

      即前面的16个直接没有任何变化，W[16]……W[79]可以按照上述规则来操作，其中==ROTL<sup>1</sup>，表示向左移1位==。

   3. **计算消息摘要**：必须使用进行了补位和补长度后的消息来计算消息摘要。计算需要两个缓冲区，每个都由5个32位的字组成，还需要一个80个32位字的缓冲区（即上述的W数组)。第一个5个字的缓冲区用a,b,c,d,e来标识，第二个5个字的缓冲区用H0，H1，H2，H3，H4来标识。其中H0……H4的初始值如下：
   
      ![image-20221216172420402](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221216172420402.png)
   
      然后初始化第一个缓冲区的内容，直接将第二个缓冲区的初始值直接赋值给第一个缓冲区。a = H0……。而后对==每80轮进行如下运算==：**注意：**下面图片中关于==T的加法运算是模运算，即结果要对2^32取余==
   
      ![](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221216173112310.png)
   
      其中ft()函数和Kt的结果如下：
   
      ![image-20221216173711512](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221216173711512.png)
      
      ![image-20221216173243314](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221216173243314.png)
      
      经过80轮运算之后，再经过如下计算，即可获得第一个512bit块的消息摘要（即重新赋值后的H0,H1,H2,H3,H4）。如果还有多个512bit块，那么新的H0……H4便作为新的缓冲区内容再进行如上计算。
      
      ![image-20221216174021677](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221216174021677.png)

#### 三.SHA-256加密算法

1. 概念：SHA-256算法属于SHA-2族。是SHA-1的后继者。相对于SHA-1，它有着更高位的输出哈希值，破解难度更大，能够提高更高的安全性。

2. 加密流程：大致上和SHA-1算法相似。下面只介绍于SHA-1不同的部分。首先它的消息摘要变成了==256bit，即32个字节，同时每块的循环次数也不再是80轮，而是变成了64轮==。

   1. **补位**：同SHA-1.但是这里要进行一下消息区块处理：从一个固定的初始哈希H(0)开始，进行以下序列的计算：

      ![image-20221216184157844](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221216184157844.png)

      其中C是SHA256的压缩函数，+是mod 232加法，即将两个数字加在一起，如果对232取余, H(N)是消息区块的哈希值.

   2. **每一个512bit块的运算**：前面同SHA-1，但是这里是扩充成==64份32bit==，前16个同理直接赋值，但后面W[16]……W[63]则借由如下规则计算：

   3. ![image-20221216181925119](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221216181925119.png)

      其中关于各函数的具体操作如下图所示：

      ![image-20221216182043381](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221216182043381.png)

      

   4. **计算消息摘要：**计算需要两个缓冲区，每个都由==8==个32位的字组成，还需要一个64个32位字的缓冲区（即上述的W数组)。第一个5个字的缓冲区用a,b,c,d,e,f,g,h来标识，第二个==八个==字的缓冲区用H0，H1，H2……H8来标识。其中H1……H8的初始值如下：

      ![image-20221216182912966](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221216182912966.png)

      

其余如SHA-1，但是随后==进行64次迭代如下运算==;

![image-20221216183140646](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221216183140646.png)

**最后同SHA-1的计算一样，便可得到32字节**的消息摘要。加密完毕。

```c++
//SHA-1主函数注释
#include "sha1.h"

int main()
{
	//sha1加密后的消息摘要为20个字节160bit，result数组长度为41，足够放结果
	char result[41];
	//sha1_init为对sha1进行初始化，传递2048给kpc
	sha1_init(2048);
	//输出数据"1"的加密后的消息摘要：356a192b7913b04c54574d18c28d46e6395428ab
	sha1_crypt((char*)"1", result);
	printf("%s\n", result);
	//输出数据"12"的加密后的结果：7b52009b64fd0a2a49e6d8a939753077792b0554
	sha1_crypt((char*)"12", result);
	printf("%s\n", result);
	//输出数据"123"加密后的结果：40bd001563085fc35165329ea1ff5c5ecbdbbeef
	sha1_crypt((char*)"123", result);
	printf("%s\n", result);
	//输出数据"1234567890123456789012345678901234567890123456789012345678901234567890"加密后的结果
	//：610e973d05145fd4c3e6c97ff349907fdc8ec4b7
	sha1_crypt((char*)"1234567890123456789012345678901234567890123456789012345678901234567890", result);
	printf("%s\n", result);
}
```

```c++
//SHA-256主函数注释

int main()
{
	//SHA-256加密的结果消息摘要为32字节256bit,结果数组为65，足够放结果
	char result[65];
	//对SHA256进行初始化，并传递2048给kpc
	sha256_init(2048);
	//输出“1”sha256加密后的消息摘要：6b86b273ff34fce19d6b804eff5a3f5747ada4eaa22f1d49c01e52ddb7875b4b
	crypt_and_print((char*)"1");
	//输出"12"sha256加密后的消息摘要:6b51d431df5d7f141cbececcf79edf3dd861c3b4069f0b11661a3eefacbba918
	crypt_and_print((char*)"12");
	//输出"123"sha256加密后的消息摘要:a665a45920422f9d417e4867efdc4fb8a04a1f3fff1fa07e998e86f7f7a27ae3
	crypt_and_print((char*)"123");
	//输出"123"sha256加密后的消息摘要:4d27a733bfffd740e782bdeb0e617de620e6836826b77445dbbdeda610292bdf
	crypt_and_print((char*)"1234567890123456789012345678901234567890123456789012345678901234567890");
}
```

### 四.国密SM2加密算法

#### 一.国密SM2概念：

SM2是国家密码管理局与于2010年12月17日发布的椭圆曲线公钥密码算法。是一种比RSA算法更先进安全的算法。再我国通常用来替代RSA算法。SM2是ECC算法的一种，基于椭圆曲线离散对数问题，计算复杂度是指数级，求解难度较大，同等安全程度要求下，椭圆曲线密码较其他公钥秒速昂发所需密钥长度小很多。

#### 二.加密算法流程：

#####1.大致加密流程如下图所示：

![image-20221219161105883](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221219161105883.png)



##### 2.SM2公私钥

算法是基于数学的，SM2定义椭圆曲线上的群运算加减乘，公私钥 ==Pb = DbP==，(Pb为公钥，Db为私钥，P为基点)生成如下：

假设我们选定的椭圆曲线如下：

![倍点运算](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9yYXcuZ2l0aHVidXNlcmNvbnRlbnQuY29tL211emlwaWFvL0dpdEh1YkltYWdlcy9tYXN0ZXIvZ21vYmpjL2dtb2JqYzAzLnBuZw)

1. 首选一条椭圆曲线，即固定 a、b 的值，假设选择的是上图所示曲线。

2. $$y^2 = x^3 + ax + b(4a^3 + 27b^2 != 0)$$

   ```c++
   //SM2椭圆曲线公式如下：
   y^2 = x^3 + ax + b(4a^3 + 27b^2 != 0)
        
   ```

3. 随机选择一个点 P 为基点，曲线做切线，经过 Q 点，切点 R1。

4. 基于 x 轴做 R1 的对称点 R，则 SM2 定义加法为 P + Q = R，这就是==**椭圆曲线加法**==。

5. 求 2 倍点，当 P = Q 时，即 P + P = R = 2P，则 R 是 P 的 2 倍点。

6. 求 3 倍点，3P = P + 2P = P + R，经过 P、R 做直线，交于椭圆曲线点 M1, 基于 x 轴对称点 M 则是 3 倍点，依次类推。

7. 求 d 倍点，假设我们同样次数为 d，运算倍点为 Q。

8. d 为私钥，Q 为公钥。所以私钥是一个大整数，公钥是一个点坐标。

##### 3.详细过程：



设需要发送的消息为比特串 M，klen 为 M 比特串的长度，加密步骤如下：

1. 用随机数发生器产生随机数 **k , 1<= k <=  n -1**

2. 计算椭圆曲线点 **C1 = [k]G = (x1，y1)**，并将 C1的数据类型转换为比特串

   1. **[K]G**：椭圆曲线上点 **G** 的 K 倍点，即[k]p = k 个p 相加，但是并不是一般意义上的代数运算，具体看上面==2.SM2公私钥==。

3. 计算椭圆曲线点 ==S = [h]Pb==，若 S 是无穷远点，则报错并退出

4. 计算椭圆曲线点 ==[k]Pb  = （x2，y2）==（Pb为公钥），并按照如下方将坐标 X2,y2的数据类型转换为比特串

5. 计算 ==t = KDF(x2 || y2，klen)==，KDF函数具体操作如下。若 t 为全 0 的比特串，则返回 步骤 1,  重新开始计算。

   - **KDF()是密钥派生函数**，作用是从一个共享的秘密比特串中派生出密钥数据。密钥派生函数KDF需要调用密码杂凑函数**Hv**()（输出长度为V比特的杂凑值）

   - **KDF(Z，klen)计算流程**：

     1. **输入**：比特串Z，整数klen(表示要获得的密钥数据的比特长度，要求该值小于2^32 - 1)

     2. **输出**：长度为klen的密钥数据比特串K

     3. **执行如下：**

        ![image-20221219170614322](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221219170614322.png)

6. 计算 ==C2  = M 异或 t==

7. 计算 ==C3 = Hash(x2 || M || y2)==，密码杂凑函数 Hash()用法如下:

   - **Hash(m)**：输入的参数 m 为 16进制的字符串，输出为 16 进制的的64位（256bit) 的字符串，具体过程如下图所示。

     [image-20221219173625980](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221219173625980.png)

1. 输出密文 ==C = C1 || C2 || C3==

   

### 五.Bcrypt加密

#### 一.概念：

Bcrypt是单向Hash加密算法，不可反向破解生成明文。bcrypt是由Niels Provos和David Mazières设计的密码哈希函数，它是==基于Blowfish密码==而来的，除了==加盐(salt)==来抵御彩虹表(rainbow table) 攻击之外，bcrypt的一个非常重要的特征就是==自适应性==，可以保证加密的速度在一个特定的范围内，即使计算机的运算能力非常高，可以通过增加迭代次数的方式，使得加密速度变慢，从而可以抵御暴力搜索攻击。

#### 二.加密流程：

由于**bcrypt**加密算法是基于**blowfish**加密算法。所以要说明bcrypt加密算法流程之前，我们先要了解一下**blowfish**加密算法的流程。在bcrypt的初始密钥设置中，salt 和 password 都被用来设置子密钥。然后经过一轮轮的标准Blowfish算法，通过交替使用salt 和 password作为key，每一轮都依赖上一轮子密钥的状态。相对于blowfish加密算法，在bcrypt加密中重置key的轮数是可以配置的，所以可以通过增加轮数来抵御暴力攻击。

##### 一. Blowfish加密：

1. **简介**：**BlowFish** 是一个对称加密的加密算法。每次加密数据为 **64位** （2个int)类型数据大小。八个字节。密钥采用==32-448==位，由一个16轮循环的Feistel结构进行加密的。大致流程看如下图所示：

   <img src="C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221223204743586.png" alt="image-20221223204743586" style="zoom:150%;" />

   先将原始的**64bit**的数据P分成左右两份L，R。然后先用左边的==L和Kr进行异或运算==，所得的结果再调用==F()函数==进行运算得到的结果再与右边的==R==进行异或操作，然后调换左右部分的位置，继续进行这样的操作，总共进行16轮就得到了最终的加密结果。

2. **计算关键变量Kr和函数F()**:        

   1. **密钥数组**：由上图易得，Kr 的范围是从**K1 到 K18** 。总共有18个密钥组成的数组。 每个密钥的长度是32位。密钥数组的初始化常用随机数。而获取一个足够随机的32bit的数，通常用==常数Π==的小数位，并将其转换为16进制来表示。如下

      ```c++
      // K1 = 0x76a301d3
      
      // K2 = 0xbc452aef
      
      // …
      
      // K18 = 0xd7acc4a5
      ```

      而blowfish的密钥长度是可变的，**32bits到448bits**，也就是1到14个32位的数字。我们可以用==Pi==来，那么则得到了14个可变长度的密钥。然后我们使用==K1和P1==进行异或操作，K2和P2进行异或操作，一直到K14和P14。因为P只有14个值，而K有18个值，所以接下来我们需要重复使用P的值，也就是==K15和P1==进行异或，K16和P2进行异或，直到K18和P4。

      将异或之后的值作为新的K数组的值。现在我们获得了一个新的K数组。

      **注意**：此时获取的K数组还不是最终的K数组。

   2. **S-BOX**:  S-box可以是固定的，也可以是动态的。比如，在DES中S-box就是静态的，而在Blowfish中S-box就是动态生成的。由上图可知，blowfish加密的==**F()函数**==需要四个S-BOX，函数的输入是32bits，首先将32bits分成4份，也就是4个8bits。S-box的作用就是将每8bits转换成为32bits，至于如何转换，可参考==DES加密算法的扩展过程==。其中四个S-BOX是固定的。其中F()函数的操作如下：

      ```c++
      1.先将S-Box0 和 S-BOx1的结果相加 % 2^32 得新的结果
      2.将新的结果与 S-BOX2的结果进行异或操作得新结果
      3.将新结果与S-BOX3的结果进行相加，最后得到32bits的结果，其中S-box的初始值也可以跟K数组一样，使用常量π的小数部分来初始化。
      ```

   3. **生成最终的K数组**：

      首先我们取一个全为0的64bits，然后K数组和S-box，应用blowfish算法，生成一个64bits。将这个64bits分成两部分，分别作为新的K1 和 K2。然后将这个64bits作为输入，再次调用blowfish算法，作为新的K3 和 K4。依次类推，最终生成所有K数组中的元素。4个S-box的数组也按照上面的流程来进行生成。从而得到最终的S-box。

##### 二.bcrypt hash结构

![image-20221223225527310](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221223225527310.png)

其中密文结构为：**$**为分割符，**2y**是bcrypt加密版本号，10是代价因子cost的值，这里是2的10次方，也就是1024轮。紧随其后的22位是**salt**盐值（用来混淆密码使用），最后的字符串就是加密的密文。

##### 三.Bcrypt加密

1. 简单来说，可以理解bcrypt加密就是对字符串进行**64次blowfish**加密得到的结果。在bcrypt的初始密钥设置中，**盐值salt**（用来混淆密码使用） 和 password（就是我们要加密的密码） 都被用来设置子密钥。然后经过一轮轮的标准Blowfish算法，通过交替使用salt 和 password作为key，每一轮都依赖上一轮子密钥的状态。
2. 加密流程：
   1. 在输入部分，cost 表示的是轮循的次数，这个我们可以自己指定，轮循次数多加密就慢。salt 是加密用盐，用来混淆密码使用。password 就是我们要加密的密码了。最后的输出是加密后的结果hash。有了3个输入，我们会调用EksBlowfishSetup函数（）去初始化**18个subkeys和4个1K大小的S-boxe**s，从而达到最终的P和S。然后使用P和S对字符串进行**64次blowfish**运算，最终得到结果。
   2. EksBlowfishSetup 函数接收上面我们的**3个参数**，返回最终的包含18个子key的P和4个1k大小的S-BOX。首先初始化，得到最初的P和S。然后调用ExpandKey函数（主要用来生成P和S），传入salt和password，生成第一轮的P和S。然后循环2的cost方次，轮流使用password和salt作为参数去生成P和S，最后返回。即加密完成。

### 六.国密SM9加密算法

#### 一.概念

**SM**9是基于双线性对的标识密码算法，与SM2类似，包含四个部分：总则，数字签名算法，密钥交换协议以及密钥封装机制和公钥加密算法。 在这些算法中使用了==椭圆曲线上的双线性对(经典的Weil对、Tate对，也有Ate对、R-ate对)==这一个工具，不同于传统意义上的SM2算法，可以实现基于身份的密码体制，也就是公钥与用户的身份信息即标识相关，从而比传统意义上的公钥密码体制有许多优点，省去了==证书管理==等。安全性基于椭圆曲线双线性映射的性质，当椭圆曲线离散对数问题和扩域离散对数问题的求解难度相当时，可用椭圆曲线对构造出安全性和实现效率兼顾的基于标识的密码算法。

#### 二.加密流程

1. **大致流程如下**：

   ![image-20221226204049931](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221226204049931.png)

2. **密钥生成**：

   1. SM9算法的密钥由==KGC==(密钥生成中心)产生，主要包括KGC的主密钥对和用户的私钥。 主密钥对分为**签名主密钥对**和**加密主密钥对**。

      - KGC产生随机数ke∈[1,N−1]作为加密主私钥，计算G1中的元素Ppub−e=[e]P1作为加密主公钥，KGC秘密保存ke，公开Ppub−e。**注意**：N 为循环群G1、G2和Gt的阶，大于==2^191的素数==

        KGC选择并公开用一个字节表示的加密私钥生成函数识别符hid。

        KGC根据用户B的IDB计算用户B的加密私钥deB。KGC首先在有限域FNFN上计算t1=H1(IDB∥hid,N)+ke，若t1=0则需重新产生加密主私钥，计算和公开加密主公钥，并更新已有用户的加密私钥;否则计算。否则计算t2=ke⋅t1−1，然后计算deB=[t2]P2。

   2. **签名主密钥对**：其私钥是一个在[1,N-1]范围内的随机数；公钥是G2群的基点P2的倍点，倍数为私钥。(**注意**：以下倍点具体求法同**SM2**)

   3. **加密主密钥对**：其私钥是一个在[1,N-1]范围内的随机数；公钥是G1群的基点P1的倍点，倍数为私钥。

   4. 主密钥对的公私钥用在不同场景，其中主私钥仅用于计算用户私钥；主公钥则由KGC公开并用在其他部分。同时，签名主公钥仅用于签名和验签算法；加密主公钥则用于密钥封装、加密和密钥交换,用户私钥由KGC产生，包括签名私钥和加密私钥。

   5. **签名私钥**：是G1群的基点P1的倍点。签名私钥仅用于签名中

      **加密私钥**：是G2群的基点P2的倍点。加密私钥用于密钥解封、解密和密钥交换中私钥KGC使用主私钥和用户身份标识(以下简称ID)生成用户的私钥。

3. **详细流程**：

   1. 设需要发送的消息为比特串M，mlen 为M的比特长度，K1_len为分组密码算法中密钥 K1 的比特长度，K2_len 为**消息认证码函数MAC(K2, Z)** 中密钥 K2 的比特长度，标识为 IDb（可以唯一确定用户B的公钥），识别符符 hid。
   
   2. 计算群 **G1**中的元素 **QB = [H1(IDb || hid，N)]P1 + Ppub-e**
      - H1()和H2()函数都是由密码杂凑函数Hv()派生的密码函数。其结果都是返回一个==1~ n -1==的整数，具体操作如下。
   
        ![image-20221228200646984](C:\Users\86183\AppData\Roaming\Typora\typora-user-images\image-20221228200646984.png)
   
      - **G1**：阶为素数N的加法循环群
   
   3. 产生随机数 **1 <= r <= N - 1**
   
   4. 计算群 **G1**中的元素 **C1=[r]QB**，将 **C1的数据类型转换为比特串**（该处C1的倍数点计算是定义在群上的，和普通代数计算不一样，具体可看上面 **四.国密SM2加密算法中公私钥的计算过程**）
   
   5. 计算群 **Gt** 中的元素 g = e(Ppub-e, P2)
   
      - **Gt**：阶为素数N的乘法循环群
   
   6. 计算群 **Gt** 中的元素 w = gr，将 W 的数据类型转换为比特串
   
      - ==gr==为乘法群Gt中元素g的r次幂
   
   7. 按加密明文的方法分类进行计算 （关于KDF函数的具体操作可看上文的**SM2加密**）
      - 如果加密明文的方法是基于密钥派生函数KDF的==序列密码==算法
        1. 计算整数**klen = K1_len + K2_len**，然后计算 **K=KDF(C1 || w || IDb，klen)**。令K1 为 K左边的K1_len 比特，K2为剩下的K2_len比特，若==K1为全0比特串==，则返回步骤**3**，重新开始计算。
        2. 否则就计算**C2 = M 异或 K1**。
      -  如果加密明文的方法是结合密钥派生函数KDF的==分组密码==算法
        1.  计算整数**klen = K1_len + K2_len**，然后计算 **K = KDF(C1 || w || IDb，klen)**。令K1 为 K左边的K1_len 比特，K2为剩下的K2_len比特，若==K1为全0比特串==，则返回步骤**3**，重新开始计算。
        2.  否则计算 **C2 = Enc(K1, M)**
   
   8. 计算 **C3 = MAC(K2，C2)**
   
      - 消息认证码函数MAC(K2,Z)的作用是防止消息数据Z被非法篡改，它在密钥K2的控制下，产生消息数据比特串Z的认证码。在本基于标识的加密算法中，消息认证码函数使用密钥派生函数生成的密钥对密文比特串求取消息认证码，从而使解密者可以鉴别消息的来源和检验数据的完整性。消息认证码函数需要调用密码杂凑函数。
      - **输入**：比特串K2(比特长度为K2_len的密钥)，比特串Z(待求取消息认证码的消息)
      - **输出**：长度为v的消息认证码数据比特串K, k = Hv(Z||K2)
   
   9. 输出密文 **C = C1 || C3 || C2**。

