#pragma once
#ifndef MATCHBENCH_SAMPLE_QUERY_TAG_HPP_INCLUDE
#define MATCHBENCH_SAMPLE_QUERY_TAG_HPP_INCLUDE

#include "../../third-party/Empirical/include/emp/bits/BitSet.hpp"

#include "config/thread_local_config.hpp"

namespace matchbench {

namespace impl {

// adapted from https://stackoverflow.com/a/6867612/17332200
uint64_t hash(uint64_t key) {

  key ^= key >> 33;
  key *= 0xff51afd7ed558ccd;
  key ^= key >> 33;
  key *= 0xc4ceb9fe1a85ec53;
  key ^= key >> 33;

  return key;

}

} // namespace impl

auto sample_query_tag() {

  const auto& cfg = matchbench::thread_local_config;

  // cycle through n arbitrary query tags
  // in random order, with replacement
  thread_local emp::Random rand(1);
  const uint64_t cur_tag_idx = rand.GetUInt64(cfg.QUERY_POOL_SIZE());
  const uint64_t cur_tag_bits = impl::hash(cur_tag_idx);

  return emp::BitSet<64>(cur_tag_bits);

}

}

#endif // #ifndef MATCHBENCH_SAMPLE_QUERY_TAG_HPP_INCLUDE
