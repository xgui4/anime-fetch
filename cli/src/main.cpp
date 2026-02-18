#include <iostream>
#include <string>
#include "os_type.hpp"

using std::string; 
using std::cout;
using std::endl; 
    
int main(int argc, char *argv[])
{
    if (argc == 1) {
        const string WINDOWS = value(OS_TYPE::WINDOWS); 
        const string LINUX = value(OS_TYPE::LINUX); 
        const string BSD = value(OS_TYPE::BSD); 
        const string UNIX = value(OS_TYPE::UNIX); 
        const string MACOS= value(OS_TYPE::MACOS); 

        const string OPERATING_SYSTEM = argv[1]; 

        if (WINDOWS == OPERATING_SYSTEM){
            cout << "Operating System : Windows" << endl;  
        }

        if (LINUX == OPERATING_SYSTEM){
            cout << "Operating System : GNU/Linux" << endl; 
        }

        if (BSD == OPERATING_SYSTEM){
            cout << "Operating System : FreeBSD" << endl; 
        }

        if (UNIX == OPERATING_SYSTEM){
            cout << "Operating System : UNIX Like System" << endl;  
        }

        if (MACOS == OPERATING_SYSTEM){
            cout << "Operating System : OS X" << endl; 
        }
    }

    else {
        cout << "Operating System : Nothing"; 
    }

    return 0; 
}

