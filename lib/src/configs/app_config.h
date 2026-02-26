#pragma once

#include <string>

enum class CmdLineArgs;

struct AppConfig {
  const std::string APP_NAME = "Anime-Fetch";
  const std::string REPO_LINK = "https://github.com/xgui4/anime-fetch";
  const std::string REPO_LINK_LABEL = "https://github.com/xgui4/anime-fetch";
  const std::string VERSION = "0.0.0.0";
  const std::string LICENSE_INFO = "GPLv3 License";

  std::string getCommandLineFlag(CmdLineArgs arg);

  /*
  @Note Not implemented yet
  */
  std::string getCommandLineFlagDesc(CmdLineArgs arg);
};