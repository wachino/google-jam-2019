# Juggle Struggle: Part 1

## Solution code

See [solution source code c++](/World%20Finals/Juggle%20Struggle%3A%20Part%201/solution.cpp)

## Analysis

You can see [solution analysis](/World%20Finals/Juggle%20Struggle%3A%20Part%201/analysis.md) extracted from Google webpage.

## Problem

_The first two paragraphs (not counting this one) of this problem and "Juggle Struggle: Part 2" are identical. The problems can otherwise be solved independently; you do not need to read or solve one in order to read or solve the other._

As manager of the Graceful Chainsaw Jugglers group, you have decided to spice the show up a bit. Instead of having each juggler individually juggle their own chainsaws, you want them to form pairs, with each pair throwing the chainsaws back and forth to each other. In this new performance, 2 × **N** jugglers will be on stage at the same time, arranged into **N** pairs, with each juggler belonging to exactly one pair.

You think the show will be more impressive if the chainsaws being juggled by different pairs of jugglers are at risk of collision. Let the stage be a two-dimensional plane, and let the straight line segment in that plane that connects the positions of two jugglers in a pair be called the pair's juggling path. When two juggling paths intersect, we say the chainsaws juggled by those pairs are at risk of collision. We call the spatial positions and the pairings of the jugglers an arrangement. An arrangement is magnificent if every two pairs of jugglers' chainsaws are at risk of collision.

After a lot of thinking and designing, you came up with a magnificent arrangement. You wrote down the positions of the jugglers on the stage and the pairings of the jugglers on a piece of paper. Unfortunately, a bad chainsaw throw cut the paper in half, and you have lost the half with the pairings. Since the stage decorations have already been designed based on the positions of the jugglers, those positions cannot be changed. The show's highly anticipated debut is a mere few hours away, so you need to find a magnificent arrangement that works! Given every juggler's position on a two-dimensional stage, find a pairing of them that yields a magnificent arrangement.

## Input

The first line of the input gives the number of test cases, **T**. **T** test cases follow. Each test case starts with one line containing a single integer **N**, the number of pairs of jugglers. Then, 2 × **N** lines follow. The i-th of these lines contains two integers **X<sub>i</sub>** and **Y<sub>i</sub>**, representing the coordinates of the position of the i-th juggler.

## Output

For each test case, output one line containing <code>Case #x: j<sub>1</sub> j<sub>2</sub> ... j<sub>2 × <b>N</b></sub></code>, representing that jugglers i and j<sub>i</sub> are to be paired together, for every i. Notice that j<sub>j<sub>i</sub></sub> = i for every i.

## Limits

Memory limit: 1GB.<br>
-10<sup>9</sup> ≤ **X<sub>i</sub>** ≤ 10<sup>9</sup>, for all i.<br>
-10<sup>9</sup> ≤ **Y<sub>i</sub>** ≤ 10<sup>9</sup>, for all i.<br>
No three juggler positions are collinear. (Note that this also implies that no two jugglers are in the same position.)<br>
There exists at least one way to pair the jugglers such that the resulting arrangement is magnificent.

### Test set 1 (Visible)

Time limit: 20 seconds.<br>
1 ≤ **T** ≤ 100.<br>
2 ≤ **N** ≤ 100.

### Test set 2 (Hidden)

Time limit: 60 seconds.<br>
1 ≤ **T** ≤ 10.<br>
2 ≤ **N** ≤ 10<sup>5</sup>.

## Sample

| Input | Output               |
| ----- | -------------------- |
| 3     |                      |
| 2     | Case #1: 3 4 1 2     |
| -1 -1 |                      |
| -1 1  |                      |
| 1 1   |                      |
| 1 -1  |                      |
| 3     | Case #2: 6 5 4 3 2 1 |
| 1 2   |                      |
| 2 1   |                      |
| 2 3   |                      |
| 3 1   |                      |
| 3 3   |                      |
| 4 2   |                      |
| 3     | Case #3: 5 4 6 2 1 3 |
| 7 1   |                      |
| 1 1   |                      |
| 7 2   |                      |
| 5 5   |                      |
| 3 5   |                      |
| 1 2   |                      |

In Sample Case #1, the jugglers' positions form a square. The only valid solution is to pair up jugglers 1 and 3, and pair up jugglers 2 and 4.
