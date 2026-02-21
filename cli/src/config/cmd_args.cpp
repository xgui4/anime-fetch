#include <exception>
#include <iostream>
#include <string>
#include "cmd_args.h"
#include "../utils/utils.hpp"
#include "../utils/cmdline_utils.h"
#include "app_config.h"

using std::string; 
using std::cout;
using std::endl; 

void display_app_version(string app_title, string version) {
    cout <<  app_title << " " << "Version " << version << endl; 
}

void display_about_app(string app_title, string about_info, string repo_link_label, string repo_link) {
    if (about_info == "") {
        cout << "A neofetch-inspired utility that fetch you system info with a OS-Tan." <<  endl;
        cout << endl;
        cout << "This is a work in progress experimental cross-platfrom version of WPFetch." << endl; 
        cout << "The source is availaible at " << create_hyperlink(repo_link_label, repo_link) << endl; 
    }
}

void display_license_info(string app_name, string license_info) {
    cout <<  app_name << " is license under the " << license_info << endl;
}

int open_gui(string path, const char* args[]) {
    try {
        cout << exec(path.c_str(), args); 
    }

    catch (std::exception error)  {
        cout << error.what(); 
        return -1; 
    }

    return 0; 
}

void display_help_info(string app_name, AppConfig appConfig) {
    cout << generate_command_block_help_str(
        Color::ForegroundYellow, 
        app_name, 
        "Show your system info and the associated OS-Tan",
        Color::Default,
        "",
        ""
    ) << endl; 

    cout << generate_command_block_help_str(
        Color::ForegroundYellow, 
        app_name, 
        "Show the " + app_name + " version running", 
        Color::ForegroundBlue, 
        appConfig.getCommandLineFlag(CmdLineArgs::CmdVersion),
        appConfig.getCommandLineFlag(CmdLineArgs::CmdVersionShort)
    ) << endl; 

    cout << generate_command_block_help_str(
        Color::ForegroundYellow, 
        app_name, 
        "Show information about the " + app_name, 
        Color::ForegroundBlue, 
        appConfig.getCommandLineFlag(CmdLineArgs::CmdAbout),
        appConfig.getCommandLineFlag(CmdLineArgs::CmdVersionShort)
    ) << endl; 

    cout << generate_command_block_help_str(
        Color::ForegroundYellow, 
        app_name, 
        "Show the license information of " + app_name, 
        Color::ForegroundBlue, 
        appConfig.getCommandLineFlag(CmdLineArgs::CmdLicense),
        appConfig.getCommandLineFlag(CmdLineArgs::CmdLicenseShort)
    ) << endl; 

    cout << generate_command_block_help_str(
        Color::ForegroundYellow, 
        app_name, 
        "Open the GUI of " + app_name, 
        Color::ForegroundBlue, 
        appConfig.getCommandLineFlag(CmdLineArgs::CmdGui),
        appConfig.getCommandLineFlag(CmdLineArgs::CmdGuiShort)
    ) << endl; 
    
    cout << generate_command_block_help_str(
        Color::ForegroundYellow, 
        app_name, 
        "Show this help message", 
        Color::ForegroundBlue, 
        appConfig.getCommandLineFlag(CmdLineArgs::CmdHelp),
        appConfig.getCommandLineFlag(CmdLineArgs::CmdHelpShort)
    ) << endl; 
}
