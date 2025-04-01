# Decks of Cards

## Description
This program implements a card deck management system that can handle multiple operations on N decks of cards. The solution uses a linked list data structure to efficiently perform various card manipulation operations.

## Operations
The program supports four types of operations:

1. **Add (Type 1)**: Add a card numbered u to the top of deck i.
2. **Remove (Type 2)**: Remove a card from the top of deck i.
3. **Move (Type 3)**: Move all cards from deck i onto the top of deck j.
4. **Merge (Type 4)**: Merge deck i into deck j in a shuffling manner.

### Merge Operation Details
The merge operation follows this procedure:
1. Take the top card from deck i and place it at the bottom of a temporary deck
2. Take the top card from deck j and place it at the bottom of the temporary deck
3. Alternate between decks until one is empty
4. If one deck becomes empty, move all remaining cards from the other deck to the temporary deck
5. Place the entire temporary deck into deck j

## Implementation

### Data Structure
- Uses a singly linked list to represent each deck
- Each node contains a card number and a pointer to the card beneath it
- Maintains both top and bottom pointers for efficient operations

### Time Complexity
- **Add**: O(1)
- **Remove**: O(1)
- **Move**: O(1)
- **Merge**: O(n) where n is the total number of cards in the two decks

### Space Complexity
- O(N + M) where N is the number of decks and M is the total number of cards across all decks

## How to Run
```bash
# Compile the code
gcc -o cards main.c

# Run with input from file
./cards < input.txt

# Run with manual input
./cards
```

## Input Format
```
N M           # N: number of decks, M: number of operations
t i [u/j]     # t: operation type (1-4), i: first deck, u/j: card number or second deck
...           # M operations in total
```

## Output Format
```
c1 card1 card2 ... cardC1    # Deck 1: count followed by cards from top to bottom
c2 card1 card2 ... cardC2    # Deck 2: count followed by cards from top to bottom
...                          # N decks in total
```

## Example Usage

### Input
```
2 5
1 1 1
1 1 2
1 2 3
1 2 4
3 1 2
```

### Output
```
0 
4 2 1 4 3
```

## Memory Management
- The implementation dynamically allocates memory for card nodes
- Uses a custom node generation function for clean allocation

## Edge Cases Handled
- Empty deck operations
- Merging with empty decks
- Moving cards between decks of varying sizes

## Notes
- This implementation can handle up to 10^5 decks and operations
- Card numbers can be as large as 10^9
- Optimized for large-scale card manipulation operations
