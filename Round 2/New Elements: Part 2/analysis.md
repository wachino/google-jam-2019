# Analysis

Let w<sub>C</sub> be the atomic weight of Codium and w<sub>J</sub> be the atomic weight of Jamarium according to the rules given in the problem statement. Let ΔC<sub>i</sub> equal C<sub>i + 1</sub> - C<sub>i</sub> and ΔJ<sub>i</sub> equal J<sub>i + 1</sub>- J<sub>i</sub>, for all 1 ≤ i < **N**. As in our analysis for New Elements, Part 1, we have:

<code>
-ΔC<sub>i</sub> / ΔJ<sub>i</sub> < w<sub>J</sub> / w<sub>C</sub>, if ΔJ<sub>i</sub> > 0.<br>
w<sub>J</sub> / w<sub>C</sub> < -ΔC<sub>i</sub> / ΔJ<sub>i</sub>, if ΔJ<sub>i</sub> < 0.<br>
-ΔC<sub>i</sub> × w<sub>C</sub> < 0, if ΔJ<sub>i</sub> = 0.
</code>

Therefore, we can get the lower bound and upper bound of w<sub>J</sub> / w<sub>C</sub> just by looking at consecutive indices. We can initially set the lower bound (let us represent it with the reduced fraction L<sub>N</sub> / L<sub>D</sub>) to be 0 and the upper bound (let us represent it with the reduced fraction U<sub>N</sub> / U<sub>D</sub>) to be ∞. We update either L<sub>N</sub> / L<sub>D</sub> or U<sub>N</sub> / U<sub>D</sub> for each pair of consecutive indexes, just as in our analysis from Part 1.

Once we have L<sub>N</sub> / L<sub>D</sub> and U<sub>N</sub> / U<sub>D</sub>, we want to find a rational number w<sub>J</sub> / w<sub>C</sub> such that L<sub>N</sub> / L<sub>D</sub> < w<sub>J</sub> / w<sub>C</sub> < U<sub>N</sub> / U<sub>D</sub>. If L<sub>N</sub> / L<sub>D</sub> > U<sub>N</sub> / U<sub>D</sub>, then there is certainly no solution. Otherwise, there must be at least one solution; for example, the [mediant](<https://en.wikipedia.org/wiki/Mediant_(mathematics)>) (L<sub>N</sub> + U<sub>N</sub>) / (L<sub>D</sub> + U<sub>D</sub>) is certainly between the bounds. However, the problem asks us to minimize w<sub>C</sub> and w<sub>J</sub> (first w<sub>C</sub>, and then w<sub>J</sub>).

## Test set 1

Since ΔJi ≤ 99 in this test set, we get L<sub>D</sub> + U<sub>D</sub> ≤ 198. Therefore, we know that a solution with w<sub>C</sub> ≤ 198 exists. We can try all possible values from 1 to 198 as w<sub>C</sub>. For each choice of w<sub>C</sub>, we can derive the smallest w<sub>J</sub> such that L<sub>N</sub> / L<sub>D</sub> < w<sub>J</sub> / w<sub>C</sub>, and then we can check whether w<sub>J</sub> / w<sub>C</sub> < U<sub>N</sub> / U<sub>D</sub>.

## Test set 2

For each integer C (from 1 to L<sub>D</sub> + U<sub>D</sub>), we can check whether there is a rational number that is strictly between L<sub>N</sub> / L<sub>D</sub> and U<sub>N</sub> / U<sub>D</sub>, and has a denominator that is not more than C. To do that, we can find a rational number with denominator not more than C closest to the average of L<sub>N</sub> / L<sub>D</sub> and U<sub>N</sub> / U<sub>D</sub>. This is because all rational numbers that are strictly between L<sub>N</sub> / L<sub>D</sub> and U<sub>N</sub> / U<sub>D</sub> are closer to the average of L<sub>N</sub> / L<sub>D</sub> and U<sub>N</sub> / U<sub>D</sub> than all rational numbers that are not strictly between L<sub>N</sub> / L<sub>D</sub> and U<sub>N</sub> / U<sub>D</sub>. We can do so by using a library function like Python's [fractions.limit_denominator](https://docs.python.org/2/library/fractions.html#fractions.Fraction.limit_denominator), or by implementing our own approximation using [continued fractions](https://en.wikipedia.org/wiki/Continued_fraction#Best_rational_within_an_interval).

Once we can solve the problem given in the previous paragraph, we can use binary search to find w<sub>C</sub> as the smallest C such that a rational number with denominator not more than C, and strictly between L<sub>N</sub> / L<sub>D</sub> and U<sub>N</sub> / U<sub>D</sub> exists. Just as we did for the previous test set, we can derive the smallest w<sub>J</sub> such that L<sub>N</sub> / L<sub>D</sub> < w<sub>J</sub> / w<sub>C</sub>.
