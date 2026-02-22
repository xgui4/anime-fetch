#pragma once

#include <stdexcept>
#include <string>

enum class OS_TYPE { Windows, Linux, BSD, Unix, MacOS, Other };

inline std::string value(OS_TYPE type) {
  switch (type) {
  case OS_TYPE::Windows:
    return "Windows";
  case OS_TYPE::Linux:
    return "Linux";
  case OS_TYPE::BSD:
    return "BSD";
  case OS_TYPE::Unix:
    return "Unix";
  case OS_TYPE::MacOS:
    return "MacOS";
  case OS_TYPE::Other:
    return "Unknow"; 
  }
}

inline OS_TYPE type(std::string value) {

  if (value == "Windows") {
    return OS_TYPE::Windows;
  }
  if (value == "Linux") {
    return OS_TYPE::Linux;
  }
  if (value == "BSD") {
    return OS_TYPE::BSD;
  }
  if (value == "Unix") {
    return OS_TYPE::Unix;
  }
  if (value == "MacOS") {
    return OS_TYPE::MacOS;
  }
  if (value == "Other") {
    return OS_TYPE::Other;
  }

  throw std::invalid_argument(value + " was invalid");
}