# Arithmetic Expression Converter and Evaluator

## Description
This program converts infix arithmetic expressions to postfix notation and then evaluates them. It handles non-negative integers and various binary operators (+, -, *, /, %) along with parentheses for expression grouping.

## Algorithm Overview
The implementation consists of two main algorithms:

### 1. Infix to Postfix Conversion
The program converts infix expressions to postfix using the shunting yard algorithm:
- Numbers are directly output to the postfix expression
- Operators are pushed onto a stack and popped based on precedence rules
- Parentheses control the evaluation order
- Higher precedence operators (*, /, %) are processed before lower precedence ones (+, -)

### 2. Postfix Expression Evaluation
After conversion, the postfix expression is evaluated using a stack-based approach:
- Numbers are pushed onto a stack
- When an operator is encountered, the top two values are popped
- The operation is performed and the result is pushed back onto the stack
- The final result is the only value remaining on the stack

## Implementation Details

### Key Functions
- **higher_precedence()**: Determines if an operator has higher or equal precedence
- **calculate()**: Performs arithmetic operations on two numbers
- **infix_to_postfix()**: Converts an infix expression to postfix notation
- **postfix_eval()**: Evaluates a postfix expression to produce a numeric result

### Data Handling
- Numbers in the expression are converted to `long long` type to handle large values
- Operators are processed according to their precedence
- Parenthesized expressions are evaluated with proper precedence rules
- Division and modulo operations follow C language integer arithmetic rules

## Time and Space Complexity
- **Time Complexity**: O(n) where n is the length of the expression
- **Space Complexity**: O(n) for storing the expression and intermediate results

## How to Run
```bash
# Compile the code
gcc -o expression_evaluator main.c

# Run with input from file
./expression_evaluator < input.txt

# Run with manual input
./expression_evaluator
```

## Input Format
The program reads three lines, each containing a valid infix expression without spaces:
```
expr1
expr2
expr3
```

## Output Format
For each infix expression, the program outputs:
```
[postfix]=[value]
```
Where:
- `[postfix]` is the postfix representation of the input expression
- `[value]` is the final evaluated value

## Example Usage

### Example 1: Basic Operations
**Input:**
```
8+9
8+9*6
8+9*6-4
```

**Output:**
```
89+=17
896*+=62
896*+4-=58
```

### Example 2: Parentheses Usage
**Input:**
```
(8+9)*6
(8+9)*(6-4)
(8-9)%(6-4)
```

**Output:**
```
89+6*=102
89+64-*=34
89-64-%=-1
```

## Constraints
- Each test case contains 3 expressions
- Expression length is at most 4000 characters
- Numbers are non-negative integers within the range of unsigned int
- Intermediate and final results stay within long long range
- No division by zero will occur
