#pragma once
#ifndef MATCHBENCH_BENCHMARK_BENCHMARK_CONTROL_HPP_INCLUDE
#define MATCHBENCH_BENCHMARK_BENCHMARK_CONTROL_HPP_INCLUDE

#include "../../../third-party/nanobench/src/include/nanobench.h"

namespace matchbench {

// handle to perform benchmark on control source code
// (should run slower than baseline)
void benchmark_control(ankerl::nanobench::Bench&);

} // namespace matchbench

#endif // #ifndef MATCHBENCH_BENCHMARK_BENCHMARK_CONTROL_HPP_INCLUDE
