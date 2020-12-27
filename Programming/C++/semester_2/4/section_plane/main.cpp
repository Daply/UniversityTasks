#include "Section.h"
int main()
{
	try
	{
		Segment S1(1, 1, 2, 2);
		double d = &S1;
		cout << "Length of ";
		cout << S1;
	    cout<< " " << d << endl;
		Segment S2;
		S2 = ~S1;
		cout << S2 << endl;
		Segment S3[2];
		S3[0] = S1;
		S3[1] = S2;
		for (int i = 0; i < 2; i++)
		{
			cout << S3[i][1] << endl;// x1
		}
		Segment S4;
		S4 = ++S1;
		cout << S4 << endl;
		Segment S5;
		S5 = --S2;
		cout << S5 << endl;
		Segment S6(1,1,5,5);
		if (S1 == S6)
			cout << "Yes.\n";
		else
			cout << "No.\n";
		if (S1 != S2)
			cout << "Yes.\n";
		else
			cout << "No.\n";
		Segment S7(1, 1, 9, 9);
		double k = &S7;
		cout << "Length of ";
		cout << S7;
		cout << " " << k << endl;
		if (S1 < S7)
			cout << "Yes.\n";
		else
			cout << "No.\n";
	}
	catch (Non_Section)
	{
		cout << "Error" << endl;
	}
}