#pragma once
#ifndef MATCHBENCH_TASK_DO_LOOKUP_TASK_HPP_INCLUDE
#define MATCHBENCH_TASK_DO_LOOKUP_TASK_HPP_INCLUDE

#include <emp/math/Random.hpp>

#include "sample_query_tag.hpp"

// prevent lookup operations from being optimized out
inline volatile size_t val;

namespace matchbench {

template<typename Depository>
static void do_lookup_task(
  Depository& depository,
  emp::Random& rand
) {

  const auto query = matchbench::sample_query_tag(rand);

  for ( const auto uid : depository.MatchRegulated(query) ) {
    val = depository.GetVal(uid);
  }

}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_TASK_DO_LOOKUP_TASK_HPP_INCLUDE
