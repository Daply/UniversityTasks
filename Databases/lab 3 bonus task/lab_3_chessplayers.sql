
--Output list of players names, who played in debut "Sicilian defense" on white side

select C.NAME, C.SURNAME from CHESSPLAYER C join PARTY P on PART_ID=PARTY_ID where PDEBUT_ID=(select DEBUT_ID from DEBUT where DEBUT_NAME='sicilian defense') and C.SIDE='WHITE'

--Output sum of contributions of every chess club participant for given period (start date, end date)

select C.SURNAME,SUM(CONTRIBUTION) from CHESSPLAYER C  join  REG_CONTRIBUTION R on REG_CONTR_ID=C.MONEY_ID where C.PART_ID in (select PARTY_ID from PARTY where PARTY_DATE >= to_date('20-2-2015','dd-mm-yyyy') AND PARTY_DATE <= to_date('22-2-2015','dd-mm-yyyy')) group by C.SURNAME;

--Output list of most expensive tournaments

select TOUR_NAME from TOURNIR where REG_CONTRIBUTION=(select MAX(REG_CONTRIBUTION) from TOURNIR)