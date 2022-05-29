#pragma once
#ifndef MATCHBENCH_CONFIG_CONFIG_HPP_INCLUDE
#define MATCHBENCH_CONFIG_CONFIG_HPP_INCLUDE

#include <emp/config/config.hpp>

namespace matchbench {

  EMP_BUILD_CONFIG(Config,
    GROUP(BENCHMARK, "Benchmark settings"),
    VALUE(QUERY_POOL_SIZE, size_t, 16,
      "Number of distinct query tags used. "
      "(Query tags are used to perform lookups on target tags inside match " "depository.)"
    ),
    VALUE(TARGET_POOL_SIZE, size_t, 64,
      "Number of distinct target tags used. "
      "(Target tags are looked-up inside the match depository using query "
      "tags.)"
    ),
    VALUE(NUM_LOOKUP_IN_TASK_MIX, size_t, 1,
      "How many lookup operations should be performed inside benchmark?"
    ),
    VALUE(NUM_REGULATION_IN_TASK_MIX, size_t, 1,
      "How many regulation operations should be performed inside benchmark?"
    ),
    VALUE(NUM_DEPOSITORIES, size_t, 64,
      "How many different depositories should be interleaved?"
    ),
  );

} // namespace matchbench {

#endif // #ifndef MATCHBENCH_CONFIG_CONFIG_HPP_INCLUDE
