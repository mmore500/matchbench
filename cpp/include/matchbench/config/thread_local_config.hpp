#pragma once
#ifndef MATCHBENCH_CONFIG_THREAD_LOCAL_CONFIG_HPP_INCLUDE
#define MATCHBENCH_CONFIG_THREAD_LOCAL_CONFIG_HPP_INCLUDE

#include "Config.hpp"

namespace matchbench {

// probably not interesting
// just boilerplate to handle configuraiton options
inline thread_local matchbench::Config thread_local_config{};

} // namespace matchbench

#endif // #ifndef MATCHBENCH_CONFIG_THREAD_LOCAL_CONFIG_HPP_INCLUDE
