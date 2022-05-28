#include "../third-party/picobench/include/picobench/picobench.hpp"

#include "matchbench/benchmark/benchmark_control.hpp"
#include "matchbench/benchmark/benchmark.hpp"

namespace matchbench {

void benchmark_baseline(picobench::state& state) {
  matchbench::benchmark(state);
}

} //namespace matchbench
