#include <iostream>

#include "Empirical/include/emp/prefab/ConfigPanel.hpp"
#include "Empirical/include/emp/web/web.hpp"

#include "matchbench/config/Config.hpp"
#include "matchbench/config/setup_config_web.hpp"
#include "matchbench/example.hpp"

emp::web::Document doc("emp_base");

matchbench::Config cfg;

int main() {
  doc << "<h1>Hello, browser!</h1>";

  // Set up a configuration panel for web application
  setup_config_web(cfg);
  cfg.Write(std::cout);
  emp::prefab::ConfigPanel example_config_panel(cfg);
  doc << example_config_panel;

  std::cout << "Hello, console!" << '\n';

  return matchbench::example();
}
