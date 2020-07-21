#include "book.h"

void GUI_user_operate(MYSQL *sock,char id[]) {
start:;
	initgraph(800, 250);

	IMAGE img;
	loadimage(&img, L".\\5.jpg", 800, 250);//先把图片放在工程项目下，使用L+"绝对路径"
	putimage(0, 0, &img);

	setbkcolor(CYAN);
	settextcolor(BLUE);
	settextstyle(22, 0, _T("黑体"));


	setfillcolor(CYAN);

	fillroundrect(100, 50, 300, 100, 10, 10);
	fillroundrect(100, 150, 300, 200, 10, 10);
	fillroundrect(500, 50, 700, 100, 10, 10);
	fillroundrect(500, 150, 700, 200, 10, 10);


	outtextxy(125, 65, _T("查询指定图书"));
	outtextxy(125, 165, _T("查询所有图书"));
	outtextxy(525, 65, _T("   修改密码"));
	outtextxy(525, 165, _T("   退出系统"));


	MOUSEMSG k;
	while (true)
	{
		k = GetMouseMsg();

		//查询指定图书
		if (k.x >= 100 && k.y >= 50 && k.x <= 300 && k.y <= 100)
		{
			if (k.uMsg == WM_LBUTTONDOWN) {
				select_book(sock);
				goto start;
			}
		}

		//查询所有图书
		if (k.x >= 100 && k.y >= 150 && k.x <= 300 && k.y <= 200)
		{
			if (k.uMsg == WM_LBUTTONDOWN){
				show_books(sock);
				goto start;
			}
		}
		
		//修改密码
		if (k.x >= 500 && k.y >= 50 && k.x <= 700 && k.y <= 100)
		{
			if (k.uMsg == WM_LBUTTONDOWN){
				update_pass(sock,id);
				goto start;
			}
		}

		//退出系统
		if (k.x >= 500 && k.y >= 150 && k.x <= 700 && k.y <= 200)
		{
			if (k.uMsg == WM_LBUTTONDOWN)
				return ;
		}
		
	}
	//这里没有closegraph
}