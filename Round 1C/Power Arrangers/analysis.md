# Analysis

## Test set 1

We can look at up to 475 figures in Test set 1, but there are 595 figures, so we cannot check them all individually. We can observe that when we investigate any particular set, we only need to look at any four of the figures (say, the first four), since we can infer the identity of the fifth. For example, if the first four figures in a set are D, E, A, and B, then we already know that the last figure in that set is C. This reduces our required number of guesses to 4 × 119 = 476. But that is still one more guess than we are allowed!

Observe that once we have determined the orders in all but one of our sets, there are only two sets remaining: the one we have not inspected, and the one we are missing. These two sets must have different figures for at least two indexes, and we can look at any such index to know which set we have. For example, if we know the last two possible sets are CADEB and CDEAB, we can look at the second index; if we see an A, we have the first set, and if we see a D, we have the second set. So, by the time we get to the 119th set on our shelf, we only need to look at one of its figures (but which one to look at will depend on what we learned earlier). After that, we will know which 119 sets we have, and therefore we will also know which set we lack.

Combining these insights, we can guarantee that we will use at most 4 × 118 + 1 = 473 guesses.

## Test set 2

In Test set 2, we only have 150 guesses, which is not much more than one guess per set! How can we possibly succeed?

We need to take further advantage of the fact that we are missing only one of the possible sets / permutations. We can start by checking the first figure in each set, using 119 guesses. When we do this, we will find that four out of five of the letters occur 24 times each, and the other one occurs only 23 times. That letter must be the one on the first figure in our missing set!

Now we can restrict our search to only our 23 sets that begin with that letter, and look at the second figure in each of those; this uses 23 guesses. One of those letters will appear only 5 times compared to 6 for the others; then we can narrow our search to those 5 out of the 23 sets, and use 5 guesses to look at the third figures of those. We will find one unique third letter, and then we only need to check the fourth figure in that set to learn what the other, missing set is. This uses a total of (5! - 1) + (4! - 1) + (3! - 1) + (2! - 1) = 119 + 23 + 5 + 1 = 148 guesses, which fits within the limit of 150.