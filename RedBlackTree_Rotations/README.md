# Red-Black Tree Rotations

## Problem

Given a red-black tree described in preorder, process operations:

- left rotation at key `k`
- right rotation at key `k`
- query node information for key `k` (children, black-depth, depth)

## Time and Space Complexity

- Tree construction: O(N)
- Rotation: O(1) after node lookup
- Query: O(h) for depth/black-depth along a root-to-node path
- Space: O(N)

## Input

- `N`
- `N` lines: node color and key in preorder description
- `M`
- `M` operations (`L k`, `R k`, `P k`)

## Output

- For each `P k`: `LK RK BD D`

## Solution

I build the tree from preorder and maintain parent/left/right pointers.

- Rotations follow standard BST pointer rewiring.
- Query computes left/right child keys directly.
- Depth and black-depth are obtained by traversing ancestor links.

The implementation focuses on structural correctness of rotations and query reporting.
