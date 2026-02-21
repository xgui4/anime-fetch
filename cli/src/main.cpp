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
        }

        else if (argument == "--about" || argument == "-a") {
            display_about_app(colored_title, nullptr, appConfig->REPO_LINK_LABEL, appConfig->REPO_LINK);
        }

        else if (argument == "--license" || argument == "-L") {
            display_license_info(colored_title, appConfig->LICENSE_INFO); 
        }

        else if (argument == "--gui" || argument == "-g") {
            cout << open_gui("Anime-Fetch-GUI") << endl; 
        }

        else if (argument == "--help" || argument == "-h") {
            display_help_info(colored_title);
        }
     }

    else {
        std::cout << "User : " << exec("whoami");
        std::cout << "System : " << exec("uname -a");

        system("kitty +icat /home/xgui4/develop/anime-fetch/assets/images/os-tan/linux/arch-1-tan.png");
    }

    return 0; 
}

