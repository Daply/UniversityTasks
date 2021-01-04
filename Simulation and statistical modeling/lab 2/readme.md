
## Lab 2

Simulate a discrete random variable with a given distribution law.
To simulate, use the Maclaurin-Marsagli generator from laboratory work No. 1 with "good" properties (which passed all tests) and the built-in software generator.
Model distribution laws:
1. Bernoulli;
2. Discrete uniform;
3. Binomial;
4. Negative binomial;
5. Geometric;
6. Hypergeometric;
7. Poisson.

Check the simulation accuracy using the output sequence of generators of length n = 10000:

1) Construct a histogram.
2) Implement the Pearson chi-square test (significance level ε<sub>0</sub>=0.05).
3) For the Bernoulli distribution over the generated sample, construct a point estimate of the distribution parameter and the confidence interval for the distribution parameter.

The developed software must be implemented in such a way that<br>
<b>Exercise 1</b><br>
Read parameters of the MM generator from the file inputMM.txt<br>
The output file outputDiscrDistrib.txt contains:<br>
(output precision up to 10 decimal places)<br>
Distribution name string<br>
Next line<br>
Distribution parameters<br>
Next line<br>
Accepted hypothesis, statistic chi-squared value, threshold chi-squared test<br>

The results of the work should be formalized in the form of a report. Report requirements
1. Theoretical material.
2. Results of computational experiments.
3. Conclusions.
