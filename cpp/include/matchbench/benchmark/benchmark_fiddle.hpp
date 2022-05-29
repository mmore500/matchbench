#pragma once
#ifndef MATCHBENCH_BENCHMARK_BENCHMARK_FIDDLE_HPP_INCLUDE
#define MATCHBENCH_BENCHMARK_BENCHMARK_FIDDLE_HPP_INCLUDE

#include "../../../third-party/nanobench/src/include/nanobench.h"

namespace matchbench {

// handle to perform benchmark on "fiddle" source code for experimentation
// (hopefully can be improved to run faster than baseline)
void benchmark_fiddle(ankerl::nanobench::Bench&);

} // namespace matchbench

#endif // #ifndef MATCHBENCH_BENCHMARK_BENCHMARK_FIDDLE_HPP_INCLUDE
