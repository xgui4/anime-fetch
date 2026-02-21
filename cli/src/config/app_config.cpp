#include "app_config.h"
#include "cmd_args.h"
#include <stdexcept>

std::string getCommandLineFlag(CmdLineArgs arg) {   
    return ARGS_LISTS.at((int)arg);
}

std::string getCommandLineFlagDesc(CmdLineArgs arg) {
    throw new std::runtime_error("Not implemented yet!"); 
}
