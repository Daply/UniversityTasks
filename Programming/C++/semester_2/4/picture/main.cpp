#include "Picture.h"
int main()
{
	try
	{
		int choice;
		Picture A1("Tymannoe ytro", "Shishkin", 1885, 1000, landscape);
		Picture A2("Belorys", "Repin", 1882, 750, portrait);
		Picture A3("Tri bogatiria", "Vasnecov", 1898, 600, another);
		Picture A4("Jiraf v ogne", "Dali", 1937, 1200, another);
		Picture A5("Avtoportret", "Van Gog", 1887, 890, portrait);
		Picture *A[5];
		A[0] = &A1;
		A[1] = &A2;
		A[2] = &A3;
		A[3] = &A4;
		A[4] = &A5;

		while (true)
		{
			cout << "Make a choice \n";
			cout << "0-exit" << endl;
			cout << "1-list of all pictures" << endl;
			cout << "2-list of pictures of mentioned artist" << endl;
			cout << "3-list of pictures of under mentioned price" << endl;
			cout << "4-list of pictures for mentioned year of mentioned genre " << endl;
			cout << "5-list of pictures in decrease of price" << endl;
			cout << "6-list of pictures in alphabetical order of the name" << endl;
			cin >> choice;
			switch (choice)
			{
			case 0: return 0;
			case 1: print1(A, 5); break;
			case 2: print2(A, 5); break;
			case 3: print3(A, 5); break;
			case 4: print4(A, 5); break;
			case 5: print5(A, 5); break;
			case 6: print6(A, 5); break;
			default: cout << "======= error of choice !!! =======\n";
			}
		}

	}
	catch (Bad_year)
	{
		cout << "Error in year \n";
	}
	catch (Bad_price)
	{
		cout << "Error in price \n";
	}
	return 0;
}