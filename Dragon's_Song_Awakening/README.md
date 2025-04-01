# Dragon's Song: Awakening

## Description
This program simulates a game called "Dragon's Song: Awakening" (DSA) where N classmates have initial powers and ranks. The implementation supports various operations including attacks, rewards, power queries, and attack history tracking.

## Problem Overview
N classmates labeled 1 to N initially have powers p₁, p₂, ..., pₙ (where p₁ ≥ p₂ ≥ ... ≥ pₙ). The game involves four types of incidents:

1. **Attack**: A classmate increases their power to match the classmate in front of them, then they swap ranks.
2. **Reward**: Each classmate gets a power increase based on their rank (rank 1 gets N-1 points, rank 2 gets N-2 points, etc.).
3. **Power Query**: Find the last rank with power ≥ q and report that classmate's label.
4. **Attack History Query**: Calculate total power increase for a classmate from their last m attacks.

## Implementation Details

### Data Structures
- **Vector**: Custom dynamic array implementation for storing attack history
- **Classmate struct**: Contains a player's label, power, attack count, and power gain history
- **Mapping arrays**: Track the relationship between labels and ranks

### Key Functions
- `true_power()`: Calculates a player's actual power including any pending rewards
- `query()`: Uses binary search to find the last rank with power ≥ q
- `pushBack()`: Adds elements to the custom vector implementation
- `getElement()`: Retrieves elements from the vector at specific positions

### Optimizations
- Binary search for efficient power queries
- Dynamic memory allocation with capacity doubling for the vector implementation
- Efficient rank and label tracking to handle frequent rank changes

## Time and Space Complexity
- **Time Complexity**: 
  - Attack/Reward operations: O(1)
  - Power Query: O(log N) using binary search
  - Attack History Query: O(1) using pre-computed prefix sums
- **Space Complexity**: O(N + T) where N is the number of classmates and T is the number of attack operations

## How to Run
```bash
# Compile the code
gcc -o dragons_song main.c

# Run with input file
./dragons_song < input.txt

# Run with manual input
./dragons_song
```

## Input Format
```
N T M
p₁ p₂ ... pₙ
operation_1
operation_2
...
operation_T
```
Where:
- N = number of classmates, T = number of incidents, M = max query length
- p₁ p₂ ... pₙ = initial power values
- operations are one of:
  - `1 a` (attack by classmate a)
  - `2` (reward all)
  - `3 q` (power query)
  - `4 b m` (attack history query)

## Output Format
The output has two parts:
1. Results of power queries and attack history queries
2. Game record showing number of attacks and power increases for each classmate

## Example
### Input
```
5 6 10
20 15 10 10 0
1 1
1 4
1 4
2
3 16
4 4 10
```

### Output
```
3 2
5

0
0
0
2 0 5
0
```

## Constraints
- 1 ≤ N ≤ 10⁶
- 1 ≤ T ≤ 5·10⁵
- 1 ≤ M ≤ 5·10⁵
- 0 ≤ pₙ ≤ pₙ₋₁ ≤ ... ≤ p₁ ≤ 10⁹
- Power queries: 0 ≤ q ≤ 10¹⁸
- Attack history queries: 1 ≤ m ≤ M
