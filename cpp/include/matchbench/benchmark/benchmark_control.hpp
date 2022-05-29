#pragma once
#ifndef MATCHBENCH_BENCHMARK_BENCHMARK_CONTROL_HPP_INCLUDE
#define MATCHBENCH_BENCHMARK_BENCHMARK_CONTROL_HPP_INCLUDE

#include "../../../third-party/picobench/include/picobench/picobench.hpp"

namespace matchbench {

void benchmark_control(picobench::state& state);

} // namespace matchbench

#endif // #ifndef MATCHBENCH_BENCHMARK_BENCHMARK_CONTROL_HPP_INCLUDE
