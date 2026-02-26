#include "cmd_args.h"
#include "lib_config.h"
#include <iostream>
#include "../utils/utils.hpp"
#include "../utils/cmdline_utils.h"
#include "../colors.hpp"

class LibConfig;

using std::cout;
using std::endl;
using std::string;

string get_app_version_str(string app_title, string version) {
  return app_title + " " + "Version " + version;
}

string get_about_app_str(string app_title, LibConfig &app_config, string about_info) {
    return "A neofetch-inspired utility that fetch you system info with a \"OS-Tan\". \n \n + "
    "This is a work in progress experimental cross-platfrom version of \"WPFetch.\" \n The source is availaible at " + create_link(app_config.REPO_LINK_LABEL, app_config.REPO_LINK);
}

string get_license_info_str(string app_name, string license_info) {
  return app_name +" is license under the " + license_info; 
}

int open_gui(string path, const char *args[]) {
  try {
    cout << exec(path.c_str(), args);
  }

  catch (std::exception error) {
    cout << error.what() << endl; 
    return -1;
  }

  return 0;
}

string get_help_info_str(string app_name, LibConfig& app_config) {

  string help_info_str = ""; 

  help_info_str = gen_cmd_block_help_str(
              Color::ForegroundYellow, app_name,
              "Show your system info and the associated OS-Tan", Color::Default,
              "", "")
  + "\n" + gen_cmd_block_help_str(
              Color::ForegroundYellow, app_name,
              "Show the " + app_name + " version running",
              Color::ForegroundBlue,
              app_config.getCommandLineFlag(CmdLineArgs::CmdVersion),
              app_config.getCommandLineFlag(CmdLineArgs::CmdVersionShort))
  + "\n" + gen_cmd_block_help_str(
              Color::ForegroundYellow, app_name,
              "Show information about the " + app_name, Color::ForegroundBlue,
              app_config.getCommandLineFlag(CmdLineArgs::CmdAbout),
              app_config.getCommandLineFlag(CmdLineArgs::CmdVersionShort))
  + "\n" + gen_cmd_block_help_str(
              Color::ForegroundYellow, app_name,
              "Show the license information of " + app_name,
              Color::ForegroundBlue,
              app_config.getCommandLineFlag(CmdLineArgs::CmdLicense),
              app_config.getCommandLineFlag(CmdLineArgs::CmdLicenseShort))
  + "\n" + gen_cmd_block_help_str(
              Color::ForegroundYellow, app_name, "Open the GUI of " + app_name,
              Color::ForegroundBlue,
              app_config.getCommandLineFlag(CmdLineArgs::CmdGui),
              app_config.getCommandLineFlag(CmdLineArgs::CmdGuiShort))
  + "\n" + gen_cmd_block_help_str(
              Color::ForegroundYellow, app_name, "Show this help message",
              Color::ForegroundBlue,
              app_config.getCommandLineFlag(CmdLineArgs::CmdHelp),
              app_config.getCommandLineFlag(CmdLineArgs::CmdHelpShort)); 
  return help_info_str;
}
