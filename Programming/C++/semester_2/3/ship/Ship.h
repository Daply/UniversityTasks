#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

enum Ship_type{sport,passenger,cargo,other}; /* (sports, passenger, cargo, other) */
enum Ship_placement{port,voyage,doc};

struct Max_level{};

class Ship
{
	const int id; /* unique numeric identifier */
	char name[20]; /* name of the ship */
	const double power;  /* displacement (in tons) */
	const Ship_type type; /* type (sports, passenger, cargo, other) */
	int level;  /* the degree of deterioration of the ship */
	const int maxlevel;  /* maximum value of the degree of deterioration of the ship (5) */
	Ship_placement place;   /* location of the ship (in port, in voyage, at the dock) */
	char date_voyage[10];  /* date of arrival of the ship at the port from the voyage */
	char date_doc[10];  /* date of arrival of the ship to the port from the dock */
	static int counter;


public:
    /* default constructor that ensures the uniqueness of the identifier for the new object */
	Ship();
	/* a constructor that sets the values ??of the class attributes and ensures the uniqueness of the identifier for the new object */
	Ship(const int& id,const Ship_type& type,const double& power,const int& maxlevel);
	/* a copy constructor that ensures the uniqueness of the identifier for a new object */
	Ship(const Ship& S);

	/* get methods */
	int get_id()const{return id;}
	Ship_placement get_place()const{return place;}
	Ship_type get_type()const{return type;}
	const char* get_date_voyage()const{return date_voyage;}
	const char* get_date_doc()const{return date_doc;}
	double get_power(){return power;}

	/* set methods */
	Ship& set_name(const char* d){strcpy(name,d); return *this;}
	Ship& set_level(const int& level)
	{
		if (level>5)
		{
			throw Max_level();
		}
		this->level=level;
		return *this;
	}
	Ship& set_place(const Ship_placement& place){ this->place=place; return *this;}
	Ship& set_date_to_port_from_voyage(const char* d){strcpy(date_voyage,d); return *this;}
	Ship& set_date_to_port_from_doc(const char* d){strcpy(date_doc,d); return *this;}

	/* a function that sends a ship on a voyage and receives as a parameter
	   the date of the ship's return from the next voyage; */
	Ship& to_voyage(const char* date);
	/* a function that returns the ship to the port from the voyage; in this case,
	   the degree of deterioration of the ship increases by a certain amount;
	   if the maximum value of the degree of deterioration is exceeded,
       the ship must be sent to the dock for preventive maintenance; */
	Ship& to_port_from_voyage(const char* date);
	/* a function that sends a ship to the dock and receives as a parameter
	   the date of the ship's return from the dock */
	Ship& to_doc(const char* date);
	/* a function that returns the ship to the port from the dock;
	   in this case, the degree of deterioration of the ship must be set at a certain value */
	Ship& from_doc_to_port();
	/* a friendly function of comparing the displacement of two ships for equality; */
	friend bool equal_power(const Ship& S1,const Ship& S2);
	/* a function that outputs information about an object to a stream; */
	void print(ostream& out)const;
};
