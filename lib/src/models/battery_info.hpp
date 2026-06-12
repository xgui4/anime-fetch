#pragma once

#include <string>

struct BatteryInfo {
    std::string vendorName; 
    std::string modelName; 
    std::string technology; 
    double capacity; 
    std::string charging;

    std::string displayMinimal() const {
        return "Battery : " + 
        vendorName + " " + 
        modelName  + " " + 
        std::to_string(capacity);
    } 

    std::string display() const {
        return "Battery : " + 
        vendorName + " "  + 
        modelName + " " + 
        technology + " " + 
        std::to_string(capacity) + " " +  
        "("  + charging  + ")";
    } 
}; 