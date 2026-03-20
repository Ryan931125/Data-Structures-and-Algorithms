# Max Heap by Repeated Insert

## Problem
Build a max heap from `N` distinct keys by inserting keys one by one (not bottom-up heapify).

## Time and Space Complexity
- Time: O(N log N)
- Space: O(N)

## Input
- `N`
- `N` distinct positive integers

## Output
- Final heap array (root first)

## Solution
For each key:
1. append to heap end
2. bubble up while parent is smaller

Using 1-based indexing makes parent lookup simple (`i/2`).
This directly implements max-heap insertion behavior and shows how heap order is maintained after every insertion.
