# Quick Sort with Swap Budget

## Problem

Sort an array with quick sort, but allow at most `B` swaps. Once the swap budget is consumed, stop performing further swaps.

## Time and Space Complexity

- Time: up to O(n^2) in the worst pivot pattern, but additionally bounded by swap budget behavior
- Space: O(log n) recursion stack on average

## Input

- `N B`
- `N` integers

## Output

- Final array state and number of swaps used

## Solution

I use first-element pivot partitioning with two pointers.

During partition:

- swap only if budget remains
- decrement budget on each swap

Recursive quick sort continues while valid partitions are produced. Budget control is shared across recursive calls, so the final array reflects exactly how far sorting progressed under the swap limit.
