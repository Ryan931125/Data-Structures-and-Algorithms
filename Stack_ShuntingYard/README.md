# Stack + Shunting Yard

## Problem

Given infix arithmetic expressions with non-negative integers, operators (`+ - * / %`), and parentheses, convert each expression to postfix form and output its evaluated value.

## Time and Space Complexity

- Time: O(n) per expression
- Space: O(n)

## Input

- Three lines, each containing one valid infix expression (no spaces)

## Output

- For each expression: `postfix=value`

## Solution

I use a two-step stack approach.

1. Infix to postfix:

- numbers are emitted directly
- operators are pushed to a stack
- higher/equal precedence operators are popped first
- parentheses control pop boundaries

2. Postfix evaluation:

- numbers push onto a value stack
- each operator pops two values, computes, then pushes result

This keeps precedence handling correct while remaining linear.
