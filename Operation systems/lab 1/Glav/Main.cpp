#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <windows.h>
using namespace std;

struct order
{
	char name[10]; // product name
	int amount; // product quantity
	double price; // product price
};

int main()
{
	char binFile[20];
	cout << "Enter the name of file(binary)\n";
	cin >> binFile;
	
////////////////////////////////////////////////////////////////////////////////////////
	STARTUPINFO siC;
	PROCESS_INFORMATION piC;

	ZeroMemory(&siC, sizeof(STARTUPINFO));
	siC.cb = sizeof(STARTUPINFO);
	char lpszCommandLineCreator[100] = ""; //= L"C:\\Users\\TEMP.CIT.002\\Documents\\Visual Studio 2008\\Projects\\Creator\\Debug\\Creator.exe ";

	//strcat(lpszCommandLineCreator,binFile);

	sprintf(lpszCommandLineCreator,"%s%s","Creator.exe ",binFile);


	// создаем новый консольный процесс
	CreateProcess(NULL,lpszCommandLineCreator, NULL, NULL, FALSE,            
			CREATE_NEW_CONSOLE, NULL, NULL, &siC, &piC);
			//cout<< "Error\n";
	// закрываем дескрипторы этого процесса
	WaitForSingleObject(piC.hProcess, INFINITE);
	CloseHandle(piC.hThread);
	CloseHandle(piC.hProcess);

	ifstream binF(binFile, ios::binary | ios::in);
	int number = countStringsInFile(binF);
	order* or = new order[number];
	int j = 0;
	cout << "Information from file(binary)\n";
	while(!binF.eof())
	{
		binF >> or[j].name >> or[j].amount >> or[j].price;
		cout << or[j].name <<"  "<< or[j].amount <<"  "<< or[j].price<<endl;
        j++;
	}
	binF.close();
////////////////////////////////////////////////////////////////////////////////////////
	char reportFile[80] = "";
	cout << "Enter the name of file reporter\n";
	cin >> reportFile;
	int minimalAmount;
	cout << "Enter the minimal amount\n";
	cin >> minimalAmount;
	double minimalPrice;
	cout << "Enter the minimal price\n";
	cin >> minimalPrice;

    char lpszCommandLineReporter[80] = "";

	sprintf(lpszCommandLineReporter,"%s%d%s%.5f%s%s%s%s","Reporter.exe ",minimalAmount," ", minimalPrice," ",binFile," ",reportFile);
	STARTUPINFO siP;
	PROCESS_INFORMATION piP;

	ZeroMemory(&siP, sizeof(STARTUPINFO));
	siP.cb = sizeof(STARTUPINFO);

	// creating new console process
	if(!CreateProcessA(NULL, lpszCommandLineReporter, NULL, NULL, FALSE,
			CREATE_NEW_CONSOLE, NULL, NULL, &siP, &piP))
			cout<< "Error\n";

	// closing process descriptors
	WaitForSingleObject(piP.hProcess, INFINITE);
	CloseHandle(piP.hThread);
	CloseHandle(piP.hProcess);

	
	ifstream file(reportFile);
	string text;
	while (getline(file,text)){
		cout << " " << text << endl;
	}
	file.close();
	system("pause");
}


int countStringsInFile(ifstream file)
{
	int i = 0;
	char *str = new char[1024];
	while(!file.eof())
	{
		file.getline(str,1024,'\n');
		i++;
	}
	return i;
}