#pragma once
#ifndef MATCHBENCH_BENCHMARK_BENCHMARK_HPP_INCLUDE
#define MATCHBENCH_BENCHMARK_BENCHMARK_HPP_INCLUDE

#include <emp/math/Random.hpp>

#include "../../../third-party/nanobench/src/include/nanobench.h"

#include "../task/do_task_mix.hpp"
#include "../typedef/MatchDepository.hpp"

#include "setup_depository.hpp"

namespace matchbench {

static void benchmark(
  ankerl::nanobench::Bench& bench,
  const std::string& name
) {

  emp::vector<MatchDepository> depositories;

  const auto& cfg = matchbench::thread_local_config;

  std::generate_n(
    std::back_inserter(depositories),
    cfg.NUM_DEPOSITORIES(),
    matchbench::setup_depository
  );

  size_t depository_idx{};
  emp::Random rand(1);

  bench.run(
    name,
    [&](){
      matchbench::do_task_mix(depositories[depository_idx], rand);
      ++depository_idx %= depositories.size();
    }
  );

}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_BENCHMARK_BENCHMARK_HPP_INCLUDE
