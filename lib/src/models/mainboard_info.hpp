#include <string>

struct MainboardInfo {
    std::string vendor_name; 
    std::string model_name; 
    std::string version; 
    std::string serial;
    std::string bios; 

    inline std::string display() {
        return "Motherboard : " +
        vendor_name + " " +
        model_name + " " +
        version + " " +
        serial + " " +
        bios;  
    } 

    inline std::string display_minimal() {
        return "Motherboard : " +
        vendor_name + " " +
        model_name + " " +
        version + " " +
        bios;  
    } 
}; 