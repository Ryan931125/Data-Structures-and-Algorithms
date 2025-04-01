# Multi-line String Matching

## Description
This program implements a multi-line string matching algorithm that combines the Rabin-Karp and Knuth-Morris-Pratt (KMP) algorithms. The implementation efficiently searches for occurrences of a multi-line pattern within a multi-line text, identifying both valid matches and spurious hits.

## Algorithm Overview
The implementation uses a two-phase approach:

1. **Rabin-Karp Hashing Phase**:
   - Converts multi-line text T and pattern P into one-dimensional arrays T' and P'
   - Uses column-wise hashing with the formula:
     ```
     τ(Q, j) = d^(k-1)·Q[1,j] + d^(k-2)·Q[2,j] + ... + d·Q[k-1,j] + Q[k,j] (mod q)
     ```
     where d=52 (alphabet size) and q is a large prime number

2. **KMP Matching Phase**:
   - Applies the KMP algorithm on the transformed arrays T' and P'
   - Computes the prefix function for pattern P'
   - Identifies potential matches (valid shifts)

3. **Verification Phase**:
   - Validates potential matches by comparing the original multi-line text and pattern
   - Distinguishes between true matches and spurious hits (hash collisions)

## Implementation Details

### Key Functions
1. **compute_prefix_function()**: Computes the prefix function for the KMP algorithm
2. **KMP_Matcher()**: Performs string matching using the KMP algorithm
3. **Main Function**: Handles input, Rabin-Karp hashing, and verification of matches

### Character Encoding
- Uppercase letters ('A' to 'Z'): Values 0 to 25
- Lowercase letters ('a' to 'z'): Values 26 to 51

## Time and Space Complexity
- **Rabin-Karp Hashing**: O(k(n+m)) where k is the number of lines, n is text length, and m is pattern length
- **KMP Preprocessing**: O(m) for computing the prefix function
- **KMP Matching**: O(n) for finding all pattern occurrences
- **Space Complexity**: O(n+m) for storing the hashed arrays and prefix function

## How to Run
```bash
# Compile the code
gcc -o string_matching main.c

# Run with input from file
./string_matching < input.txt

# Run with manual input
./string_matching
```

## Input Format
```
k n m q               # k: number of lines, n: text length, m: pattern length, q: prime modulus
T[1][1...n]           # First line of text T
T[2][1...n]           # Second line of text T
...
T[k][1...n]           # k-th line of text T
P[1][1...m]           # First line of pattern P
P[2][1...m]           # Second line of pattern P
...
P[k][1...m]           # k-th line of pattern P
```

## Output Format
```
T'[1] T'[2] ... T'[n]  # Hashed representation of text T
P'[1] P'[2] ... P'[m]  # Hashed representation of pattern P
s1 s2 ...              # All valid shifts (or -1 if none)
s1 s2 ...              # All spurious hits (or -1 if none)
```

## Example Usage

### Example 1: Simple Match with No Spurious Hits
**Input:**
```
1 6 3 53
ABCxyz
ABC
```

**Output:**
```
0 1 2 49 50 51
0 1 2
0
-1
```

### Example 2: No Valid Matches
**Input:**
```
3 5 3 1000000007
abcde
fghij
klmno
ABC
FGH
KLM
```

**Output:**
```
71952 74709 77466 80223 82980
270 3027 5784
-1
-1
```

### Example 3: Matches with Spurious Hits
**Input:**
```
1 6 1 2
abcdef
a
```

**Output:**
```
0 1 0 1 0 1
0
0 2 4
2 4
```

## Constraints
- 1 ≤ k, n, m ≤ 10^6
- 1 ≤ km ≤ kn ≤ 10^6
- 2 ≤ q ≤ 10^9 + 7
- Input strings use only uppercase and lowercase English letters
