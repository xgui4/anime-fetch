#pragma once

#include <string>

struct MainboardInfo {
    std::string vendor_name; 
    std::string model_name; 
    std::string version; 
    std::string serial;
    std::string bios; 

    std::string display() const {
        return "Motherboard : " +
        vendor_name + " " +
        model_name + " " +
        version + " " +
        serial + " " +
        bios;  
    } 

    std::string display_minimal() const {
        return "Motherboard : " +
        vendor_name + " " +
        model_name + " " +
        version + " " +
        bios;  
    } 
}; 