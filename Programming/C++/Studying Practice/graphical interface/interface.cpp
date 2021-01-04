#include<vector>
#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;
#include <windows.h>
#include<Windowsx.h>
int NUMLINES=0;
struct music
{
	char name[20];
	char autor[20];
	char singer[20];
	char number[20];
	char date[20];
	char operation[20];
	int came;
	int sold;
	char price[20];
	int kol;
};
static int count=0;
char line[] ="-----------------------------------------------------------------------------------------";
vector <music> y;
music Y;

void input()
{
	ifstream in_music("input_music.txt");
	while(!in_music.eof())
	{
		in_music>>Y.number>>Y.date>>Y.operation>>Y.came>>Y.sold>>Y.price>>Y.name>>Y.autor>>Y.singer;
		y.push_back(Y);
	}
  in_music.close();
}
char buf_boat[10];
char buf_area[10];
void select(int k)
{
	NUMLINES=0;
	ofstream buf;
	buf.open("buf.txt", ios::out);
	switch(k)
	{
	case 1:  //	the specified CD provides information on the total number and total cost of compacts sold during the specified period;
				{
		buf<<line<<endl;
		buf<<"|  "<<setw(54)<<"CD :"<<setw(20)<<buf_boat<<" | "<<endl;
		buf<<line<<endl;
		buf<<"|  "<<setw(42)<<"CD quantity: "<<" | "<<setw(29)<<"Total cost of compacts"<<" | "<<setw(22)<<endl;
		buf<<line<<endl;
		NUMLINES+=5;
		int buf_kol = 0;
		for(int i=0; i < y.size();i++)
		{
			if(strcmp(y[i].number, buf_boat)==0)
			{
				NUMLINES++;
				buf<<"|  "<<setw(42)<<y[i].came<<" | "<<setw(29)<<y[i].price<<" | "<<endl;
			}
		}
		buf<<line<<endl;
		NUMLINES+=3;
		break;
		}
	case 2: //for all compacts, information about the number of sold and remaining compacts of the same type is formed and displayed
        {
			vector <char*> c;
			char *C;
			for(int j=0; j<y.size();j++)
			{
				C = new char[20];
				strcpy(C, y[j].number);
				c.push_back(C);
			}
			int z=0;
			for(int j=0; j<c.size()-1;j++)
			{
				for(int i=j+1; i<c.size();i++)
				{
					if(strcmp(c[j], c[i])==0)
					{
						c.erase(c.begin()+i);
						z++;
						i--;
					}
				}
			}
			for(int j=0; j<c.size();j++)
			{
				buf<<line<<endl;
				buf<<"|  "<<setw(57)<<"CD Information No. "<<" | "<<setw(14)<<c[j]<<"  |"<<endl;
				buf<<line<<endl;
				buf<<"|  "<<setw(37)<<"Number sold "<<" | "<<setw(34)<<"Number of remaining "<<"  |"<<endl;
				buf<<line<<endl;
				NUMLINES+=5;
				int buf_kol=0;
				for(int i=0; i < y.size();i++)
				{
					if(strcmp(c[j],y[i].number)==0)
					{
						buf<<"|  "<<setw(37)<<y[i].sold<<" | "<<setw(34)<<y[i].came-y[i].sold<<"  |"<<endl;
						buf_kol++;
						NUMLINES++;
					}
				}
				buf<<line<<endl;
				NUMLINES+=3;
			}
			break;
		}
	case 3:  //for a CD purchased the maximum number of times, all information about it and about the musical compositions contained on it is displayed;
		{
			char *max_sold = new char[20];
			int i = 0;
			int max=0;
			while(i<y.size())
			{
				int buf_sold = 0;
				for(int j=0; j<y.size();j++)
				{
					if(strcmp(y[j].number, y[i].number)==0)
					{
						buf_sold += y[j].sold;
					}
				}
				if(buf_sold > max)
				{
					max = buf_sold;
					strcpy(max_sold, y[i].number);
				}
				i++;
			}
			buf<<line<<endl;
			buf<<"|  "<<setw(35)<<"CD with the most popular artists"<<"    | "<<setw(18)<<max_sold<<"   |"<<endl;
			buf<<"|  "<<setw(52)<<"Number sold "<<" |    "<<setw(14)<<max<<"    |"<<endl;
			buf<<line<<endl;
			NUMLINES+=5;
			break;
		}
	case 4:  //for the most popular performer, information on the number of sold compacts with the works performed by him is displayed;
		{
			char *max_sold = new char[20];
			int i = 0;
			int max=0;
			while(i<y.size())
			{
				int buf_sold = 0;
				for(int j=0; j < y.size();j++)
				{
					if(strcmp(y[j].number, y[i].number)==0)
					{
						buf_sold += y[j].sold;
					}
				}
				if(buf_sold > max)
				{
					max = buf_sold;
					strcpy(max_sold, y[i].number);
				}
				i++;
			}
			buf<<line<<endl;
			buf<<"|  "<<setw(30)<<"CD purchased the maximum number of times "<<"   | "<<setw(19)<<max_sold<<" |  "<<endl;
			buf<<line<<endl;
			buf<<"|"<<setw(20)<<"Title of the work"<<"|"<<setw(12)<<"Author"<<"  | "<<setw(12)<<"Singer"<<" |"<<setw(10)<<" Quantity"<<"|"<<setw(6)<<" Sold"<<"|"<<setw(6)<<"Price"<<"|  "<<endl;

            
			NUMLINES+=5;
			for(i=0; i<y.size();i++)
			{
				if(strcmp(y[i].number,max_sold)==0)
				{
					NUMLINES++;
                    buf<<"|"<<setw(20)<<y[i].name<<" | "<<setw(12)<<y[i].autor<<" | "<<setw(12)<<y[i].singer<<" | "<<setw(8)<<y[i].came<<"  |"<<setw(6)<<y[i].sold<<"  |"<<setw(6)<<y[i].price<<"| "<<endl;
			        buf<<line<<endl;
				}
			}
			buf<<line<<endl;
			NUMLINES+=3;
			break;
		}
	case 5:   //for each author, information is determined about the number of sold compacts with his records and the amount of money received.
		{
			vector <char*> c;
			char *C;
			for(int j=0; j<y.size();j++)
			{
				C = new char[20];
				strcpy(C, y[j].autor);
				c.push_back(C);
			}
			int z=0;
			for(int j=0; j<c.size()-1;j++)
			{
				for(int i=j+1; i<c.size();i++)
				{
					if(strcmp(c[j], c[i])==0)
					{
						c.erase(c.begin()+i);
						z++;
						i--;
					}
				}
			}
			for(int j=0; j<c.size();j++)
			{
				buf<<line<<endl;
				buf<<"|  "<<setw(57)<<" Author "<<" | "<<setw(14)<<c[j]<<"  |"<<endl;
				buf<<line<<endl;
				buf<<"|  "<<setw(37)<<"Sold quantity"<<" | "<<setw(34)<<"Revenue (amount of money)"<<"  |"<<endl;
				buf<<line<<endl;
				NUMLINES+=5;
				int buf_kol=0;
				for(int i=0; i < y.size();i++)
				{
					if(strcmp(c[j],y[i].autor)==0)
					{
						buf<<"|  "<<setw(37)<<y[i].sold<<" | "<<setw(34)<<y[i].price<<"  |"<<endl;
						buf_kol++;
						NUMLINES++;
					}
				}
				buf<<line<<endl;
				NUMLINES+=3;
			}
			break;
		}
	}
	buf.close();
}
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);// window procedure
char szWinName[] = "MyWin";				// window class name

