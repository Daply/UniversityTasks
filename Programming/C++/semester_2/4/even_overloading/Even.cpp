#include "Even.h"
Even::Even()
{
	this->n = 2;
};
Even::Even(const int& n)
{
	if (is_even(n) == false)
	{
		throw Non_even();
	}
	else
	{
		this->n = n;
	}
};
Even::Even(const Even& e)
{
	n = e.n;
};

Even& Even::operator +=(const Even& e)
{
	n += e.n;
	return *this;
};
Even& Even::operator -=(const Even& e)
{
	n -=e.n;
	return *this;
};
Even& Even::operator *=(const Even& e)
{
	n *=e.n;
	return *this;
};

Even operator -(const Even& e)
{
	return Even(-e.n);
};
Even operator +(const Even& e)
{
	return Even(+e.n);
};

bool operator <(const Even& e1, const Even& e2)
{
	return e1.n < e2.n;
};
bool operator >(const Even& e1, const Even& e2)
{
	return e1.n > e2.n;
};
bool operator ==(const Even& e1, const Even& e2)
{
	return e1.n == e2.n;
};
bool operator !=(const Even& e1, const Even& e2)
{
	return e1.n != e2.n;
};
bool operator <=(const Even& e1, const Even& e2)
{
	return e1.n <= e2.n;
};
bool operator >=(const Even& e1, const Even& e2)
{
	return e1.n >= e2.n;
};

Even operator +(const Even& e1, const Even& e2)
{
	return Even(e1.n+e2.n);
};
Even operator -(const Even& e1, const Even& e2)
{
	Even tmp(e1);
	tmp -= e2;
	return tmp;
};
Even operator *(const Even& e1, const Even& e2)
{
	Even tmp(e1);
	tmp *= e2;
	return tmp;
};

istream& operator >> (istream& in, Even& e)
{
	int n_;
	cout << "Input the number: ";
	in >> n_;
	if (n_%2!=0)
	{
		throw Non_even();
	}
	e.n = n_;
	return in;
};
ostream& operator << (ostream& out, const Even& e)
{
	return out << "n= " << e.n << endl;
};