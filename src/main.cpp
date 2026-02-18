#include <cstdlib>
#include <string>

using std::string; 
    
int main(int argc, char *argv[])
{
    string space = " "; 

    string fetcher = "fastfetch"; 

    string configuration = "-c neofetch"; 

    string image = "-l /home/xgui4/develop/anime-fetch/assets/images/os-tan/linux/arch-1-tan.png"; 

    string command = fetcher+ space + configuration + space + image;

    system(command.c_str());

    return 0; 
}

