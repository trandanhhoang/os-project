# Follow

https://github.com/ossu/computer-science/blob/master/coursepages/ostep/README.md#roadmap

# Prerequisite

- use lldb instead of gdb

## Policy

- short job, long job
  - multi-level feedback queue
    - Same level, round robin
    - move job down priority
    - every T second, move all job to the highest priority (solve starvation)

# Memory vitualization
- Address translation

# Concurrency

- 3 instructions(fetch, decode, execute) below are not atomic.
  1. load
  2. incr  
  3. store