#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int n = 50;
	char * sentence = new char[n];
	char * result = new char[n];
	cout<<"Input sentence \n";
	cin.getline(sentence, n);
	
	// creating matrix with words indexes:
	// each matrix line will contain 
	// first word index in a sentence
	// and last index
	int ** words = new int*[n];
	for (int i = 0; i < n; i++) 
	{
	    words[i] = new int[2];
	}

	int word_index = 0;
	int words_count = 0;
	for (int i = 0; i < n; i++) 
	{
	    if (sentence[i] == 32) 
	    {
	        if (i > 0) 
	        {
	            words[words_count][1] = i - 1;
	        }
	        word_index = 0;
	        words_count++;
	    }
	    else 
	    {
	        if (word_index == 0) 
			{
	            words[words_count][0] = i;
	        }
	        word_index++;
	    }
	}
	words[words_count][1] = n;
	words_count++;
	int index = 0;
	if (words_count % 2 == 0) 
	{
	    int middle = words_count / 2 - 1;
	    for (int i = 0; i < words_count; i++) 
	    {
	        if (i != middle && i != middle + 1)
	        {
	            for (int j = words[i][0]; j <= words[i][1]; j++) 
	            {
	                result[index] = sentence[j];
	                index++;
	            }
	            result[index] = ' ';
	            index++;
	        }
	    }
	}
	else
	{
	    int middle = words_count / 2;
	    for (int i = 0; i < words_count; i++) 
	    {
	        if (i != middle)
	        {
	            for (int j = words[i][0]; j <= words[i][1]; j++) 
	            {
	                result[index] = sentence[j];
	                index++;
	            }
	            result[index] = ' ';
	            index++;
	        }
	    }
	}

	for (int i = 0; i < n; i++) 
	{
 	     cout << result[i];
	}

    delete [] sentence;
    for (int i = 0; i < n; i++) 
	{
	    delete [] words[i];
	}
	system("pause");
}
