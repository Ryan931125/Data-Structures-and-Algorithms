# Insertion Sort with Back-Moves Budget

## Description
This program implements the insertion sort algorithm with a limited budget of back-moves. The algorithm sorts an array of integers, but is constrained by a maximum number of "back-moves" it can perform.

## Algorithm Overview
The insertion sort algorithm implemented here works by:
1. Iterating through each element of the array starting from the second element (index 1)
2. For each element, temporarily storing its value
3. Shifting elements to the right to make room for the temporary value in its correct sorted position
4. Each shift operation counts as one "back-move" against the budget

The budget constraint limits how many shifting operations (back-moves) can be performed. Once the budget is exhausted, elements can still be inserted but without shifting other elements.

## Implementation Details

### Functions
1. **insert()**: Places an element at position `m` into its correct sorted position in the array
   - Takes the element at position `m` and moves it left until it finds its correct sorted position
   - Each rightward shift of an element counts as one back-move against the budget
   - Stops shifting when either:
     - The budget is exhausted
     - The correct position is found
     - The beginning of the array is reached

2. **Insertion_sort()**: Calls the insert function for each element in the array

### Key Features
- Global counter `moves` to track remaining back-moves
- Early termination when budget is exhausted
- Proper handling of partially sorted arrays when budget is insufficient

## Time and Space Complexity
- **Time Complexity**: 
  - Best case: O(n) when array is already sorted
  - Average/Worst case: O(min(n², B)) where B is the back-move budget
- **Space Complexity**: O(1) as sorting is done in-place

## How to Run
```bash
# Compile the code
gcc -o insertion_sort main.c

# Run with input from file
./insertion_sort < input.txt

# Run with manual input
./insertion_sort
```

## Input Format
```
N B           # N: array size, B: back-move budget
a1 a2 ... aN  # Array elements
```

## Output Format
```
The array is a1 a2 ... aN after X back-moves.
```
Where X is either the total back-moves used (if sorting completed) or B (if budget was exhausted).

## Example Usage

### Example 1: Fully sorted within budget
**Input:**
```
3 2
1 3 2
```

**Output:**
```
The array is 1 2 3 after 1 back-moves.
```

### Example 2: Budget exhausted before completion
**Input:**
```
4 2
2 2 4 1
```

**Output:**
```
The array is 2 1 2 4 after 2 back-moves.
```

## Constraints
- 1 ≤ N ≤ 2¹⁰
- 1 ≤ B ≤ 2²⁰
- -2³⁰ ≤ array elements ≤ 2³⁰

## Notes
- This implementation strictly follows the specified insertion sort procedure
- Each back-move corresponds to shifting an element right (line 4 in the Insert routine)
- The algorithm tracks the exact number of back-moves used
