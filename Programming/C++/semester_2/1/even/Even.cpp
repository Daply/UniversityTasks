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
Even::Even(const Even& r)
{
	n = r.n;
};
void Even::print(ostream& out) const
{
	out << "n = " << n << endl;
};
Even& Even::input(istream& in, ostream& out)
{
	int a;
	out << "Input your number ";
	in >>a;
	if (is_even(a) == false)
	{
		throw Non_even();
	}
	else
	{
		n = a;
	}
	return *this;
};
Even Even::next_number() const
{
	return Even(n+2);
};
Even Even::previous_number()
{
	if (n == 2)
	{
		throw Not_prev();
	}
	return Even(n - 2);
};
Even addition_numb(const Even& r1, const Even& r2)
{
	return Even(r1.n + r2.n) ;
};
Even subtraction_numb(const Even& r1, const Even& r2)
{
	return Even(r1.n - r2.n);
};
Even multiplication_numb(const Even& r1, const Even& r2)
{
	return Even(r1.n * r2.n);
};
bool equal_numb(const Even& r1, const Even& r2)
{
	return r1.n == r2.n;
};
