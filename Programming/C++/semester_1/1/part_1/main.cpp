#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int a, b;
	cout<<"Input a\n ";
	cin>>a;
	cout<<"Input b\n";
	cin>>b;
	
	int num_ = 0;
	int digits_sum = 0;
	int num_length = 0;
	int middle_num = 0;
	int middle_digit = 0;
	for (int num = a; num <= b; num++) 
	{
	    num_ = num;
	    digits_sum = 0;
	    num_length = 0;
	    middle_digit = 0;
	    while (num_ != 0) 
		{
	        digits_sum += num_%10;
	        num_ = num_/10;
	        num_length++;
	    }
	    if (num_length%2 != 0) 
		{
	        middle_num = num/((int)pow(10, num_length/2));
    	    middle_digit = middle_num%10;
    	    if (digits_sum == (middle_digit * middle_digit)) 
			{
    	        cout<<num;
    	    }
	    }
	}
	system("pause");
}