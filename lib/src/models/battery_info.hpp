#pragma once

#include <string>

struct BatteryInfo {
    std::string vendorName; 
    std::string modelName; 
    std::string technology; 
    std::string capacity; 
    std::string charging;

    std::string displayMinimal() const {
        return "Battery : " + 
        vendorName + " " + 
        modelName  + " " + 
        capacity;
    } 

    std::string display() const {
        return "Battery : " + 
        vendorName + " "  + 
        modelName + " " + 
        technology + " " + 
        capacity + " " +  
        "("  + charging  + ")";
    } 
}; 