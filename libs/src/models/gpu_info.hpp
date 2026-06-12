#pragma once

#include <string>

const double BYTES_PER_GIBIBYTE = 1024 * 1024 * 1024;

struct GPUInfo {
    std::string vendorName; 
    std::string modelName; 
    double memoryInBytes = -1;  
    int frequencyMHz = -1; 
    int gpuCores = -1;
    std::string driverVersion = ""; 
    std::string id = ""; 
    std::string vendorID = ""; 
    std::string device_id = "";  

    std::string display() const {
        return "GPU : " +
        vendorName + " " +
        modelName + 
        "( " + std::to_string(static_cast<double>((memoryInBytes) / BYTES_PER_GIBIBYTE)) + " GB " + " ) " +
        "drivers : " + driverVersion; 
    } 

    std::string displayMinimal() const {
        return "GPU : " +
        vendorName + " " +
        modelName; 
    } 
}; 

/*
                gpu.id(),
                "vendor:", gpu.vendor(),
                "model:", gpu.name(),
                "driverVersion:", gpu.driverVersion(),
                "memory [MiB]:", bytes_to_MiB(gpu.memory_Bytes()),
                "frequency:", gpu.frequency_MHz(),
                "cores:", gpu.num_cores(),
                "vendor_id:", gpu.vendor_id(),
                "device_id:", gpu.device_id());
*/