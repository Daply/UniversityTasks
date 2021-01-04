--1. Create a view containing information about employees of retirement age.

create or replace view PENSIONERS_AGE as
    select * from EMP
    where MONTHS_BETWEEN(SYSDATE, BIRTHDATE)/12 >= 65;
    
--2. Create a view containing data about the dismissed employees: employee name, date of dismissal, department, title.

create or replace view FIRED_WORKERS (EMPNAME, ENDDATE, DEPTNAME, JOBNAME) as
select E.EMPNAME, C.ENDDATE, D.DEPTNAME, J.JOBNAME from EMP E join CAREER C on E.EMPNO = C.EMPNO join DEPT D on C.DEPTNO = D.DEPTNO join JOB J on C.JOBNO = J.JOBNO where E.EMPNO not in (select EMP.EMPNO from EMP join CAREER on EMP.EMPNO = CAREER.EMPNO join JOB on CAREER.JOBNO = JOB.JOBNO where CAREER.ENDDATE is null);
                    
--3. Create a view containing the name of the employee, the position the employee is currently holding, and the employee's total wages for the third quarter of 2010. Name the first column Employee, the second Position, and the third Result_3_kv.

create or replace view THIRD_QUARTAL (Employee, Position, Result_3_kv) as select E.EMPNAME, J.JOBNAME, SUM(S.SALVALUE) from EMP E natural join CAREER C natural join JOB J natural join SALARY S where S.YEAR = 2010 and S.MONTH between 7 and 9 and C.ENDDATE is null group by E.EMPNAME, J.JOBNAME;

--4. Based on the view from task 2 and the SALARY table, create a view containing data about employees who were dismissed who were paid more than 2 times. In the created view, display the month of payroll and the amount of the paycheck in one column, use a comma as a separator.

create or replace view FIRED_WORKERS_TWO_SALARIES_PAID  (EMPNAME, ENDDATE, DEPTNAME, JOBNAME, MONTH_AND_SUM) as select W.EMPNAME, W.ENDDATE, W.DEPTNAME, W.JOBNAME, S.MONTH || ', ' || S.SALVALUE AS MONTH_AND_SUM from FIRED_WORKERS W join SALARY S where S.EMPNO in (select EMPNO from FIRED_WORKERS natural join SALARY group by EMPNO having COUNT(SALVALUE)>2);


