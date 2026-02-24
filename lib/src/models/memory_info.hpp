#pragma once

#include <string>

struct MemoryInfo {
    std::string vendor_name;
    std::string model_name; 
    std::string name; 
    std::string serial; 
    std::string total_memory; 
    std::string free_memory; 

    std::string display_minimal() const {
        return "Memory : " + 
        free_memory + "/" + total_memory + "GB"; 
    } 

    std::string display() const {
        return "Memory : " + 
        vendor_name + " " +
        name + " " +
        serial + " " + 
        free_memory + "/" + total_memory + "GB"; 
    } 
};