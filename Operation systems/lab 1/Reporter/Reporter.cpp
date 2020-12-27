#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


struct order
{
char name[10];
int amount;
double price;
};

int countStringsInFile(ifstream file)
{
	int i = 0;
	char *str = new char[1024];
	while(!file.eof())
	{
		file.getline(str,1024,'\n');
		i++;
	}
	return i;
}

void main(int argc, char* argv[])
{
	order* or;
	
	int j = 0;
    ifstream in(argv[3], ios::binary | ios::in);
	int count = countStringsInFile(in);
	or = new order[count];
	while(!in.eof())
	{
		in >> or[j].name >> or[j].amount >> or[j].price;
		cout << or[j].name <<"  "<< or[j].amount <<"  "<< or[j].price<<endl;
        j++;
	}

	in.close();

	int minAmount = atoi(argv[1]);
	double minPrice = atof(argv[2]);
	ofstream out(argv[4], ios::out);

    cout << "File and objects are exepted\n";

	out << "Report on file: " << argv[3] << endl;

	for(int i = 0; i < count; i++)
	{
		if(or[i].amount <= minAmount || or[i].price*or[i].amount <= minPrice)
			out << or[i].name << " " << or[i].amount << " " << or[i].price*or[i].amount << endl;
	}
	out.close();
	system("pause");
}
