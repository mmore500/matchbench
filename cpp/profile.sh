#!/bin/bash

make production

sudo perf record -g ./matchbench $@
sudo perf script | ./third-party/FlameGraph/stackcollapse-perf.pl| third-party/FlameGraph/flamegraph.pl > graph.svg
firefox graph.svg
