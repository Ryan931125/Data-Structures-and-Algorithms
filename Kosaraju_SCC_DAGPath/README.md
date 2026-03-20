# Kosaraju SCC + DAG Path Check

## Problem
Given a directed graph, assign one color to each strongly connected component (SCC). In mode 2, also determine whether all SCC colors can be covered by one valid acyclic path in the condensed DAG.

## Time and Space Complexity
- Time: O(V + E)
- Space: O(V + E)

## Input
- `|B| |A| mode`
- `|A|` directed edges

## Output
- Mode 1: number of colors (SCC count)
- Mode 2: SCC count, then `1` or `0` for path feasibility

## Solution
I use Kosaraju's algorithm:

1. DFS on the original graph to get finishing order.
2. DFS on the transposed graph in reverse finishing order to label SCCs.

The SCC count is the minimum required color count. For mode 2, I build/inspect SCC-level ordering constraints in the condensed DAG and check whether all components can be chained in one valid direction-consistent path.
