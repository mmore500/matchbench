// redefine emp namespace to prevent ODR violations
#define emp emp_fiddle
#define fiddle

#include "../third-party/nanobench/src/include/nanobench.h"

#include "matchbench/benchmark/benchmark_fiddle.hpp"
#include "matchbench/benchmark/benchmark.hpp"

namespace matchbench {

// handle to perform benchmark on "fiddle" source code for experimentation
// (hopefully can be improved to run faster than baseline)
void benchmark_fiddle(ankerl::nanobench::Bench& bench) {
  matchbench::benchmark(bench, "fiddle");
}

} //namespace matchbench
