# New Elements: Part 2

## Solution code

See [solution source code c++](/Round%202/New%20Elements%3A%20Part%202/solution.cpp)

## Analysis

You can see [solution analysis](/Round%202/New%20Elements%3A%20Part%202/analysis.md) extracted from Google webpage.

## Problem

_The first two paragraphs (not counting this one) of this problem and "New Elements: Part 1" are identical. The problems can otherwise be solved independently; you do not need to read or solve one in order to read or solve the other._

Muriel is on the path to discovering two new elements that she has named Codium and Jamarium. She has not been able to isolate them yet, but she wants to start investigating some important properties, like their atomic weights, by indirect means. Since Muriel is working with a single isotope of Codium and a single isotope of Jamarium, their atomic weights are strictly positive integers.

Muriel managed to create **N** different molecules, each of which contains one or more atoms of Codium and one or more atoms of Jamarium, and no other elements. For each molecule, she knows how many atoms of each element are present in it. The molecular weight of a molecule is the sum of the atomic weights of all the atoms it contains.

As a first step, Muriel sorted the molecules by strictly increasing molecular weight. Now she wants to find out possible integer values for the atomic weights of both Codium and Jamarium that are consistent with the ordering. Since she is aware there could be many consistent pairs of values, she wants one that minimizes the atomic weight of Codium. If there are multiple pairs in which Codium's atomic weight is minimum, she wants the one in which Jamarium's atomic weight is minimum.

## Input

The first line of the input gives the number of test cases, **T**. **T** test cases follow. The first line of a test case contains a single integer **N**, the number of molecules. Each of the next **N** lines describes a different molecule with two integers C<sub>i</sub> and J<sub>i</sub> that represent the number of Codium and Jamarium atoms in the i-th molecule, respectively. The molecules are given in strictly increasing order of molecular weight.

## Output

For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1), and `y` is `IMPOSSIBLE` (in uppercase) if there is no pair of integer atomic weights that would make the order of the molecules strictly increasing in molecular weight. Otherwise, `y` should be two integers `c` `j` where `c` is the atomic weight of Codium and `j` is the atomic weight of Jamarium, chosen according to the rules above.

## Limits

Time limit: 20 seconds per test set.<br>
Memory limit: 1GB.<br>
1 ≤ **T** ≤ 100.<br>
2 ≤ **N** ≤ 10.<br>
(**C<sub>i</sub>**, **J<sub>i</sub>**) ≠ (**C<sub>j</sub>**, **J<sub>j</sub>**) for all i ≠ j. (All molecules are different.)

### Test set 1 (Visible)

1 ≤ **C<sub>i</sub>** ≤ 100, for all i.
1 ≤ **J<sub>i</sub>** ≤ 100, for all i.

### Test set 2 (Hidden)

1 ≤ **C<sub>i</sub>** ≤ 10<sup>9</sup>, for all i.
1 ≤ **J<sub>i</sub>** ≤ 10<sup>9</sup>, for all i.

## Sample

| Input | Output              |
| ----- | ------------------- |
| 3     |                     |
| 3     | Case #1: 2 1        |
| 1 1   |                     |
| 1 2   |                     |
| 2 1   |                     |
| 4     | Case #2: IMPOSSIBLE |
| 1 2   |                     |
| 2 1   |                     |
| 4 2   |                     |
| 2 4   |                     |
| 3     | Case #3: 1 1        |
| 1 2   |                     |
| 1 3   |                     |
| 2 3   |                     |

In Sample Case #1, the difference between the last two molecules is having an extra atom of one element or the other. Given that the one having the extra Codium is heavier overall, we conclude that Codium must be heavier than Jamarium. The values 2 and 1 for the atomic weights of Codium and Jamarium make the molecular weights 1 × 2 + 1 × 1 = 3, 1 × 2 + 2 × 1 = 4, and 2 × 2 + 1 × 1 = 5, respecting the strict ordering. Since Codium is heavier than Jamarium in this case, 2 is Codium's minimum atomic weight, and 1 is of course Jamarium's minimum atomic weight.

Let a, b, c and d be the molecular weights of the molecules in Sample Case #2, in increasing order of molecular weight. By their atom contents, d = 2 × a and c = 2 × b. It follows from a < b that d = 2 × a < 2 × b = c, which means there is no pair of values for the atomic weights that would make the ordering strictly increasing.

In Sample Case #3, notice that the molecules happen to be sorted in strictly increasing order of total number of atoms. Therefore, assigning both elements an atomic weight of 1 makes the atomic weights be sorted in strictly increasing order.
