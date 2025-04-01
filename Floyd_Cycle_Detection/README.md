# Floyd Cycle Detection

## Description
This program implements the Floyd Cycle Detection algorithm (also known as the "Tortoise and Hare" algorithm) to detect cycles in a linked list. The implementation traces the path of the hare pointer and reports all nodes visited during the detection process.

## Algorithm Overview
The Floyd Cycle Detection algorithm works by maintaining two pointers that traverse the linked list at different speeds:

1. The "tortoise" moves one node at a time
2. The "hare" moves two nodes at a time
3. If there is a cycle, the hare will eventually meet the tortoise within the cycle
4. If there is no cycle, the hare will reach the end of the list

This implementation focuses on tracking the path of the hare through the linked list, printing the data values of each node it visits.

## Implementation Details

### Data Structures
- **Node**: A structure containing an integer data value and a pointer to the next node
- **Linked List**: A sequence of nodes where each node points to the next node in the sequence

### Key Functions
- **getnode()**: Creates a new node with the given data and next pointer
- **floyd_cycle_detection()**: Implements the cycle detection algorithm and prints the hare's path

## Time and Space Complexity
- **Time Complexity**: O(n) where n is the number of nodes in the linked list
- **Space Complexity**: O(1) for the algorithm itself (uses only two pointers regardless of input size)

## How to Run
```bash
# Compile the code
gcc -o cycle_detection main.c

# Run with input from file
./cycle_detection < input.txt

# Run with manual input
./cycle_detection
```

## Input Format
```
N                # Number of nodes
data_1 next_1    # Data and next pointer for node 1
data_2 next_2    # Data and next pointer for node 2
...
data_N next_N    # Data and next pointer for node N
```

Where:
- `data_i` is the integer value stored in node i
- `next_i` is the 1-indexed position of the node that node i points to (0 means NULL)

## Output Format
```
data_1 data_next_next_1 data_next_next_next_next_1 ... data_last
```

The output shows all data values in nodes visited by the hare pointer, where:
- If a cycle is detected, the last value is the node where the hare meets the tortoise
- If no cycle is detected, the last value is the last node the hare visits before reaching NULL

## Example Usage

### Example 1: Cyclic Linked List
**Input:**
```
5
1 2
2 3
3 4
4 5
5 1
```

**Output:**
```
1 3 5 2 4 1
```

### Example 2: Non-Cyclic Linked List
**Input:**
```
5
1 2
2 3
3 4
4 0
5 3
```

**Output:**
```
1 3
```

## Constraints
- 1 ≤ N ≤ 10^5
- -2^30 ≤ data ≤ 2^30
- 0 ≤ next ≤ N

## Applications
Floyd's Cycle Detection algorithm has various practical applications:
- Detecting deadlocks in resource allocation
- Finding loops in linked data structures
- Determining the quality of random number generators
- Detecting cycles in graph algorithms
