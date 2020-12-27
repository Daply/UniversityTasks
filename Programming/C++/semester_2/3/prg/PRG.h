#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

enum PRG_state{normal,weak,dead};
enum PRG_race{human,gnome,elf,orc,dragon};
enum PRG_gender{male,female};

struct MAX_health{};

class PRG
{
    int id; /* a unique numeric identifier */
	const char name[20]; /* character's name */
	PRG_state state; /* condition (normal, weak, dead) */
    const PRG_race race; /* race (human, gnome, elf, orc, dragon, ...) */
    const PRG_gender gender; /* gender */
	int age; /* age */
	int health; /* the current value of the character's health (non-negative value); */
	int max_health; /* the maximum value for the character's health (38) */
	static int counter;


public:
	PRG();
	/* a constructor that sets the values ​​of immutable fields and
	   ensures the uniqueness of the identifier for the new object;
	   provide for the handling of all exceptional situations in the class. */
	PRG(const char name[20],const PRG_race& race,const PRG_gender& gender);
	PRG(const PRG& S);

	/* get methods */
	int get_id(){return id;}
	const char* get_name()const{return name;}
	PRG_state get_state(){return state;};
	const PRG_race get_race()const{return race;}
	const PRG_gender get_gender()const{return gender;}
	int get_age(){return age;}
	int get_health()
	{
		return health;
		if (health>max_health)
		{
			throw MAX_health();
		}
	}

	/* set methods */
	PRG& set_id(int id){this->id=id; return *this;};
	PRG& set_state(const PRG_state& state)
	{
		this->state=state;
		return *this;
	}
	int set_age(int age){ return age;}
	int set_health(int health){ return health;}

    /* loss of health by a character in the event of a battle with another character.
       When colliding with a character similar to himself, he loses 10 health units,
       when colliding with a character of another race, he loses 15 health units.
       If the percentage of the character's health becomes less than 10,
       the character automatically switches from the "healthy" state to the "weak" state.
       If the current health value is 0, the character automatically switches from any
       state to the "dead" state. A weakened or dead character cannot fight. */
	PRG& battle(const PRG& S1,const PRG& S2);
	/* replenishment of health by drinking a sip of living water.
	   Each sip brings five units of health, but its amount cannot exceed the maximum value.
	   If the percentage of the character's health becomes greater than or equal to 10,
	   the character automatically switches from the "weakened" state to the "healthy" state.
	   A dead character cannot drink living water; */
	PRG& fill_health();
	/* comparison of characters by percentage of health (the ratio of the character's
       current health to the maximum amount of health); */
	friend bool equal_health(const PRG& S1,const PRG& S2);
	/* output of information about the character to the output stream. */
	void print(ostream& out)const;
};
