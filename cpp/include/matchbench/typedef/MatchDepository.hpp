#pragma once
#ifndef MATCHBENCH_TYPEDEF_MATCHDEPOSITORY_HPP_INCLUDE
#define MATCHBENCH_TYPEDEF_MATCHDEPOSITORY_HPP_INCLUDE

#include <emp/matching/MatchDepository.hpp>
#include <emp/matching/matchbin_metrics.hpp>
#include <emp/matching/selectors_static/RankedSelector.hpp>
#include <emp/matching/regulators/PlusCountdownRegulator.hpp>

namespace matchbench {

using MatchDepository = emp::MatchDepository<
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
>;

} // namespace matchbench

#endif // #ifndef MATCHBENCH_TYPEDEF_MATCHDEPOSITORY_HPP_INCLUDE
