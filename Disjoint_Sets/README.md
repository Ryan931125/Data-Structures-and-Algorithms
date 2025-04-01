# Disjoint Sets Implementation

## Description
This program implements a disjoint-set (or union-find) data structure with path compression and union-by-rank optimizations. It supports three main operations: Find-Set, Union, and Print-Path. The implementation follows the standard algorithms as described in the CLRS (Introduction to Algorithms) textbook.

## Data Structure Overview
A disjoint-set data structure maintains a collection of disjoint dynamic sets. Each set is identified by a representative element, which is typically one of its members. The data structure provides efficient operations to:

1. **Find the representative** of the set containing a given element
2. **Merge two sets** into a single set
3. **Track the path** from any element to its set representative

## Implementation Details

### Node Structure
Each element in the disjoint set is represented by a Node structure with two fields:
- `p`: Parent pointer (points to itself for a representative element)
- `rank`: A rough measure of the tree's height used for optimizing union operations

### Key Functions

1. **Find_Set(x)**: Determines the representative element of the set containing x
   - Implements path compression by making every node on the path from x to the root point directly to the root
   - Time complexity: O(α(n)) amortized, where α is the inverse Ackermann function

2. **Union(x, y)**: Merges the sets containing x and y
   - First finds the representatives of both sets using Find_Set
   - Then links the two trees based on their ranks
   - Time complexity: O(α(n)) amortized

3. **Link(x, y)**: Helper function for Union
   - Links two trees based on their ranks
   - Attaches the tree with smaller rank to the tree with larger rank
   - Increments rank when joining trees of equal rank

4. **Print_Path(x)**: Prints the path from x to its representative
   - Follows parent pointers from x until reaching the root
   - Does not modify the data structure (unlike Find_Set which performs path compression)

### Optimizations

1. **Path Compression**: When Find_Set is called, each node along the path from x to the root is made to point directly to the root
2. **Union by Rank**: Trees with smaller ranks are attached to trees with larger ranks, keeping the height of the resulting tree minimized

## Fast I/O Implementation
The program includes an optimized I/O mechanism with custom `readchar()` and `ReadInt()` functions for faster input processing.

## Time and Space Complexity
- **Time Complexity**: O(M × α(N)) for M operations on N elements, where α is the inverse Ackermann function (practically constant)
- **Space Complexity**: O(N) for storing N elements in the disjoint set

## How to Run
```bash
# Compile the code
gcc -o disjoint_sets main.c

# Run with input from file
./disjoint_sets < input.txt

# Run with manual input
./disjoint_sets
```

## Input Format
```
N               # Number of elements (1 to N)
M               # Number of operations
operation_1     # First operation (F x, U x y, or P x)
operation_2     # Second operation
...
operation_M     # M-th operation
```

Operation types:
- `F x`: Find the representative of the set containing x
- `U x y`: Union the sets containing x and y
- `P x`: Print the path from x to its representative

## Output Format
For each Print-Path operation (`P x`), the program outputs a line containing the path from x to its representative:
```
x x1 x2 ... representative
```
where x1, x2, etc. are intermediate nodes on the path from x to its representative.

## Example Usage

### Example 1: Basic Operations
**Input:**
```
3
6
F 1
U 3 1
U 3 3
U 2 2
F 2
P 3
```

**Output:**
```
3 1
```

### Example 2: Multiple Unions and Path Printing
**Input:**
```
5
10
U 4 5
F 5
P 4
P 5
P 3
U 5 4
U 2 4
F 2
U 2 5
P 2
```

**Output:**
```
4 5
5
3
2 5
```

## Constraints
- 1 ≤ N ≤ 1,000,000 (number of elements)
- 1 ≤ M ≤ 1,000,000 (number of operations)
