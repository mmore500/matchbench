#define emp emp_fiddle

#include "../third-party/nanobench/src/include/nanobench.h"

#include "matchbench/benchmark/benchmark_fiddle.hpp"
#include "matchbench/benchmark/benchmark.hpp"

namespace matchbench {

void benchmark_fiddle(ankerl::nanobench::Bench& bench) {
  matchbench::benchmark(bench, "fiddle");
}

} //namespace matchbench
