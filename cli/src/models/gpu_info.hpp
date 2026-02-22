#include <string>

struct GPU_INFO {
    std::string vendor_name; 
    std::string model_name;
    std::string memory; 

    inline std::string display() {
        return "GPU : " + vendor_name + " " + model_name + "( " + memory + " )" "x)\n";  
    } 
}; 