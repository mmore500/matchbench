#!/bin/bash

make

for NUM_LOOKUP in 1 4 16; do
  for POOL_SIZE in 16 32 64; do

    ./matchbench \
      -NUM_LOOKUP_IN_TASK_MIX "${NUM_LOOKUP}" \
      -NUM_REGULATION_IN_TASK_MIX 1 \
      -TARGET_POOL_SIZE "$((4 * POOL_SIZE))" \
      -QUERY_POOL_SIZE "$((1 * POOL_SIZE))" \
      -NUM_DEPOSITORIES 16
  done
done
