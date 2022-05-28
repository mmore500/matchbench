#pragma once
#ifndef MATCHBENCH_DO_LOOKUP_TASK_HPP_INCLUDE
#define MATCHBENCH_DO_LOOKUP_TASK_HPP_INCLUDE

#include "sample_query_tag.hpp"

// prevent lookup operations from being optimized out
inline volatile size_t val;

namespace matchbench {

template<typename Depository>
static void do_lookup_task(Depository& depository) {

  const auto query = matchbench::sample_query_tag();

  for ( const auto uid : depository.MatchRegulated(query) ) {
    val = depository.GetVal(uid);
  }

}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_DO_LOOKUP_TASK_HPP_INCLUDE
