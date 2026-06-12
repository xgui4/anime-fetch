#pragma once

#include <string>

struct KernelInfo{
    std::string name; 

    std::string display() const {
        return "Kernel : " + 
        name; 
    }
};