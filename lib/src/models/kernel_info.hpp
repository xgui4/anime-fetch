#pragma once

#import <string>

struct KernelInfo{
    std::string name; 

    std::string display() {
        return "Kernel : " + 
        name; 
    }
};