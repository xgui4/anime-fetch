#pragma once

#include <string>

enum class CmdLineArgs;

class LibConfig {
public : 
  const std::string LIBRARY_NAME = "Anime-Fetch-Lib";
  const std::string REPO_LINK = "https://github.com/xgui4/anime-fetch";
  const std::string REPO_LINK_LABEL = "https://github.com/xgui4/anime-fetch";
  const std::string APP_VERSION = "0.0.0.0";
  const std::string LICENSE_INFO = "GPLv3 License";

  std::string getCommandLineFlag(CmdLineArgs arg);

  /*
  @Note Not implemented yet
  */
  std::string getCommandLineFlagDesc(CmdLineArgs arg);
};