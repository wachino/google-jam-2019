# Sorting Permutation Unit

## Solution code

See [solution source code c++](/World%20Finals/Sorting%20Permutation%20Unit/solution.cpp)

## Analysis

You can see [solution analysis](/World%20Finals/Sorting%20Permutation%20Unit/analysis.md) extracted from Google webpage.

## Problem

You may have heard of Google's Tensor Processing Units, which are used to build neural networks. However, there is one research area that is even deeper and more important than machine learning: sorting!

We are working on a special new chip called the Sorting Permutation Unit, which is very fast at applying permutations to arrays of integers. Formally, a permutation is an ordering of the first n positive integers

<code>p<sub>1</sub>, p<sub>2</sub>, ..., p<sub>n</sub></code>

and applying it to an array of n integers

<code>a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub></code>

yields the new array

<code>a<sub>p<sub>1</sub></sub>, a<sub>p<sub>2</sub></sub>, ..., a<sub>p<sub>n</sub></sub>.</code>

For example, applying the permutation 3, 1, 2, 4 to the array 99, 234, 45, 800 would yield the new array 45, 99, 234, 800.

However, permutations are expensive to represent in the hardware, so the unit can only have access to at most **P** distinct permutations. We need your help figuring out what those permutations should be!

Given **K** arrays of **N** integers each, you must first specify up to **P** permutations (of size **N**) of your choice. Then, for each of those **K** input arrays, you must provide one sequence of up to **S** instructions (each of which is a permutation from your specified set). When the instructions in this sequence are applied, in the given order, to the array, they must yield an array sorted in nondecreasing order. In each of your **K** sequences of instructions, you may use each of your **P** permutations zero or more times (not necessarily consecutively).

## Input

The first line of the input gives the number of test cases, **T**. **T** test cases follow. Each begins with one line with four integers **P**, **S**, **K**, and **N**: the maximum number of permutations allowed, the maximum number of instructions you are allowed to use to sort each array, the number of arrays, and the number of integers in each array. Then, there are **K** more lines of **N** integers **A<sub>i1</sub>**, **A<sub>i2</sub>**, .., **A<sub>iN</sub>** each, where the j-th integer on the i-th line, **A<sub>ij</sub>**, represents the j-th value of the i-th array.

## Output

For each test case, first output the following, in this order:

- One line containing `Case #x:`, where `x` is the test case number (starting from 1).
- One line containing one integer P', where 1 ≤ P' ≤ **P**: the number of permutations you have chosen to use.
- P' lines, the i-th of which contains **N** integers p<sub>i1</sub> p<sub>i2</sub> ... p<sub>i**N**</sub>, where p<sub>ij</sub> is the j-th element of the i-th permutation.

Then, output **K** more lines. The i-th of these gives the instructions that you will apply to the i-th array given in the input. Each such line must begin with one integer S', where 0 ≤ S' ≤ **S**, and must continue with S' integers X<sub>1</sub>, X<sub>2</sub>, ..., X<sub>S'</sub>, where 1 ≤ X<sub>k</sub> ≤ P' for all k. Here, X<sub>k</sub> represents that the k-th instruction you apply to the i-th array is the X<sub>k</sub>-th permutation (counting starting from 1) in your list of permutations. These instructions must yield an array with the elements of the i-th input array, sorted in nondecreasing order.

## Limits

Time limit: 20 seconds per test set.<br>
Memory limit: 1GB.<br>
1 ≤ **T** ≤ 10.<br>
**S** = 450.<br>
1 ≤ **K** ≤ 30.<br>
2 ≤ **N** ≤ 50.<br>
1 ≤ **A<sub>ij</sub>** ≤ 1000, for all i and j.

### Test set 1 (Visible)

**P** = 20.

### Test set 2 (Hidden)

**P** = 5.

## Sample

| Input       | Output    |
| ----------- | --------- |
| 2           |           |
| 20 450 4 3  | Case #1:  |
| 10 10 11    | 2         |
| 17 4 1000   | 3 1 2     |
| 999 998 997 | 2 1 3     |
| 10 10 11    | 0         |
| 20 450 5 5  | 1 2       |
|             | 2 2 1     |
|             | 1 2       |
| 1 2 3 4 5   | Case #2:  |
| 2 3 4 5 1   | 1         |
| 3 4 5 1 2   | 5 1 2 3 4 |
| 4 5 1 2 3   | 0         |
| 5 1 2 3 4   | 1 1       |
|             | 2 1 1     |
|             | 3 1 1 1   |
|             | 4 1 1 1 1 |

In Sample Case #1, we can define up to **P** = 20 permutations. One viable strategy uses only these two:

1. 3 1 2
1. 2 1 3

We can handle the four arrays as follows:

- `10 10 11`: This is already sorted in nondecreasing order, so we do not need to do anything.
- `17 4 1000`: We can apply permutation #2 to yield 4 17 1000.
- `999 998 997`: One option is to first apply permutation #2 to turn the array into 998 999 997, then apply permutation #1 to turn the array into 997 998 999.
- `10 10 11`: This is the same as the first array. Applying permutation #2 also yields array sorted in nondecreasing order. (But we could have used the line 0 as we did before.)

In Sample Case #2, notice that we can use the same permutation instruction more than once on the same array, if desired.
