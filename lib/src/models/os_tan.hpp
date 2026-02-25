#pragma once

#include <string>

enum class OSTanFamily {
    Windows,
    Apple,
    MacOS,
    BSD,
    Linux
}; 

struct OSTan {
    std::string name;
    std::string imagePath; 
    OSTanFamily family; 
}; 
