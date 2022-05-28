#pragma once
#ifndef MATCHBENCH_UTIL_SCRAMBLE_HPP_INCLUDE
#define MATCHBENCH_UTIL_SCRAMBLE_HPP_INCLUDE

namespace matchbench {

// adapted from https://stackoverflow.com/a/6867612/17332200
inline uint64_t scramble(uint64_t key) {
  key ^= key >> 33;
  key *= 0xff51afd7ed558ccd;
  key ^= key >> 33;
  key *= 0xc4ceb9fe1a85ec53;
  key ^= key >> 33;

  return key;
}

} // namespace matchbench

#endif // #ifndef MATCHBENCH_UTIL_SCRAMBLE_HPP_INCLUDE
