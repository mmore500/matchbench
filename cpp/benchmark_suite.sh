#!/bin/bash

make

for NUM_LOOKUP in 1 16 64; do
  for POOL_SIZE in 1 16 64; do

    ./matchbench \
      -NUM_LOOKUP_IN_TASK_MIX "${NUM_LOOKUP}" \
      -NUM_REGULATION_IN_TASK_MIX 1 \
      -TARGET_POOL_SIZE "$((32 * POOL_SIZE))" \
      -QUERY_POOL_SIZE "$((16 * POOL_SIZE))"

  done
done
