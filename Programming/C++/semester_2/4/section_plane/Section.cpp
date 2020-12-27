#include <math.h>
#include <iostream>
#include "Section.h"
using namespace std;

Segment::Segment()
{
	x1 = 0; y1 = 0;
	x2 = 2; y2 = 2;
}

Segment::Segment(const int &x1, const int &y1, const int &x2, const int &y2)
{
	if (x1 == x2&&y1 == y2) throw Non_Section();
	else
	{
		this->x1 = x1; this->y1 = y1;
		this->x2 = x2; this->y2 = y2;
	}
}
Segment::Segment(const Segment& s)
{
	x1 = s.x1; y1 = s.y1;
	x2 = s.x2; y2 = s.y2;
}

istream& operator >> (istream& in, Segment& s)
{
	int x1_, x2_, y1_, y2_;
	cout << "Input the number: ";
	in >> x1_>>x2_>>y1_>>y2_;
	if (x1_==x2_ && y1_==y2_)
	{
		throw Non_Section();
	}
	s.x1 = x1_;
	s.x2 = x2_;
	s.y1 = y1_;
	s.y2 = y2_;
	return in;
};
ostream& operator << (ostream& out, const Segment& s)
{
	return out<<"Segment: "<<endl << "x1= " << s.x1 << endl << "x2= " << s.x2 << endl << "y1= " << s.y1 << endl << "y2= " << s.y2 << endl;
};

Segment& Segment:: operator =(const Segment& s)
{
		x1 = s.x1;
		x2 = s.x2;
		y1 = s.y1;
		y2 = s.y2;
	return *this;
};

double operator &(const Segment& s)
{
	return sqrt((double) abs((s.x2 - s.x1)*(s.x2 - s.x1) + (s.y2 - s.y1)*(s.y2 - s.y1)));
};

Segment operator ~(const Segment& s)
{
	return (Segment(-s.x1, -s.y1, -s.x2, -s.y2));
};

int& Segment::operator[](const int& i)
{
	switch (i)
	{
	case (1) : return x1;
	case (2) : return y1;
	case (3) : return x2;
	case (4) : return y2;
	}
};

Segment& Segment:: operator++ ()
{
	x1 = x1 + 1;
	y1 = y1 + 1;
	x2 = x2 + 1;
	y2 = y2 + 1;
	return *this;
};
Segment& Segment:: operator-- ()
{
	x1 = x1 - 1;
	y1 = y1 - 1;
	x2 = x2 - 1;
	y2 = y2 - 1;
	return *this;
};

bool operator ==(const Segment& s1, const Segment& s2)
{
	return (s1.x1 == s2.x1, s1.y1 == s2.y1, s1.x2 == s2.x2, s1.y2 == s2.y2);
};
bool operator !=(const Segment& s1, const Segment& s2)
{
	return (s1.x1 != s2.x1, s1.y1 != s2.y1, s1.x2 != s2.x2, s1.y2 != s2.y2);
};

bool operator <(const Segment& s1, const Segment& s2)
{
	return abs((s1.x2 - s1.x1)*(s1.x2 - s1.x1) + (s1.y2 - s1.y1)*(s1.y2 - s1.y1)) < abs((s2.x2 - s2.x1)*(s2.x2 - s2.x1) + (s2.y2 - s2.y1)*(s2.y2 - s2.y1));
};
bool operator >(const Segment& s1, const Segment& s2)
{
	return abs((s1.x2 - s1.x1)*(s1.x2 - s1.x1) + (s1.y2 - s1.y1)*(s1.y2 - s1.y1)) > abs((s2.x2 - s2.x1)*(s2.x2 - s2.x1) + (s2.y2 - s2.y1)*(s2.y2 - s2.y1));
};
bool operator >=(const Segment& s1, const Segment& s2)
{
	return abs((s1.x2 - s1.x1)*(s1.x2 - s1.x1) + (s1.y2 - s1.y1)*(s1.y2 - s1.y1)) >= abs((s2.x2 - s2.x1)*(s2.x2 - s2.x1) + (s2.y2 - s2.y1)*(s2.y2 - s2.y1));
};
bool operator <=(const Segment& s1, const Segment& s2)
{
	return abs((s1.x2 - s1.x1)*(s1.x2 - s1.x1) + (s1.y2 - s1.y1)*(s1.y2 - s1.y1)) <= abs((s2.x2 - s2.x1)*(s2.x2 - s2.x1) + (s2.y2 - s2.y1)*(s2.y2 - s2.y1));
};