--1. When performing this laboratory work, it is required to use the database created by the student in laboratory work No. 2.
-- Players who play in the same game (against each other).

select c1.NAME, c1.SURNAME, c2.NAME, c2.SURNAME from CHESSPLAYER c1, CHESSPLAYER c2 where c1.PART_ID = c2.PART_ID and c1.SURNAME != c2.SURNAME;

--2. Simple operator CASE ()
--By the tournament id we determine the name of the tournament

select  TOUR_NAME, 
		case TOUR_ID
		when 1 then 'Crazy chessers'
		when 2 then 'Chess masters'
		else 'It is tournir for professionals'
		end
	from TOURNIR;

--3. Search operator CASE ()
--Games of which tournaments by date.

select PARTY_ID,
case
when PARTY_DATE between to_date('20-02-2015', 'DD-MM-YYYY') and to_date('22-02-2015', 'DD-MM-YYYY') then 'Qualifying Tournament'
when PARTY_DATE between to_date('17-01-2015', 'DD-MM-YYYY') and to_date('19-01-2015', 'DD-MM-YYYY') then 'Final tournament for professionals'
else 'Other tournaments'
end
from PARTY;


--4. With() statement
--Players who won by playing as white.

WITH chessers AS(SELECT * FROM CHESSPLAYER WHERE SIDE = 'White')
SELECT * FROM chessers LEFT JOIN PARTY p ON PARTY_ID = PART_ID WHERE p.RESULT = 'Whites won';

--5. Inline view
--Tournaments with conducted tournament systems.

SELECT * FROM TOURNIR t, (SELECT ts.SYSTEM_NAME, ts.SYSTEM_ID FROM TOUR_SYSTEM ts) tos
WHERE t.TOUR_SYSTEM_ID = tos.SYSTEM_ID;

--6. Uncorrelated query
--Minimum entry tournaments

SELECT * FROM TOURNIR WHERE REG_CONTRIBUTION = (SELECT MIN(REG_CONTRIBUTION) FROM TOURNIR)

--7. Correlated query
--Players who paid 3000;

SELECT NAME, SURNAME FROM CHESSPLAYER WHERE MONEY_ID 
IN (SELECT REG_CONTR_ID FROM REG_CONTRIBUTION WHERE CONTRIBUTION = 3000) 

--8. NULLIF function
--Hide the name of Ivanov.

SELECT NULLIF(SURNAME,'Ivanov'), NAME, BIRTH_DATE, LEVELS FROM CHESSPLAYER 

--9. NVL2 function
--Name and date of the tournament

SELECT NVL2(t.TOUR_NAME, t.TOUR_NAME, 'Not identified'), t.TOUR_START_DATE FROM TOURNIR t;

--10. TOP-N analysis
--Display the last three registered participants.

SELECT * FROM (SELECT * FROM CHESSPLAYER) с WHERE rownum <= 3 ORDER BY rownum;

--11. ROLLUP() function
--Number of levels

select decode(grouping(LEVELS),0,to_char(LEVELS),'Total') LEVELS, count(*) from CHESSPLAYER group by rollup(LEVELS);

--12. Submit your query to use the data manipulation language MERGE statement
--Table of new tournaments (new and plus changed old ones)

CREATE TABLE TOURNAMENT
(
	TOUR_ID NUMBER(20) PRIMARY KEY NOT NULL,
    TOUR_NAME CHAR(50) NOT NULL,
    REG_CONTRIBUTION NUMBER(20) NOT NULL,
	PRIZES_FOR_1_2_3_PLACES NUMBER(20),
    TOUR_START_DATE DATE NOT NULL,
    TOUR_END_DATE DATE NOT NULL,
	TOUR_SYSTEM_ID NUMBER(20) NOT NULL
  );
  
INSERT INTO TOURNAMENT VALUES (TOURNIR_seq.nextval, 'SUPER CHESS TOURNIR', 42000, to_date('14-11-2016', 'dd-mm-yyyy'), to_date('20-11-2016', 'dd-mm-yyyy'));
INSERT INTO TOURNAMENT VALUES (TOURNIR_seq.nextval, 'Chess World Championship', 81000, to_date('17-03-2016', 'dd-mm-yyyy'), to_date('20-03-2016', 'dd-mm-yyyy'));
INSERT INTO TOURNAMENT VALUES (TOURNIR_seq.nextval, 'Qualifying chess tournir', 9000, to_date('13-08-2016', 'dd-mm-yyyy'), to_date('18-08-2016', 'dd-mm-yyyy'));

----------MERGE syntax	

MERGE INTO TABLE_NAME 
USING table_reference ON (condition) WHEN MATCHED 
THEN UPDATE SET column1 = value1 [, column2 = value2 ...] WHEN NOT MATCHED 
THEN INSERT (column1 [, column2 ...]) VALUES (value1 [, value2 ...) ;
-------------------------	

--Changing the first table of tournaments if the second table has the same and inserting a new tournament if there is none

MERGE INTO TOURNIR t1 
USING TOURNAMENT t2 ON (t1.TOUR_NAME = t2.TOUR_NAME) WHEN MATCHED 
THEN UPDATE SET t1.REG_CONTRIBUTION = t2.REG_CONTRIBUTION WHEN NOT MATCHED 
THEN INSERT (t1.TOUR_ID, t1.TOUR_NAME, t1.REG_CONTRIBUTION, t1.PRIZES_FOR_1_2_3_PLACES, t1.TOUR_START_DATE,
 t1.TOUR_END_DATE, t1.TOUR_SYSTEM_ID)
VALUES (t2.TOUR_ID, t2.TOUR_NAME, t2.REG_CONTRIBUTION, t2.PRIZES_FOR_1_2_3_PLACES, t2.TOUR_START_DATE,
 t2.TOUR_END_DATE, t2.TOUR_SYSTEM_ID) ;	

	
