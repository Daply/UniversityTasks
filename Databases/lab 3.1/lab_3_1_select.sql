
-- SIMPLE QUIRIES:
-- 1. Get information about the location of the sales department (SALES) of the company.
select DEPTADDR from DEPT where DEPTNAME='SALES';

-- 2. Get information about the departments located in Chicago and New York.
select * from DEPT where DEPTADDR='CHICAGO' or DEPTADDR='NEW YORK';

-- FUNCTIONS: 
-- 3. Find the 2009 minimum wage.
select min(SALVALUE) from SALARY where YEAR=2009

-- 4. Get information about all employees born no later than January 1, 1960.
select * from EMP where DATE(BIRTHDATE) <= '1960-01-01';

-- 5. Count the number of employees whose information is available in the database.
select count(*) from EMP;

-- 6. Find employees whose name consists of one word. Give names in lower case, with the letter t on the right removed.
select rtrim(UPPER(EMPNAME),'t') from EMP where EMPNAME not like '% %'; 

-- 7. Get information about employees, indicating the date of birth in the format day (date), month (name), year (name).
select EMPNO, EMPNAME, TO_CHAR(BIRTHDATE, 'dd'), TO_CHAR(BIRTHDATE, 'MONTH'), TO_CHAR(BIRTHDATE, 'YEAR') from EMP; 

-- 8. Get information about positions by changing the job titles “CLERK” and “DRIVER” to “WORKER”.
select JOBNO, decode(JOBNAME, 'DRIVER', 'WORKER', 'CLERK', 'WORKER', JOBNAME), MINSALARY from JOB;

-- HAVING 
-- 9. Determine the average salary for the years in which there were accruals for at least three months.
select avg(SALVALUE), YEAR from SALARY group by YEAR having count(MONTH) >= 3;

-- EQUAL CONNECTION:
-- 10. Print the payroll with the names of the employees.
select EMPNAME, SALVALUE, MONTH, YEAR from EMP, SALARY where EMP.EMPNO=SALARY.EMPNO;

-- NOT EQUAL CONNECTION:
-- 11. Specify information about the accrual of salaries to employees that fall into the fork: the minimum salary for the position - the minimum salary for the position plus five hundred. Indicate the position corresponding to the fork.
select JOBNAME, SALVALUE from JOB, SALARY where SALARY.SALVALUE>JOB.MINSALARY and  SALARY.SALVALUE<=(JOB.MINSALARY+500);

-- COMBINING TABLES:
-- INNER: 
-- 12. Input information on wages that coincide with the minimum salaries by position (indicating these positions).
select * from SALARY inner join JOB on JOB.MINSALARY=SALARY.SALVALUE;

-- NATURAL:
-- 13. Find the career information of an employee by listing the employee's name instead of the employee number.
select EMPNAME, JOBNAME, DEPTNO, STARTDATE, ENDDATE from EMP natural join CAREER inner join job on job.JOBNO=CAREER.JOBNO;

-- SIMPLE INTERNAL CONNECTION:
-- 14. Find the career information of an employee by listing the employee's name instead of the employee number.
select EMPNAME, JOBNAME, DEPTNO, STARTDATE, ENDDATE from CAREER join EMP on CAREER.EMPNO=EMP.EMPNO join JOB on JOB.JOBNO=CAREER.JOBNO;

-- COMBINING THREE AND MORE TABLES:
-- 15. Provide information about the careers of employees with their names, job titles, and department name.
select EMPNAME, DEPTNAME, JOBNAME, STARTDATE, ENDDATE from EMP natural join CAREER natural join DEPT natural join JOB;

-- EXTERNAL UNION:
-- 1. Provide information about the careers of employees with their names. What kind of external pooling did you use? Build your query using the opposite kind of join. Build your query using a full outer join.
select EMPNAME, DEPTNO, JOBNAME, STARTDATE, ENDDATE from EMP full outer join CAREER on emp.EMPNO=CAREER.EMPNO join JOB on JOB.JOBNO=CAREER.JOBNO;

select EMPNAME, DEPTNO, JOBNAME, STARTDATE, ENDDATE from EMP right join CAREER on emp.EMPNO=CAREER.EMPNO join JOB on JOB.JOBNO=CAREER.JOBNO;

select EMPNAME, DEPTNO, JOBNAME, STARTDATE, ENDDATE from EMP left join CAREER on emp.EMPNO=CAREER.EMPNO join JOB on JOB.JOBNO=CAREER.JOBNO;
