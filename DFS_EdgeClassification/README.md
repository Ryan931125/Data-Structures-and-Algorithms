# DFS Edge Classification

## Problem

Run DFS on a directed graph and classify each edge as:

- tree edge
- back edge
- forward edge
- cross edge

## Time and Space Complexity

- Time: O(V + E)
- Space: O(V + E)

## Input

- `|V|`
- For each vertex: outdegree followed by adjacency list

## Output

- For each vertex, edge labels in adjacency-list order

## Solution

I maintain standard DFS metadata:

- color (WHITE, GRAY, BLACK)
- discovery time
- finish time
- parent

Classification during traversal:

- to WHITE -> tree edge
- to GRAY -> back edge
- to BLACK and descendant relation -> forward edge
- otherwise -> cross edge

This follows the textbook DFS classification rules for directed graphs.
