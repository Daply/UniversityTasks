#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "common_header.h"
int main1(int argc, char* argv[])
{
	printf ("Hello client app\n");
	if (argc>1)
	{
		printf ("Argc: %d\n",argc);
		printf ("%s\n",argv[0]);
		HANDLE hPut, hGet;
		char lpszPut[20];
		char lpszGet[20];  
		Sleep(100);
		wsprintf(lpszGet, "GET%d ",atoi(argv[1]));

		wsprintf(lpszPut, "PUT%d ",atoi(argv[1]));

		hPut = OpenEvent(EVENT_ALL_ACCESS, FALSE, lpszPut);

		if (!hPut) 
		{
			printf ("ERR: Can't open event PUT[%s]\n",lpszPut);
			Sleep (10000);


			return 100;
		}
		hGet = OpenEvent(EVENT_ALL_ACCESS,FALSE,lpszGet);
		if (!hPut)
		{
			printf ("ERR: Can't open event GET[%s]\n",lpszGet);
			Sleep (10000);
			return 100;
		}

		HANDLE hWrite = (HANDLE) atoi(argv[3]);
		HANDLE hRead = (HANDLE) atoi(argv[2]);

		printf ("hRead: %d\n",(int)hRead);
		printf ("hWrite: %d\n",(int) hWrite);

		while (true)
		{
			DWORD dwBytesRead;
			char key [10];
			Order record;
			printf ("Read or modify [r/m]?:");
			char choise;
			scanf ("%c",&choise);
			if (choise=='r' || choise == 'R')
			{
				printf ("Enter key: ");
				scanf("%10s",&key);
				if (!WriteFile(hWrite,&READ,sizeof(READ),&dwBytesWritten,NULL))
				{
					_cputs("Write to file failed.\n");
					_cputs("Press any key to finish.\n");
					_getch();
					return GetLastError();
				}
				SetEvent(hGet);
				printf ("[]Sending READ [%d] request to server\n",READ);
				WaitForSingleObject(hPut,INFINITE);
				if (!WriteFile(hWrite,&key,sizeof(key),&dwBytesWritten,NULL))
				{
					_cputs("Write to file failed.\n");
					_cputs("Press any key to finish.\n");
					_getch();
					return GetLastError();
				}
				SetEvent(hGet);
				printf ("[]Sending key [%s] to server\n",key);	
				WaitForSingleObject(hPut,INFINITE);
				int response;								
				if (!ReadFile(hRead,&response,	sizeof(response),&dwBytesRead,	NULL))
				{
					_cputs("Read from the pipe failed.\n");
					_cputs("Press any key to finish.\n");
					_getch();
					return GetLastError();
				}
				printf ("[]Got %d response code\n",response);			
				SetEvent(hGet);
				if (response == NOT_FOUND)
				{
					printf ("[] Record NOT FOUND\n");
				}
				else
				{	
					Order order;	
					WaitForSingleObject(hPut,INFINITE);
					if (!ReadFile(hRead,&order,sizeof(order),&dwBytesRead,	NULL))
					{
						_cputs("Read from the pipe failed.\n");
						_cputs("Press any key to finish.\n");
						_getch();
						return GetLastError();
					}
					printf ("Record :\n\t\tName: %s\n\t\tAmount: \%d\n\t\tPrice: %3.3lf\n",order.name,order.amount,order.price);
				}				 
				continue;
			}
			if (choise=='m' || choise == 'M')
			{
				printf ("Enter key: ");
				scanf("%10s",&key);
				DWORD dwBytesWritten;
				if (!WriteFile(hWrite,&MODIFY,sizeof(MODIFY),&dwBytesWritten,NULL))
				{
					_cputs("Write to file failed.\n");
					_cputs("Press any key to finish.\n");
					_getch();
					return GetLastError();
				}
				SetEvent(hGet);
				printf ("[]Sending MODIFY [%d] request to server\n",MODIFY);
				WaitForSingleObject(hPut,INFINITE);
				if (!WriteFile(hWrite,&key,sizeof(key),&dwBytesWritten,NULL))
				{
					_cputs("Write to file failed.\n");
					_cputs("Press any key to finish.\n");
					_getch();
					return GetLastError();
				}
				SetEvent(hGet);
				printf ("[]Sending key [%s] to server\n",key);				
				WaitForSingleObject(hPut,INFINITE);
				int response;				
				DWORD dwBytesRead;
				if (!ReadFile(hRead,&response,sizeof(response),&dwBytesRead,NULL))
				{
					_cputs("Read from the pipe failed.\n");
					_cputs("Press any key to finish.\n");
					_getch();
					return GetLastError();
				}
				printf ("[]Got %d response code\n",response);
				SetEvent(hGet);
				if (response == NOT_FOUND)
				{
					printf ("[] Record NOT FOUND\n");					
				}
				else
				{		
					WaitForSingleObject(hPut,INFINITE);
					if (!ReadFile(hRead,&record,sizeof(record),&dwBytesRead,NULL))
					{
						_cputs("Read from the pipe failed.\n");
						_cputs("Press any key to finish.\n");
						_getch();
						return GetLastError();
					}
					SetEvent(hGet);
					printf ("Record :\n\t\tName: %s\n\t\tAmount: \%d\n\t\tPrice: %3.3lf\n",record.name,record.amount,record.price);
					printf ("\n Enter new values:\n");
					Order  order; 	
					printf ("\t\tName: %s\n",record.name);
					strncpy(order.name, record.name,10);
					printf ("\t\tAmount: ");
					scanf ("%d",&order.amount);
					printf ("\t\tPrice: ");
					scanf ("%lf",&order.price);

					if (!WriteFile(hWrite,&order,sizeof(order),&dwBytesWritten,NULL))
					{
						_cputs("Write to file failed.\n");
						_cputs("Press any key to finish.\n");
						_getch();
						return GetLastError();
					}
					SetEvent(hGet);
					printf ("[]Sending updated record to server\n");					
				}				
				continue;
			}
			 

		}
	}
	_cputs("Press any key to finish.\n");
	_getch();
	return 0;
}