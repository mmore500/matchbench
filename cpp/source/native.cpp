#include <iostream>

#include "Empirical/include/emp/base/vector.hpp"

#include "matchbench/config/Config.hpp"
#include "matchbench/config/setup_config_native.hpp"
#include "matchbench/example.hpp"

// This is the main function for the NATIVE version of CSE 491 Matching Benchmark.

matchbench::Config cfg;

int main(int argc, char* argv[]) {
  // Set up a configuration panel for native application
  setup_config_native(cfg, argc, argv);
  cfg.Write(std::cout);

  std::cout << "Hello, world!" << "\n";

  return matchbench::example();
}
