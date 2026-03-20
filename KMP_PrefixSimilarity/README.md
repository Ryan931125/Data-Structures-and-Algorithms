# KMP Prefix Similarity

## Problem

Given source string `S` and copier string `C`, compute a score for every prefix of `C`.
For each prefix `P`:

- `H(P)`: number of occurrences in `S`
- `L(P)`: number of prefix-suffix borders in `P`
- `Score(P) = H(P) * L(P)`

## Time and Space Complexity

- Time: O(|S| + |C|)
- Space: O(|C|)

## Input

- Line 1: `S`
- Line 2: `C`

## Output

- One score per prefix of `C` (length 1 to |C|)

## Solution

I use the KMP prefix-function workflow.

- Compute prefix function on `C`.
- Derive border counts for all prefixes.
- Run KMP matching to count prefix hits in `S`.
- Propagate counts backward using prefix links.

Then multiply border count and hit count for each prefix.
