# New Elements: Part 1

## Solution code

See [solution source code c++](/Round%202/New%20Elements%3A%20Part%201/solution.cpp)

## Analysis

You can see [solution analysis](/Round%202/New%20Elements%3A%20Part%201/analysis.md) extracted from Google webpage.

## Problem

_The first two paragraphs (not counting this one) of this problem and "New Elements: Part 2" are identical. The problems can otherwise be solved independently; you do not need to read or solve one in order to read or solve the other._

Muriel is on the path to discovering two new elements that she has named Codium and Jamarium. She has not been able to isolate them yet, but she wants to start investigating some important properties, like their atomic weights, by indirect means. Since Muriel is working with a single isotope of Codium and a single isotope of Jamarium, their atomic weights are strictly positive integers.

Muriel managed to create **N** different molecules, each of which contains one or more atoms of Codium and one or more atoms of Jamarium, and no other elements. For each molecule, she knows how many atoms of each element are present in it. The molecular weight of a molecule is the sum of the atomic weights of all the atoms it contains.

As a first step towards figuring out exact molecular weights for the molecules and atomic weights for the two elements, Muriel wants to sort the molecules by strictly increasing molecular weight. To assess the difficulty of that task, she wants to know how many orders are valid considering only the information she has right now. An ordering of the molecules is considered valid if there exist values for the atomic weights of Codium and Jamarium such that the ordering is strictly increasing in molecular weight.

To give an example, we represent each molecule by the ordered pair of the number of atoms of Codium and Jamarium it contains. If Muriel has 3 molecules represented by (1, 1), (2, 1) and (1, 2), there are two possible orderings that can be strictly increasing in molecular weight: (1, 1), (1, 2), (2, 1) and (1, 1), (2, 1), (1, 2). The first ordering is valid for any assignment of atomic weights in which Codium is the heaviest of the two elements, and the second is valid for any assignment in which Jamarium is the heaviest. The only case remaining is when both Codium and Jamarium have the same atomic weight, in which case (1, 2) and (2, 1) have the same molecular weight, so no strictly increasing ordering can be produced for that scenario.

## Input

The first line of the input gives the number of test cases, **T**. **T** test cases follow. The first line of a test case contains a single integer **N**, the number of molecules. Each of the next **N** lines describes a different molecule with two integers C<sub>i</sub> and J<sub>i</sub> that represent the number of Codium and Jamarium atoms in the i-th molecule, respectively.

## Output

For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is the total number of valid orderings as defined above.

## Limits

Time limit: 20 seconds per test set.<br>
Memory limit: 1GB.<br>
1 ≤ **T** ≤ 100.<br>
1 ≤ **C<sub>i</sub>** ≤ 10<sup>9</sup>, for all i.<br>
1 ≤ **J<sub>i</sub>** ≤ 10<sup>9</sup>, for all i.<br>
(**C<sub>i</sub>**, **J<sub>i</sub>**) ≠ (**C<sub>j</sub>**, **J<sub>j</sub>**) for all i ≠ j. (All molecules are different.)

### Test set 1 (Visible)

1 ≤ **N** ≤ 6.

### Test set 2 (Hidden)

1 ≤ **N** ≤ 300.

## Sample

| Input | Output     |
| ----- | ---------- |
| 3     |            |
| 3     | Case #1: 2 |
| 1 1   |            |
| 1 2   |            |
| 2 1   |            |
| 4     | Case #2: 2 |
| 1 2   |            |
| 2 4   |            |
| 2 1   |            |
| 4 2   |            |
| 3     | Case #3: 1 |
| 1 2   |            |
| 1 3   |            |
| 2 3   |            |

Sample Case #1 is explained in the statement.

In Sample Case #2, the two valid orderings are (1, 2), (2, 1), (2, 4), (4, 2) and (2, 1), (1, 2), (4, 2), (2, 4). Notice that the ordering (1, 2), (2, 1), (4, 2), (2, 4) is invalid because if (1, 2) is strictly less heavy than (2, 1), then (2, 4), which is exactly twice as heavy as (1, 2), must be strictly less heavy than (4, 2), which is exactly twice as heavy as (2, 1).
