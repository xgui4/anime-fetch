#pragma once

#include <string>

struct CPUInfo {
    std::string vendorName; 
    std::string modelName;
    int minFrequency;  
    int maxFrequency;  
    int physicalsCores; 
    int logicalsCores; 
    long l1cache; 
    long l2cache; 
    long l3cache; 

    std::string display() const {
        return "CPU : " + 
        vendorName + " " + 
        modelName + 
        "(" + std::to_string(logicalsCores) + "X)"
        + "( caches : " + "L1 Cache : " + std::to_string(l1cache)  + "L2 Cache : " + std::to_string(l2cache) + "L3 Cache : " + std::to_string(l3cache) 
        + "frequency: " + std::to_string(minFrequency) + "Up To" + std::to_string(maxFrequency) + "Mhz)";  
    } 

    std::string displayMinimal() const {
        return "CPU : " + 
        vendorName + " " + 
        modelName + 
        "(" + std::to_string(logicalsCores) + "X)"; 
    } 
};  