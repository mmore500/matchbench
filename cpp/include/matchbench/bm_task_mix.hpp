#pragma once
#ifndef MATCHBENCH_BM_TASK_MIX_HPP_INCLUDE
#define MATCHBENCH_BM_TASK_MIX_HPP_INCLUDE

#include <iostream>

#include "../../third-party/picobench/include/picobench/picobench.hpp"

#include "do_task_mix.hpp"
#include "setup_depository.hpp"

namespace matchbench {

void bm_task_mix(picobench::state& state) {

  auto depository = matchbench::setup_depository();

  for (auto __ : state) matchbench::do_task_mix(depository);

}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_BM_TASK_MIX_HPP_INCLUDE
