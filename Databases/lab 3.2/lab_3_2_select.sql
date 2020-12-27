--NESTED SUBQUERIES:

--SUBQUIRES SELECTING ONE LINE:

--1. Find the names of employees who received the minimum wage over the years of payroll.
select EMPNAME from EMP where (select EMPNO from SALARY where SALVALUE IN (select MINSALARY from job))=EMPNO; 

--SUBQUIRES RETURNING MORE THAN ONE LINE:

--2. Find the names of employees who worked or are working in the same departments in which the employee with the name RICHARD MARTIN worked or works.
select EMPNAME from EMP where EMP.EMPNO in (select EMPNO from CAREER where CAREER.DEPTNO in (select DEPTNO from CAREER where CAREER.EMPNO in (select EMPNO from EMP where EMP.EMPNAME='RICHARD MARTIN')))  and not emp.empname= 'RICHARD MARTIN';

--COMPARISON FOR MORE THAN ONE VALUE:

--3. Find the names of employees who have worked or are working in the same departments and positions as the 'RICHARD MARTIN' employee.
select EMPNAME from EMP where EMP.EMPNO in (select EMPNO from CAREER where CAREER.DEPTNO in (select DEPTNO from CAREER where CAREER.EMPNO in (select EMPNO from EMP where EMP.EMPNAME='RICHARD MARTIN')) and CAREER.JOBNO in (select  JOBNO from CAREER where CAREER.EMPNO  in (select EMPNO from EMP where EMP.EMPNAME='RICHARD MARTIN')));

--ANY/ALL OPERATORS

--4. Find information about the numbers of employees who received a salary for any month that is greater than the average salary for 2007 or more than the average salary for 2008.
select EMPNO from SALARY where SALVALUE > any ((select avg(SALVALUE) from SALARY where SALARY.YEAR=2007),(select avg(SALVALUE) from SALARY where SALARY.YEAR=2008));

--5. Find information about the numbers of employees who received a salary for any month that is greater than the average salary for all years of accrual.
select EMPNO from SALARY where SALVALUE > all (select avg(SALVALUE) from SALARY where SALARY.YEAR in (select year from SALARY));

--USING HAVING WITH NESTED SUBQUERIES:

--6. Determine the years in which the accrued average salary was higher than the average salary for all accrual years.
select YEAR from SALARY group by YEAR having (avg(SALVALUE) > (select avg(SALVALUE) from SALARY));

--CORRELATING SUBQUIRES:

--7. Determine the numbers of departments in which employees have worked or are working with payroll.
select DEPTNO from CAREER where EMPNO in (select EMPNO from SALARY);

--EXISTS OPERATOR:

--8. Determine the numbers of departments in which employees have worked or are working with payroll.
select DEPTNO from CAREER where exists (select EMPNO from SALARY);

--NOT EXISTS OPERATOR:

--9. Determine the numbers of departments for whose employees salaries were not calculated.
select DEPTNO from CAREER where not exists (select EMPNO from SALARY);

--COMPOSITE INQUIRIES:

--10. Display information about the careers of employees with the names and addresses of departments instead of department numbers.
select EMP.EMPNAME, DEPT.DEPTNAME, DEPT.DEPTADDR from EMP natural join CAREER natural join DEPT;

--CAST OPERATOR:

--11. Determine the whole part of average salaries, by year of accrual.
select YEAR, cast(avg(SALVALUE) as number(10)) from SALARY group by YEAR;

--CASE OPERATOR:

--12. Divide employees into age groups: A) age 20-30 years; B) 31-40 years old; C) 41-50; D) 51-60 or undefined.
select EMPNO, EMPNAME,
    case
        when (sysdate - BIRTHDATE)/365 between 20 and 30
            then 'A'
        when (sysdate - BIRTHDATE)/365 between 31 and 40
            then 'B'
        when (sysdate - BIRTHDATE)/365 between 41 and 50
            then 'C'
        when (sysdate - BIRTHDATE)/365 between 51 and 60
            then 'D'
        else null
    end
    from EMP;

--13. Recode the department numbers by prefixing the department number with the letters BI for numbers <= 20, letters LN for numbers> = 30.
select D.DEPTNO,
    case
        when D.DEPTNO <= 20 then concat('BI', cast (D.DEPTNO as varchar(10)))
        when D.DEPTNO >= 30 then concat('LN', cast (D.DEPTNO as varchar(10)))
    end,
    D.DEPTNAME, D.DEPTADDR
    from DEPT D;

--COALESCE OPERATOR:

--14. Issue information about employees from the EMP table, replacing the lack of date of birth with the date '01 -01-1000 '.
select EMPNO, EMPNAME, coalesce(BIRTHDATE, to_date('01-01-1000', 'dd-mm-yyyy')) from EMP;
