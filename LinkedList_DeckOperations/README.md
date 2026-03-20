# Linked List Deck Operations

## Problem

Maintain `N` card decks under four operations:

- push card to top
- pop top card
- move all cards from one deck to another
- merge two decks by alternating cards from their tops

## Time and Space Complexity

- Push: O(1)
- Pop: O(1)
- Move all: O(1)
- Alternating merge: O(a + b)
- Space: O(total cards)

## Input

- `N M`
- `M` operation lines (types 1 to 4)

## Output

- Final content of each deck: card count, then cards from top to bottom

## Solution

Each deck is a singly linked list with head and tail pointers.

- head gives O(1) top operations
- tail gives O(1) concatenation for move-all
- merge is built by alternating pops from two heads into a temporary list

This structure avoids expensive shifting and scales well for large operations.
