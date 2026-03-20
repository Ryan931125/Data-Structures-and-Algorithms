# Backtracking Zig-Zag Permutations

## Problem

Given an integer array (possibly with duplicates), output all permutations where consecutive differences alternate signs:
`(a[i+1]-a[i]) * (a[i+2]-a[i+1]) < 0`
for all valid `i`.

## Time and Space Complexity

- Time: O(N! ) in the worst case
- Space: O(N) recursion stack, plus output storage

## Input

- `N`
- `N` integers

## Output

- Number of valid permutations
- All valid permutations in lexicographic order

## Solution

I sort the input first, then use backtracking with pruning.

At each depth:

- skip duplicates that would generate the same prefix
- once enough elements are chosen, reject branches that violate zig-zag condition immediately

This avoids exploring many impossible branches and keeps output in lexicographic order.
