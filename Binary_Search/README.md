# Binary Search with Step-by-Step Tracing

## Description
This program implements the binary search algorithm to find a target value in a sorted array. The implementation includes detailed tracing that shows each step of the search process, making it educational for understanding how binary search works.

## Algorithm Overview
Binary search is a divide-and-conquer algorithm that finds the position of a target value within a sorted array:

1. Compare the target value to the middle element of the array
2. If the target matches the middle element, the search is complete
3. If the target is less than the middle element, continue searching in the left half
4. If the target is greater than the middle element, continue searching in the right half
5. Continue this process until the target is found or the subarray becomes empty

## Implementation Details

### Function Behavior
The binary search function in this implementation:
- Takes an array, a key to search for, and the bounds (left and right indices)
- Prints the search range at each step of the algorithm
- Returns the index if the key is found, or indicates that the key was not found

### Output Features
- Shows the current search range at each iteration
- Displays the final result (either the index where the key was found or "Not found")
- Follows 1-indexed output format for clear communication

## Time and Space Complexity
- **Time Complexity**: O(log n) - where n is the size of the array
- **Space Complexity**: O(1) - constant extra space is used regardless of input size

## How to Run
```bash
# Compile the code
gcc -o binary_search main.c

# Run with input from file
./binary_search < input.txt

# Run with manual input
./binary_search
```

## Input Format
```
N key        # N: array size, key: value to search for
a1 a2 ... aN # Sorted array elements
```

## Output Format
For each iteration of the search:
```
Searching key in range [l, r].
```

Final result:
```
Found at index m.  # If found at position m
```
OR
```
Not found.         # If not found
```

## Example Usage

### Example 1: Key Found
**Input:**
```
3 4
1 2 4
```

**Output:**
```
Searching 4 in range [1, 3].
Searching 4 in range [3, 3].
Found at index 3.
```

### Example 2: Key Not Found
**Input:**
```
3 3
1 2 4
```

**Output:**
```
Searching 3 in range [1, 3].
Searching 3 in range [3, 3].
Searching 3 in range [3, 2].
Not found.
```

## Constraints
- 1 ≤ N ≤ 2²²
- 1 ≤ key ≤ 2²²
- 1 ≤ array elements ≤ 2²²
- The input array is guaranteed to be sorted in non-decreasing order

## Educational Value
This implementation is particularly useful for:
- Visualizing the binary search algorithm's execution
- Understanding how the search space narrows with each iteration
- Learning algorithmic problem-solving techniques for sorted data
