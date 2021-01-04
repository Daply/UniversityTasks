
## Lab1

Simulate a continuous, uniformly distributed on the half-interval [0, 1) random variable.<br>

Use linear congruential generator and Maclaurin-Marsaglia generator for simulation.<br>
The linear congruent generator has the form:<br>
x<sub>t</sub> + 1 = (axsub>t</sub> + c) mod M,<br>
where x<sub>1</sub>, x<sub>2</sub>, ..., x<sub>n</sub> is the output sequence of the generator of length n, x0 is the initial value, a ≠ 0 is the factor, c is the increment, M is the modulus.<br>

<b>Exercise 1.</b><br>
For a linear congruential generator, use different values for the modulus M:
1) 31 < M <169, choose the other parameters (x<sub>0</sub>, a, с, n) yourself;
2) 2<sup>16</sup> > M > 2<sup>10</sup>, select the remaining parameters yourself so that the period of the output sequence is maximum.
3) M > 2<sup>20</sup>, select the other parameters yourself so that the period of the output sequence is maximum.

<b>Exercise 2.</b><br>
Implement the Maclaurin-Marsagli generator on the basis of two linear congruent generators, with the parameters selected in exercise 1.<br>
The parameters of the Maclaurin-Marsagli generator should be chosen independently, so that, according to the test results, the Maclaurin-Marsagli generator has “better” statistical properties compared to linear congruent generators on the basis of which it is built.<br>

<b>Exercise 3.</b><br>
For each generator (three linear and Maclaurin-Marsagli generator), check the simulation accuracy using the output sequence of generators of length n<sub>1</sub> = 10000 and n<sub>2</sub> = 106:<br>
1) Construct a scatter diagram (draw on the plane the set of points {(x<sub>1</sub>, x<sub>2</sub>), (x<sub>2</sub>, x<sub>3</sub>), ..., (x<sub>n-1</sub>, x<sub>n</sub>)});
2) Implement the test "coincidence of moments" (significance level ε<sub>0</sub>=0.05);
3) Implement the test "covariance" (significance level ε<sub>0</sub>=0.05, the number of checked statistics |R’(j)-R(j)|, j = 0, ... 10);
4) Implement the Pearson chi-square test (choose the number of partition cells equal to 1000, significance level ε<sub>0</sub>=0.05).

The developed software must be implemented in such a way that<br>

<b>Exercise 1</b><br>
Read the parameters of the linear congruential generator from the inputLC.txt file:<br>
The first line of the file contains the number x<sub>0</sub> - the initial value,<br>
the second line a ≠ 0 is a factor,<br>
third line c - increment,<br>
fourth line M - module<br>
the fifth line n is the sample length.<br>
read the parameters of the Maclaurin-Marsagli generator from the file inputMM.txt:<br>
The first four lines contain the parameters of the first generator<br>
The next four lines are the parameters of the second generator<br>
The ninth line contains the number of memory locations of the Maclaurin-Marsagli generator<br>
Tenth row n - sample length<br>
Output file outputLC.txt, outputMM.txt contains:<br>
(output precision up to 10 decimal places)<br>
<b>First line</b><br>
The value of the stat. estimating the parameter mat. expect.<br>
<b>Second line</b><br>
Accepted hypothesis, Value of statistics for hypothesis testing for n<sub>1</sub> = 10000 threshold, significance level<br>
Third line Accepted hypothesis, Value of statistics for hypothesis testing for n<sub>2</sub> = 10<sup>6</sup>, threshold, significance level<br>
<b>Fourth line</b><br>
The value of the stat. variance parameter estimates<br>
Fifth line: Accepted hypothesis, Value of statistics to test the hypothesis for n<sub>1</sub> = 10000, threshold, significance level<br>
Sixth line Accepted hypothesis, Value of statistics for testing the hypothesis for n<sub>2</sub> = 10<sup>6</sup>, threshold, level of significance<br>
<b>COVARIATION</b><br>
From the seventh to the 17th lines, the values of the statistics covariance (for n<sub>1</sub> = 10000), the accepted hypothesis, threshold, significance level<br>
17th line to 27th line contains the values of the statistics covariance (for n<sub>2</sub> = 10<sup>6</sup>), the accepted hypothesis, threshold, significance level<br>
28 line Chi-square value of Pearson statistics for (for n<sub>1</sub> = 10000), accepted hypothesis, threshold, significance level<br>
29 line Chi-square value of Pearson statistics for (for n<sub>2</sub> = 10<sup>6</sup>), accepted hypothesis, threshold, significance level<br>

The results of the work should be drawn up in the form of a report. Report requirements
1. Theoretical material.
2. Results of computational experiments.
3. Conclusions.

Designing computational experiments.<br>
The report should contain numerical values:<br>
• estimates of the mathematical expectation;<br>
• variance estimates;<br>
• statistics for mathematical expectation;<br>
• statistics for variance;<br>
• threshold (according to the level of significance);<br>
• |R’(j)-R (j)|, j = 0, ... 9.<br>
