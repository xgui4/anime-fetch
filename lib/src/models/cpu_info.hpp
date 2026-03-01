#pragma once

#include <string>

struct CPUInfo {
    std::string vendorName; 
    std::string modelName;
    int frequency;  //@todo : TBD    
    int logicalsCores; 
    int cacheSize; 

    std::string display() const {
        return "CPU : " + 
        vendorName + " " + 
        modelName + 
        "(" + std::to_string(logicalsCores) + "X)"
        + "( caches : " + std::to_string(cacheSize) 
        + "frequency: " + std::to_string(frequency) + "ghz)";  
    } 

    std::string displayMinimal() const {
        return "CPU : " + 
        vendorName + " " + 
        modelName + 
        "(" + std::to_string(logicalsCores) + "X)"; 
    } 
};  