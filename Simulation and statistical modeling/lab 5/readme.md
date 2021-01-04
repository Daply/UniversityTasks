
## Lab 5

Implement a simulation model in accordance with its version in the GPSS modeling system and in a universal programming language.

Modeling the process of functioning of a computer with a network of AWP.

Initial data:
1. The computer serves a network of 3 AWPs (AWP-1, AWP-2, AWP-3), providing a multi-program operation mode (the memory area is divided into n blocks).
2. Tasks arriving from the AWP form Poisson flows with intensities of λ<sub>1</sub> task per second (AWP-1), λ<sub>2</sub> task per second (AWP-2), λ<sub>3</sub> task per second (AWP-3),
and the execution time of the task in the processor has an exponential distribution with the mathematical expectation of seconds.
3. After the execution in the computer, 40% of all tasks are served in the ADCU, and the listing of one listing takes [a±δ] seconds (uniform distribution law).
4. The model records the number of completed tasks for each workstation separately.
Purpose: To develop a GPSSV - a model for analyzing the process of functioning of a computer with a network of AWPs within one hour.
Initial list of experiments. n=10, λ<sub>1</sub>=0.05, λ<sub>2</sub>=0.04, λ<sub>3</sub>=0.01, μ=9, a=12, δ=8
