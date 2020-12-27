#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool is_automorph(int number) 
{
	int square = number*number;
	while (number > 0)
	{
		if (number%10 != square%10)
		{    
            return false;
        }
		number = number/10;
		square = square/10;
	}
	
	return true;
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
	
	cout<<"Automorph: 0 " <<is_automorph(0)<<endl;
	cout<<"Automorph: 5 " <<is_automorph(5)<<endl;
	cout<<"Automorph: 6 " <<is_automorph(6)<<endl;
	cout<<"Automorph: 25 " <<is_automorph(25)<<endl;
	cout<<"Automorph: 76 " <<is_automorph(76)<<endl;
	cout<<"Automorph: 1 " <<is_automorph(1)<<endl;
	cout<<"Automorph: 2 " <<is_automorph(2)<<endl;
	cout<<"Automorph: 3 " <<is_automorph(3)<<endl;
	cout<<"Automorph: 4 " <<is_automorph(4)<<endl;
	
	int quantity = 0; 
	int count_columns = 0;
    for (int j = 0; j < m; j++) 
	{
	    quantity = 0; 
	    for (int i = 0; i < n; i++) 
	    {
	        int number = matrix[i][j];
	        if (is_automorph(number)) 
	        {
	            quantity++;
	        }
	    }
	    cout<<quantity<<endl;
	    if (quantity == m) 
	    {
	        for (int k = 0; k < n; k++) 
	        {
	            int tmp = matrix[k][j];
	            matrix[k][j] = matrix[k][count_columns];
	            matrix[k][count_columns] = tmp;
	        }
	        count_columns++;
	    }
	}
	
	for (int i = 0; i < n; i++) 
	{
	    for (int j = 0; j < m; j++) 
	    {
	        cout<<matrix[i][j]<<' ';
	    }
	    cout<<endl;
	}
    
    for (int i = 0; i < n; i++)
        delete [] matrix[i];
	system("pause");
}