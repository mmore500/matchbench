#include <iostream>

#define PICOBENCH_IMPLEMENT
#include "../third-party/picobench/include/picobench/picobench.hpp"

#include "matchbench/config/thread_local_config.hpp"
#include "matchbench/config/setup_config_native.hpp"
#include "matchbench/bm_task_mix.hpp"

int main(int argc, char* argv[]) {

  // Set up a configuration panel for native application
  setup_config_native(matchbench::thread_local_config, argc, argv);
  matchbench::thread_local_config.Write(std::cout);

  picobench::runner runner;
  return runner.run();
}

PICOBENCH(matchbench::bm_task_mix).samples(10000).iterations({1000});
