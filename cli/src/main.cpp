#include "configs/lib_config.h"
#include "configs/cmd_args.h"
#include "os_type.hpp"
#include "services/system_info_service.h"
#include "utils/cmdline_utils.h"
#include "utils/utils.hpp"
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[]) {
  LibConfig appConfig;

  if (argc > 1) {
    const string colored_title =
        create_colored_str(Color::ForegroundYellow, appConfig.LIBRARY_NAME);

    const string argument = argv[1];

    if (argument == "--version" || argument == "-v") {
      cout << get_app_version_str(colored_title, appConfig.APP_VERSION) << endl; 
    }

    else if (argument == "--about" || argument == "-a") {
      cout << get_about_app_str(colored_title, appConfig) << endl; 
    }

    else if (argument == "--license" || argument == "-L") {
      cout << get_license_info_str(colored_title, appConfig.LICENSE_INFO) << endl; 
    }

    else if (argument == "--gui" || argument == "-g") {
      cout << open_gui("Anime-Fetch-GUI") << endl;
    }

    else if (argument == "--help" || argument == "-h") {
      cout << get_help_info_str(colored_title, appConfig) << endl; 
    }
  }

  else {
    try {
      SystemInfoService systemInfo = SystemInfoService(); 

      cout << systemInfo.getOperatingSystemInfo() << endl; 

      cout << systemInfo.getKernelName() << endl; 

      cout << systemInfo.getMemoryInfo() << "GB" << endl; 

      auto cpus_info = systemInfo.getCpuInfo(); 

      for (CPUInfo cpu_info : cpus_info) {
          cout << cpu_info.display() << endl; 
      }

      auto gpus_info = systemInfo.getGpuInfo(); 

      for (GPUInfo gpu_info : gpus_info) {
        cout << gpu_info.display() << endl; 
      }

      #ifdef __unix__ 
      if (systemInfo.getOsType() == OS_TYPE::MacOS) {
        system("kitty +icat ~/.anime-fetch/images/os-tan/mac/system-tan.png"); 
      }

      if (systemInfo.getOsType() == OS_TYPE::Linux) {
        system("kitty +icat ~/.anime-fetch/images/os-tan/linux/arch-1-tan.png");
      }

      if (systemInfo.getOsType() == OS_TYPE::BSD) {
        system("kitty +icat ~/.anime-fetch/images/os-tan/bsd/free-bsd-tan.png");
      }

      if (systemInfo.getOsType() == OS_TYPE::Unix) {
        system("kitty +icat ~/.anime-fetch/images/os-tan/others/solaris-tan.png");
      }

      if (systemInfo.getOsType() == OS_TYPE::Other) {
        system("kitty +icat ~/.anime-fetch/images/os-tan/windows/windows7-tan.png"); 
      }
	  #elif WIN32
	  system("chafa C:\\Users\\xgui4-dev\\.anime-fetch\\images\\os-tan\\windows\\windows11-tan.png"); 
      #endif
    }
    catch (std::runtime_error error) {
      cout << create_error_str_from_runtime_error(error) << endl;; 
    }
  }

  return 0;
}
