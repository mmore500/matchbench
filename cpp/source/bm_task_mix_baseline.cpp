#include "../third-party/picobench/include/picobench/picobench.hpp"

#include "matchbench/bm_task_mix_control.hpp"
#include "matchbench/bm_task_mix.hpp"

namespace matchbench {

void bm_task_mix_baseline(picobench::state& state) {
  matchbench::bm_task_mix(state);
}

} //namespace matchbench
