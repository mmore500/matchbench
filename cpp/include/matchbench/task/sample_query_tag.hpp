#pragma once
#ifndef MATCHBENCH_SAMPLE_QUERY_TAG_HPP_INCLUDE
#define MATCHBENCH_SAMPLE_QUERY_TAG_HPP_INCLUDE

#include "../config/thread_local_config.hpp"
#include "../typedef/BitSet.hpp"
#include "../util/scramble.hpp"

namespace matchbench {

static auto sample_query_tag() {

  const auto& cfg = matchbench::thread_local_config;

  // cycle through n arbitrary query tags
  // in random order, with replacement
  thread_local emp::Random rand(1);
  const uint64_t cur_tag_idx = rand.GetUInt64(cfg.QUERY_POOL_SIZE());
  const uint64_t cur_tag_bits = matchbench::scramble(cur_tag_idx);


  return matchbench::BitSet(cur_tag_bits);

}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_SAMPLE_QUERY_TAG_HPP_INCLUDE
