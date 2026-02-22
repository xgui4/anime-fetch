#include "config/app_config.h"
#include "config/cmd_args.h"
#include "os_type.hpp"
#include "services/system_info_service.hpp"
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
  AppConfig appConfig;

  if (argc > 1) {
    const string colored_title =
        create_colored_str(Color::ForegroundYellow, appConfig.APP_NAME);

    const string argument = argv[1];

    if (argument == "--version" || argument == "-v") {
      display_app_version(colored_title, appConfig.VERSION);
    }

    else if (argument == "--about" || argument == "-a") {
      display_about_app(colored_title, appConfig);
    }

    else if (argument == "--license" || argument == "-L") {
      display_license_info(colored_title, appConfig.LICENSE_INFO);
    }

    else if (argument == "--gui" || argument == "-g") {
      cout << open_gui("Anime-Fetch-GUI") << endl;
    }

    else if (argument == "--help" || argument == "-h") {
      display_help_info(colored_title, appConfig);
    }
  }

  else {
    try {
      SystemInfoService systemInfo = SystemInfoService(); 

      cout << systemInfo.getOperatingSystemInfo() << endl; 

      cout << systemInfo.getKernelName() << endl; 

      cout << systemInfo.getMemoryInfo() << "GB" << endl; 

      auto cpus_info = systemInfo.getCpuInfo(); 

      for (CPU_INFO cpu_info : cpus_info) {
          cout << cpu_info.display() << endl; 
      }

      auto gpus_info = systemInfo.getGpuInfo(); 

      for (GPU_INFO gpu_info : gpus_info) {
        cout << gpu_info.display() << endl; 
      }

      if (systemInfo.getOsType() == OS_TYPE::Windows) {
        system("kitty +icat ~/.anime-fetch/images/os-tan/windows/win11-os-tan-temp.png"); 
      }

      if (systemInfo.getOsType() == OS_TYPE::MacOS) {
        system("kitty +icat ~/.anime-fetch/images/os-tan/mac/system-tan.png"); 
      }

      if (systemInfo.getOsType() == OS_TYPE::Linux) {
        system("kitty +icat ~/.anime-fetch/images/os-tan/linux/arch-1-tan.png");
      }

      if (systemInfo.getOsType() == OS_TYPE::BSD) {
        system("kitty +icat ~/.anime-fetch/images/os-tan/others/free-bsd-tan.png");
      }

      if (systemInfo.getOsType() == OS_TYPE::Unix) {
        system("kitty +icat ~/.anime-fetch/images/os-tan/others/solaris-tan.png");
      }

      if (systemInfo.getOsType() == OS_TYPE::Other) {
        system("kitty +icat ~/.anime-fetch/images/os-tan/windows/os-tan7.png"); 
      }
    }
    catch (std::runtime_error error) {
      cout << create_error_str_from_runtime_error(error) << endl;; 
    }
  }

  return 0;
}
