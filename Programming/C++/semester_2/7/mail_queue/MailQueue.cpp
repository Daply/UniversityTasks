# include <iostream>
# include <list>
# include <string>
# include <fstream>
# include <algorithm>
#include <sstream>
using namespace std;
struct network
{
	string termcode;
	string mailcode;
	string priority;
	string info;
};
class Mail_queue
{
	list <network> v;
public:
	void read_from_file(char* filename)
	{
		network s;
		ifstream f(filename);
		while (!f.eof())
		{
			f >> s.termcode;
			f >> s.mailcode;
			f >> s.priority;
			f >> s.info;
			v.push_back(s);
		}
		f.close();
	}
	void add(ostream& out, istream& in)  
	{
		network s;
		out << "Input data\n";
		in >> s.termcode;
		in >> s.mailcode;
		in >> s.priority;
		in >> s.info;
		v.push_back(s);
	}
	void print(ostream& out)  
	{
				list <network>::iterator it;
		for (it = v.begin();it != v.end();it++) 
			out << (*it).termcode << "\t" << (*it).mailcode << "\t" << (*it).priority  << "\t" << (*it).info << endl;
	}

		void chose_1(ostream & out)
	{
		list<network>::iterator it = v.begin();
		list<network>::iterator iterm;
		string temp_priority = (*it).priority;

		for (it = v.begin();it != v.end();it++)
		{
			if((*it).priority > temp_priority)
			{
				temp_priority = (*it).priority;
     			iterm = it;
			}
		}
		out <<"code terminal: "<< (*iterm).termcode <<"\n"<<"code message: "<< (*iterm).mailcode << "\n"<<"priority: "<<(*iterm).priority <<"\n"<<"info part: "<< (*iterm).info << "\n";
		v.erase(iterm);
	}

        void chose_2(ostream & out)
		{
        list<network>::iterator it1 = v.begin();
		list<network>::iterator iter = v.begin();
		string temp_info;
        int len = (*it1).info.length();

		for (it1 = v.begin();it1 != v.end();it1++)
		{
			if((*it1).info.length() > len)
			{
				len = (*it1).info.length();
     			iter = it1;
			}
		}
        out <<"code terminal: "<< (*iter).termcode <<"\n"<<"code message: "<< (*iter).mailcode << "\n"<<"priority: "<<(*iter).priority <<"\n"<<"info part: "<< (*iter).info << "\n";
		v.erase(iter);
		}

};
