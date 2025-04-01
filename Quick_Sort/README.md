# Quick Sort with Swap Budget

## Description
This program implements the Quick Sort algorithm with a limited budget of swaps. The algorithm sorts an array of integers but is constrained by a maximum number of swap operations it can perform. It follows a specific version of the Quick Sort algorithm that uses a simple pivot selection strategy (first element) and performs partitioning through two-pointer techniques.

## Algorithm Overview
The implementation consists of three main components:

1. **QuickSort Function**: Recursively divides the array into partitions and sorts them
   - Takes an array, left bound, right bound, and remaining swap budget
   - Returns early if the swap budget is exhausted
   - Calls the partition function to find the pivot position
   - Recursively sorts the left and right subarrays

2. **Partition Function**: Rearranges elements around a pivot
   - Selects the leftmost element as the pivot
   - Uses two pointers (i and j) working inward from both ends
   - Swaps elements that are out of place relative to the pivot
   - Finally places the pivot in its correct sorted position
   - Decrements the swap budget for each swap performed

3. **Swap Function**: Exchanges two elements in the array

## Implementation Details

### Key Features
- **Budget Tracking**: Maintains and updates a counter for the remaining swap operations
- **Early Termination**: Stops the sorting process when the swap budget is exhausted
- **Conditional Swapping**: Only performs swaps if there's remaining budget

### Time Complexity
- **Best Case**: O(n log n) when the array is balanced after partitioning
- **Average Case**: O(n log n)
- **Worst Case**: O(n²) when the array is already sorted or nearly sorted
- **With Swap Budget**: Limited by min(normal complexity, swap budget)

## How to Run
```bash
# Compile the code
gcc -o quicksort main.c

# Run with input from file
./quicksort < input.txt

# Run with manual input
./quicksort
```

## Input Format
```
N B           # N: array size, B: swap budget
a1 a2 ... aN  # Array elements
```

## Output Format
```
The array is a1 a2 ... aN after X swaps.
```
Where X is either the total swaps used (if sorting completed) or B (if budget was exhausted).

## Example Usage

### Example 1: Fully sorted within budget
**Input:**
```
3 2
1 3 2
```

**Output:**
```
The array is 1 2 3 after 1 swaps.
```

### Example 2: Budget exhausted before completion
**Input:**
```
4 2
2 3 4 1
```

**Output:**
```
The array is 1 2 4 3 after 2 swaps.
```

## Key Differences from Standard Quick Sort
1. **Swap Limitation**: The algorithm stops when the swap budget is exhausted
2. **Tracking Mechanism**: Uses a pointer to an integer to track swaps across recursive calls
3. **Partition Return Handling**: Returns a special value when budget is exhausted

## Constraints
- 1 ≤ N ≤ 2¹⁰
- 1 ≤ B ≤ 2¹⁰
- -2³⁰ ≤ array elements ≤ 2³⁰
