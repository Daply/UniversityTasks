#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool is_prime(int number) 
{
    for (int i = 2; i <= number/2; i++) 
	{
        if (number%i == 0) 
		{
            return false;
        }
    }
    return true;
};

int main()
{
	int x;
	cout<<"Input x\n ";
	cin>>x;
	
	bool found = false;
	int y = 0;
	for (int y = 1; y < 1000; y++) 
	{
	    for (int p1 = 1; p1 < 1000; p1++) 
		{
	        for (int p2 = 1; p2 < 1000; p2++) 
			{
	            if (x*x - y*y == p1*p2 &&
	                   is_prime(p1) && is_prime(p2)) 
				{
	               cout<<y<<endl;
	               found = true;
	               break;
	            }
	            if (found) 
	                break;
	        }
	        if (found) 
	            break;
	    }
	}

	system("pause");
}