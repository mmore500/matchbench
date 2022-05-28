#pragma once
#ifndef MATCHBENCH_BM_TASK_MIX_HPP_INCLUDE
#define MATCHBENCH_BM_TASK_MIX_HPP_INCLUDE

#include <iostream>

#include "../../third-party/picobench/include/picobench/picobench.hpp"

#include "do_task_mix.hpp"
#include "setup_depository.hpp"

namespace matchbench {

void bm_task_mix(picobench::state& state) {

  using depository_t = decltype(matchbench::setup_depository());
  emp::vector<depository_t> depositories;
  const auto& cfg = matchbench::thread_local_config;

  std::generate_n(
    std::back_inserter(depositories),
    cfg.NUM_DEPOSITORIES(),
    matchbench::setup_depository
  );

  size_t depository_idx{};

  for (auto __ : state) {
    matchbench::do_task_mix(depositories[depository_idx]);
    ++depository_idx %= depositories.size();
  }

}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_BM_TASK_MIX_HPP_INCLUDE
