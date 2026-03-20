# Selection Sort with Swap Budget

## Problem

Sort an array using selection sort, but allow at most `B` swaps.

## Time and Space Complexity

- Time: O(n^2)
- Space: O(1)

## Input

- `N B`
- `N` integers

## Output

- Final array state and number of swaps used

## Solution

For each index `i`:

- find the minimum element index in `[i, n-1]`
- swap only if needed and budget remains

This keeps standard selection-sort behavior while enforcing the swap cap. If budget runs out early, the array is the correct partial state after the performed swaps.
