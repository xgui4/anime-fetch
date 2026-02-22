#include <stdexcept>
#include <string>
#include "app_config.h"
#include "cmd_args.h"

std::string AppConfig::getCommandLineFlag(CmdLineArgs arg) {
  return ARGS_LISTS.at((int)arg);
}

std::string AppConfig::getCommandLineFlagDesc(CmdLineArgs arg) {
  throw new std::runtime_error("Not implemented yet!");
}
