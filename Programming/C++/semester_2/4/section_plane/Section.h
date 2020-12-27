#include <math.h>
#include <iostream>
using namespace std;

struct Non_Section {};

class Segment
{
	int x1, x2, y1, y2;  // coordinates of the start and end points of the segment
public:
    /* default constructor */
	Segment();
	/* a constructor that sets field values; 
	   check the correctness of setting the coordinates of the start 
	   and end points of the segment, provide for the generation 
	   of the Non_Section exception if this condition is violated */
	Segment(const int &x1, const int &y1, const int &x2, const int &y2);
	/* copy constructor */
	Segment(const Segment &s);
	
    /* input-output of class objects into a stream using overloaded 
	   operators << and >> for this purpose; when entering, 
	   check for the correctness of specifying the coordinates of 
	   the start and end points of the segment; 
	   provide for the generation of a Non_Section exception 
	   if this condition is violated */
	friend istream& operator >> (istream& in, Segment& s); //throw Non_Even
	friend ostream& operator << (ostream& out, const Segment& s);

    /* assignment of one object to another using the overloaded 
	   operator = for this purpose */
	Segment& operator =(const Segment& s);

    /* obtaining the value of the length of a segment using 
	   the overloaded unary operator & for this purpose */
	friend double operator &(const Segment& s);
	
	/* obtaining a new segment, symmetric to the given segment 
	   relative to the center of the coordinate system, 
	   using the overloaded operator ~ for this purpose */
	friend Segment operator ~(const Segment& s);

    /* getting the coordinates of the specified point using 
	   the overloaded indexing operator [] for this purpose */
    int& operator [](const int& i);

    /* increasing or decreasing the values ​​of coordinates of 
	   the starting or ending points of the segment by one 
	   using the overloaded operators ++ (increment) and -- (decrement) */
	Segment& operator ++();
	Segment& operator --();

    /* comparison of two objects of a class using for these purposes 
	   comparison operators (==,! =) Overloaded as friendly functions; 
	   two objects are considered equal to each other if they completely coincide */
	friend bool operator ==(const Segment& s1, const Segment& s2);
	friend bool operator !=(const Segment& s1, const Segment& s2);

    /* comparison of the lengths of two segments using overloaded 
	   operators <, <=,>,> = for this purpose */
	friend bool operator <(const Segment& s1, const Segment& s2);
	friend bool operator >(const Segment& s1, const Segment& s2);
	friend bool operator >=(const Segment& s1, const Segment& s2);
	friend bool operator <=(const Segment& s1, const Segment& s2);
};