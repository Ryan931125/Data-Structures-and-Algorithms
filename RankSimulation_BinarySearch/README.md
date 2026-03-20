# Rank Simulation + Binary Search

## Problem

Simulate a ranked class game with events:

- attack and rank swap
- global reward update
- query last rank with power >= q
- query gain from player's last `m` attacks

## Time and Space Complexity

- Attack: O(1)
- Reward update: O(1) (lazy offset)
- Power query: O(log N)
- Attack-history query: O(1)
- Space: O(N + total attacks)

## Input

- `N T M`
- Initial powers
- `T` event lines (types 1 to 4)

## Output

- Query answers (type 3 and type 4)
- Final per-player attack statistics block

## Solution

I combine:

- rank/label mapping arrays for O(1) swaps
- lazy global reward accumulation
- per-player prefix sums for attack history

Power threshold queries are answered with binary search on effective powers.
