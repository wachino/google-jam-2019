# Analysis

In this problem, we need to determine the number of each type of X-day ring by querying the total number of rings in existence at the end of a certain day.

Let R<sub>1</sub> be the number of 1-day rings, R<sub>2</sub> be the number of 2-day rings, ... etc. at the end of day 0. The number of X-day rings doubles at the end of every day that is a multiple of X. Thus, the total number of rings on day i is

<code>
    R<sub>1</sub>*2<sup>i</sup> + R<sub>2</sub>*2<sup>floor(i/2)</sup> + R<sub>3</sub>*2<sup>floor(i/3)</sup> + R<sub>4</sub>*2<sup>floor(i/4)</sup> + R<sub>5</sub>*2<sup>floor(i/5)</sup> + R<sub>6</sub>*2<sup>floor(i/6)</sup>.
</code>

## Test set 1

In the first test set, we are allowed six queries to determine the six unknown variables. Note that if we query any day number larger than 63, then the number of 1-day rings on that day will be a multiple of 2<sub>63</sub> (equivalently, it is 0 modulo 2<sub>63</sub>). Similarly, if we query any day number larger than X*63, then the number of X-day rings will be 0 modulo 2<sub>63</sub> on that day.

Thus, on day 315 (=5 * 63), the total number of rings, modulo 2<sub>63</sub>, is R<sub>6</sub> * 2<sup>52</sup> (since the number of 1-day, 2-day, ..., 5-day rings are all 0 modulo 2<sub>63</sub>). Since R<sub>6</sub> ≤ 100, we know that R<sub>6</sub> * 2<sup>52</sup> does not exceed 2<sub>63</sub>, so we can directly determine R<sub>6</sub>. Then, on day 252 (=4 * 63), the total number of rings, modulo 2<sub>63</sub>, is R<sub>6</sub> * 2<sup>42</sup> + R<sub>5</sub> * 2<sup>50</sup>. Since we already know R<sub>6</sub> and we know this sum cannot be more than 2<sub>63</sub>, we can solve for R<sub>5</sub>. We may continue this process by querying days 189 (=3 * 63), 126 (=2 * 63), 63 (=1 * 63) and 1 to determine R<sub>4</sub>, R<sub>3</sub>, R<sub>2</sub> and R<sub>1</sub>, respectively.

## Alternative

Note that since we are querying six days and attempting to solve for six variables, we may choose to query (for example) days 1,2, ... , 6. This gives us a system of equations with six equations and six variables. Since these equations are linearly independent, we can solve this system, via [Gaussian elimination](https://en.wikipedia.org/wiki/Gaussian_elimination) for example, to get the solution.

## Test set 2

The second test set requires another insight. We are only given two queries, so we must be able to solve for multiple R<sub>i</sub> at once.

Let's think about what information we get by querying day 189 (=3*63). This gives R<sub>6</sub> * 2<sup>31</sup> + R<sub>5</sub> * 2<sup>37</sup> + R<sub>4</sub> * 2<sup>47</sup>, modulo 2<sup>63</sup>. However, it is possible that there is some overlap between R<sub>6</sub> * 2<sup>31</sup> and R<sub>5</sub> * 2<sup>37</sup>. For example, all other things being equal, we would not be able to differentiate between the case where R<sub>6</sub>=64 and R<sub>5</sub>=0 and the case where R<sub>6</sub>=0 and R<sub>5</sub>=1. Both of these would have 2<sup>37</sup> total rings.

We must use the fact that R<sub>i</sub> ≤ 100. In order for the number of i-day rings to not interfere with the number of (i-1)-day rings on day d, we need 2<sup>floor(d/(i-1))</sup> > 100 * 2<sup>floor(d/i)</sup> (note that this is equivalent to floor(d/(i-1)) ≥ floor(d/i)+7 since 2<sup>7</sup> > 100). If we ignore the modulo 2<sup>63</sup> restriction, then we could solve the question in a single query of (for example) 1000. This would give us

<code>
    R<sub>1</sub>*2<sup>1000</sup> + R<sub>2</sub>*2<sup>500</sup> + R<sub>3</sub>*2<sup>333</sup> + R<sub>4</sub>*2<sup>250</sup> + R<sub>5</sub>*2<sup>200</sup> + R<sub>6</sub>*2<sup>166</sup>.
</code>

Since R<sub>i</sub> ≤ 100, we coud determine R<sub>6</sub> by taking this value modulo 2<sup>200</sup> to get R<sub>6</sub> * 2<sup>166</sup>, then by dividing by 2<sup>166</sup>. We then could iteratively determine R<sub>5</sub>, R<sub>4</sub>, ..., R<sub>1</sub>. However, this idea does not work since the problem is modulo 2<sup>63</sup>. There is no single query that can give us all of the information we need, modulo 2<sup>63</sup>.<br>
We will use one query to determine the values of R<sub>4</sub>, R<sub>5</sub>, and R<sub>6</sub>, followed by a second query to determine the values of R<sub>1</sub>, R<sub>2</sub>, and R<sub>3</sub>. We saw above that a query of 189 (=3 * 63) will not work. However, a query of (for example) 200 will work:

<code>
    R<sub>4</sub>*250 + R<sub>5</sub>*240 + R<sub>6</sub>*233,
</code>

and then solve for each in the same way as for the 1000 case. We can then make a second query of (for example) 56:

<code>
    R<sub>1</sub> * 2<sup>56</sup> + R<sub>2</sub> * 2<sup>28</sup> + R<sub>3</sub> * 2<sup>18</sup> + R<sub>4</sub> * 2<sup>14</sup> + R<sub>5</sub> * 2<sup>11</sup> + R<sub>6</sub> * 2<sup>9</sup>.
</code>

We know the value of R<sub>4</sub>, R<sub>5</sub>, and R<sub>6</sub> from the first step, so we may substitute those in and then solve for R<sub>1</sub>, R<sub>2</sub>, and R<sub>3</sub> one-by-one.

Note that the choice of 200 and 56 above were not the only possible options. In this problem, we could either guess-and-check for these values offline or (preferably) write a loop in the program to find two values that satisfy the criteria. We also need to ensure that the term with the largest exponent is not too large. For example, we cannot use a query of 250 in the first step since this gives R<sub>4</sub> * 2<sup>62</sup> + R<sub>5</sub> * 2<sup>50</sup> + R<sub>6</sub> * 2<sup>41</sup>, because the first term (R<sub>4</sub> * 2<sup>62</sup>) may be at least 2<sup>63</sup>.