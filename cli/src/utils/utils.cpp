#include <string> 
#include "utils.hpp"

using std::string;

string exec(const char* cmd, const char* args[], const int argc) {
    
    string args_string = ""; 

    for (int i = 0; i < argc; i++) {
        args_string += (string)" " + args[i]; 
    } 

    string full_cmd_string = cmd + args_string; 

    const char* full_cmd = full_cmd_string.c_str(); 

    char buffer[128];

    string result = "";

    FILE* pipe = popen(full_cmd, "r");

    if (!pipe) {
        return "Erreur";
    }

    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        result += buffer;
    }

    pclose(pipe);
    
    return result;
}