#include "utils.hpp"
#include <string>

using std::string;

string exec(const char *cmd, const char *args[], const int argc) {

  string args_string = "";

  for (int i = 0; i < argc; i++) {
    args_string += (string) " " + args[i];
  }

  string full_cmd_string = cmd + args_string;

  const char *full_cmd = full_cmd_string.c_str();

  char buffer[128];

  string result = "";

  #ifdef __linux__
    FILE *pipe = popen(full_cmd, "r");
  #elif _WIN32
    FILE *pipe = _popen(full_cmd, "r");
  #endif
  if (!pipe) {
    return "Erreur";
  }

  while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
    result += buffer;
  }

#ifdef __linux__
  pclose(pipe);
#elif _WIN32
  _pclose(pipe);
#endif

  return result;
}

std::string bytes_to_gigabytes(long bytes) {
  const unsigned long long GIBIBYTE = 1024ULL * 1024ULL * 1024ULL;
  return std::to_string(static_cast<double>(bytes) / GIBIBYTE);
}
 