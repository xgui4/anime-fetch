#include "cmd_args.h"
#include "app_config.h"
#include <iostream>
#include "../utils/utils.hpp"
#include "../utils/cmdline_utils.h"
#include "../colors.hpp"

class AppConfig;

using std::cout;
using std::endl;
using std::string;

void display_app_version(string app_title, string version) {
  cout << app_title << " " << "Version " << version << endl;
}

void display_about_app(string app_title, AppConfig &app_config, string about_info) {
  if (about_info == "") {
    cout << "A neofetch-inspired utility that fetch you system info with a "
            "OS-Tan."
         << endl;
    cout << endl;
    cout << "This is a work in progress experimental cross-platfrom version of "
            "WPFetch."
         << endl;
    cout << "The source is availaible at "
         << create_link(app_config.REPO_LINK_LABEL, app_config.REPO_LINK) << endl;
  }
}

void display_license_info(string app_name, string license_info) {
  cout << app_name << " is license under the " << license_info << endl;
}

int open_gui(string path, const char *args[]) {
  try {
    cout << exec(path.c_str(), args);
  }

  catch (std::exception error) {
    cout << error.what();
    return -1;
  }

  return 0;
}

void display_help_info(string app_name, AppConfig& app_config) {
  cout << gen_cmd_block_help_str(
              Color::ForegroundYellow, app_name,
              "Show your system info and the associated OS-Tan", Color::Default,
              "", "")
       << endl;

  cout << gen_cmd_block_help_str(
              Color::ForegroundYellow, app_name,
              "Show the " + app_name + " version running",
              Color::ForegroundBlue,
              app_config.getCommandLineFlag(CmdLineArgs::CmdVersion),
              app_config.getCommandLineFlag(CmdLineArgs::CmdVersionShort))
       << endl;

  cout << gen_cmd_block_help_str(
              Color::ForegroundYellow, app_name,
              "Show information about the " + app_name, Color::ForegroundBlue,
              app_config.getCommandLineFlag(CmdLineArgs::CmdAbout),
              app_config.getCommandLineFlag(CmdLineArgs::CmdVersionShort))
       << endl;

  cout << gen_cmd_block_help_str(
              Color::ForegroundYellow, app_name,
              "Show the license information of " + app_name,
              Color::ForegroundBlue,
              app_config.getCommandLineFlag(CmdLineArgs::CmdLicense),
              app_config.getCommandLineFlag(CmdLineArgs::CmdLicenseShort))
       << endl;

  cout << gen_cmd_block_help_str(
              Color::ForegroundYellow, app_name, "Open the GUI of " + app_name,
              Color::ForegroundBlue,
              app_config.getCommandLineFlag(CmdLineArgs::CmdGui),
              app_config.getCommandLineFlag(CmdLineArgs::CmdGuiShort))
       << endl;

  cout << gen_cmd_block_help_str(
              Color::ForegroundYellow, app_name, "Show this help message",
              Color::ForegroundBlue,
              app_config.getCommandLineFlag(CmdLineArgs::CmdHelp),
              app_config.getCommandLineFlag(CmdLineArgs::CmdHelpShort))
       << endl;
}