int WINAPI WinMain (
				HINSTANCE hThisInst,	// handle to the program instance
				HINSTANCE hPrevInst,	// handle to previous instance
				LPSTR lpszArgs,		// command line arguments
				int nWinMode		// window opening model
		   ) 
{
	HWND hwnd;		// window handle
	MSG msg;		// message structure
	WNDCLASSEX wcl;		// window structure
		
		/* Let's define the window class. */ 
	wcl.cbSize = sizeof(WNDCLASSEX);	// size of the WNDCLASSEX structure
	wcl.hInstance = hThisInst;		// handle to the program instance
	wcl.lpszClassName = szWinName;		// window class name
	wcl.lpfnWndProc = WindowProc;		// window procedure
	wcl.style =0;					// window style - default
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION); 	// large pictogram 
	wcl.hIconSm = NULL;			// small version of the large pictogram
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW); 	// cursor style
	wcl.lpszMenuName = NULL;		// menu name - missing
	wcl.cbClsExtra = 0;			// no additional class memory required
	wcl.cbWndExtra = 0;			// no additional window memory required
	wcl.hbrBackground=CreateHatchBrush(HS_DIAGCROSS, RGB(225,225,225));// window background color - white
		
	if(!RegisterClassEx(&wcl)) return 0;
		
	hwnd = CreateWindow
	(
		szWinName, 			// window class name 
		"Info", 		// window title 
		WS_CAPTION | WS_SYSMENU | WS_VSCROLL,		// window style - standard  
		100, 			// X coordinate - default
		25, 			// Y coordinate - default
		750, 			// window width - default
		650, 			// window height - default
		NULL,				// parent window handle - no window
		NULL,				// menu descriptor - no menu
		hThisInst,			// handle to the program instance 
		NULL				// no additional arguments
	);
			
	ShowWindow(hwnd, nWinMode);
	UpdateWindow(hwnd);
		
	while(GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	return msg.wParam; 
}
LRESULT CALLBACK WindowProc(HWND hwnd, UINT mes, WPARAM wParam, LPARAM lParam) 
{		
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	static int cxChar, cxCaps, cyChar, cyClient, iVscrollPos;
	TEXTMETRIC tm;
	HFONT hFont;
	static HWND hwndEdit1;
	static HWND hwndEdit2;
	y.clear();
	input();
	switch(mes) 
	{	
	case WM_CREATE :
	{
		FILE *pFile = fopen("buf.txt", "w");
		fclose (pFile);
		hdc = GetDC(hwnd);
		GetTextMetrics(hdc, &tm);
		CreateWindow("static", "\tTo display information:\n\n-on the specified CD. Enter the disc name:\t\t           and press the button\n\n-by all compacts. The number of sold and remaining. Click the button \n\n-by most popular performer. Click the button\n\n-for each author. Click the button\n\n-information about the number of sold and the remaining compacts of the same type. Click the button", WS_CHILD | WS_VISIBLE, 0, 0, 750, 195, hwnd, (HMENU)0, NULL, NULL);
		hwndEdit1 = CreateWindowEx(WS_EX_CLIENTEDGE, "edit", "", WS_CHILD | WS_VISIBLE, 400, 30, 80, 20, hwnd, (HMENU)1001, NULL, NULL);
		//hwndEdit2 = CreateWindowEx(WS_EX_CLIENTEDGE, "edit", "", WS_CHILD | WS_VISIBLE, 420, 60, 73, 20, hwnd, (HMENU)1002, NULL, NULL);
		CreateWindow("Button", "OK", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 620, 30, 40, 20, hwnd, (HMENU)10001, NULL, NULL);
		CreateWindow("Button", "OK", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 550, 60, 40, 20, hwnd, (HMENU)10002, NULL, NULL);
		CreateWindow("Button", "OK", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 400, 93, 40, 20, hwnd, (HMENU)10003, NULL, NULL);
		CreateWindow("Button", "OK", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 265, 125, 40, 20, hwnd, (HMENU)10004, NULL, NULL);
		CreateWindow("Button", "OK", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 630, 157, 40, 20, hwnd, (HMENU)10005, NULL, NULL);
		cxChar = tm.tmAveCharWidth;
		cxCaps =(tm.tmPitchAndFamily & 1 ? 3 : 2) * cxChar / 2;
		cyChar = tm.tmHeight + tm.tmExternalLeading;
		ReleaseDC(hwnd, hdc);
		SetScrollRange(hwnd, SB_VERT, 0, NUMLINES, FALSE);
		SetScrollPos(hwnd, SB_VERT, iVscrollPos, TRUE);
	}
	return 0;
	case WM_COMMAND:
		{
			if(LOWORD(wParam) == 10001)
			{
				Edit_GetLine(hwndEdit1, 0, buf_boat, 10);
				select(1);
				Edit_SetText(hwndEdit1, NULL);
			}
			if(LOWORD(wParam) == 10002)
			{
				Edit_GetLine(hwndEdit2, 0, buf_area, 10);
				select(2);
				Edit_SetText(hwndEdit2, NULL);
			}
			if(LOWORD(wParam) == 10003)
			{
				select(3);
			}
			if(LOWORD(wParam) == 10004)
			{
				select(4);
			}
			if(LOWORD(wParam) == 10005)
			{
				select(5);
			}
			SetScrollRange(hwnd, SB_VERT, 0, NUMLINES, FALSE);
			iVscrollPos=0;
			SetScrollPos(hwnd, SB_VERT, iVscrollPos, TRUE);
			hdc=GetDC(hwnd);
			GetClientRect(hwnd,&rect);
			InvalidateRect(hwnd, &rect, TRUE);
			ReleaseDC(hwnd,hdc);
		}
	return 0;
	case WM_VSCROLL :
		switch(LOWORD(wParam))
		{
		case SB_LINEUP :
			iVscrollPos -= 1;
		break;
		case SB_LINEDOWN :
			iVscrollPos += 1;
		break;
		case SB_PAGEUP :
			iVscrollPos -= cyClient / cyChar;
		break;
		case SB_PAGEDOWN :
			iVscrollPos += cyClient / cyChar;
		break;
		case SB_THUMBPOSITION :
			iVscrollPos = HIWORD(wParam);
		break;
		default :
		break;
		}
		iVscrollPos = max(0, min(iVscrollPos, NUMLINES));
		if (iVscrollPos != GetScrollPos(hwnd, SB_VERT))
		{
			SetScrollPos(hwnd, SB_VERT, iVscrollPos, TRUE);
			InvalidateRect(hwnd, NULL, TRUE);
		}
	return 0;
	case WM_PAINT:
		{
		hdc=BeginPaint(hwnd,&ps);
		GetClientRect(hwnd,&rect);
		hFont = CreateFont(15,0,0,0,FW_DONTCARE,FALSE,TRUE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY, VARIABLE_PITCH,TEXT("Lucida Console"));
        SelectObject(hdc, hFont);
		int i = 12;
		char str[100];
		ifstream buf;
		buf.open("buf.txt");
		while(!buf.eof())
		{
			int z = cyChar *(1 - iVscrollPos + i);
			i++;
			buf.getline(str, 100);
			TextOut(hdc, 0, z, str, strlen(str));
		}
		buf.close();
		EndPaint(hwnd,&ps); 
		return 0;
	}
	case WM_DESTROY: 
		{
		remove("buf.txt");
		PostQuitMessage(0);
		return 0;
		}
	default:
		return DefWindowProc(hwnd, mes, wParam, lParam) ; 
	}
	return 0; 
}