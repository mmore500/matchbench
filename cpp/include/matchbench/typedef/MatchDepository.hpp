#pragma once
#ifndef MATCHBENCH_TYPEDEF_MATCHDEPOSITORY_HPP_INCLUDE
#define MATCHBENCH_TYPEDEF_MATCHDEPOSITORY_HPP_INCLUDE

// allow MatchDepository typedef to be overridden separately
// for baseline, control, and fiddle

#ifdef also_baseline
#include "baseline/MatchDepository.hpp"
#endif

#ifdef baseline
#include "baseline/MatchDepository.hpp"
#endif

#ifdef control
#include "control/MatchDepository.hpp"
#endif

#ifdef fiddle
#include "fiddle/MatchDepository.hpp"
#endif

#endif // #ifndef MATCHBENCH_TYPEDEF_MATCHDEPOSITORY_HPP_INCLUDE
