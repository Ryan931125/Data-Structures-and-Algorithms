# Printing Queue with Binomial Heap

## Description
This program implements a printer queue management system using a binomial max-heap data structure. The system efficiently handles multiple printer queues and operations like adding jobs, printing the highest priority job, and transferring all jobs from one printer to another.

## Algorithm Overview
The implementation utilizes a binomial heap to provide efficient operations:

1. **Binomial Heap**: A collection of binomial trees where each tree follows these properties:
   - Binomial tree of order k has 2^k nodes
   - Each node can have at most one child of each order
   - The root of each tree has the highest priority (max-heap property)

2. **Key Operations**:
   - **Union**: Merges two binomial heaps in O(log n) time
   - **Insert**: Adds a new job to a printer's queue in O(log n) time
   - **Extract-Max**: Removes and returns the highest priority job in O(log n) time

## Implementation Details

### Data Structures
- **Tree**: Node in the binomial heap containing:
  - `order`: The rank of the binomial tree
  - `id`: Job ID
  - `priority`: Job priority
  - `next`: Pointer to the next binomial tree in the heap
  - `child`: Pointer to the highest order child

- **Heap**: A binomial heap structure containing:
  - `head`: Pointer to the first binomial tree (lowest order)

### Key Functions
1. **BinomialHeapMerge**: Merges two heaps' trees into a single ordered list
2. **BinomialHeapUnion**: Combines two heaps by merging and consolidating trees of the same order
3. **BinomialHeapInsert**: Adds a new job to a printer's queue
4. **BinomialHeapExtractMax**: Removes and returns the highest priority job
5. **reverse**: Helper function to reverse a linked list of trees

## Time Complexity
- **Add Operation**: O(log n)
- **Print Operation**: O(log n)
- **Move Operation**: O(log(n+m)) where n and m are the number of jobs in the source and destination printers

## How to Run
```bash
# Compile the code
gcc -o printing_queue main.c

# Run with input from file
./printing_queue < input.txt

# Run with manual input
./printing_queue
```

## Input Format
```
N M                       # N: number of printers, M: number of operations
operation_1               # Operations are described below
operation_2
...
operation_M
```

### Operation Types:
1. `1 job_id priority printer_id`: Add a job with given ID and priority to printer queue
2. `2 printer_id`: Print the highest priority job from a printer queue
3. `3 printer_id1 printer_id2`: Move all jobs from printer_id1 to printer_id2

## Output Format
The program produces different outputs based on the operation:
- For add operations: `X jobs waiting on printer Y`
- For print operations: `job_id printed` or `no documents in queue`
- For move operations: `X jobs waiting on printer Y after moving`

## Example Usage

### Example 1: Basic Operations
**Input:**
```
1 5
1 1 1 1
1 2 2 1
2 1
2 1
2 1
```

**Output:**
```
1 jobs waiting on printer 1
2 jobs waiting on printer 1
2 printed
1 printed
no documents in queue
```

## Advantages of Binomial Heap
- **Efficient Merging**: Unlike binary heaps, binomial heaps can merge two priority queues in O(log n) time
- **Optimal for Move Operations**: The move operation benefits from the efficient union operation
- **Maintains Priority**: Preserves the highest priority job at the root for quick access

## Constraints
- 1 ≤ N, M ≤ 10^6
- 1 ≤ job_id, priority ≤ 10^9
- All job IDs and priorities are unique
- For move operations, source and destination printers are different
