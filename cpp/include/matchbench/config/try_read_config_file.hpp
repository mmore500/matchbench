#pragma once
#ifndef MATCHBENCH_CONFIG_TRY_READ_CONFIG_FILE_HPP_INCLUDE
#define MATCHBENCH_CONFIG_TRY_READ_CONFIG_FILE_HPP_INCLUDE

#include <cstdlib>
#include <filesystem>
#include <iostream>

#include "Config.hpp"

namespace matchbench {

inline void try_read_config_file(matchbench::Config & config, emp::ArgManager & am) {
  if (std::filesystem::exists("matchbench.cfg")) {
    std::cout << "Configuration read from matchbench.cfg" << '\n';
    config.Read("matchbench.cfg");
  }
  am.UseCallbacks();
  if (am.HasUnused()) std::exit(EXIT_FAILURE);
}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_CONFIG_TRY_READ_CONFIG_FILE_HPP_INCLUDE
