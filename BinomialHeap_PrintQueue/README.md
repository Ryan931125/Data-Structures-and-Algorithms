# Binomial Heap Print Queue

## Problem

Manage multiple printer queues with operations:

- add a print job with priority
- print (extract highest priority)
- move all jobs from one printer to another

## Time and Space Complexity

- Insert: O(log n)
- Extract-max: O(log n)
- Merge/move queues: O(log(n + m))
- Space: O(total jobs)

## Input

- `N M`
- `M` operation lines (types 1, 2, 3)

## Output

- Operation-dependent status messages (queue size / printed job / empty queue)

## Solution

Each printer queue is a binomial max-heap.

Why this structure:

- It supports efficient union of two heaps.
- It supports max-priority extraction.
- It naturally handles frequent merge operations between printers.

Core operations used are `union`, `insert` (as union with one-node heap), and `extract-max`.
