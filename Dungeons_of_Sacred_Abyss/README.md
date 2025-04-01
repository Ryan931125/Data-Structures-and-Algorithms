# Dungeons of Sacred Abyss

## Description
This program implements a dungeon traversal system for the game "Dungeons of Sacred Abyss." The implementation manages a network of interconnected dungeons, player movement, and a treasure transportation system. It handles various operations including moving between dungeons, planning treasure transportation, and calculating maximum possible treasure values.

## Features
The system supports six different operations:

1. **Downstream Movement**: Move to the first available downstream dungeon
2. **Upstream Movement**: Move to the unique upstream dungeon, making the pathway disappear
3. **Plan Treasure Transportation**: Calculate the smallest dungeon number where a treasure can maintain non-negative value
4. **Guess Maximum Value**: Find the maximum possible original value of a hypothetical treasure
5. **Discover Treasure**: Process a newly found treasure through the transportation system
6. **Construct Pathway**: Add a new pathway between dungeons (bonus feature)

## Implementation Details

### Data Structures
- **Dpath**: A linked list structure to represent downstream paths from a dungeon
- **Maxdeep**: A doubly-linked list to track the maximum path depths from a dungeon
- **Treasure**: Structure to store information about discovered treasures
- **Dungeon**: Main structure containing downstream paths, upstream connections, and maximum depth information

### Key Functions
1. **init_dungeon()**: Creates and initializes a new dungeon
2. **init_max_deep()**: Calculates the maximum depth possible from each dungeon
3. **find_min_index()**: Uses binary search to find the minimum index in a route where a value can be maintained

### Algorithms
- **Binary Search**: Used in the "plan" operation to efficiently find the smallest dungeon
- **Linked Lists**: Used to manage the dynamic nature of dungeons and paths
- **Path Tracking**: Maintains a record of the current path for planning operations

## Time Complexity
- **Downstream/Upstream Operations**: O(1)
- **Plan Operation**: O(log n) using binary search
- **Guess Operation**: O(1) due to pre-computed maximum depths
- **Discover Operation**: O(d) where d is the depth of the dungeon from the entry
- **Construct Operation**: O(k) where k is the number of downstream paths from the current dungeon

## How to Run
```bash
# Compile the code
gcc -o dungeons main.c

# Run with input from file
./dungeons < input.txt

# Run with manual input
./dungeons
```

## Input Format
```
N M Q                  # N: dungeons, M: initial pathways, Q: operations
u1 v1 l1               # First pathway: from u1 to v1 with length l1
...
uM vM lM               # Last initial pathway
operation_1            # First operation
...
operation_Q            # Last operation
```

### Operation Types:
1. `1`: Move downstream
2. `2`: Move upstream
3. `3 t`: Plan for treasure with value t
4. `4`: Guess maximum possible treasure value
5. `5 p`: Discover treasure with value p
6. `6 v l`: Construct pathway to dungeon v with length l

## Output Format
Different operations produce different outputs:
- For operations 1-4: The result of the operation (dungeon number or value)
- For operation 5: Information about escorted treasures (if applicable)
- For operation 6: No output

## Example Usage

### Example: Basic Dungeon Traversal
**Input:**
```
4 3 8
0 1 2
0 2 5
1 3 2
1
3 3
1
1
3 4
3 0
2
2
```

**Output:**
```
1
0
3
-1
0
3
1
0
```

## Technical Challenges
1. **Dynamic Pathway Management**: Handling the creation and destruction of pathways
2. **Treasure Transportation System**: Implementing the complex rules for treasure movement
3. **Maximum Value Calculation**: Efficiently computing the maximum possible treasure value
4. **Memory Management**: Ensuring proper allocation and deallocation of linked list structures

## Constraints
- 2 ≤ N ≤ 10^6 (number of dungeons)
- 0 ≤ M ≤ N-1 (initial pathways)
- 1 ≤ Q ≤ 10^6 (operations)
- Each dungeon (except 0) has at most one upstream pathway
- Path lengths and treasure values can be very large (up to 10^18)
