#include <stdexcept>
#include <string>

enum class OS_TYPE {
    WINDOWS,
    LINUX,
    BSD,
    UNIX,
    MACOS
};

inline std::string value(OS_TYPE type) {
    switch(type) {
        case OS_TYPE::WINDOWS: return "Windows"; 
        case OS_TYPE::LINUX: return "Linux"; 
        case OS_TYPE::BSD: return "BSD"; 
        case OS_TYPE::UNIX: return "Unix";
        case OS_TYPE::MACOS: return "MacOS"; 
    }
}

inline OS_TYPE type(std::string value) {
    
    if (value == "Windows") {
        return OS_TYPE::WINDOWS;
    }
    if (value == "Linux") {
        return OS_TYPE::LINUX;
    }
    if (value == "BSD") {
        return OS_TYPE::BSD; 
    }
    if (value == "Unix") {
        return OS_TYPE::UNIX; 
    }
    if (value == "MacOS") {
        return OS_TYPE::MACOS;
    }

    throw std::invalid_argument(value + " was invalid"); 
}