#include "Picture.h"
int Picture::counter = 0;
Picture::Picture(const char name[], const char surname[], const int& year, const int& price, const Genre& genre) : ID(++counter), year(year), price(price), genre(genre)
{
	if (year <= 0)
		throw Bad_year();
	if (price <= 0)
		throw Bad_price();
	strcpy(this->name, name);
	strcpy(this->surname, surname);
}
istream& operator>>(istream& in, Picture& p)
{
	char name[15], surname[20];
	int _year, _price;
	in >> _year >> _price;
	if (_year <= 0)
		throw Bad_year();
	if (_price <= 0)
		throw Bad_price();
	strcpy(p.name, name);
	strcpy(p.surname, surname);
	p.year = _year;
	p.price = _price;
	return in;
}
ostream& operator<<(ostream& out, const Picture& p)
{
	return out << "ID = " << p.ID << endl << "name = " << p.name << endl << "surname = " << p.surname << endl << "year = " << p.year << endl << "price = "
		<< p.price << endl << "genre = " << p.genre << endl;
}
void print1(Picture *p[], int size)
{
	cout << "===================================================== \n";
	for (int i = 0; i < size; i++)
		cout << *p[i] << endl;
	cout << "===================================================== \n";
}
void print2(Picture *p[], int size)
{
	cout << "===================================================== \n";
	char surname[30];
	int n = 0;
	cout << "Enter searching name of the artist: \n";
	cin >> surname;
	for (int i = 0; i < size; i++)
	{
		if (strcmp(p[i]->get_surname(), surname) == 0)
		{
			cout << *p[i] << endl;
			n++;
		}
	}
	if (n == 0)
		cout << "There aren't any pictures of this artist \n";
	cout << "===================================================== \n";
}
void print3(Picture *p[], int size)
{
	cout << "===================================================== \n";
	int price;
	int n = 0;
	cout << "Enter searching cost of the picture: \n ";
	cin >> price;
	for (int i = 0; i<size; i++)
	{
		if (p[i]->get_price() > price)
		{
			cout << *p[i] << endl;
			n++;
		}
	}
	if (n == 0)
		cout << "There aren't any pictures of this price \n";
	cout << "===================================================== \n";
}
void print4(Picture *p[], int size)
{
	cout << "===================================================== \n";
	int n = 0;
	int year;
	cout << "Enter searching year of creating the picture: ";
	cin >> year;
	int genre;
	cout << "Enter searching genre of the picture: 0 - landlandscape, 1 - portrait, 2 - another \n";
	cin >> genre;
	for (int i = 0; i<size; i++)
	{
		if (p[i]->get_year() == year && p[i]->get_genre() == genre)
		{
			cout << *p[i] << endl;
			n++;
		}
	}
	if (n == 0)
		cout << "There aren't any pictures of this year and genre \n";
	cout << "===================================================== \n";
}
void print5(Picture *p[], int size)
{
	cout << "===================================================== \n";
	for (int i = 0; i <size - 1; i++)
		for (int j = i + 1; j <size; j++)
			if (p[i]->get_price() < p[j]->get_price())
			{
				Picture *tmp = p[j];
				p[j] = p[i];
				p[i] = tmp;
			}

	for (int i = 0; i < size; i++)
		cout << *p[i] << endl;
	cout << "===================================================== \n";
}
void print6(Picture *p[], int size)
{
	cout << "===================================================== \n";
	for (int i = 0; i <size - 1; i++)
		for (int j = i + 1; j <size; j++)
			if (strcmp(p[i]->get_name(), p[j]->get_name())>0)
			{
				Picture *tmp = p[j];
				p[j] = p[i];
				p[i] = tmp;
			}

	for (int i = 0; i < size; i++)
		cout << *p[i] << endl;
	cout << "===================================================== \n";
}