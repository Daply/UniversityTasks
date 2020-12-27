## Topic: "Stream Creation".

A task.<br>
Write a console program for parallel matrix-vector multiplication. Program includes streams of two types: main and mul.<br>
The mul thread should do the following:<br>
1. Multiply the row of the square matrix by the vector.
2. Write the result of multiplication to the corresponding cell of the resulting vector.
3. Print to the console the message “product of string n by vector is: <result multiplication> "
4. Complete your work.
Notes:<br>
1. You should think over the transfer of parameters and return of the result by the mul stream yourself.
2. When multiplying a row of a matrix by a vector after each multiplication command "sleep" 7 milliseconds.
The main thread should do the following:<br>
1. Request from the console the dimension of a square matrix and a vector.
2. Create a square matrix and vector.
3. Enter the elements of a square matrix and a vector from the console.
4. Start the mul threads. The number of threads mul must be equal to the number of rows in matrix. Each stream corresponds to one row of the matrix.
5. Wait for all threads mul.
6. Output the resulting vector to the console.
7. Complete the work.
Notes.
1. To wait for the threads mul to terminate, use the function WaitForMultipleObjects.
2. To "fall asleep" use the Sleep function.
Optional task.<br>
The main thread starts the number of mul threads specified from the console, which multiply the rows matrix and vector (thread pool).<br>
Distribution of work between threads develop yourself.