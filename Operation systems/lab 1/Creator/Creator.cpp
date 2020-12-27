#include <iostream>
#include<fstream>
using namespace std;
struct order
{
	char name[10];
	int amount;
	double price;
};
int main(int argc, char *argv[])
{	
    ofstream out(argv[1], ios::binary | ios::out);
	int number;
	cout << "Enter the number of objects:\n";
	cin >> number;
	order* or = new order[number];
	cout << "Enter objects:\n";

	for(int i = 0; i < number; i++)
	   {
        cin >> or[i].name;
		cin >> or[i].amount;
		cin >> or[i].price;
	   }
	for(int i = 0; i < number; i++)
	   {
        out << or[i].name << " ";
		out << or[i].amount << " ";
		if (i != number-1)
		out << or[i].price << "\n";
		else
        out << or[i].price;
	   }
    out.close();
	cout << "End of entering information\n";

}