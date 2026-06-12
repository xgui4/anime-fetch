#include "kernel_info_module.h"
#include "models/kernel_info.hpp"
#include "utils/cmdline_utils.h"
#include <iostream>
#include <stdexcept>

#ifdef WIN32
#include <hwinfo/hwinfo.h>
#elif __linux__
#include <hwinfo/hwinfo.h>
#endif

KernelInfoModule::KernelInfoModule() : Module() {

}

KernelInfoModule::~KernelInfoModule() {
}

std::string KernelInfoModule::display() const {
	return std::string();
}

std::string KernelInfoModule::displayWithArgs(std::vector<std::any>) const {
	return std::string();
}

std::string KernelInfoModule::displayMinimal() const {
	return std::string();
}

std::string KernelInfoModule::displayFeatures() const {
	return std::string();
}

std::string KernelInfoModule::getKernelInfo() {
    #ifdef __linux__
      try {
        return "Kernel : " +  hwinfo::OS().kernel(); 
      }
      catch (std::runtime_error error) {
        std::cout << create_error_str_from_runtime_error(error) << std::endl;; 
        return "Kernel : Unknow"; 
      }
  #elif _WIN32
    try {
        return "Kernel : " + hwinfo::OS().kernel();
    }
    catch (std::runtime_error error) {
        std::cout << create_error_str_from_runtime_error(error) << std::endl;
        ;
        return "Kernel : Unknow";
    }
  #elif __unix
    return  "Kernel : " + exec("uname -Kpr"); 
  #endif
  return "Kernel : Unknown";
}