#pragma once
#ifndef MATCHBENCH_CONFIG_SETUP_CONFIG_WEB_HPP_INCLUDE
#define MATCHBENCH_CONFIG_SETUP_CONFIG_WEB_HPP_INCLUDE

#include <emp/config/ArgManager.hpp>
#include <emp/web/UrlParams.hpp>
#include <emp/web/web.hpp>

#include "Config.hpp"
#include "try_read_config_file.hpp"

namespace matchbench {

inline void setup_config_web(matchbench::Config & config)  {
  auto specs = emp::ArgManager::make_builtin_specs(&config);
  emp::ArgManager am(emp::web::GetUrlParams(), specs);
  matchbench::try_read_config_file(config, am);
}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_CONFIG_SETUP_CONFIG_WEB_HPP_INCLUDE
