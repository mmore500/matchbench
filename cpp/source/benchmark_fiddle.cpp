#include "../third-party/picobench/include/picobench/picobench.hpp"

#include "matchbench/benchmark/benchmark_fiddle.hpp"
#include "matchbench/benchmark/benchmark.hpp"

namespace matchbench {

void benchmark_fiddle(picobench::state& state) {
  matchbench::benchmark(state);
}

} //namespace matchbench
