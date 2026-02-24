#include <string>

struct BatteryInfo {
    std::string vendor_name; 
    std::string model_name; 
    std::string technology; 
    std::string capacity; 
    std::string charging;

    inline std::string display_minimal() {
        return "Battery : " + 
        vendor_name + " " + 
        model_name  + " " + 
        capacity;
    } 

    inline std::string display() {
        return "Battery : " + 
        vendor_name + " "  + 
        model_name + " " + 
        technology + " " + 
        capacity + " " +  
        "("  + charging  + ")";
    } 
}; 