#include <iostream>
using namespace std;

struct Non_even{};

class Even
{
	int n;
	bool is_even(int a)
	{
		if (a % 2 == 0)
		{
			return true;
		}
		return false;
	}
public:
    // constructor
	Even();  // default
	Even(const int& n);  // copy throw (Non_Even)
	Even(const Even& e);
    // assignment operators
	Even& operator +=(const Even& e);
	Even& operator -=(const Even& e);
	Even& operator *=(const Even& e);
    // unary + and -
	friend Even operator -(const Even& e);
	friend Even operator +(const Even& e);
    // binary comparison operators
	friend bool operator <(const Even& e1, const Even& e2);
	friend bool operator >(const Even& e1, const Even& e2);
	friend bool operator ==(const Even& e1, const Even& e2);
	friend bool operator !=(const Even& e1, const Even& e2);
	friend bool operator <=(const Even& e1, const Even& e2);
	friend bool operator >=(const Even& e1, const Even& e2);
    // binary arithmetic operators
	friend Even operator +(const Even& e1, const Even& e2);
	friend Even operator -(const Even& e1, const Even& e2);
	friend Even operator *(const Even& e1, const Even& e2);
    // binary I / O operators
	friend istream& operator >> (istream& in, Even& e);  // throw (Non_Even)
	friend ostream& operator << (ostream& out, const Even& e);
};