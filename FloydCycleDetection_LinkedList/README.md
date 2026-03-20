# Floyd Cycle Detection (Linked List)

## Problem

Given a linked-list structure (node value + next index), run Floyd's tortoise-hare algorithm and print the nodes visited by the hare pointer.

## Time and Space Complexity

- Time: O(n)
- Space: O(1)

## Input

- `N`
- `N` lines: `data_i next_i` (`next_i = 0` means null)

## Output

- Hare traversal values in visit order, ending at null or meeting point

## Solution

I maintain two pointers:

- tortoise moves 1 step
- hare moves 2 steps

If a cycle exists, they eventually meet. If not, hare reaches null. The output follows the required trace of hare-visited nodes.
