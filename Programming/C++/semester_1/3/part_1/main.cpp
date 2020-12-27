#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool is_palindrome(char* word, int size) 
{
	for (int i = 0; i < size/2; i++) {
	    if (word[i] != word[size - i - 1])
	       return false;
	}
	return true;
};

int main()
{
    int n = 50;
	char * sentence = new char[n];
	cout<<"Input sentence \n";
	cin.getline(sentence, n);
	
	char * word = new char[n];
	int word_index = 0;
	for (int i = 0; i < n; i++) 
	{
	    char curr = sentence[i];
	    if ((curr >= 65 && curr <= 90) ||
	         (curr >= 97 && curr <= 122)) 
	    {
	        word[word_index] = curr;
	        word_index++;
	    }
	    else 
	    {
	        if (is_palindrome(word, word_index)) 
	        {
	            cout<<word<<endl;
	        }
	        word_index = 0;
	        word = new char[n];
	    }
	}

    if (is_palindrome(word, word_index)) 
	{
	    cout<<word<<endl;
	}

    delete [] sentence;
    delete [] word;
	system("pause");
}