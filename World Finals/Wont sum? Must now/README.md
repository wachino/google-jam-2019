# Won't Sum? Must Now

## Solution code

See [solution source code c++](/World%20Finals/Wont%20Sum%3F%20Must%20Now/solution.cpp)

## Analysis

You can see [solution analysis](/World%20Finals/Wont%20Sum%3F%20Must%20Now/analysis.md) extracted from Google webpage.

## Problem

In 2016, it was shown that every positive integer can be written as the sum of three or fewer palindromic terms. For the purposes of this problem, a palindromic term is a string of digits (with no leading zeroes) that represents a positive integer and reads the same forward and backward.

Given a positive integer **S**, find K palindromic terms that sum to **S**, such that K is minimized.

## Input

The first line of input gives the number of test cases, **T**. **T** lines follow, each containing a positive integer **S**.

## Output

For each test case, output one line of the form `Case #x: A1` (if only one term is needed), `Case #x: A1 A2` (if only two terms are needed), or `Case #x: A1 A2 A3` (if three terms are needed), where x is the case number (counting starting from 1), each A<sub>i</sub> is a palindromic term (as described above), and the sum of the A<sub>i</sub>s equals **S**.

## Limits

Time limit: 20 seconds per test set.<br>
Memory limit: 1GB.<br>
1 ≤ **T** ≤ 100.

### Test set 1 (Visible)

1 ≤ **S** ≤ 10<sup>10</sup>.

### Test set 2 (Hidden)

1 ≤ **S** ≤ 10<sup>40</sup>.

## Sample

| Input      | Output                             |
| ---------- | ---------------------------------- |
| 3          |                                    |
| 1          | Case #1: 1                         |
| 198        | Case #2: 191 7                     |
| 1234567890 | Case #3: 672787276 94449 561686165 |

In Sample Case #1, the input is already a palindrome.

In Sample Case #2, note that `99 99`, for example, would also be an acceptable answer. Even though there are multiple instances of `99`, they count as separate terms, so this solution uses the same number of terms as `191 7`.

Also note that `191 07`, `181 8 9`, `0110 88`, `101 97`, `7.0 191.0`, and `-202 4`, for example, would not be acceptable answers.
