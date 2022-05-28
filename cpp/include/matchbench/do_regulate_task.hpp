#pragma once
#ifndef MATCHBENCH_DO_REGULATE_TASK_HPP_INCLUDE
#define MATCHBENCH_DO_REGULATE_TASK_HPP_INCLUDE

#include <iostream>

#include "sample_query_tag.hpp"

namespace matchbench {

template<typename Depository>
void do_regulate_task(Depository& depository) {

  const auto query = matchbench::sample_query_tag();

  for ( const auto uid : depository.MatchRaw(query) ) {
    depository.AdjRegulator(
      uid, // which tag to upregulate
      1 // arbitrary downregulation amount
    );
  }

}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_DO_REGULATE_TASK_HPP_INCLUDE
