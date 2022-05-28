#pragma once
#ifndef MATCHBENCH_SETUP_DEPOSITORY_HPP_INCLUDE
#define MATCHBENCH_SETUP_DEPOSITORY_HPP_INCLUDE

#include <iostream>

#include "../../third-party/Empirical/include/emp/matching/MatchDepository.hpp"
#include "../../third-party/Empirical/include/emp/matching/matchbin_metrics.hpp"
#include "../../third-party/Empirical/include/emp/matching/selectors_static/RankedSelector.hpp"
#include "../../third-party/Empirical/include/emp/matching/regulators/PlusCountdownRegulator.hpp"
#include "../../third-party/Empirical/include/emp/math/Random.hpp"

#include "config/thread_local_config.hpp"

namespace matchbench {

auto setup_depository() {

  emp::MatchDepository<
    size_t, // value type
    emp::ApproxDualStreakMetric<64>, // tag-matching metric w/ 64-bit tags
    // emp::HammingMetric<64>, // tag-matching metric w/ 64-bit tags
    emp::statics::RankedSelector<>, // return the best-matching tag
    emp::PlusCountdownRegulator<
      std::deci, // Slope
      std::ratio<1,4>, // MaxUpreg
      std::deci, // ClampLeeway
      2 // CountdownStart
    >, // how should regulation affect matching?
    true, // enable raw tag lookup cache
    0 // regulated lookup cache size, disabled
  > depository;

  using tag_t = emp::BitSet<64>;
  const auto& cfg = matchbench::thread_local_config;
  thread_local emp::Random random(1);

  // fill up depository with randomly-generated tag-value pairs
  for (size_t i{}; i < cfg.TARGET_POOL_SIZE(); ++i) depository.Put(
    random.GetUInt(), // value
    tag_t(random) // tag
  );

  return depository;
}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_SETUP_DEPOSITORY_HPP_INCLUDE
