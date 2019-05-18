# Analysis

## Test set 1

In the first test set, there can be at most six molecules, so we can easily check all 6! = 720 possible orderings of them. The nontrivial part is figuring out how to check an ordering. We cannot check all possible atomic weights, since they can be arbitrary integers, and those integers might need to be quite large (since the **C<sub>i</sub>** and **J<sub>i</sub>** values can be as large as 10<sup>9</sup>).

For each ordering of molecules, we must determine whether there is at least one valid pair of atomic weights w<sub>C</sub> and w<sub>J</sub> for Codium and Jamarium, respectively, such that the molecules are in strictly increasing order of molecular weight. We do not need to find particular values; we only need to show existence or non-existence.

Let k = w<sub>J</sub> / w<sub>C</sub>. Then, if w<sub>C</sub> and w<sub>J</sub> are valid for our ordering, we can substitute w<sub>J</sub> = k × w<sub>C</sub> in the requirement for any pair of molecules (**C<sub>a</sub>**, **J<sub>a</sub>**), (**C<sub>b</sub>**, **J<sub>b</sub>**) such that a < b:

**C<sub>a</sub>** × w<sub>C</sub> + **J<sub>a</sub>** × kw<sub>C</sub> < **C<sub>b</sub>** × w<sub>C</sub> + **J<sub>b</sub>** × kw<sub>C</sub>

If **J<sub>a</sub>** = **J<sub>b</sub>**, then this reduces to **C<sub>a</sub>** < **C<sub>b</sub>**, which is a simple check; if it is false, then no set of atomic weights is valid, and we can stop checking this ordering. Otherwise, rearranging some terms and dividing, our expression becomes:

(**C<sub>a</sub>** - **C<sub>b</sub>**) / (**J<sub>b</sub>** - **J<sub>a</sub>**) < k, if **J<sub>a</sub>** < **J<sub>b</sub>**, or
k < (**C<sub>a</sub>** - **C<sub>b</sub>**) / (**J<sub>b</sub>** - **J<sub>a</sub>**), if **J<sub>a</sub>** > **J<sub>b</sub>**.

So, we can start by assuming that k can take on any value in an infinite range. Then, whenever we check a pair of molecules, we get a new (non-inclusive) upper or lower bound on the value of k, and we can update one end of the range accordingly. If we find that constraints force the range to be empty (e.g., because the upper end is forced to be smaller than the lower end), then no valid set of atomic weights exists. Otherwise, at least one does. Notice that even though the atomic weights of Codium and Jamarium must both be integers, any rational value of k corresponds to some pair of integers.

This is a quick set of checks, and it is even quicker if we realize that we only need to check consecutive pairs of molecules. However, as in any problem involving comparisons of fractional quantities, we must be careful to compute exact values instead of using floating-point approximations.

## Test set 2

Considering the solution of Test set 1 in reverse can lead us to a solution for Test set 2. If we consider two arbitrary molecules with indices a and b, they can appear in two possible orderings. If one of them is impossible according to the math above, it means that the other is the ordering of the molecules for every possible assignment of atomic weights. If that's the case, we can ignore the pair of molecules (a, b). However, if both orderings are possible, we obtain a range of valid values for the ratio k of the form (0, R<sub>a,b</sub>) for one ordering and a range of the form (R<sub>a,b</sub>, +∞) for the other, where R<sub>a,b</sub> = |(**C<sub>a</sub>** - **C<sub>b</sub>**) / (**J<sub>a</sub>** - **J<sub>b</sub>**)|. That means, for all orderings that correspond to atomic weights that yield a ratio strictly less than R<sub>a,b</sub>, the molecules a and b appear in a specific relative order, and for all orderings that correspond to values yielding a ratio strictly greater than R<sub>a,b</sub>, the molecules a and b appear in the other relative order. If the ratio is exactly R<sub>a,b</sub>, the two molecules weigh exactly the same, so no ordering is valid.

By the previous paragraph, if we consider a function f from ratios into orderings, f is a piecewise constant function that is undefined at ratios R<sub>a,b</sub> for any pair a, b and is constant in any interval that doesn't contain any such ratio. Moreover, the image of f over (0, R<sub>a,b</sub>) consists of orderings with molecules a and b in one relative order and the image of f over (R<sub>a,b</sub>, +∞) consists of orderings with molecules a and b in the other relative order. Therefore, no two elements in f's image are the same. The number of elements in f's image, which is the answer to the problem, is the number of different non-zero R<sub>a,b</sub> values, plus 1. Notice that it is possible that R<sub>a,b</sub> = Rc,d for different molecules a, b, c, d, and we need to count the number of unique values.

The algorithm to count the number of different values that are equal to R<sub>a,b</sub> for some a, b is immediate: try every pair of molecules, calculate the ratio as explained for the Test set 1 solution (if there is one), and add it to a set of fractions to discard non-uniques. This algorithm takes a quadratic number of insertions into a set, which makes it quadratic or barely above quadratic overall depending on the set implementation that is used.
