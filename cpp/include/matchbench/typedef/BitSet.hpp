#pragma once
#ifndef MATCHBENCH_TYPEDEF_BITSET_HPP_INCLUDE
#define MATCHBENCH_TYPEDEF_BITSET_HPP_INCLUDE

#include "emp/bits/BitSet.hpp"

// anonymous namespace and inheritance ensure that different
// implementations are preserved across translation units
// see https://stackoverflow.com/a/44346057/17332200

namespace matchbench {
namespace { // anonymous namespace

using BitSet_parent_t = emp::BitSet<64>;

class BitSet : public BitSet_parent_t {
  // inherit constructors
  using BitSet_parent_t::BitSet_parent_t;
};

} // anonymous namespace
} // namespace matchbench

#endif // #ifndef MATCHBENCH_TYPEDEF_BITSET_HPP_INCLUDE
