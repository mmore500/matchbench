#define emp emp_control

#include "../third-party/nanobench/src/include/nanobench.h"

#include "matchbench/benchmark/benchmark_control.hpp"
#include "matchbench/benchmark/benchmark.hpp"

namespace matchbench {

void benchmark_control(ankerl::nanobench::Bench& bench) {
  matchbench::benchmark(bench, "control");
}

} //namespace matchbench
