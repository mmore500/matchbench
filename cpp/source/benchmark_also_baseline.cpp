// redefine emp namespace to prevent ODR violations
#define emp emp_also_baseline

#include "../third-party/nanobench/src/include/nanobench.h"

#include "matchbench/benchmark/benchmark_also_baseline.hpp"
#include "matchbench/benchmark/benchmark.hpp"

namespace matchbench {

// handle to perform benchmark on baseline source code
void benchmark_also_baseline(ankerl::nanobench::Bench& bench) {
  matchbench::benchmark(bench, "also_baseline");
}

} //namespace matchbench
