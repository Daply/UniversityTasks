#include "Even.h"
int main()
{
	try
	{
		Even N1(4);
		cout << N1 << endl;

		Even N2;
		cin >> N2;
		cout << N2 << endl;

		Even N3(20);
		N3 += N1;
		cout << N3 << endl;

		Even N4(10);
		N4 -= N1;
		cout << N4 << endl;

		Even N5(6);
		N5 *= N1;
		cout << N5 << endl;

		Even N6(10);
		N6 = -N6;
		cout << N6 << endl;

		if (N6 < N3)
			cout << "Yes!" << endl;
		else
			cout << "No!" << endl;

		Even N7[3];
		N7[0] = N3;
		N7[1] = N4;
		N7[2] = N1+N2;
		for (int i = 0; i < 3; i++)
		{
			cout << N7[i] << " ";	
		}
		cout << endl << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "Summa of "<< N7[i] <<" and "<< N7[i]<<" of the array" << endl;
			cout << N7[i] + N7[i] << " ";
		}
		cout << endl << endl;
		for (int i = 0; i < 3; i++)
		{
			if (N7[i] != N7[0])
				cout << "No!" << endl;
			else
				cout << "Yes" << endl;
		}
		cout << endl << endl;
		Even *N8[3];
	    N8[0] = &N3;
		N8[1] = &N1;
	    N8[2] = &N2;
		for (int i = 0; i < 3; i++)
		{
			cout << *N8[i] << endl;
		}
	}
	catch (Non_even)
	{
		cout << "Error. This number is not even." << endl;
	}
	return 0;
}