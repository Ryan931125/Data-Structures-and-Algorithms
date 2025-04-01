# Data Structures and Anticheating

## Description
This program implements a string pattern matching system to detect potential plagiarism between submissions. It calculates similarity scores by combining hit counts and plagiarism likelihood for each prefix of a copier submission against a source submission.

## Algorithm Overview

The system uses a combination of two key string matching algorithms:

1. **Knuth-Morris-Pratt (KMP) Algorithm**: Used to efficiently find all occurrences of patterns in text
2. **Prefix Function Computation**: Used to identify strings that are both prefixes and suffixes

The solution computes two main metrics:

- **Hit Count (H)**: The number of occurrences of a pattern in the source string
- **Plagiarism Likelihood (L)**: The number of prefixes of a string that are also suffixes of that string

These metrics are combined to calculate the **Similarity Score (S)** for each prefix of the copier submission against the source submission, using the formula: S = H × L.

## Implementation Details

### Key Functions

1. **compute_prefix**: Computes the prefix function (π) for a given string
   - Identifies the longest proper prefix that is also a suffix for each position
   - Uses the KMP algorithm's preprocessing step
   - Time complexity: O(m) where m is the string length

2. **kmp_matcher**: Finds all occurrences of a pattern in a text
   - Uses the KMP algorithm for efficient matching
   - Maintains a hit count array to track matches
   - Time complexity: O(n) where n is the text length

3. **main**: Orchestrates the process
   - Reads input strings (source and copier submissions)
   - Computes plagiarism likelihood based on prefix function
   - Calculates and outputs similarity scores for each prefix

### Optimizations

- **Efficient Hit Count Calculation**: Uses the KMP algorithm to avoid redundant text scanning
- **Prefix-Suffix Relationship Tracking**: Efficiently computes plagiarism likelihood using the prefix function
- **Propagation of Hit Counts**: Uses a bottom-up approach to accumulate hit counts

## Time and Space Complexity

- **Time Complexity**: O(|S| + |C|) where |S| is the length of the source submission and |C| is the length of the copier submission
- **Space Complexity**: O(|C|) for storing the prefix function, plagiarism likelihood, and hit counts

## How to Run

```bash
# Compile the code
gcc -o anticheating main.c

# Run with input from file
./anticheating < input.txt

# Run with manual input
./anticheating
```

## Input Format

```
S       # Source submission string
C       # Copier submission string
```

## Output Format

```
S(C[1:1], S)    # Similarity score for the first character of C
S(C[1:2], S)    # Similarity score for the first two characters of C
...
S(C[1:|C|], S)  # Similarity score for the entire string C
```

## Example Usage

### Example 1: Repeated Pattern

**Input:**
```
aaaaa
aaa
```

**Output:**
```
5
8
9
```

In this example:
- For prefix "a": Hit count = 5, Plagiarism likelihood = 1, Score = 5
- For prefix "aa": Hit count = 4, Plagiarism likelihood = 2, Score = 8
- For prefix "aaa": Hit count = 3, Plagiarism likelihood = 3, Score = 9

### Example 2: Distinct Pattern

**Input:**
```
ntucsiedsa
csie
```

**Output:**
```
1
1
1
1
```

## Constraints

- 0 < |S| ≤ 5×10^6
- 0 < |C| ≤ 5×10^6
- Submissions contain only lowercase English letters (except in subtask 2 where only 'a' is allowed)
