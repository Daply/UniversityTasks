--Chess club
--The trigger must prevent the insertion of game information in the tournament,
--if the player has not paid the membership fees in the year of the tournament.
--(the structure of the REG_CONTRIBUTION and PARTY tables has changed, CONTRIBUTION contains CHESSPL_ID - the id of the chess player who paid the contribution and the DATE_OF_PAY date when the contribution was made, FIRST_CHESSPL_ID and SECOND_CHESSPL_ID have been added to PARTY)
CREATE OR REPLACE TRIGGER INSERT_IN_PARTY
    BEFORE INSERT ON PARTY
	DECLARE 
	first_ch NUMBER;
	second_ch NUMBER;
	FOR EACH ROW
    BEGIN
		SELECT COUNT(*) INTO first_ch FROM REG_CONTRIBUTION WHERE CHESSPL_ID = :NEW.FIRST_CHESSPL_ID AND TO_CHAR(DATE_OF_PAY, 'YYYY') = TO_CHAR(:NEW.DATE_OF_PAY, 'YYYY'));
		SELECT COUNT(*) INTO second_ch FROM REG_CONTRIBUTION WHERE CHESSPL_ID = :NEW.SECOND_CHESSPL_ID AND TO_CHAR(DATE_OF_PAY, 'YYYY') = TO_CHAR(:NEW.DATE_OF_PAY, 'YYYY'));
		IF NOT first_ch OR second_ch
			RAISE_APPLICATION_ERROR(-20000, "Player didn't pay contribution for that game");
	END;
