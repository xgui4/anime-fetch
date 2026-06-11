#pragma once

#include <string>

struct MainboardInfo {
    std::string vendorName; 
    std::string modelName; 
    std::string version; 
    std::string serial;
    std::string bios; 

    std::string display() const {
        return "Motherboard : " +
        vendorName + " " +
        modelName + " " +
        version + " " +
        serial + " " +
        bios;  
    } 

    std::string displayMinimal() const {
        return "Motherboard : " +
        vendorName + " " +
        modelName + " " +
        version + " " +
        bios;  
    } 
}; 