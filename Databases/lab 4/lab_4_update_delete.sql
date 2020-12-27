--1. Raise the lower bound for the minimum wage in the JOB table to $ 1000.

update JOB set MINSALARY = 1000 where MINSALARY < 1000;
    
--2. Raise the minimum wage in the JOB table by 10% for all majors except CFO.
    
update JOB set MINSALARY = 1.1*MINSALARY where JOBNAME != 'FINANCIAL DIRECTOR';
    
--3. Raise the minimum wage in the JOB table by 10% for clerks and 20% for the CFO (single operator).
    
update JOB set MINSALARY = case when JOBNAME = 'CLERK' then 1.1*MINSALARY when JOBNAME = 'FINANCIAL DIRECTOR' then 1.2*MINSALARY else MINSALARY end;

--4. Set the minimum salary of the CFO to 90% of the salary of the CEO.

update JOB set MINSALARY = 0.9*(select MINSALARY from JOB where JOBNAME = 'EXECUTIVE DIRECTOR') where JOBNAME = 'FINANCIAL DIRECTOR';

--5. In the EMP spreadsheet, lowercase employee names beginning with the letter 'J'.

update EMP set EMPNAME = lower(EMPNAME) where EMPNAME like 'J%';

--6. Modify the two-word employee names in the EMP table so that both words in the name start with a capital letter and continue in uppercase.

update EMP set EMPNAME = INITCAP(EMPNAME) where EMPNAME like '% %';
    
--7. In the EMP table, convert the employee names to uppercase.
    
update EMP set EMPNAME = UPPER(EMPNAME);
    
--8. Relocate the RESEARCH to the same city as the SALES.
    
update DEPT set DEPTADDR = (select DEPTADDR from DEPT where DEPTNAME = 'SALES') where DEPTNAME = 'RESEARCH';
    
--9. Add the new employee to the EMP table. His name and surname must match yours, written in Latin letters according to the passport, the date of birth also coincides with yours.

insert into EMP set (7737, 'DARIA PLESHCHANKOVA', to_date('21-03-1996','dd-mm-yyyy'));
   
--10. Define a new employee (see the previous task) to work in the accounting department (ACCOUNTING department) starting from the current date.

insert into CAREER values (1004, 7737, 10, CURRENT_DATE, null);

--11. Delete all records from the TMP_EMP table. Add information about the employees who are currently clerks.

delete from TMP_EMP;

insert into TMP_EMP select E.EMPNO, E.EMPNAME, E.BIRTHDATE from EMP E join CAREER C ON E.EMPNO = C.EMPNO join JOB J ON C.JOBNO = J.JOBNO WHERE J.JOBNAME = 'CLERK' and C.ENDDATE is null;
           
--12. Add to the TMP_EMP table information about those employees who no longer work at the enterprise, and during the period of work held only one position.

insert into TMP_EMP select * from EMP where EMPNO in ( select EMP.EMPNO from EMP join CAREER ON EMP.EMPNO = CAREER.EMPNO join JOB ON CAREER.JOBNO = JOB.JOBNO where CAREER.ENDDATE is not null GROUP BY EMP.EMPNO having COUNT(EMP.EMPNO) = 1);
        
--13. Execute the same request for those employees who have never started work in the enterprise.

insert into TMP_EMP select * from EMP where EMPNO in (select EMP.EMPNO from EMP left join CAREER ON EMP.EMPNO = CAREER.EMPNO where CAREER.STARTDATE is null);
            
--14. Delete all records from the TMP_JOB table and add information to it for those specialties that are not currently used in the enterprise.

delete FROMfrom TMP_JOB;

insert into TMP_JOB select * from JOB where JOBNO not in (select JOBNO from CAREER where ENDDATE is null);
        
--15. Accrue a salary of 120% of the minimum base salary for all employees working in the enterprise. The salary is accrued according to the position occupied by the employee at the moment and attributed to the last month relative to the current date.

insert into SALARY select EMPNO, extract(MONTH from ADD_MONTHS(sysdate, -1)), extract(YEAR from ADD_MONTHS(sysdate, -1)), 1.2 * MINSALARY from CAREER natural join EMP natural join JOB where ENDDATE is null;
        
--16. Delete the salary data for the previous year.

delete from SALARY where YEAR = extract(YEAR from ADD_MONTHS(sysdate, -12));

--17. Delete the career information of employees who are currently no longer employed by the enterprise, but once worked.

delete from CAREER where EMPNO not in (select EMP.EMPNO from EMP join CAREER on EMP.EMPNO = CAREER.EMPNO join JOB on CAREER.JOBNO = JOB.JOBNO where CAREER.ENDDATE is null);

--18. Delete the information about the accrued salary of employees who are currently no longer working at the enterprise (you can use the results of the previous query).

delete from SALARY where EMPNO not in ( select EMP.EMPNO from EMP join CAREER on EMP.EMPNO = CAREER.EMPNO join JOB on CAREER.JOBNO = JOB.JOBNO where CAREER.ENDDATE is null);
            
--19. Delete records from the EMP table for those employees who have never started work in the enterprise.

delete from EMP where EMPNO in (select EMP.EMPNO from EMP left join CAREER on EMP.EMPNO = CAREER.EMPNO where CAREER.STARTDATE is null);




