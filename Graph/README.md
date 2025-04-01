# Graph Edge Classification with DFS

## Description
This program implements the standard Depth-First Search (DFS) algorithm to traverse a directed graph and classify each edge into one of four categories: tree edges, back edges, forward edges, and cross edges. The implementation follows the DFS algorithm as described in CLRS (Introduction to Algorithms) textbook.

## Edge Classification
In a directed graph, DFS classifies edges into four types:

1. **Tree Edges (T)**: Edges that form the DFS tree. These are edges (u,v) where vertex v is discovered for the first time through this edge.
2. **Back Edges (B)**: Edges (u,v) that connect a vertex u to an ancestor v in the DFS tree. These edges create cycles in the graph.
3. **Forward Edges (F)**: Non-tree edges (u,v) that connect a vertex u to a descendant v in the DFS tree.
4. **Cross Edges (C)**: All other edges. They connect vertices that are neither ancestors nor descendants of each other in the DFS tree.

## Algorithm Overview
The algorithm uses a depth-first traversal approach:

1. Initialize all vertices as WHITE (undiscovered)
2. For each undiscovered vertex, perform a DFS visit
3. During the DFS visit:
   - Mark the vertex as GRAY (discovered but not finished)
   - Recursively visit all its undiscovered (WHITE) neighbors
   - Mark the vertex as BLACK (finished) when all its neighbors have been processed
4. Classify each edge according to the color of its destination vertex:
   - WHITE destination → Tree Edge (T)
   - GRAY destination → Back Edge (B)
   - BLACK destination → Forward Edge (F) or Cross Edge (C), determined by discovery times

## Implementation Details

### Data Structures
- **Vertex**: Structure containing color, discovery time, finish time, and ancestor information
- **Edge**: Structure containing destination vertex, edge type, and pointer to next edge
- **Adjacency List**: Array of linked lists representing the graph

### Key Functions
- **dfs_visit**: Recursive function that performs the DFS traversal and edge classification
- **main**: Handles input/output and initiates the DFS algorithm

## Time and Space Complexity
- **Time Complexity**: O(V + E) where V is the number of vertices and E is the number of edges
- **Space Complexity**: O(V + E) for the graph representation plus O(V) for the recursion stack

## How to Run
```bash
# Compile the code
gcc -o graph_classification main.c

# Run with input from file
./graph_classification < input.txt

# Run with manual input
./graph_classification
```

## Input Format
```
|V|                 # Number of vertices
d₁ n₁₁ n₁₂ ... n₁ₙ   # Adjacency list for vertex 1 (outdegree followed by neighbors)
d₂ n₂₁ n₂₂ ... n₂ₙ   # Adjacency list for vertex 2
...
d|V| n|V|₁ n|V|₂ ... # Adjacency list for vertex |V|
```

## Output Format
```
1 c₁₁c₁₂...c₁ₙ       # Vertex 1 followed by edge classifications
2 c₂₁c₂₂...c₂ₙ       # Vertex 2 followed by edge classifications
...
|V| c|V|₁c|V|₂...    # Vertex |V| followed by edge classifications
```
Where each c is one of T (tree), B (back), F (forward), or C (cross).

## Example Usage

### Example 1: Graph with Multiple Edge Types
**Input:**
```
5
2 2 4
1 1
3 2 4 5
2 3 5
0
```

**Output:**
```
1 TT
2 B
3 CBT
4 TF
5
```

### Example 2: Strongly Connected Graph
**Input:**
```
3
2 2 3
2 1 3
2 1 2
```

**Output:**
```
1 TF
2 BT
3 BB
```

## Edge Classification Rules
- Edge (u,v) is a **Tree Edge** if v.color is WHITE when the edge is explored
- Edge (u,v) is a **Back Edge** if v.color is GRAY when the edge is explored
- Edge (u,v) is a **Forward Edge** if v.color is BLACK and u.discovery_time < v.discovery_time
- Edge (u,v) is a **Cross Edge** if v.color is BLACK and u.discovery_time > v.discovery_time

## Constraints
- 1 ≤ |V| ≤ 1000
- No self-edges or multiple edges (0 ≤ |E| ≤ |V| × (|V| - 1))
