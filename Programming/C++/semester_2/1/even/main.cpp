#include "Even.h"
int main()
{
	try
	{
		Even N;
		N.print(cout);
		cout << "get N = " << N.get_n() << endl;
		N.set_n(4);
		cout << "Parameter: " << endl;
		N.print(cout);
		Even M(6);
		cout << "Parameter: " << endl;
		M.print(cout);
		Even P;
		cout << "Input: " << endl;
		P.input(cin, cout);
		cout << "Next number:";
		P.next_number().print(cout);
		cout << "Previous number:";
		P.previous_number().print(cout);
		cout << "Equal_number: ";
		if (equal_numb(M, P) == true) cout << "Yes" << endl;
		else cout << "No" << endl;
		cout << "Summa = ";
		addition_numb(N, M).print(cout);
		cout << endl;
		cout << "Difference = ";
		subtraction_numb(M, P).print(cout);
		cout << endl;
		cout << "Composition = ";
		multiplication_numb(N, P).print(cout);
		cout << endl;
	}
		catch (Non_even)
		{
			cout<<"This number is not even.\n";
		}
		catch (Not_prev)
		{
			cout<<"There is no previous for this number\n";
		}
		return 0;
}
