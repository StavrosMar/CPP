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
 
 
 
    return 0;
}
