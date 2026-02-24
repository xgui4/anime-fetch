#pragma once

#include <string>

struct BatteryInfo {
    std::string vendor_name; 
    std::string model_name; 
    std::string technology; 
    std::string capacity; 
    std::string charging;

    std::string display_minimal() const {
        return "Battery : " + 
        vendor_name + " " + 
        model_name  + " " + 
        capacity;
    } 

    std::string display() const {
        return "Battery : " + 
        vendor_name + " "  + 
        model_name + " " + 
        technology + " " + 
        capacity + " " +  
        "("  + charging  + ")";
    } 
}; 