#pragma once

#import <string>
#import "location.hpp"

struct ImageInfo {
    std::string path;
    std::string file_name; 
    std::string alt_txt; 
    Location location; 
}; 