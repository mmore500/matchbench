#include <chrono>
#include <iostream>

#define ANKERL_NANOBENCH_IMPLEMENT
#include "../third-party/picobench/include/picobench/picobench.hpp"

#include "matchbench/benchmark/benchmark_also_baseline.hpp"
#include "matchbench/benchmark/benchmark_baseline.hpp"
#include "matchbench/benchmark/benchmark_control.hpp"
#include "matchbench/benchmark/benchmark_fiddle.hpp"
#include "matchbench/config/thread_local_config.hpp"
#include "matchbench/config/setup_config_native.hpp"

int main(int argc, char* argv[]) {

  // Set up a configuration panel for native application
  setup_config_native(matchbench::thread_local_config, argc, argv);
  matchbench::thread_local_config.Write(std::cout);

  ankerl::nanobench::Bench bench;

  // setup benchmark infrastructure
  bench.title(
    "Empirical Implementations"
  ).unit(
    "task composite"
  ).warmup(
    100
  ).relative(
    true
  ).minEpochTime(
    std::chrono::milliseconds{100}
  ).maxEpochTime(
    std::chrono::milliseconds{200}
  );
  bench.performanceCounters(
    true
  );

  // run benchmarks
  matchbench::benchmark_baseline(bench);
  matchbench::benchmark_control(bench);
  matchbench::benchmark_fiddle(bench);
  matchbench::benchmark_also_baseline(bench);

  // print end separator
  for (size_t i{}; i < 200; ++i) std::cout << '=';
  std::cout << '\n' << '\n' << '\n';

  return 0;
}
