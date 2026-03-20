# Insertion Sort with Move Budget

## Problem

Sort an array using insertion sort, but allow at most `B` back-moves (right shifts of existing elements). Once budget is exhausted, no more shifts are allowed.

## Time and Space Complexity

- Time: O(min(n^2, B + n))
- Space: O(1)

## Input

- `N B`
- `N` integers

## Output

- Final array state and number of back-moves used

## Solution

I keep the standard insertion-sort loop. For each element:

- save current key
- shift larger elements right while budget remains
- place key into the final slot

This preserves insertion-sort behavior when budget is enough, and gives the correct partial progress when budget runs out.
