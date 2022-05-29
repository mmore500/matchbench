#include <iostream>

#define PICOBENCH_IMPLEMENT
#include "../third-party/picobench/include/picobench/picobench.hpp"

#include "matchbench/benchmark/benchmark_baseline.hpp"
#include "matchbench/benchmark/benchmark_control.hpp"
#include "matchbench/benchmark/benchmark_fiddle.hpp"
#include "matchbench/config/thread_local_config.hpp"
#include "matchbench/config/setup_config_native.hpp"

int main(int argc, char* argv[]) {

  // Set up a configuration panel for native application
  setup_config_native(matchbench::thread_local_config, argc, argv);
  matchbench::thread_local_config.Write(std::cout);

  picobench::runner runner;
  return runner.run();
}

PICOBENCH(matchbench::benchmark_baseline).samples(1000).iterations({1000});
PICOBENCH(matchbench::benchmark_control).samples(1000).iterations({1000});
PICOBENCH(matchbench::benchmark_fiddle).samples(1000).iterations({1000});
// add redundant baseline benchmark to account for measurement effects
PICOBENCH(matchbench::benchmark_baseline).samples(1000).iterations({1000});
