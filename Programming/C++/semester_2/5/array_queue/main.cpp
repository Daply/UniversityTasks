#include "ArrayQueue.h"
int main()
{
	ArrayQueue AQ(5);
	AQ.push(1);
	AQ.print(cout);
	AQ.push(2);
	AQ.push(3);
	AQ.push(4);
	AQ.push(5);
	AQ.print(cout);
	cout << AQ.pop() << endl;
	AQ.print(cout);
	ArrayQueue AQ1(AQ);
	AQ1.print(cout);
	ArrayDeque AD(4);
	AD.push_head(1);
	AD.push_head(2);
	AD.push_tail(3);
	AD.push_tail(4);
	AD.print(cout);
	AD.pop_tail();
	AD.pop_head();
	AD.print(cout);
	ArrayQueueIterator AQI(AQ);
	while (AQI.in_range())
	{
		cout << *AQI << " ";
		++AQI;
	}
	return 0;
}