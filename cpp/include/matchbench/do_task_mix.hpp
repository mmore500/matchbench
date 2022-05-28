#pragma once
#ifndef MATCHBENCH_DO_TASK_MIX_HPP_INCLUDE
#define MATCHBENCH_DO_TASK_MIX_HPP_INCLUDE

#include <iostream>

#include "config/thread_local_config.hpp"

#include "do_lookup_task.hpp"
#include "do_regulate_task.hpp"

namespace matchbench {

template<typename Depository>
void do_task_mix(Depository& depository) {

  const auto& cfg = matchbench::thread_local_config;

  for (size_t i{}; i < cfg.NUM_REGULATION_IN_TASK_MIX(); ++i) {
    matchbench::do_regulate_task(depository);
  }

  for (size_t i{}; i < cfg.NUM_LOOKUP_IN_TASK_MIX(); ++i) {
    matchbench::do_lookup_task(depository);
  }

}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_DO_TASK_MIX_HPP_INCLUDE
