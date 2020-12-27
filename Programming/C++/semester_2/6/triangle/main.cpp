#include"Triangle.h"
#include <iostream>
using namespace std;

void test (Triangle &t)
{
	cout << "Test: p=" << t.perimetr() << "\t" << "s=" << t.area() << endl << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Isosceles triangle: " << endl;
	Isosceles_triangle a1(10,7);
	cout << "p=" << a1.perimetr() << "\t" << "s=" << a1.area() << endl << endl;
	test(a1);

	cout << "Equilateral triangle: " << endl;
	Equilateral_triangle a2(5);
	cout << "p=" << a2.perimetr() << "\t" << "s=" << a2.area() << endl << endl;
	test(a2);

	cout << "Rectangular triangle: " << endl;
	Rectangular_triangle a3(3,4,5);
	cout << "p=" << a3.perimetr() << "\t" << "s=" << a3.area() << endl << endl;
	test(a3);

	cout << "Rectangular isosceles triangle: " << endl;
	Rectangular_isosceles_triangle a4(4,5);
	cout << "p=" << a3.perimetr() << "\t" << "s=" << a3.area() << endl << endl;
	test(a3);

    cout << "Array: " << endl;

	Triangle* a[3];
	a[0] = &a1;
	a[1] = &a2;
	a[2] = &a3;

	for(int i=0; i<3; i++)
	{
		cout << "p=" << a[i]->perimetr() << "\t" << "s=" << a[i]->area() << endl;
	}

	system("pause");
	return 0;
}
