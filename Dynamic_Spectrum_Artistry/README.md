# Dynamic Spectrum Artistry

## Description
This program solves the Dynamic Spectrum Artistry problem by implementing Kosaraju's algorithm to find Strongly Connected Components (SCCs) in a directed graph. The implementation colors blocks such that blocks with bidirectional paths between them must have the same color, and blocks without bidirectional paths must have different colors. Additionally, it can determine if there exists an acyclic path through the condensed graph that includes all colors.

## Algorithm Overview
The solution uses a two-phase approach based on Kosaraju's algorithm:

1. **Phase 1: Identify Strongly Connected Components**
   - Perform a depth-first search (DFS) on the original graph to compute finishing times
   - Create a transpose graph by reversing all edges
   - Perform a second DFS on the transpose graph, considering vertices in order of decreasing finishing times
   - Each DFS tree in the second traversal represents a strongly connected component

2. **Phase 2: Path Finding (Only in mode 2)**
   - Create a condensed graph where each SCC is represented by a single vertex
   - Check if there exists a valid topological ordering that forms a path through all SCCs

## Implementation Details

### Data Structures
- **Vertex**: Represents a block with color, discovery/finish times, and ancestor information
- **Edge**: Represents a directed arrow between blocks
- **Adjacency Lists**: Efficiently store the graph structure

### Key Functions
1. **dfs_visit_1**: First DFS traversal to calculate finishing times and create the order of vertices
2. **dfs_visit_2**: Second DFS traversal on the transpose graph to identify SCCs
3. **main**: Coordinates the algorithm execution and outputs the results

### Fast I/O Implementation
- Custom `readchar()` and `ReadInt()` functions for efficient input handling
- Uses buffered reading to minimize system calls

## Time and Space Complexity
- **Time Complexity**: O(|B| + |A|), where |B| is the number of blocks and |A| is the number of arrows
- **Space Complexity**: O(|B| + |A|) for storing the graph and related information

## How to Run
```bash
# Compile the code
gcc -o dynamic_spectrum main.c

# Run with input from file
./dynamic_spectrum < input.txt

# Run with manual input
./dynamic_spectrum
```

## Input Format
```
|B| |A| mode         # |B|: number of blocks, |A|: number of arrows, mode: 1 or 2
u1 v1                # First arrow from block u1 to block v1
u2 v2                # Second arrow from block u2 to block v2
...
u|A| v|A|            # Last arrow
```

## Output Format
For mode 1:
```
Number_of_colors     # Number of colors needed
```

For mode 2:
```
Number_of_colors     # Number of colors needed
Path_exists          # 1 if path exists, 0 if not
```

## Example Usage

### Example 1: Simple SCC with a Path
**Input:**
```
3 3 2
1 2
2 1
2 3
```

**Output:**
```
2
1
```

In this example:
- Blocks 1 and 2 form an SCC and must have the same color
- Block 3 must have a different color
- Total colors needed: 2
- A path exists through all colors (2 → 3)

### Example 2: Multiple SCCs without a Complete Path
**Input:**
```
5 5 2
1 2
2 3
3 1
2 4
5 4
```

**Output:**
```
3
0
```

## Key Insights
1. The number of colors needed equals the number of SCCs in the graph
2. A path including all colors exists if and only if there is a Hamiltonian path in the condensed graph
3. A Hamiltonian path exists if and only if there is a unique topological ordering

## Constraints
- 0 ≤ |A| ≤ min(|B| · (|B| - 1), 10^6)
- 1 ≤ ui, vi ≤ |B|
- No duplicate arrows
- mode ∈ {1, 2}
