#pragma once

#include <string>

struct MemoryInfo {
    std::string vendorName;
    std::string modelName; 
    std::string name; 
    std::string serial; 
    std::string totalMemory; 
    std::string freeMemory; 

    std::string displayMinimal() const {
        return "Memory : " + 
        freeMemory + "/" + totalMemory + "GB"; 
    } 

    std::string display() const {
        return "Memory : " + 
        vendorName + " " +
        name + " " +
        serial + " " + 
        freeMemory + "/" + totalMemory + "GB"; 
    } 
};