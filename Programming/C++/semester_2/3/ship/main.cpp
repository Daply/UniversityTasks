#include <iostream>
#include"Ship.h"

using namespace std;

int main()
{
	try
	{
	Ship a1(1,cargo,6,8);
	a1.to_voyage("07.03.2014").print(cout);
	a1.to_doc("09.03.2014").print(cout);
	a1.set_name("shipper").print(cout);
	a1.set_level(5).print(cout);
	a1.from_doc_to_port().print(cout);
	a1.set_date_to_port_from_voyage("05.04.2014");
	a1.to_doc("10.06.2014");
	Ship a2;
	a2.print(cout);
	}
	catch(Max_level)
	{
		cout<<"Max level is 5"<<endl;
	}
	system("pause");
}
