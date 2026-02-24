#pragma once

#include <any>
#include <string>

struct DiskInfo {
    std::string vendor_name; 
    std::string model_name; 
    std::string serial; 
    std::string size; 
    std::string free_size;
    std::any volumes;  //@TODO : TBD 

    std::string display() const {
        return "Disk : " + 
        vendor_name + " " +
        model_name + " " + 
        free_size  + "/" + size + " " +
        "(" + serial + ")"; 
        //@todo the volumes
    }

    std::string display_minimal() const {
        return "Disk : " + 
        vendor_name + " " +
        model_name + " " + 
        free_size  + "/" + size; 
    }
}; 