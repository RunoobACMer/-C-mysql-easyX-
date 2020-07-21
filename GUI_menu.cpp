#include<graphics.h>
#include<conio.h>
#include<cstdio>
#include<iostream>
#include "book.h"
using namespace std;

char* ConvertLPWSTRToLPSTR(LPWSTR lpwszStrIn)
{
	LPSTR pszOut = NULL;
	if (lpwszStrIn != NULL)
	{
		int nInputStrLen = wcslen(lpwszStrIn);

		// Double NULL Termination
		int nOutputStrLen = WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, NULL, 0, 0, 0) + 2;
		pszOut = new char[nOutputStrLen];
		if (pszOut != NULL)
		{
			memset(pszOut, 0x00, nOutputStrLen);
			WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, pszOut, nOutputStrLen, 0, 0);
		}
	}
	return pszOut;
}

void GUI_menu(MYSQL *sock)
{
start:;
		initgraph(700, 400);

		IMAGE img;
		loadimage(&img, L".\\5.jpg", 700, 400);
		//先把图片放在工程项目下，使用L+"绝对路径"
		putimage(0, 0, &img);

		setbkcolor(CYAN);
		settextcolor(BLUE);
		settextstyle(22, 0, _T("黑体"));


		setfillcolor(CYAN);

		fillroundrect(200, 50, 500, 100, 10, 10);
		outtextxy(260, 65, _T("   管理员登录"));
		fillroundrect(200, 150, 500, 200, 10, 10);
		outtextxy(270, 165, _T("   师生登录"));
		fillroundrect(200, 250, 500, 300, 10, 10);
		outtextxy(270, 265, _T("   退出系统"));


		MOUSEMSG k;
		while (true)
		{
			k = GetMouseMsg();

			if (k.x >= 200 && k.y >= 50 && k.x <= 500 && k.y <= 100)
			{
				if (k.uMsg == WM_LBUTTONDOWN)
				{
					GUI_admin_login(sock);
					goto start;
				}
			}

			if (k.x >= 200 && k.y >= 150 && k.x <= 500 && k.y <= 200)
			{
				if (k.uMsg == WM_LBUTTONDOWN)
				{
					GUI_reader_login(sock);
					goto start;
				}
			}

			if (k.x >= 200 && k.y >= 250 && k.x <= 500 && k.y <= 300)
			{
				if (k.uMsg == WM_LBUTTONDOWN)
				{
					closegraph();
					return;
				}
			}

		}
	
	closegraph();
}