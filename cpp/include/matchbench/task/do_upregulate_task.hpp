#pragma once
#ifndef MATCHBENCH_TASK_DO_UPREGULATE_TASK_HPP_INCLUDE
#define MATCHBENCH_TASK_DO_UPREGULATE_TASK_HPP_INCLUDE

#include <emp/math/Random.hpp>

#include "sample_query_tag.hpp"

namespace matchbench {

// do a single unit of regulation work, drawing an arbitrary query tag
// and upregulating the target tag it maches to
template<typename Depository>
static void do_upregulate_task(
  Depository& depository,
  emp::Random& rand
) {

  const auto query = matchbench::sample_query_tag(rand);

  for ( const auto uid : depository.MatchRaw(query) ) {
    depository.AdjRegulator(
      uid, // which tag to upregulate
      -0.2 // arbitrary downregulation amount
    );
  }

}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_TASK_DO_UPREGULATE_TASK_HPP_INCLUDE
