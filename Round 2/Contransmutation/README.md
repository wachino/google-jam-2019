# Contransmutation

## Solution code

See [solution source code js](/Round%202/Contransmutation/solution.js)

## Analysis

You can see [solution analysis](/Round%202/Contransmutation/analysis.md) extracted from Google webpage.

## Problem

Last year, we asked you to help us [convert expensive metals into lead](https://codingcompetitions.withgoogle.com/codejam/round/0000000000007764/000000000003675c). (You do not need to know anything about the previous problem to solve this one.) But your country's leader is still greedy for more lead!

There are **M** metals known in the world; lead is metal number 1 on your periodic table. Your country's leader has asked you to use the metals in the treasury to make as much lead as possible.

For each metal (including lead), you know exactly one formula that lets you destroy one gram of that metal and create one gram each of two metals. (It is best not to think too much about the principle of mass conservation!) Note that it is possible that the formula for the i-th metal might produce the i-th metal as one of the products. The formulas do not work with partial grams. However, you can use each formula as often as you would like (or not at all), as long as you have a gram of the required ingredient.

If you make optimal choices, what is the largest number of grams of lead you can end up with, or is it unbounded? If it is not unbounded: since the output can be a really big number, we only ask you to output the remainder of dividing the result by the prime 10<sup>9</sup>+7 (that is, 1000000007).

## Input

The first line of the input gives the number of test cases, **T**. **T** test cases follow. Each begins with one line with an integer **M**: the number of metals known in the world. Then there are M more lines with two integers **R<sub>i1</sub>** and **R<sub>i2</sub>** each; the i-th of these lines, counting starting from 1, indicates that you can destroy one gram of metal i to create one gram of metal **R<sub>i1</sub>** and one gram of metal **R<sub>i2</sub>**. Finally, there is one line with M integers **G<sub>1</sub>**, **G<sub>2</sub>**, ..., **G<sub>M</sub>**; **G<sub>i</sub>** is the number of grams of metal i in the treasury. Lead is metal 1.

## Output

For each test case, output one line containing `Case #x: y` where `x` is the test case number (starting from 1). If there is no bound on the maximum amount of lead that can be produced, y must be `UNBOUNDED`. Otherwise, y must be the largest amount of lead, in grams, that you can end up with, modulo the prime 10<sup>9</sup>+7 (that is, 1000000007).

## Limits

1 ≤ **R<sub>i1</sub>** < **R<sub>i2</sub>** ≤ **M**, for all i.<br>
Time limit: 20 seconds per test set.<br>
Memory limit: 1GB.

### Test set 1 (Visible)

1 ≤ **T** ≤ 100.<br>
2 ≤ **M** ≤ 10.<br>
0 ≤ **G<sub>i</sub>** ≤ 10, for all i.

### Test set 2 (Hidden)

1 ≤ **T** ≤ 100.<br>
2 ≤ **M** ≤ 100.<br>
0 ≤ **G<sub>i</sub>** ≤ 10, for all i.

### Test set 3 (Hidden)

1 ≤ **T** ≤ 5.<br>
2 ≤ **M** ≤ 10<sup>5</sup>.<br>
0 ≤ **G<sub>i</sub>** ≤ 10<sup>9</sup>, for all i.

## Sample

| Input       | Output             |
| ----------- | ------------------ |
| 3           |                    |
| 2           | Case #1: UNBOUNDED |
| 1 2         |                    |
| 1 2         |                    |
| 1 0         |                    |
| 2           | Case #2: 0         |
| 1 2         |                    |
| 1 2         |                    |
| 0 0         |                    |
| 4           | Case #3: 10        |
| 2 4         |                    |
| 3 4         |                    |
| 2 4         |                    |
| 2 3         |                    |
| 10 10 10 10 |                    |

In Sample Case #1, you have one formula that turns 1 gram of lead into 1 gram of lead and 1 gram of the second metal, and another formula that turns 1 gram of the second metal into 1 gram of lead and 1 gram of the second metal. You can alternate between these formulas to produce as much of both metals as you want.

Sample Case #2 has the same formulas as Sample Case #1, but you have no metals to start with!

In Sample Case #3, none of the formulas help you produce more lead, so you cannot end up with more lead than you started with.
