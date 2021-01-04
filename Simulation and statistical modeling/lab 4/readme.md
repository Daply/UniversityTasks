
## Lab 4

<b>Exercise 1.</b><br>
Using the Monte Carlo method, calculate the approximate value of certain integrals.

![integral](https://github.com/Daply/university-assignments/blob/master/Simulation%20and%20statistical%20modeling/lab%204/exercise_1.png)

Check simulation accuracy:<br>
1. Compare the obtained value either with the exact value (if it can be calculated), or with the approximate one obtained in any mathematical package (for example, in mathematica).
2. Compare also with the method based on quadrature formulas (Gauss CF, Bode CF, Wedl CF).
3. Find the number n of independent random variables required to calculate the integral with an accuracy of 0.001 and a confidence level of 0.95.
4. Using the found theoretical value of n from item 3, conduct 1000 experiments for different values of the initial state of the BSV generator and find the number of experiments for which the integral is calculated with an accuracy of 0.001.
5. Find the accuracy of calculating the integral if the following generator is used as the BSV: α<sub>i</sub>=i/(n+1), i = 1..n.

<b>Exercise 2.</b><br>
Solve a system of linear algebraic equations using the Monte Carlo method. The program must be implemented in such a way as to read the matrix A and the vector f from the file.<br>
The first line of the file contains the number n - the size of the matrix A.<br>
The next n lines contain matrix A.<br>
n + 2 the line is empty.<br>
n + 3 lines contain vector f.<br>

The results of the work should be formalized in the form of a report. Report requirements
1. Theoretical material.
2. Results of computational experiments.
3. Conclusions.
