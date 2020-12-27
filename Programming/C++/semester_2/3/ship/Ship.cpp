#include "Ship.h"
int Ship::counter=100;
Ship::Ship():id(++counter),type(other),power(0),maxlevel(5)
{
	name[0]=0;
	level=0;
	place=port;
	date_voyage[0]=0;
	date_doc[0]=0;
};

Ship::Ship(const int& id,const Ship_type& type,const double& power,const int& maxlevel):type(type),power(power),id(++counter),maxlevel(5)
{
	name[0]=0;
	level=0;
	place=port;
	date_voyage[0]=0;
	date_doc[0]=0;
};
Ship::Ship(const Ship& S):id(++counter),type(S.type),power(S.power),place(port),maxlevel(5)
{
	strcpy(date_voyage,S.date_voyage);
	strcpy(date_doc,S.date_doc);
};
Ship& Ship::to_voyage(const char* date)
{
	if(place==port || place==doc)
	{
		place=port;
		strcpy(date_voyage,date);
	}
		return *this;
};
Ship& Ship::to_port_from_voyage(const char* date)
{
	if(place==voyage)
	{
		place=port;
		strcpy(date_doc,date);
		level++;
		if(level==maxlevel)
		{
			place=doc;
		}
	}
	    return *this;
};
Ship& Ship::to_doc(const char* date)
{
	if(place==port || place==voyage)
	{
		place=doc;
		date_voyage[0]=0;
		strcpy(date_doc,date);
	}
	    return *this;
};
Ship& Ship::from_doc_to_port()
{
	if(place==doc)
	{
		place=port;
		date_voyage[0]=0;
	}
	    return *this;
};
bool equal_power(const Ship& S1,const Ship& S2)
{
	return S1.power==S2.power;
}
const char* s_type[]={"sport","passenger","cargo","other"};
const char* s_place[]={"port","voyage","doc"};
void Ship::print(ostream& out)const
{
	out<<"id="<<id<<" name="<<name<<" power="<<power<<" type="<<s_type[type]<<" level="<<level<<" place="<<s_place[place]<<" date voyage="<<date_voyage<<" date doc="<<date_doc<<endl;
}
