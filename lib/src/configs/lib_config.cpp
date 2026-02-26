#include <stdexcept>
#include <string>
#include "lib_config.h"
#include "cmd_args.h"

std::string LibConfig::getCommandLineFlag(CmdLineArgs arg) {
  return ARGS_LISTS.at((int)arg);
}

std::string LibConfig::getCommandLineFlagDesc(CmdLineArgs arg) {
  throw new std::runtime_error("Not implemented yet!");
}
