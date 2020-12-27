#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool is_mersenne(int number) 
{
    int num = number + 1;
    int power = 0; 
    for (int i = 0;;i++) 
    {
        power = (int)pow(2,i);
        if (power > num) 
        {
           break;
        }
        else if(power == num)
        {
           return true;
        }
    }  
    
    return false;
};

int main()
{
    int n = 0;
    int m = 0;
	cout<<"Input n\n ";
	cin>>n;
	cout<<"Input m\n ";
	cin>>m;
	int ** matrix = new int*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];
	for (int i = 0; i < n; i++) 
	{
	    for (int j = 0; j < m; j++) 
	    {
	        cin>>matrix[i][j];
	    }
	}
	
	int* mersennes_quantity = new int[m];
	int max_quantity_col = 0;
	int max_quantity = 0;
	int quantity = 0; 
	for (int j = 0; j < m; j++) 
	{
	    quantity = 0;
	    for (int i = 0; i < n; i++) 
	    {
	        int number = matrix[i][j];
	        if (is_mersenne(number)) 
	        {
	            quantity++;
	        }
	    }
	    if (quantity > max_quantity)
	    {
	        max_quantity = quantity;
	        max_quantity_col = j;
	    }
	}
    cout<<max_quantity_col;
    
    for (int i = 0; i < n; i++)
        delete [] matrix[i];
    delete[] mersennes_quantity;
	system("pause");
}