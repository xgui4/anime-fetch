#pragma once

#include <string>
#include "location.hpp"

struct Image {
    std::string path;
    std::string fileName; 
    std::string altTxt; 
    Location location; 
}; 