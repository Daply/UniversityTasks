DROP TABLE Reg_contribution CASCADE CONSTRAINTS;
DROP TABLE Debut CASCADE CONSTRAINTS;
DROP TABLE Party CASCADE CONSTRAINTS;
DROP TABLE Tour_system CASCADE CONSTRAINTS;
DROP TABLE Tournir CASCADE CONSTRAINTS;
DROP TABLE Сhessplayer CASCADE CONSTRAINTS;




CREATE TABLE Reg_contribution
  (
    Reg_contr_ID                       INTEGER NOT NULL ,
    Contribution                       INTEGER CHECK ( Contribution < 1000 )
  ) ;
ALTER TABLE Reg_contribution ADD CONSTRAINT Reg_contribution_PK PRIMARY KEY ( Reg_contr_ID ) ;

INSERT INTO Reg_contribution VALUES
	(1, 1000);
INSERT INTO Reg_contribution VALUES
	(2, 1500);
INSERT INTO Reg_contribution VALUES
	(3, 300);
INSERT INTO Reg_contribution VALUES
	(4, 800);



CREATE TABLE Debut
  (
    Debut_ID                           INTEGER NOT NULL ,
    Debut_name                         CHAR (40)
  ) ;
ALTER TABLE Debut ADD CONSTRAINT Debut_PK PRIMARY KEY ( Debut_ID ) ;

INSERT INTO Debut VALUES
	(1, 'sicilian defense');
INSERT INTO Debut VALUES 
	(2, 'kings gambit');
INSERT INTO Debut VALUES 
	(3, 'Philidor defense');
INSERT INTO Debut VALUES 
	(4, 'four knights game');
INSERT INTO Debut VALUES 
	(5, 'Ponziani opening');
INSERT INTO Debut VALUES 
	(6, 'Evans gambit');

CREATE TABLE Party
  (
    Party_ID                           INTEGER NOT NULL ,
    Party_date                         DATE ,
    Whites_steps                       INTEGER ,
    Result                             CLOB ,
    Tournir_ID                         INTEGER NOT NULL ,
    PDebut_ID                          INTEGER NOT NULL
  ) ;
ALTER TABLE Party ADD CONSTRAINT Party_PK PRIMARY KEY ( Party_ID ) ;

INSERT INTO Party VALUES 
	(1, to_date('20-2-2015','dd-mm-yyyy'),19,'Blacks won',1,1);
INSERT INTO Party VALUES 
	(2, to_date('21-2-2015','dd-mm-yyyy'),16,'Whites won',1,4);
INSERT INTO Party VALUES 
	(3, to_date('22-2-2015','dd-mm-yyyy'),24,'Whites won',1,2);
INSERT INTO Party VALUES 
	(4, to_date('17-6-2015','dd-mm-yyyy'),20,'Blacks won',2,3);
INSERT INTO Party VALUES 
	(5, to_date('18-6-2015','dd-mm-yyyy'),29,'Whites won',2,5);
INSERT INTO Party VALUES 
	(6, to_date('19-6-2015','dd-mm-yyyy'),27,'Blacks won',2,7);
	
CREATE TABLE Tour_system
  (
    System_ID                          INTEGER NOT NULL ,
    System_name                        CHAR (40)
  ) ;
ALTER TABLE Tour_system ADD CONSTRAINT Tour_system_PK PRIMARY KEY ( System_ID ) ;

INSERT INTO Tour_system VALUES 
	(1, 'swiss system');
INSERT INTO Tour_system VALUES 
	(2, 'round system');
INSERT INTO Tour_system VALUES 
	(3, 'scheveningen system');

CREATE TABLE Tournir
  (
    Tour_ID                            INTEGER NOT NULL ,
    Tour_name                          CHAR (50) ,
    Reg_contribution                   INTEGER ,
    Prizes_for_1_2_3_places            INTEGER ,
    Tour_start_date                    DATE ,
    Tour_end_date                      DATE ,
    Tour_system_ID                     INTEGER NOT NULL
  ) ;
ALTER TABLE Tournir ADD CONSTRAINT Tournir_PK PRIMARY KEY ( Tour_ID ) ;

INSERT INTO Tournir VALUES 
	(1, 'Crazy chessers',9000, 3000, to_date('20-2-2015','dd-mm-yyyy'), to_date('22-2-2015','dd-mm-yyyy'), 3);
INSERT INTO Tournir VALUES 
	(2, 'Chess masters',12000, 4000, to_date('17-6-2015','dd-mm-yyyy'), to_date('19-6-2015','dd-mm-yyyy'), 2);

