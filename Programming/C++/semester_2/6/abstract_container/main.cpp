#include "classes.h"

void test1(AbstractStack & AS)
{
	if (!AS.is_empty())
	{
		cout << "Pop element: " << AS.pop() << endl;
	}
}
void test2(AbstractQueue &AQ)
{
	if (!AQ.is_empty())
	{
		cout << "Pop element: " << AQ.del() << endl;
	}
}
int main()
{
	try
	{
		ArrayStack AS(5);
		cout << "Enter elements: \n";
		for (int i = 0; i<5; i++)
		{
			int n;
			cin >> n;
			AS.push(n);
		}
		cout << endl;
		cout << "ArrayStack" << endl;
		ArrayStackIterator ASI(AS);
		while (ASI.in_range())
		{
			cout << *ASI << " ";
			++ASI;
		}
		cout << endl;
		test1(AS);


		ListStack LS;
		cout << "Enter elements: \n";
		for (int i = 0; i < 5; i++)
		{
			int n;
			cin >> n;
			LS.push(n);
		}
		cout << endl;
		cout << "ListStack" << endl;
		ListStackIterator LSI(LS);
		while (LSI.in_range())
		{
			cout << *LSI << " ";
			++LSI;
		}
		cout << endl;
		test1(LS);


		ArrayQueue AQ;
		cout << "Enter elements: \n";
		for (int i = 0; i < 5; i++)
		{
			int n;
			cin >> n;
			AQ.ins(n);
		}
		cout << endl;
		cout << "ArrayQueue" << endl;
		AQ.print(cout);
		cout << endl;
		test2(AQ);



		ListQueue LQ;
		cout << "Enter elements: \n";
		for (int i = 0; i < 5; i++)
		{
			int n;
			cin >> n;
			LQ.ins(n);
		}
		cout << endl;
		cout << "ListQueue" << endl;
		LQ.print(cout);
		cout << endl;


		ArrayDeque AD(10);
		cout << "Enter elements: \n";
		for (int i = 0; i < 5; i++)
		{
			int n;
			cin >> n;
			if (i % 2 == 0)
				AD.ins_tail(n);
			else
				AD.ins_head(n);
		}
		cout << endl;
		cout << "ArrayDeque" << endl;
		AD.print(cout);
		cout << endl;


		ListDeque LD;
		cout << "Enter elements: \n";
		for (int i = 0; i < 5; i++)
		{
			int n;
			cin >> n;
			LD.ins_tail(n);
		}
		cout << endl;
		cout << "ListDeque" << endl;
		LD.print(cout);
		cout << endl;


		AbstractStack* AbstrS [2];
		AbstrS[0] = &AS; 
		AbstrS[1] = &LS;


		AbstractQueue* AbstrQ[3];
		AbstrQ[0] = &AQ; 
		AbstrQ[1] = &LQ;
		AbstrQ[2] = &AD;

		cout << endl << endl << "Arrays" << endl << endl;
		for (int i = 0; i < 2; i++)
		{
			if (!AbstrS[i]->is_empty())
				cout << "Pop element from AbstractStack: " << AbstrS[i]->pop() << endl;
			if (!AbstrS[i]->is_full())
				AbstrS[i]->push(i);
		}
		cout << endl << endl;
		for (int i = 0; i < 3; i++)
		{
			if (!AbstrQ[i]->is_empty())
			{
				cout << "Pop element from AbstractQueue: " << AbstrQ[i]->del() << endl;
			}
		}
		cout << endl << endl;

		cout << "ArrayStack:" << endl << endl;
		ASI.reset_begin();
		while (ASI.in_range())
		{
			cout << *ASI << " ";
			++ASI;
		}
		cout << endl << endl;
		cout << "ListStack:" << endl << endl;
		LSI.reset_begin();
		while (LSI.in_range())
		{
			cout << *LSI << " ";
			++LSI;
		}
	}
	catch (char *str)
	{
		cout << str << endl;
	}
}