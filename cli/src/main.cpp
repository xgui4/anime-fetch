#include <iostream>
#include <ostream>
#include <string>
#include "utils/cmdline_utils.h"
#include "config/cmd_args.h"
#include "utils/utils.hpp"
#include "config/app_config.h"

using std::string; 
using std::cout;
using std::endl; 
    
int main(int argc, char *argv[])
{
    AppConfig * appConfig = new AppConfig(); 

    if (argc > 1) {
        const string colored_title = generate_colored_string(Color::ForegroundYellow, appConfig->APP_NAME); 

        const string argument = argv[1]; 

        if (argument == "--version" || argument == "-v") {
            display_app_version(colored_title, appConfig->VERSION); 
            // cout << colored_title << " " << "Version " << appConfig->VERSION << endl; 
        }

        else if (argument == "--about" || argument == "-a") {
            display_about_app(colored_title, nullptr, appConfig->REPO_LINK_LABEL, appConfig->REPO_LINK);
            // cout << "A neofetch-inspired utility that fetch you system info with a OS-Tan." <<  endl;
            // cout << endl;
            // cout << "This is a work in progress experimental cross-platfrom version of WPFetch." << endl; 
            //cout << "The source is availaible at " << create_hyperlink(appConfig->REPO_LINK_LABEL, appConfig->REPO_LINK) << endl; 
        }

        else if (argument == "--license" || argument == "-L") {
            display_license_info(colored_title, appConfig->LICENSE_INFO); 
            // cout << "Anime-Fetch is license under the GPLv3 license" << endl;
        }

        else if (argument == "--gui" || argument == "-g") {
            cout << open_gui("Anime-Fetch-GUI") << endl; 
            //cout << "GUI Mode coming soon!" << endl; 
        }

        else if (argument == "--help" || argument == "-h") {
            display_help_info(colored_title);
            /* 
            cout << generate_command_block_help_str(
                Color::ForegroundYellow, 
                appConfig->APP_NAME, 
                "Show your system info and the associated OS-Tan",
                Color::Default,
                "",
                ""
            ) << endl; 

            cout << generate_command_block_help_str(
                Color::ForegroundYellow, 
                appConfig->APP_NAME, 
                "Show the " + colored_title + " version running", 
                Color::ForegroundBlue, 
                "--version",
                "-v"
            ) << endl; 

            cout << generate_command_block_help_str(
                Color::ForegroundYellow, 
                appConfig->APP_NAME, 
                "Show information about the " + colored_title, 
                Color::ForegroundBlue, 
                "--about",
                "-a"
            ) << endl; 

            cout << generate_command_block_help_str(
                Color::ForegroundYellow, 
                appConfig->APP_NAME, 
                "Show the license information of " + colored_title, 
                Color::ForegroundBlue, 
                "--license",
                "-L"
            ) << endl; 

            cout << generate_command_block_help_str(
                Color::ForegroundYellow, 
                appConfig->APP_NAME, 
                "Open the GUI of " + colored_title, 
                Color::ForegroundBlue, 
                "--gui",
                "-g"
            ) << endl; 
            
            cout << generate_command_block_help_str(
                Color::ForegroundYellow, 
                appConfig->APP_NAME, 
                "Show this help message", 
                Color::ForegroundBlue, 
                "--help",
                "-h"
            ) << endl; 

            */
        }
     }

    else {
        std::cout << "User : " << exec("whoami");
        std::cout << "System : " << exec("uname -a");

        system("kitty +icat /home/xgui4/develop/anime-fetch/assets/images/os-tan/linux/arch-1-tan.png");
    }

    return 0; 
}

