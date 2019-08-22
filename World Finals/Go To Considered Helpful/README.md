# Go To Considered Helpful

## Solution code

See [solution source code c++](/World%20Finals/Go%20To%20Considered%20Helpful/solution.cpp)

## Analysis

You can see [solution analysis](/World%20Finals/Go%20To%20Considered%20Helpful/analysis.md) extracted from Google webpage.

## Problem

Marlin is a fish who lost his son and is trying to find him. Fortunately, he ran into Cynthia, a turtle, as she swam around with her brothers, Wally and Seymour. Cynthia knows exactly where Marlin needs to go, and she can be very precise in giving directions. While Marlin is smart and can follow them perfectly, keeping track of a long list of directions can be problematic. Cynthia needs to find a way to make the list of directions short.

Marlin lives in a matrix of **R** rows and **C** columns. Some cells of the matrix are dangerous and cannot be entered. Marlin and his son are currently in different non-dangerous cells. Marlin's son never moves to a different cell. Cynthia decided to give Marlin directions in the form of a program consisting of a list of instructions, each on a single line. Each instruction is of one of 5 types:

- `N`: move one cell North (up),
- `S`: move one cell South (down),
- `W`: move one cell West (left),
- `E`: move one cell East (right), and
- `G(i)`: jump to the i-th line of the instruction list (counting starting from 1).

After executing a line with any of the first 4 instructions, Marlin jumps to the next line on the list if there is one. If there is no next line, Marlin just stands still forever.

For example, if Marlin were following the program

1: N<br>
2: E<br>
3: G(6)<br>
4: S<br>
5: G(1)<br>
6: W<br>
7: G(4)<br>

he would move North (line 1), then East (2), then jump to line 6 without physically moving (3), then move West (6), then jump to line 4 (7), then move South (4), then jump to line 1 (5), then move North (1), etc.

If at any point Marlin and his son are at the same cell, they will be reunited and Marlin will no longer follow any instructions. Cynthia the turtle wants to find out the smallest number of lines in a program that would get Marlin to the same cell as his son, without him ever going into a dangerous cell or moving outside of the matrix boundaries. All `G` instructions must jump to existing lines in the program.

## Input

The first line of the input gives the number of test cases, **T**. **T** test cases follow. Each test case starts with a line containing **R** and **C**, the number of rows and columns in the matrix. Then, **R** lines follow containing a string of **C** characters each. The j-th character of the i-th of these lines **A<sub>ij</sub>** represents the cell in the i-th row and j-th column of the matrix. The character is `#` if the cell is dangerous, an uppercase `M` if the cell is the one Marlin is currently at, an uppercase `N` if the cell is the one Marlin's son is currently at and `.` if the cell is an unoccupied non-dangerous cell.

## Output

For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and y is `IMPOSSIBLE` if there is no program that would get Marlin to his son under the conditions explained above, or the smallest number of instructions in such a program.

## Limits

Memory limit: 1GB.<br>
1 ≤ **T** ≤ 100.<br>
**A<sub>ij</sub>** is either `#`, ., uppercase `M` or uppercase `N`, for all i and j.<br>
**A<sub>ij</sub>** = M for exactly one pair of i and j.<br>
**A<sub>ij</sub>** = N for exactly one pair of i and j.

### Test set 1 (Visible)

Time limit: 30 seconds.<br>
1 ≤ **R** ≤ 10.<br>
1 ≤ **C** ≤ 10.

### Test set 2 (Hidden)

Time limit: 120 seconds.

For at most 10 test cases:<br>
1 ≤ **R** ≤ 100.<br>
1 ≤ **C** ≤ 100.

For the remaining test cases:<br>
1 ≤ **R** ≤ 50.<br>
1 ≤ **C** ≤ 50.

## Sample

| Input | Output              |
| ----- | ------------------- |
| 5     |                     |
| 2 5   | Case #1: 4          |
| N...# |                     |
| ....M |                     |
| 2 5   | Case #2: 7          |
| N#... |                     |
| ...#M |                     |
| 5 5   | Case #3: 5          |
| N..## |                     |
| #.### |                     |
| #...# |                     |
| ##.## |                     |
| ##..M |                     |
| 5 5   | Case #4: 6          |
| ..N## |                     |
| #.### |                     |
| #...# |                     |
| ##.## |                     |
| ##..M |                     |
| 3 3   | Case #5: IMPOSSIBLE |
| #M#   |                     |
| ###   |                     |
| #N#   |                     |

Below are some shortest programs for each of the possible sample case.

- Sample Case #1:
  1: W<br>
  2: N<br>
  3: S<br>
  4: G(1)

  or

  1: W<br>
  2: N<br>
  3: W<br>
  4: G(3)

  .

- Sample Case #2:
  1: N<br>
  2: W<br>
  3: W<br>
  4: S<br>
  5: W<br>
  6: W<br>
  7: N

  .

- Sample Case #3:
  1: W<br>
  2: W<br>
  3: N<br>
  4: N<br>
  5: G(2)

  .

- Sample Case #4:
  1: W<br>
  2: W<br>
  3: N<br>
  4: N<br>
  5: E<br>
  6: G(1)

  .

Notice that even though the program must contain the smallest possible number of lines, it is not required to minimize the number of moves that Marlin makes.
