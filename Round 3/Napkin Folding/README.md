# Napkin Folding

## Solution code

See [solution source code c++](/Round%203/Napkin%20Folding/solution.cpp)

## Analysis

You can see [solution analysis](/Round%203/Napkin%20Folding/analysis.md) extracted from Google webpage.

## Problem

Chalk has been actively traveling the world with his friends taking pictures in all the coolest places. Most recently, he made his way to Europe, where he studied the history of [napkin folding](https://en.wikipedia.org/wiki/Napkin_folding). Ever since, Chalk has been collecting a wide variety of napkins to practice the art of napkin folding.

Chalk's napkins can be defined as [simple polygons](https://en.wikipedia.org/wiki/Simple_polygon). A simple polygon is a polygon in which no edges intersect except for adjacent edges which meet at their shared vertex. Each vertex of the polygon is on exactly two edges.

Chalk folds his napkins by first drawing a _folding pattern_ on them. A folding pattern is a set of **K**-1 line segments which are drawn on the napkin. Each line segment connects two points with rational coordinates on the border of the polygon defining the napkin and is fully contained in the polygon. No two line segments in a folding pattern may touch or overlap, except possibly at common endpoints. A folding pattern of **K**-1 line segments splits the napkin into **K** polygonal regions. Two points are in the same region if there exists some continuous line (not necessarily straight) between them which does not intersect any edge of the polygon or any line segment in the folding pattern — even at endpoints.

Chalk is only interested in neat _folding patterns_. A folding pattern is _neat_ if any two regions that are adjacent to the same folding line segment **F** are [symmetric](https://en.wikipedia.org/wiki/Reflection_symmetry) with respect to **F**. This means that folding the napkin along that line segment would result in the two regions lining up perfectly.

The following picture illustrates a neat folding pattern with **K**=8 regions.

![Napkin Folding](/images/round-3-napkin-folding.png)

Chalk has been successfully folding his collection of napkins using neat folding patterns. But he has some napkins in his collection that he has not been able to find a neat folding pattern for. For each of those napkins, Chalk needs your help to find a neat folding pattern with **K** regions or determine that no such neat folding pattern exists.

## Input

The first line of the input gives the number of test cases, **T**. **T** test cases follow. Each test case starts with a line containing two integers **N** and **K**: the number of points in the polygon defining Chalk's napkin and the number of regions to split the napkin into with a neat folding pattern containing **K**-1 line segments.

The polygon defining the napkin is represented as a list of the **N** vertices, as encountered when traveling along the perimeter of the polygon in the clockwise direction, with the first vertex being chosen arbitrarily. The next **N** lines represent that list. The i-th of these contains two integers **X<sub>i</sub>** and **Y<sub>i</sub>**, indicating that the i-th point is located at (**X<sub>i</sub>**, **Y<sub>i</sub>**) in two-dimensional space.

## Output

For each test case, output one line containing `Case #x: y`, where `x` is the test case number (starting from 1) and `y` is `POSSIBLE` if it is possible to make a neat folding pattern with **K** regions and `IMPOSSIBLE` otherwise.

If it is possible to make a neat folding pattern with **K** regions, output **K**-1 more lines listing the segments of a neat folding pattern with K regions, in any order. Each line should represent a different segment as <code>A<sub>x</sub></code> <code>A<sub>y</sub></code> <code>B<sub>x</sub></code> <code>B<sub>y</sub></code>, where (<code>A<sub>x</sub></code>, <code>A<sub>y</sub></code>) and (<code>B<sub>x</sub></code>, <code>B<sub>y</sub></code>) are the two endpoints of the segment, in any order. Each of <code>A<sub>x</sub></code>, <code>A<sub>y</sub></code>, <code>B<sub>x</sub></code>, and <code>B<sub>y</sub></code> should be in the form `N/D` where `N` and `D` are positive integers (written with no leading zeroes) sharing no common prime factors, and representing the rational number `N/D`. There must be no whitespace between `N` and `/`, or between `/` and `D`.

## Limits

Time limit: 60 seconds per test set.<br>
Memory limit: 1GB.<br>
1 ≤ **T** ≤ 100.<br>
3 ≤ **N** ≤ 200.<br>
1 ≤ **X<sub>i</sub>** ≤ 1000, for all i.<br>
1 ≤ **Y<sub>i</sub>** ≤ 1000, for all i.<br>
The **N** points are given in clockwise order.<br>
No two adjacent edges of the polygon are collinear.<br>
The polygon is a simple polygon with strictly positive area.<br>
No two edges intersect except for adjacent edges at their shared endpoint.

### Test set 1 (Visible)

**K** = 2.

### Test set 2 (Hidden)

2 ≤ **K** ≤ 10.

## Sample

| Input1 | Output1             |
| ------ | ------------------- |
| 4      |                     |
| 4 2    | Case #1: POSSIBLE   |
| 1 1    | 1/1 2/1 2/1 1/1     |
| 1 2    |                     |
| 2 2    |                     |
| 2 1    |                     |
| 3 2    | Case #2: POSSIBLE   |
| 1 1    | 1/1 1/1 3/2 3/2     |
| 1 2    |                     |
| 2 1    |                     |
| 8 2    | Case #3: IMPOSSIBLE |
| 1 3    |                     |
| 3 5    |                     |
| 5 5    |                     |
| 4 4    |                     |
| 7 3    |                     |
| 5 1    |                     |
| 4 2    |                     |
| 3 1    |                     |
| 8 2    | Case #4: POSSIBLE   |
| 1 3    | 1/1 3/1 7/1 3/1     |
| 3 5    |                     |
| 4 4    |                     |
| 5 5    |                     |
| 7 3    |                     |
| 5 1    |                     |
| 4 2    |                     |
| 3 1    |                     |

| Input2 | Output2           |
| ------ | ----------------- |
| 1      |                   |
| 10 8   | Case #1: POSSIBLE |
| 4 1    | 3/1 1/1 4/1 2/1   |
| 3 1    | 3/1 1/1 3/1 2/1   |
| 2 2    | 2/1 2/1 3/1 2/1   |
| 2 3    | 2/1 2/1 3/1 3/1   |
| 1 3    | 2/1 3/1 3/1 3/1   |
| 1 4    | 2/1 3/1 2/1 4/1   |
| 2 4    | 1/1 3/1 2/1 4/1   |
| 3 3    |                   |
| 3 2    |                   |
| 4 2    |                   |

Note: Sample 2 is not valid for Test set 1. Only Sample 1 will be tested prior to running Test set 1 (the same way samples normally are). Moreover, Sample 2 will not be tested prior to running Test set 2.

For Sample Case #1, a neat folding pattern with **K**=2 can be drawn using any of the 4 dashed lines:

![Napkin Folding](/images/round-3-napkin-folding-1.png)

For Sample Case #2, a neat folding pattern with **K**=2 can be drawn as follows:

![Napkin Folding](/images/round-3-napkin-folding-2.png)

For Sample Case #3, there are no neat folding patterns:

![Napkin Folding](/images/round-3-napkin-folding-3.png)

For Sample Case #4, there are two possible neat folding patterns with **K**=2:

![Napkin Folding](/images/round-3-napkin-folding-4.png)

For the test set 2 sample case, a neat folding pattern with **K**=8 can be drawn as follows:

![Napkin Folding](/images/round-3-napkin-folding-5.png)
