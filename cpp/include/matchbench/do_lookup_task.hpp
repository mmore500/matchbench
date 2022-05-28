#pragma once
#ifndef MATCHBENCH_DO_LOOKUP_TASK_HPP_INCLUDE
#define MATCHBENCH_DO_LOOKUP_TASK_HPP_INCLUDE

#include <iostream>

#include "sample_query_tag.hpp"

volatile size_t val;

namespace matchbench {

template<typename Depository>
void do_lookup_task(Depository& depository) {

  const auto query = matchbench::sample_query_tag();

  for ( const auto uid : depository.MatchRegulated(query) ) {
    val = depository.GetVal(uid);
  }

}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_DO_LOOKUP_TASK_HPP_INCLUDE
