#include <string>

struct CPUInfo {
    std::string vendor_name; 
    std::string model_name;
    int frequency;  //@todo : TBD    
    int logicals_cores; 
    int cache_size; 

    inline std::string display() {
        return "CPU : " + 
        vendor_name + " " + 
        model_name + 
        "(" + std::to_string(logicals_cores) + "X)"
        + "( caches : " + std::to_string(cache_size) 
        + "frequency: " + std::to_string(frequency) + "ghz)";  
    } 


    inline std::string display_minimal() {
        return "CPU : " + 
        vendor_name + " " + 
        model_name + 
        "(" + std::to_string(logicals_cores) + "X)"; 
    } 
}; 