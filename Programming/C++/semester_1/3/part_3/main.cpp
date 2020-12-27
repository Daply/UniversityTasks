#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int n = 50;
	char * sentence = new char[n];
	char * result = new char[n];
	cout << "Input sentence \n";
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
	
	int words_count = 0;
	int word_first_index = -1;
	bool digits = true;
	for (int i = 0; i < n; i++) 
	{
	    char curr = sentence[i];
	    if (curr == 0) 
	    {
	       if (word_first_index != -1 && digits) 
	       {
	           words[words_count][0] = word_first_index;
	           words[words_count][1] = i - 1;
	           words_count++;
	           word_first_index = -1;
	       }
	       continue;    
	    }
	    if (curr == 32) 
	    {
	        if (i > 0 && word_first_index != -1 && digits) 
	        {
	            words[words_count][0] = word_first_index;
	            words[words_count][1] = i - 1;
	            words_count++;
	        }
	        word_first_index = -1;
	        digits = true;
	    }
	    else 
	    {
	        if (word_first_index == -1 && curr >= 48 && curr <= 57 && digits) 
	        {
	            word_first_index = i;
	        }
	        else if (curr < 48 || curr > 57)
	        {
	            word_first_index = -1;
	            digits = false;
	        }
	    }
	    if (words_count == 2) 
	    {
	        // it is needed only two words 
	        // consisting of digits
	        break;
	    }
	}
	
	int index = 0;
	for (int i = 0; i < n; i++) 
	{
	    if (i >= words[0][0] && i <= words[0][1])
	    {
	        for (int j = words[1][0]; j <= words[1][1]; j++) 
	        {
	            result[index] = sentence[j];
	            index++;
	        }
	        i += (words[0][1] - words[0][0]);
	    }
	    else if (i >= words[1][0] && i <= words[1][1]) 
	    {
	        for (int j = words[0][0]; j <= words[0][1]; j++) 
	        {
	            result[index] = sentence[j];
	            index++;
	        }
	        i += (words[1][1] - words[1][0]);
	    }
	    else
	    {
	        result[index] = sentence[i];
	        index++;
	    }
	}
	
	cout << endl;

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
