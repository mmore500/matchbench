#pragma once
#ifndef MATCHBENCH_BENCHMARK_BENCHMARK_HPP_INCLUDE
#define MATCHBENCH_BENCHMARK_BENCHMARK_HPP_INCLUDE

#include <emp/math/Random.hpp>

#include "../../../third-party/nanobench/src/include/nanobench.h"

#include "../task/do_task_mix.hpp"
#include "../typedef/MatchDepository.hpp"

#include "setup_depository.hpp"

namespace matchbench {

// feed do_task_mix to nanobench
static void benchmark(
  ankerl::nanobench::Bench& bench,
  const std::string& name
) {

  // set up a vector of depositories for us to cycle over and operate on
  // (meant to model the realistic scenario where we would be
  // switching between operations on different depositories in a population)
  const auto& cfg = matchbench::thread_local_config;
  emp::vector<MatchDepository> depositories;
  std::generate_n(
    std::back_inserter(depositories),
    cfg.NUM_DEPOSITORIES(),
    matchbench::setup_depository
  );

  // state for benchmark
  size_t depository_idx{};
  emp::Random rand(1);

  // have nanobench call and measure do_task_mix
  bench.run(
    name,
    [&](){
      matchbench::do_task_mix(depositories[depository_idx], rand);
      // each replicate measurement is performend on the next depository
      ++depository_idx %= depositories.size();
    }
  );

}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_BENCHMARK_BENCHMARK_HPP_INCLUDE
