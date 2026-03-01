#pragma once

#include <string>

struct GPUInfo {
    std::string vendorName; 
    std::string modelName;
    std::string memory; 

    std::string display() const {
        return "GPU : " +
        vendorName + " " +
        modelName + 
        "( " + memory + " ) GB";  
    } 
}; 