CREATE TABLE Chessplayer
  (
    Chessplayer_ID                     INTEGER NOT NULL ,
    Surname                            CHAR (50) ,
    Name                               CHAR (40) ,
    Fathers_name                       CHAR (40) ,
	Side                               CHAR (40) DEFAULT = 'WHITE',
    Levels                             INTEGER CHECK IN (1,2,3,4,5),
    Birth_date                         DATE ,
    Date_of_entering                   DATE ,
    Privelegies                        CLOB ,
    Part_ID                            INTEGER NOT NULL,
    Money_ID                           INTEGER NOT NULL
  ) ;
ALTER TABLE Chessplayer ADD CONSTRAINT Chessplayer_PK PRIMARY KEY ( Chessplayer_ID ) ;

INSERT INTO Chessplayer VALUES 
	(1,'Ivanov','Igor','Vladimirivich','WHITE',2, to_date('6-8-1993','dd-mm-yyyy'), to_date('17-1-2013','dd-mm-yyyy'), 'SUPER SMART',1,1);
INSERT INTO Chessplayer VALUES 
	(2,'Sokolov','Andrey','Semenovich','BLACK',2, to_date('20-8-1994','dd-mm-yyyy'), to_date('15-6-2014','dd-mm-yyyy'), 'SUPER SMART',1,1);
INSERT INTO Chessplayer VALUES 
	(3,'Smelev','Victor','Petrovich','WHITE',2, to_date('11-9-1992','dd-mm-yyyy'), to_date('21-12-2014','dd-mm-yyyy'), 'SUPER SMART',2,1);	
INSERT INTO Chessplayer VALUES 
	(4,'Sidorov','Sergey','Igorevich','BLACK',2, to_date('7-3-1992','dd-mm-yyyy'), to_date('18-2-2013','dd-mm-yyyy'), 'SUPER SMART',2,1);
INSERT INTO Chessplayer VALUES 
	(5,'Sidorov','Sergey','Igorevich','BLACK',2, to_date('7-3-1992','dd-mm-yyyy'), to_date('18-2-2013','dd-mm-yyyy'), 'SUPER SMART',3,1);
INSERT INTO Chessplayer VALUES 
	(6,'Ivanov','Igor','Vladimirivich','WHITE',2, to_date('6-8-1993','dd-mm-yyyy'), to_date('17-1-2013','dd-mm-yyyy'), 'SUPER SMART',3,1);
	
INSERT INTO Chessplayer VALUES 
	(7,'Timurov','Aleksey','Geogrievich','WHITE',3, to_date('14-8-1993','dd-mm-yyyy'), to_date('5-5-2014','dd-mm-yyyy'), 'SUPER SMART',1,2);
INSERT INTO Chessplayer VALUES 
	(8,'Antonevich','Egor','Vasilievich','BLACK',3, to_date('3-4-1993','dd-mm-yyyy'), to_date('10-9-2014','dd-mm-yyyy'), 'SUPER SMART',1,2);
INSERT INTO Chessplayer VALUES 
	(9,'Stepanov','Aleksandr','Vladimirivich','WHITE',3, to_date('5-7-1993','dd-mm-yyyy'), to_date('13-12-2013','dd-mm-yyyy'), 'SUPER SMART',2,2);	
INSERT INTO Chessplayer VALUES 
	(10,'Kireev','Vadim','Sergeevich','BLACK',3, to_date('1-11-1993','dd-mm-yyyy'), to_date('4-6-2013','dd-mm-yyyy'), 'SUPER SMART',2,2);
INSERT INTO Chessplayer VALUES 
	(11,'Timurov','Aleksey','Geogrievich','BLACK',3, to_date('14-8-1993','dd-mm-yyyy'), to_date('5-5-2014','dd-mm-yyyy'), 'SUPER SMART',3,2);
INSERT INTO Chessplayer VALUES 
	(12,'Stepanov','Aleksandr','Vladimirivich','WHITE',3, to_date('5-7-1993','dd-mm-yyyy'), to_date('13-12-2013','dd-mm-yyyy'), 'SUPER SMART',3,2);	


ALTER TABLE Party ADD CONSTRAINT Party_Debut_FK FOREIGN KEY ( PDebut_ID ) REFERENCES Debut ( Debut_ID ) ;

ALTER TABLE Party ADD CONSTRAINT Party_Tournir_FK FOREIGN KEY ( Tournir_ID ) REFERENCES Tournir ( Tour_ID ) ;

ALTER TABLE Tournir ADD CONSTRAINT Tour_system_FK FOREIGN KEY ( Tour_system_ID ) REFERENCES Tour_system ( System_ID ) ;

ALTER TABLE Chessplayer ADD CONSTRAINT Chesspl_Reg_contr_FK FOREIGN KEY ( Money_ID ) REFERENCES Reg_contribution ( Reg_contr_ID ) ;

ALTER TABLE Chessplayer ADD CONSTRAINT Chessplayer_Party_FK FOREIGN KEY ( Part_ID ) REFERENCES Party ( Party_ID ) ;
