#pragma once

#import <string>
#import "location.hpp"

struct ImageInfo {
    std::string path;
    std::string fileName; 
    std::string altTxt; 
    Location location; 
}; 