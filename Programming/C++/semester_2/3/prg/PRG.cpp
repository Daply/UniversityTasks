#include "PRG.h"
int PRG::counter=100;
PRG::PRG():id(++counter),name("John"),race(orc),gender(male)
{
	state=normal;
	age=34;
	health=1;
	max_health=38;

};

PRG::PRG(const char name[20],const PRG_race& race,const PRG_gender& gender):name(),race(race),id(++counter),gender(gender)
{
	state=normal;
	age=34;
	health=1;
	max_health=38;
};

PRG::PRG(const PRG& S):name(),id(++counter),race(S.race),gender(S.gender)
{
	state=normal;
	age=34;
	health=1;
	max_health=38;
};

PRG& PRG::battle(const PRG& S1,const PRG& S2)
{
	if(S1.race==S2.race)
	{
		health=health-10;
	}
	else
	{
		health=health-15;
	}
	if (health<10)
	{
		state=weak;
	}
	if (health==0)
	{
		state=dead;
	}
		return *this;
};
PRG& PRG::fill_health()
{
		health=+5;
		if (health>=max_health)
		{
			health=max_health;
		}
		if (health>=10)
		{
			if (state==weak)
			{
				state=normal;
			}
		}
	    return *this;
};

bool equal_health(const PRG& S1,const PRG& S2)
{
	return S1.health==S2.health;
}
const char* S_state[]={"normal","weak","dead"};
const char* S_race[]={"human","gnome","elf","orc","dragon"};
const char* S_gender[]={"male","female"};
void PRG::print(ostream& out)const
{
	out<<"id="<<id<<" name="<<name<<" state="<<S_state[state]<<" race="<<S_race[race]<<" gender="<<S_gender[gender]<<" age="<<age<<" health="<<health<<endl;
}
