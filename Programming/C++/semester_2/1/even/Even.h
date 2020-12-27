#include <iostream>
using namespace std;

struct Non_even{};
struct Not_prev{};

class Even
{
	int n;
	bool is_even(int a)
	{
		if (a % 2 == 0)
		{
			return true;
		}
		else return false;
	};
public:
	Even();
	Even(const int& n);
	Even(const Even& r);
	int get_n() const { return n; };
	Even& set_n (int n) { this->n = n; return *this; };
	void print(ostream& out) const;
	Even& input(istream& in, ostream& out);
	Even next_number() const;
	Even previous_number();
	friend Even addition_numb(const Even& r1, const Even& r2);
	friend Even subtraction_numb(const Even& r1, const Even& r2);
	friend Even multiplication_numb(const Even& r1, const Even& r2);
	friend bool equal_numb(const Even& r1, const Even& r2);
};
