#pragma once

#include <string>

struct OSInfo {
    std::string name; 
    std::string vendor_name;
    std::string short_name; 
    std::string version; 
    std::string arch; 
    std::string endianess; 

    std::string display_minimal() {
        return "OS : " + 
        vendor_name + " " + 
        name + " " + 
        version + 
        arch;
    }

    std::string display() {
        return "OS : " + 
        vendor_name + " " + 
        name + " " + 
        version + " " + 
        arch + " " + 
        endianess;
    }    
};