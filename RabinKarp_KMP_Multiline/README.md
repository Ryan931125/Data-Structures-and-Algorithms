# Multi-line Matching (Rabin-Karp + KMP)

## Problem

Find occurrences of a `k`-line pattern in a `k`-line text.
The solution must report valid shifts and spurious hits (hash collisions).

## Time and Space Complexity

- Hash transformation: O(k(n + m))
- KMP matching on transformed arrays: O(n + m)
- Verification of candidate shifts: depends on number of candidates
- Space: O(n + m)

## Input

- `k n m q`
- `k` lines of text (length `n`)
- `k` lines of pattern (length `m`)

## Output

- Hashed text array `T'`
- Hashed pattern array `P'`
- Valid shifts (or `-1`)
- Spurious hits (or `-1`)

## Solution

I convert each column of the multi-line strings into a rolling hash value (Rabin-Karp idea), producing 1D arrays `T'` and `P'`.

Then I run KMP on `T'` vs `P'` to get candidate shifts in linear time. Finally, each candidate is verified against original multi-line characters, separating real matches from collisions.
