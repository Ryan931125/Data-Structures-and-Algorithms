# Red-Black Tree Implementation

This repository contains a C implementation of a Red-Black Tree with left and right rotation operations. The code demonstrates fundamental operations on a Red-Black Tree, specifically focusing on rotations and tree traversal techniques.

## Overview

A Red-Black Tree is a self-balancing binary search tree with additional properties that ensure the tree remains approximately balanced. This implementation provides functionality for:

- Creating a Red-Black Tree from a preorder traversal
- Performing left and right rotations
- Calculating depth and black-depth of nodes
- Traversing the tree

## Features

- **Tree Construction**: Build a Red-Black Tree from preorder traversal
- **Left Rotation**: Implementation of the standard left rotation operation
- **Right Rotation**: Implementation of the standard right rotation operation
- **Node Information**: Calculate and display information about specific nodes, including:
  - Left and right child keys
  - Black-depth of a node
  - Depth of a node

## Technical Details

The implementation uses the following data structures:

- `Node`: Represents a node in the Red-Black Tree, containing data, color information, and pointers to left, right, and parent nodes
- `Stack`: Used during tree construction from preorder traversal

## Usage

### Input Format

The program takes input in the following format:

1. The first line contains a single positive integer `N`, representing the number of internal nodes in the Red-Black Tree.
2. The next `N` lines each contain:
   - A character `C` ('B' for black, 'R' for red) representing the node's color
   - An integer `k` representing the node's key
3. The next line contains a single integer `M`, representing the number of operations to perform.
4. The next `M` lines each contain an operation in one of the following formats:
   - `L k`: Perform a left rotation on the node with key `k`
   - `R k`: Perform a right rotation on the node with key `k`
   - `P k`: Print information about the node with key `k`

### Output Format

For each `P k` operation, the program outputs a line in the format:
- `LK RK BD D`: Where `LK` is the key of the left child, `RK` is the key of the right child, `BD` is the black-depth, and `D` is the depth.
- If a child is `NULL`, its key is output as `-1`.

## Sample Input/Output

### Sample 1

Input:
```
5
B 2
B 1
B 4
R 3
R 5
5
P 4
L 2
P 4
R 4
P 4
```

Output:
```
3 5 1 1
2 5 0 0
3 5 1 1
```

### Sample 2

Input:
```
2
B 2
R 1
3
P 2
R 2
P 2
```

Output:
```
1 -1 0 0
-1 -1 0 1
```

## Compilation and Execution

To compile the program, use GCC:

```bash
gcc -o red_black_tree main.c
```

To run with input from a file:

```bash
./red_black_tree < input.txt
```

## Implementation Notes

- The code assumes valid inputs and does not check for edge cases like non-existent nodes.
- After rotations, the Red-Black Tree properties might not be maintained as the focus is on the rotation operations themselves.
- The implementation uses a stack-based approach to construct the tree from a preorder traversal.
