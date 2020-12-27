#include "Student.h"
void main()
{
	Student A1("Petrov", 3.0, 5.0);
	A1.output(cout);
	A1.getGrade();
	A1.changeNum(cin);
	A1.output(cout);
	Student A2(A1);
	if (equal_grade(A1, A2))
	{
		cout << "Yes\n";
	}
	else
	{
		cout << "No\n";
	}
	system("pause");
}