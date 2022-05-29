// redefine emp namespace to prevent ODR violations
#define emp emp_control
#define control

#include "../third-party/nanobench/src/include/nanobench.h"

#include "matchbench/benchmark/benchmark_control.hpp"
#include "matchbench/benchmark/benchmark.hpp"

namespace matchbench {

// handle to perform benchmark on control source code
// (should run slower than baseline)
void benchmark_control(ankerl::nanobench::Bench& bench) {
  matchbench::benchmark(bench, "control");
}

} //namespace matchbench
