#pragma once
#ifndef MATCHBENCH_BENCHMARK_BENCHMARK_ALSO_BASELINE_HPP_INCLUDE
#define MATCHBENCH_BENCHMARK_BENCHMARK_ALSO_BASELINE_HPP_INCLUDE

#include "../../../third-party/nanobench/src/include/nanobench.h"

namespace matchbench {

// handle to perform benchmark on baseline source code
void benchmark_also_baseline(ankerl::nanobench::Bench&);

} // namespace matchbench

#endif // #ifndef MATCHBENCH_BENCHMARK_BENCHMARK_ALSO_BASELINE_HPP_INCLUDE
