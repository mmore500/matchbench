// redefine emp namespace to prevent ODR violations
#define emp emp_baseline
#define baseline

#include "../third-party/nanobench/src/include/nanobench.h"

#include "matchbench/benchmark/benchmark_baseline.hpp"
#include "matchbench/benchmark/benchmark.hpp"

namespace matchbench {

// handle to perform benchmark on baseline source code
void benchmark_baseline(ankerl::nanobench::Bench& bench) {
  matchbench::benchmark(bench, "baseline");
}

} //namespace matchbench
