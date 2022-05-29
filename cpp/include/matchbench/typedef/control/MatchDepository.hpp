#pragma once
#ifndef MATCHBENCH_TYPEDEF_CONTROL_MATCHDEPOSITORY_HPP_INCLUDE
#define MATCHBENCH_TYPEDEF_CONTROL_MATCHDEPOSITORY_HPP_INCLUDE

#include <emp/matching/MatchDepository.hpp>
#include <emp/matching/matchbin_metrics.hpp>
#include <emp/matching/selectors_static/RankedSelector.hpp>
#include <emp/matching/regulators/PlusCountdownRegulator.hpp>

namespace matchbench {
namespace {

// typedef tag-matching data structure
// it's like a dictionary where keys are bitstring tags
// and values (in this case) are size_t's

// lookups are performed using a query tag
// the best-matching target tag inside the data structure is found
// and the value associated with that target tag is returned

// it's called a "depository" because key-value pairs
// can be added but cannot be deleted
using MatchDepository = emp::MatchDepository<
  size_t, // value type
  // how should "how well" a query tag and a stored tag match be
  // measured?
  // this measure compares the longest continuously-matching and
  // continuously-mismatching sequence of bits between two tags
  emp::ApproxDualStreakMetric<64>, // tag-matching metric w/ 64-bit tags
  // alternate faster-to-compute tag-matching metric
  // emp::HammingMetric<64>, // tag-matching metric w/ 64-bit tags
  emp::statics::RankedSelector<>, // return the best-matching tag
  // what policy should be used to control
  // how regulation affect matching?
  // (individual stored tags can be up- or down-regulated
  // to make them more or less likely to match to a query)
  emp::PlusCountdownRegulator<
    std::deci, // Slope
    std::ratio<1,4>, // MaxUpreg
    std::deci, // ClampLeeway
    2 // (for intermittently resetting regulation, not used here)
  >,
  // IMPORTANT
  // enable cache for raw tag queries (i.e., no regulation considered)
  // cache stores lookup tag and returned tag
  //
  // either all queries are cached forever
  // or nothing is cached
  // (raw tag lookup cache is never invalidated)
  true,
  // IMPORTANT
  // set max cache capacity for regulated tag queries
  // cache stores lookup tag and returned tag
  //
  // a fifo cache is used
  // (regulated tag lookup cache is frequently invalidated by
  // subsequent regulation adjustments)
  0 // regulated lookup cache size, disabled
>;

}
} // namespace matchbench

#endif // #ifndef MATCHBENCH_TYPEDEF_CONTROL_MATCHDEPOSITORY_HPP_INCLUDE
