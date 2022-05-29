#pragma once
#ifndef MATCHBENCH_BENCHMARK_SETUP_DEPOSITORY_HPP_INCLUDE
#define MATCHBENCH_BENCHMARK_SETUP_DEPOSITORY_HPP_INCLUDE

#include <emp/math/Random.hpp>

#include "../config/thread_local_config.hpp"
#include "../typedef/BitSet.hpp"
#include "../typedef/MatchDepository.hpp"

namespace matchbench {

// generate a new tag depository to perform lookups in
// populate it with random tag-value pairs
static auto setup_depository() {

  matchbench::MatchDepository depository;

  const auto& cfg = matchbench::thread_local_config;
  thread_local emp::Random random(1);

  // fill up depository with randomly-generated tag-value pairs
  for (size_t i{}; i < cfg.TARGET_POOL_SIZE(); ++i) depository.Put(
    random.GetUInt(), // value
    matchbench::BitSet(random) // tag
  );

  return depository;
}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_BENCHMARK_SETUP_DEPOSITORY_HPP_INCLUDE
