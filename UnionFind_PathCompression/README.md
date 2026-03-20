# Union-Find with Path Compression

## Problem

Maintain disjoint sets over `1..N` with operations:

- `F x`: find representative
- `U x y`: union two sets
- `P x`: print path from `x` to its representative

## Time and Space Complexity

- Amortized `Find` / `Union`: O(alpha(N))
- Total for `M` operations: O(M \* alpha(N))
- Space: O(N)

## Input

- `N`
- `M`
- `M` operation lines (`F`, `U`, `P`)

## Output

- For each `P x`, print the path to representative

## Solution

I use disjoint-set forests with two optimizations:

- path compression in `Find_Set`
- union by rank in `Link`

Together they keep trees shallow and operations near-constant in practice.
