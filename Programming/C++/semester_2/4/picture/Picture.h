#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Bad_year{};
struct Bad_price{};

enum Genre{ landscape, portrait, another };

class Picture
{
	Picture();
	int ID;            // unique numeric identifier (id)
	char name[15];     // paintitng name
	char surname[20];  // name of the artist
	int year;          // year of creation
	int price;         // estimated value
	Genre genre;       // genre
	static int counter;
public:
	Picture(const char name[], const char surname[], const int& year, const int& price, const Genre& genre);

	int get_ID()const { return ID; }
	const char* get_name()const { return name; }
	const char* get_surname()const { return surname; }
	int get_year()const { return year; }
	int get_price()const { return price; }
	Genre get_genre()const { return genre; }
	Picture& set_name(const char* nm) { strcpy(name, nm); return *this; }
	Picture& set_surname(const char* snm) { strcpy(surname, snm); return *this; }
	Picture& set_year(const int& yr){ this->year = yr; return *this; }
	Picture& set_price(const int& pr){ this->price = pr; return *this; }
	Picture& set_genre(const Genre& g) { this->genre = g; return *this; }

	friend istream& operator>>(istream& in, Picture& p);
	friend ostream& operator<<(ostream& out, const Picture& p);

	static int get_count() { return counter; }
};
void print1(Picture *p[], int size);
void print2(Picture *p[], int size);
void print3(Picture *p[], int size);
void print4(Picture *p[], int size);
void print5(Picture *p[], int size);
void print6(Picture *p[], int size);