[![version](https://img.shields.io/endpoint?url=https%3A%2F%2Fmmore500.github.io%2Fmatchbench%2Fversion-badge.json)](https://github.com/mmore500/matchbench/releases)
[![GitHub Actions Status](https://github.com/mmore500/matchbench/actions/workflows/CI/badge.svg)](https://github.com/mmore500/matchbench/actions/workflows/CI/)
[![Documentation Status](https://readthedocs.org/projects/matchbench/badge/?version=latest)](https://matchbench.readthedocs.io/en/latest/?badge=latest)
[![documentation coverage](https://img.shields.io/endpoint?url=https%3A%2F%2Fmmore500.github.io%2Fmatchbench%2Fdocumentation-coverage-badge.json)](https://matchbench.readthedocs.io/en/latest/)
[![code coverage status](https://codecov.io/gh/mmore500/matchbench/branch/master/graph/badge.svg)](https://codecov.io/gh/mmore500/matchbench)
[![dotos](https://img.shields.io/endpoint?url=https%3A%2F%2Fmmore500.com%2Fmatchbench%2Fdoto-badge.json)](https://github.com/mmore500/matchbench/search?q=todo+OR+fixme&type=)
[![GitHub stars](https://img.shields.io/github/stars/mmore500/matchbench.svg?style=flat-square&logo=github&label=Stars&logoColor=white)](https://github.com/mmore500/matchbench)

Tag-matching benchmark boilerplate for CSE 491.


-   Free software: MIT license

# Quickstart

Be sure to clone recursively & don't be concerned if it takes a mintue or two, there are a lot of submodules.
```bash
git clone --recursive https://github.com/mmore500/matchbench.git
cd matchbench/cpp
make
./benchmark_suite.sh
```

To switch compilers
```bash
make clean
export CXX=g++
make
```

# Tag-Matching Recap

In evolutionary programming, it is important to be able to match queries to an available set of objects in a dynamic, flexible way (e.g., an "environmental signal" to a program module defined in a digital genome).
A good way to do this is a tag-matching process, where a query tag is compared to a set of available tagged operands.
The best-matching operand can be returned to the query.
It is especially useful to be able to incorporate "regulation" into this process so that, dynamically at runtime, tagged operands can be "upregulated" or "downregulated" to affect whether they are returned in response to queries.
Downregulated operands, for example, would be more likely to be outcompeted by other operands to be the answer to a query.

To enable this type of lookup, empirical provides a `emp::TagDepository` data structure.
(Termed so because tagged entities can be added but not removed.)
This data structure facilitates look ups where a best-matching tag or tag(s) are returned in response to query tags.

This `TagDepository` data structure is templated to allow for compile-time configuration, with three major components:
"Tag Depository" data structure
* tag comparison metric
  * How should we test how "well" two tags match?
  * example: interpret the tags as integers and take absolute difference
  * example: hamming distance between tags
  * example (slower but w/ promising evolutionary properties): "streak method" to compare longest-matching and -mismatching contiguous sequence of bits
* operand selection operator
  * How should we decide which tagged operands to return to a query?
  * example: top matching tag better than X threshold, otherwise no tag
  * example: top two matching tags
  * example: all tags better than X threshold
  * example: randomly with probability proportional to match quality
* tag regulation implementation
  * How should a tag's regulatory state (cumulative down or up regulation) affect its match score to queries?
  * untested idea: only allow complete deactivation of a tag
Due to the flexibility required to handle different operators and metrics, the TagDepository is basically just a vector of tag-operand pairs.
To perform a lookup, the query tag is compared against all operand tags using the configured comparison metric to generate a vector of match scores.
Then, the operand selection operator operates on those scores to decide which operand(s) should be yielded.

Some caching of responses to queries is possible (and performed), although regulation invalidates these cached responses.

We assume fixed-length bitstring tags.

This tag-matching process turns out to be the primary time-consumer in performance profiles for much of my work, so doing it more efficiently could have big tangible benefits.

# Possible Avenues for Optimization

You can look at the result of a flame graph profile I did [here](https://raw.githubusercontent.com/mmore500/matchbench/master/graph.svg), but it's not very informative.
Figuring out a better way to profile would be helpful.

1. vectorization

A large part of the run time is taking a query tags and comparing it against all operand tags to generate a vector of tag-match scores.
The operand tags are stored in sequential memory within the depository.

Seems like a good opportunity for vectorization, especially for simpler tag matching metrics like the hamming metric.
(Although more expensive metrics like longest contiguous matching sequence would benefit more, they seem possible less feasible to vectorize).

2. tag-matching metric

Because the metric is computed so often (between every query and all operands), performance is crucial.

3. caching

It is difficult to tune the caching policy, especially when work conditions
change over evolutionary time (expanding genomes, more/less regulation, etc.).
Some sort of auto-tuned caching system could be helpful here.

# Organization

The project is set up to compile benchmarks separately using three different Empirical library copies that can be edited fully independently:
1. `cpp/third-party/Empirical_baseline` (current best-performing code)
  * current best-performing code; for comparison purposes, don't change
2. `cpp/third-party/Empirical_control`
  * slower than baseline, to make sure benchmark is working correctly
3. `cpp/third-party/Empirical_fiddle`
  * current best-performing code; make changes here

Additionally, the `MatchDepository` template instantiation used can be edited directly just for the "fiddle" benchmark at `cpp/include/matchbench/typdef/fiddle/MatchDepository.hpp`.
(You can comment/uncomment some code here to switch out the "streak" tag distance metric for hamming distance.)

[Nanobench](https://github.com/martinus/nanobench) is used to benchmark each Empirical library copy.
For the microbenchark, a configurable-size randomly generated `MatchDepository` is prepared then configurable numbers of random lookup queries and regulation adjustments are made on that depository.
A duplicate baseline condition `also_baseline` is included to account for weird issues with link order affecting performance.

Benchmarks for each source tree are compiled separately than linked together when `make`-ed (with special care to avoid ODR violations).
You can run benchmarks at default settings via the executable `./matchbench`.
To run the benchmarks across a suite of settings to designed model representative runtime conditions, use `./benchmark_suite.sh`.

Interesting places to look & fiddle around inside the Empirical source tree are:
* [emp::TagDepository](https://github.com/devosoft/Empirical/blob/native-canvas/include/emp/matching/MatchDepository.hpp)
  * tag matching data structure
* [emp::SmallFifoMap](https://github.com/devosoft/Empirical/blob/c366d4f29e0b03d1b697aab78c8a4b444aac3b93/include/emp/datastructs/SmallFifoMap.hpp)
  * data structure used for cache for regulated query lookup (frequently invalidated by regulation)
* [emp::ApproxDualStreakMetric](https://github.com/devosoft/Empirical/blob/91ba797a3ad5ae19b2839155fb9a7823581d69fb/include/emp/matching/matchbin_metrics.hpp#L460)
  * the evolutionaryily-promising but expensive tag distance metric
* [emp::BitSet](https://github.com/devosoft/Empirical/blob/91ba797a3ad5ae19b2839155fb9a7823581d69fb/include/emp/bits/BitSet.hpp#L926)
  * `LongestSegmentOnes()` (important for the streak metric) may be of particular interest

## Credits

This package was created with [Cookiecutter][https://github.com/audreyr/cookiecutter] and the [mmore500/cookiecutter-dishtiny-project][https://github.com/mmore500/cookiecutter-dishtiny-project] project template.

This package uses [Empirical](https://github.com/devosoft/Empirical#readme), a library of tools for scientific software development, with emphasis on also being able to build web interfaces using Emscripten.
