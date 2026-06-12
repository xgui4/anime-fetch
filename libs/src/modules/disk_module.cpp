#include "disk_module.h"
#include "models/disk_info.hpp"
#include <string>

#ifdef __linux
#include <hwinfo/hwinfo.h>
#include <hwinfo/disk.h>
#endif
#ifdef WIN32
// #include <hwinfo/hwinfo.h>
// #include <hwinfo/disk.h>
#endif

#include <stdexcept>

DiskModule::DiskModule() : Module() {
	this->_disks = getDiskInfo(); 
}

DiskModule::~DiskModule() {

}

std::string DiskModule::display() const {
	std::string disk_info_string = "";
	for (DiskInfo cpu : this->_disks) {
		disk_info_string += cpu.display() + "\n";
	}
	return disk_info_string;
}

std::string DiskModule::displayWithArgs(std::vector<std::any>) const {
	return std::string();
}

std::string DiskModule::displayMinimal() const {
	std::string disk_info_string = ""; 
	for (DiskInfo disk : this->_disks) {
		disk_info_string += disk.displayMinimal() + "\n"; 
	}
	return disk_info_string; 
}

std::string DiskModule::displayFeatures() const {
    throw std::runtime_error("Not Implemented Yet!");
}

// private
std::vector<DiskInfo> DiskModule::getDiskInfo() {
    return std::vector<DiskInfo>(); 
}

