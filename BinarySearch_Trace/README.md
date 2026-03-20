# Binary Search Trace

## Problem

Given a sorted array and a target key, run binary search, print each searched range, and report whether the key is found.

## Time and Space Complexity

- Time: O(log n)
- Space: O(1)

## Input

- `N key`
- `N` sorted integers

## Output

- Search trace lines
- Final line: found index or not found

## Solution

I keep `left` and `right` boundaries and repeatedly check the middle index.

- `a[mid] == key`: done
- `a[mid] < key`: move `left = mid + 1`
- otherwise: move `right = mid - 1`

Before each decision, the current `[left, right]` range is printed.
