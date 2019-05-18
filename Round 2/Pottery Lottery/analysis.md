# Analysis

## A simple (but incorrect) approach

Our tempting first thought might be: why not just put one of our tokens in each vase? Then we can sit back and just wait to win, no matter which vase gets chosen. Who needs the other 80 days?

The flaw in this reasoning is that if multiple vases are tied for having the fewest tokens, there is no winner. A quick simulation can show us that there is only a unique winner around 57% of the time. So this approach has no hope of passing, and we have to work harder!

## A slightly more complex (but also incorrect) approach

It might still seem that we can succeed without inspecting any vases. What if we just choose one vase up front — without loss of generality, we will pick vase #20 — and try to make it the winning vase? Over the course of the first 99 nights, we distribute fake tokens among the other 19 vases, as evenly as possible (to prevent any one of those vases from becoming more of a threat than the others). The labels on these fake tokens do not matter, since we are banking on vase 20 winning. Then, on the 100th night, we place our token in vase 20. Since each of the other 19 vases will be burdened with 5 (or maybe even 6) extra tokens, the odds are good that vase 20 will have the fewest, right?

Unfortunately, those odds aren't so good. Again, we can write a quick simulation to verify that our strategy will only succeed around 53% of the time — it's even worse than the strategy above! The average "burden" that we add to the other vases just isn't large enough compared to the random variation in the number of tokens per vase.

## A better approach

We will need to take advantage of our inspection ability, but when should we use it? There is not much value in inspecting early on in the lottery, since relatively few tokens will have been placed. On the other hand, if we inspect too late, we may not have enough nights left on which to react to whatever information we discover.

We can devise a version of our first approach that also incorporates inspection. In this approach, V and N are parameters that we will have to discover:

Choose to "give up on" the first V vases. We will assume that none of these will win, and so the labels on the tokens we add to them will not matter. Spend the first N nights sabotaging them (evenly).
Spend the next 20 turns inspecting every vase, in order.
Based on the results of our inspections, choose the vase with the fewest tokens (out of the remaining 20-V vases) to be our candidate winning vase.
On each of the remaining 99 - 20 - N nights, choose a vase (other than our candidate vase) with the smallest number of tokens in our inspection results, and add a token to it. Then, update the inspection results to reflect this.

On day 100, add our own token to the candidate vase.

We might worry that our inspections are only snapshots in time that grow stale. By the time we inspect vase 20, our estimate for vase 1 is already out-of-date — what if more tokens have been added to it since then? To compare the estimates a little more fairly, we could adjust them by the expected number of tokens that have been added since the night of the estimate (i.e., the number of additional nights, divided by 20). This adjustment will be at most .95, which is less than a single full token, so the adjustments could only possibly be used to break ties among vases with the same number of tokens... and we can get the same effect by just choosing the vase with the highest-numbered ID in the event of a tie.

It is not too hard to simulate this process, so we can try out different values of V and N to see what yields the best results, and find that V = 14, N = 60 works about 95% of the time. That gives us, per the binomial distribution, about a 99.96% chance of solving at least 225 out of 250 cases correctly. Since the problem only has one Visible test set, we should just submit and hope for the best!

## Can we do even better?

If we want to experiment further, there are even better solutions out there! Here is a variant of the above strategy; it succeeds over 98% of the time:

Days 1-60: Put 4 tokens into each of vases 1-15.<br>
Days 61-80: Inspect every case. Find the two vases with the smallest number of tokens (breaking ties in favor of higher-numbered vases, as we will throughout this strategy), and designate them as candidates.<br>
Days 81-94: Greedily put a token into the non-candidate vase that has the smallest number of tokens, per our inspection results. Update those results.<br>
Days 95-96: Inspect the two candidates again and commit to the one with fewer tokens.<br>
Days 97-99: Sabotage the other candidate.<br>

If we hang onto two candidates, it is less likely that both of them will accumulate a lot of tokens via bad luck during the second sabotage phase. We benefit from delaying our decision point for as long as possible, while still leaving enough time to deal with our runner-up.
