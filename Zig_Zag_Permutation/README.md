# Zig-Zag Permutation

## Description
This algorithm finds all "beautiful" permutations of an integer array. A permutation is considered "beautiful" if it satisfies the following condition:
```
(a[n+1] - a[n])(a[n+2] - a[n+1]) < 0, for all 1 ≤ n ≤ N-2
```

In simpler terms, a beautiful array is one where each element is either greater than both its neighbors or less than both its neighbors, creating a zig-zag pattern.

## Problem Specifications
- Input array can contain repeated elements
- Arrays with N ≤ 2, are always considered beautiful
- All permutations must be output in lexicographical order
- The program handles large integers (using long long type)

## Time & Space Complexity
- **Time Complexity**: O(N!) for the worst case, where N is the array length
- **Space Complexity**: O(N × M), where M is the number of beautiful permutations (max 2×10^5)

## Implementation Details

### Key Functions
1. `check()` - Verifies if an array follows the zigzag pattern
2. `beauty()` - Recursively generates all beautiful permutations with backtracking
3. `main()` - Handles input/output and array sorting

### Optimizations
- Early termination when a sequence violates the beauty condition
- Skipping duplicate permutations
- Detecting impossible cases (when more than half of elements are the same)
- Lexicographical ordering using initial sorting

## How to Run
```bash
# Compile the code
gcc -o zigzag_permutation main.c

# Run with input from file
./zigzag_permutation < input.txt

# Run with manual input
./zigzag_permutation
```

## Input Format
```
N           # Length of array
a1 a2 ... aN  # Array elements
```

## Output Format
```
M           # Number of beautiful permutations
p1,1 p1,2 ... p1,N  # First beautiful permutation
...
pM,1 pM,2 ... pM,N  # Last beautiful permutation
```

## Example Usage

### Input
```
3
3 2 1
```

### Output
```
4
1 3 2
2 1 3
2 3 1
3 1 2
```

## Notes
- Any array with length N ≤ 2 is always considered beautiful
- The algorithm avoids timeout by using backtracking to prune permutations that cannot be beautiful
- Large integer handling is implemented using long long data type for calculations
