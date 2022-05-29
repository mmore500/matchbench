#pragma once
#ifndef MATCHBENCH_BM_TASK_MIX_HPP_INCLUDE
#define MATCHBENCH_BM_TASK_MIX_HPP_INCLUDE

#include "../../../third-party/picobench/include/picobench/picobench.hpp"

#include "../task/do_task_mix.hpp"
#include "../typedef/MatchDepository.hpp"

#include "setup_depository.hpp"

namespace matchbench {

static void benchmark(picobench::state& state) {

  emp::vector<MatchDepository> depositories;

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
