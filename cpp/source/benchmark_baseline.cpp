#define emp emp_baseline

#include "../third-party/nanobench/src/include/nanobench.h"

#include "matchbench/benchmark/benchmark_baseline.hpp"
#include "matchbench/benchmark/benchmark.hpp"

namespace matchbench {

void benchmark_baseline(ankerl::nanobench::Bench& bench) {
  matchbench::benchmark(bench, "baseline");
}

} //namespace matchbench
