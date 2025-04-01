# Selection Sort with Swap Budget

## Description
This program implements the selection sort algorithm with a swap budget constraint. Given an array of N integers, the algorithm sorts the array using at most B swaps. The selection sort implementation follows a specific version that finds the minimum element in the unsorted portion and swaps it with the first unsorted element.

## Algorithm Overview
The selection sort algorithm implemented here has two main components:

1. **Get_Min_Index**: Finds the index of the minimum element in a specified range of the array
2. **Selection_Sort**: Performs the sorting with a budget constraint on the number of swaps

The algorithm works by:
1. Finding the minimum element in the unsorted portion of the array
2. Swapping it with the first element of the unsorted portion
3. Expanding the sorted portion by one element
4. Repeating until either the array is sorted or the swap budget is exhausted

## Time and Space Complexity
- **Time Complexity**: O(n²), where n is the size of the array
- **Space Complexity**: O(1) auxiliary space (in-place sorting)

## Implementation Details
The implementation includes:
- Handling the swap budget constraint
- Tracking the number of swaps performed
- Only performing swaps when necessary (when the minimum element isn't already in position)
- Correctly stopping when either the array is sorted or the budget is exhausted

## How to Run
```bash
# Compile the code
gcc -o selection_sort main.c

# Run with input from file
./selection_sort < input.txt

# Run with manual input
./selection_sort
```

## Input Format
```
N B           # N: size of array, B: swap budget
a1 a2 ... aN  # Array elements
```

## Output Format
```
The array is a1 a2 ... aN after X swaps.
```
Where X is the number of swaps performed (either the actual number needed or B if the budget was exhausted).

## Example Usage

### Example 1: Array can be fully sorted within budget
**Input:**
```
3 2
1 3 2
```

**Output:**
```
The array is 1 2 3 after 1 swaps.
```

### Example 2: Budget is exhausted before array is fully sorted
**Input:**
```
4 2
2 3 4 1
```

**Output:**
```
The array is 1 2 4 3 after 2 swaps.
```

## Constraints
- 1 ≤ N ≤ 2¹⁰
- 1 ≤ B ≤ 2¹⁰
- -2³⁰ ≤ array elements ≤ 2³⁰

## Notes
- The algorithm strictly follows the specified selection sort procedure
- Even if multiple elements have the same value, the algorithm correctly identifies the first occurrence of the minimum value
- The implementation handles arrays with duplicate values appropriately
