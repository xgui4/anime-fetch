#include <string>

struct CPU_INFO {
    std::string vendor_name; 
    std::string model_name;
    int numbers_of_core; 

    inline std::string display() {
        return "CPU : " + vendor_name + " " + model_name + " (" + std::to_string(numbers_of_core) + "x)\n";  
    } 
}; 