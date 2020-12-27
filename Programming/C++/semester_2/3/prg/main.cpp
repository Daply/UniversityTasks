#include <iostream>
#include"PRG.h"

using namespace std;

int main()
{
	try
	{
	PRG a1("rgd", dragon, male);
	a1.print(cout);


	PRG a2;
	a2.print(cout);
	}
	catch(MAX_health)
	{
		cout<<"Max health is 38"<<endl;
	}
	system("pause");
}

