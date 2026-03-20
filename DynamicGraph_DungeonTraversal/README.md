# Dynamic Graph Dungeon Traversal

## Problem
Model a dungeon system with dynamic path operations and treasure behavior. Support movement, route planning, value bounds, treasure discovery, and optional path construction.

## Time and Space Complexity
- Move downstream / upstream: O(1)
- Planning query (type 3): O(log d) on current route depth `d`
- Maximum-value query (type 4): O(1)
- Discover treasure (type 5): O(d)
- Path construction (type 6): depends on local adjacency updates
- Space: O(N + M + tracked treasures)

## Input
- `N M Q`
- `M` directed pathways with length
- `Q` operations (types 1 to 6)

## Output
- Results for operations that require responses (movement/planning/value/discovery)

## Solution
I store dungeons as a directed graph with explicit upstream/downstream links and maintain route-state metadata.

Key points:
- Current route context is tracked incrementally.
- Planning uses binary search over route constraints to find the first valid dungeon.
- Value-bound queries are answered from maintained depth/value summaries.

This keeps frequent gameplay operations fast while still supporting dynamic changes.
