#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include "os_type.hpp"
#include "cmdline_utils.h"

using std::string; 
using std::cout;
using std::endl; 

std::string exec(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) return "Erreur";
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        result += buffer;
    }
    pclose(pipe);
    return result;
}
    
int main(int argc, char *argv[])
{
    const string REPO_LINK = "https://github.com/xgui4/anime-fetch"; 
    const string REPO_LINK_LABEL = "https://github.com/xgui4/anime-fetch"; 
    const string NAME = "Anime-Fetch"; 
    const string VERSION = "0.0.0"; 

    if (argc > 1) {
        const string colored_title = generate_colored_string(Color::ForegroundYellow, NAME); 

        const string argument = argv[1]; 

        if (argument == "--version" || argument == "-v") {
            cout << colored_title << " " << "Version " << VERSION << endl; 
        }

        else if (argument == "--about" || argument == "-a") {
            cout << "A neofetch-inspired utility that fetch you system info with a OS-Tan." <<  endl;
            cout << endl;
            cout << "This is a work in progress experimental cross-platfrom version of WPFetch." << endl; 
            cout << "The source is availaible at " << create_hyperlink(REPO_LINK_LABEL, REPO_LINK) << endl; 
        }

        else if (argument == "--license" || argument == "-L") {
            cout << "Anime-Fetch is license under the GPLv3 license" << endl;
        }

        else if (argument == "--gui" || argument == "-g") {
            cout << "GUI Mode coming soon!" << endl; 
        }

        else if (argument == "--help" || argument == "-h") {

            cout << generate_command_block_help_str(
                Color::ForegroundYellow, 
                NAME, 
                "Show your system info and the associated OS-Tan",
                Color::Default,
                "",
                ""
            ) << endl; 

            cout << generate_command_block_help_str(
                Color::ForegroundYellow, 
                NAME, 
                "Show the " + colored_title + " version running", 
                Color::ForegroundBlue, 
                "--version",
                "-v"
            ) << endl; 

            cout << generate_command_block_help_str(
                Color::ForegroundYellow, 
                NAME, 
                "Show information about the " + colored_title, 
                Color::ForegroundBlue, 
                "--about",
                "-a"
            ) << endl; 

            cout << generate_command_block_help_str(
                Color::ForegroundYellow, 
                NAME, 
                "Show the license information of " + colored_title, 
                Color::ForegroundBlue, 
                "--license",
                "-L"
            ) << endl; 

            cout << generate_command_block_help_str(
                Color::ForegroundYellow, 
                NAME, 
                "Open the GUI of " + colored_title, 
                Color::ForegroundBlue, 
                "--gui",
                "-g"
            ) << endl; 
            
            cout << generate_command_block_help_str(
                Color::ForegroundYellow, 
                NAME, 
                "Show this help message", 
                Color::ForegroundBlue, 
                "--help",
                "-h"
            ) << endl; 
        }
     }

    else {
        std::cout << "User : " << exec("whoami");
        std::cout << "System : " << exec("uname -a");

        system("kitty +icat /home/xgui4/develop/anime-fetch/assets/images/os-tan/linux/arch-1-tan.png");
    }

    return 0; 
}

