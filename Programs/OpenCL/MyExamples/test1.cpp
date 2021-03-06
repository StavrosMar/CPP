//*****Description*****
// This program is a test for OpenCL library installation
//*********************

//*****Compile*****
// with the following command : g++ -o hello hello.cpp -framework opencl
//****************

//#include <stdio.h>
//#include <stdlib.h>

//C bindings
//#include <OpenCL/opencl.h>
 
#include <iostream>
#include <vector>
//C++ bindings downloaded from https://www.khronos.org/registry/OpenCL/
#include "cl.hpp"

int main(){
    //get all platforms (drivers)
    std::vector<cl::Platform> all_platforms;
    cl::Platform::get(&all_platforms);
    if(all_platforms.size()==0){
        std::cout<<" No platforms found. Check OpenCL installation!\n";
        exit(1);
    }
    cl::Platform default_platform=all_platforms[0];
    std::cout << "Using platform: "<<default_platform.getInfo<CL_PLATFORM_NAME>()<<"\n";
 
    //get default device of the default platform
    std::vector<cl::Device> all_devices;
    default_platform.getDevices(CL_DEVICE_TYPE_ALL, &all_devices);
    if(all_devices.size()==0){
        std::cout<<" No devices found. Check OpenCL installation!\n";
        exit(1);
    }
    cl::Device default_device=all_devices[0];
    std::cout<< "Using device: "<<default_device.getInfo<CL_DEVICE_NAME>()<<"\n";
 
    //Create Context - link between Host-Device
    cl::Context context(default_device); 

    //Program for execution
    cl::Program::Sources sources;

    //Kernel of my program C=A+B
    std::string kernel_code = 
	    " void kernel simple_add(global const int* A, global const int* B, global int* C) {"
	    "C[get_global_id(0)] = A[get_global_id(0)]+B[get_global_id(0)]; "
	    " }";

    //Build Kernel
    sources.push_back(std::make_pair(kernel_code.c_str(), std::strlen(kernel_code.c_str())) );

    cl::Program program( context, sources);
    
    program.build(all_devices);
    /*
    
    if( program.build( default_device ) != CL_SUCCESS) {
	    std::cout << " Error building: "<< program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(default_device)<<"\n";
	    exit(1);
    }

    */
    return 0;
 }
