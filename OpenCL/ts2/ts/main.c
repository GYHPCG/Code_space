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
"                       __global TYPE *c,                       \n" \
"                       const TYPE bb)                    \n" \
"{                                                               \n" \
"    //Get our global thread ID  ,                                \n" \
"    size_t id = get_global_id(0),id2;                                  \n" \
"    id2=id+bb;                                                       \n" \
"    //Make sure we do not go out of bounds                      \n" \
"        c[id2] = id2;/*a[id];*/                                  \n" \
"}                                                               \n" \
                                                                "\n" ;
//"#pragma OPENCL EXTENSION cl_khr_fp64 : enable                    \n" \


int main( int argc, char* argv[] )
{
    // Length of vectors
    unsigned int n = 3;

    // Host input vectors
    TYPE *h_a;
    TYPE *h_b;
    // Host output vector
    TYPE *h_c;
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
    //h_b = (TYPE*)malloc(bytes);
    h_c = (TYPE*)malloc(3*bytes);

    // Initialize vectors on host
    int i;
    for( i = 0; i < n; i++ )
    {
        h_a[i] = 1;
        //h_b[i] = 1;
    }
    for( i = 0; i < 3*n; i++ )
    {
        h_c[i] = 0;
        //h_b[i] = 1;
    }
    size_t globalSize, localSize;
    cl_int err;

    // Number of work items in each local work group
    //localSize = 64;

    // Number of total work items - localSize must be devisor
    globalSize = 3*n;//ceil(n/(double)localSize)*localSize;

    // Bind to platform
    err = clGetPlatformIDs(3, cpPlatform, NULL);
    // Get ID for the device, change the platform number to get the correct gpu driver.
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
    //d_b = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes, NULL, NULL);
    d_c = clCreateBuffer(context, CL_MEM_READ_WRITE, 3*bytes, NULL, NULL);
    //d_e = clCreateBuffer(context, CL_MEM_READ_WRITE, bytes, NULL, NULL);

    err = clEnqueueWriteBuffer(queue, d_c, CL_TRUE, 0,
                                   3*bytes, h_c, 0, NULL, NULL);
    err |= clEnqueueWriteBuffer(queue, d_a, CL_TRUE, 0,
                                   bytes, h_a, 0, NULL, NULL);

//for(int i = 0;i<3;i++){
            // Write our data set into the input array in device memory


                                   bb = 0*n;
    // Set the arguments to our compute kernel
    err  = clSetKernelArg(kernel, 0, sizeof(cl_mem), &d_a);
    err |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &d_c);
    err |= clSetKernelArg(kernel, 2, sizeof(TYPE), &bb);
    // Execute the kernel over the entire range of the data set
    err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &globalSize, 0,
                                                              0, NULL, NULL);
//}
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
                                3*bytes, h_c, 0, NULL, NULL );

    //Sum up vector c and print result divided by n, this should equal 1 within error

    double sum = 0;
    for(i=0; i<2*n; i++) {
        printf("%d\n",h_c[i]);
        sum += h_c[i];
    }


    printf("final result: %f\n", sum);

    // release OpenCL resources
    clReleaseMemObject(d_a);
    //clReleaseMemObject(d_b);
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
