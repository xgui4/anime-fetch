#pragma once

#include <string>

struct OSInfo {
    std::string name; 
    std::string vendorName;
    std::string short_name; 
    std::string version; 
    std::string arch; 
    std::string endianess; 

    std::string displayMinimal() const {
        return "OS : " + 
        vendorName + " " + 
        name + " " + 
        version + 
        arch;
    }

    std::string display() const {
        return "OS : " + 
        vendorName + " " + 
        name + " " + 
        version + " " + 
        arch + " " + 
        endianess;
    }    
};