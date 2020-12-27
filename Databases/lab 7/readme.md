## PL/SQL

1. Add a TAX column to the SALARY table to calculate the monthly income tax on salaries on a progressive scale. 
The tax is calculated according to the following rule:<br>
 - tax is equal to 9% of the salary accrued in the month, if the total salary from the beginning of the year to the end of the month in question does not exceed 20,000;<br>
 - tax is equal to 12% of the salary accrued in the month, if the total salary from the beginning of the year to the end of the month in question is more than 20,000, but does not exceed 30,000;<br>
 - tax is equal to 15% of the salary accrued in the month if the total salary from the beginning of the year to the end of the month in question is more than 30,000.<br>

2. Make a program for calculating the tax and inserting it into the SALARY table:<br>
a) using a simple loop with a cursor and an if statement;<br>
b) using a simple loop with a cursor and a case statement;<br>
c) using the cursor FOR loop;<br>
d) using a cursor with a parameter, passing the number of the employee for whom the tax should be calculated.<br>

3. Draw up the programs (from the previous task) in the form of procedures.
4. Create a function that calculates payroll tax for the entire period of accruals for a specific employee. Pass the tax percentage (up to 20,000, up to 30,000, above 30,000, employee number) as parameters.
5. Create a subroutine that calculates the total employee salary tax for the entire period of accruals. Pass the tax percentage (up to 20,000, up to 30,000, above 30,000, employee number) as parameters. The return value is the total tax.
6. Create a package that includes a procedure for calculating tax for all employees, a procedure for calculating taxes for an individual employee identified by his number, a function for calculating the total tax on an employee's salary for the entire period of accruals.
7. Create a trigger to act when data is updated in the SALARY table. Namely, if the SALVALUE field is updated, then when a new salary is assigned that is less than the official salary (JOB table, MINSALARY field), the change is not made and the old value is saved, if the new salary value is higher than the official salary, then the change is made.
8. Create a trigger to act when a record is deleted from the CAREER table. If the ENDDATE field in the deleted row contains NULL, then the record is not deleted, otherwise it is deleted.
9. Create a trigger to add or modify data in the EMP table. If the BIRTHDATE field in the inserted or modified row contains NULL, then the message ‘BERTHDATE is NULL’ should be displayed after the insertion or modification. If the BIRTHDATE field in the inserted or modified row contains a date earlier than ‘01 -01-1940 ’, then‘ PENTIONA ’should be returned. In the newly inserted line, the employee's name must be capitalized.
10. Create a program to change the type of a given variable from a character type (VARCHAR2) to a numeric type (NUMBER). The program must contain an exception handling section. The processing should be to issue the message ‘ERROR: argument is not a number’. An exception occurs when specifying a string as a number with a comma separating the fractional and integer parts.
