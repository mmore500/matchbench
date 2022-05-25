#pragma once
#ifndef MATCHBENCH_CONFIG_SETUP_CONFIG_NATIVE_HPP_INCLUDE
#define MATCHBENCH_CONFIG_SETUP_CONFIG_NATIVE_HPP_INCLUDE

#include "Empirical/include/emp/config/ArgManager.hpp"

#include "try_read_config_file.hpp"

namespace matchbench {

void setup_config_native(matchbench::Config & config, int argc, char* argv[]) {
  auto specs = emp::ArgManager::make_builtin_specs(&config);
  emp::ArgManager am(argc, argv, specs);
  matchbench::try_read_config_file(config, am);
}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_CONFIG_SETUP_CONFIG_NATIVE_HPP_INCLUDE
