#include <any>
#include <string>

struct DiskInfo {
    std::string vendor_name; 
    std::string model_name; 
    std::string serial; 
    std::string size; 
    std::string free_size;
    std::any volumes;  //@TODO : TBD 

    inline std::string display() {
        return "Disk : " + 
        vendor_name + " " +
        model_name + " " + 
        free_size  + "/" + size + " " +
        "(" + serial + ")"; 
        //@todo the volumes
    }

    inline std::string display_minimal() {
        return "Disk : " + 
        vendor_name + " " +
        model_name + " " + 
        free_size  + "/" + size; 
    }
}; 