#pragma once

#include <string>

struct GPUInfo {
    std::string vendor_name; 
    std::string model_name;
    std::string memory; 

    std::string display() const {
        return "GPU : " +
        vendor_name + " " +
        model_name + 
        "( " + memory + " ) GB";  
    } 
}; 