#pragma once

#include <any>
#include <string>

struct DiskInfo {
    std::string vendorName; 
    std::string modelName; 
    std::string serial; 
    std::string size; 
    std::string freeSize;
    std::any volumes;  //@TODO : TBD 

    std::string display() const {
        return "Disk : " + 
        vendorName + " " +
        modelName + " " + 
        freeSize  + "/" + size + " " +
        "(" + serial + ")"; 
        //@todo the volumes
    }

    std::string displayMinimal() const {
        return "Disk : " + 
        vendorName + " " +
        modelName + " " + 
        freeSize  + "/" + size; 
    }
}; 