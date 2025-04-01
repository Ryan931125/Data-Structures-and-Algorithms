# Max-Heap Construction by Multiple Insertions

## Description
This program implements a max-heap data structure through sequential insertion operations. Unlike the more efficient heapify method, this implementation builds the max-heap by inserting elements one by one, which provides a clearer illustration of how heap properties are maintained with each addition.

## Algorithm Overview
The implementation follows the standard max-heap insertion algorithm:

1. **Max-Heap-Insert**: Adds a new element to the max-heap
   - Increases the heap size by 1
   - Initializes the new position with a placeholder value (-1)
   - Calls Heap-Increase-Key to position the new element correctly

2. **Heap-Increase-Key**: Places the newly inserted element in its correct position
   - Sets the value at the specified index
   - Repeatedly compares with parent and swaps if needed
   - Continues until the heap property is satisfied

3. **Swap**: Helper function to exchange two elements in the array

## Implementation Details

### Key Functions
- **max_heap_insert(int a[], int key)**: Inserts a new key into the max-heap
- **heap_increase_key(int a[], int i, int key)**: Adjusts the position of a key to maintain the max-heap property
- **swap(int arr[], int a, int b)**: Swaps two elements in the array

### Data Structure
- A simple array representation of the heap
- Index 0 is not used (to simplify parent-child relationships)
- For any node at index i:
  - Parent is at index ⌊i/2⌋
  - Left child is at index 2i
  - Right child is at index 2i+1

## Time Complexity
- **Insertion**: O(log n) for each element, where n is the current size of the heap
- **Overall Construction**: O(n log n) for inserting n elements
- **Space Complexity**: O(n) for storing n elements

## How to Run
```bash
# Compile the code
gcc -o max_heap main.c

# Run with input from file
./max_heap < input.txt

# Run with manual input
./max_heap
```

## Input Format
```
N               # Number of elements
e1 e2 ... eN    # N distinct positive integers
```

## Output Format
```
h1 h2 ... hN    # Max-heap representation after all insertions
```

## Example Usage

### Example 1: Simple Insertion
**Input:**
```
2
1 3
```

**Output:**
```
3 1
```

### Example 2: Larger Heap
**Input:**
```
4
8 9 6 4
```

**Output:**
```
9 8 6 4
```

## Properties of the Resulting Max-Heap
1. The root element (at index 1) is always the maximum value
2. For any node at index i, the value is greater than or equal to its children
3. The heap is a complete binary tree (all levels are fully filled except possibly the last one)

## Constraints
- 1 ≤ N ≤ 10^6
- 1 ≤ Element values ≤ 10^9
- All elements are distinct positive integers
