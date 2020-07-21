#include "book.h"

void GUI_admin_operate(MYSQL *sock) {
start:;
	initgraph(800, 450);

	IMAGE img;
	loadimage(&img, L".\\5.jpg", 800, 450);//先把图片放在工程项目下，使用L+"绝对路径"
	putimage(0, 0, &img);

	setbkcolor(CYAN);
	settextcolor(BLUE);
	settextstyle(22, 0, _T("黑体"));


	setfillcolor(CYAN);

	fillroundrect(100, 50, 300, 100, 10, 10);
	fillroundrect(100, 150, 300, 200, 10, 10);
	fillroundrect(100, 250, 300, 300, 10, 10);
	fillroundrect(500, 50, 700, 100, 10, 10);
	fillroundrect(500, 150, 700, 200, 10, 10);
	fillroundrect(500, 250, 700, 300, 10, 10);
	fillroundrect(300, 350, 500, 400, 10, 10);

	outtextxy(125, 65, _T("   添加用户"));
	outtextxy(125, 165, _T("   删除用户"));
	outtextxy(105, 265, _T("   查询所有用户"));
	outtextxy(525, 65, _T("   添加图书"));
	outtextxy(525, 165, _T("   删除图书"));
	outtextxy(505, 265, _T("   查询所有图书"));
	outtextxy(325, 365, _T("     退出"));
	
	MOUSEMSG k;
	while (true)
	{
		k = GetMouseMsg();

		if (k.x >= 100 && k.y >= 50 && k.x <= 300 && k.y <= 100)
		{
			if (k.uMsg == WM_LBUTTONDOWN) {
				add_user(sock);
				goto start;
			}
		}
		if (k.x >= 100 && k.y >= 150 && k.x <= 300 && k.y <= 200)
		{
			if (k.uMsg == WM_LBUTTONDOWN){
				del_user(sock);
				goto start;
			}
		}
		if (k.x >= 100 && k.y >= 250 && k.x <= 300 && k.y <= 300)
		{
			if (k.uMsg == WM_LBUTTONDOWN){
				show_users(sock);
			goto start;
			}
		}
		if (k.x >= 500 && k.y >= 50 && k.x <= 700 && k.y <= 100)
		{
			if (k.uMsg == WM_LBUTTONDOWN){
				add_book(sock);
				goto start;
			}
		}
		if (k.x >= 500 && k.y >= 150 && k.x <= 700 && k.y <= 200)
		{
			if (k.uMsg == WM_LBUTTONDOWN){
				del_book(sock);
				goto start;
			}
		}
		if (k.x >= 500 && k.y >= 250 && k.x <= 700 && k.y <= 300)
		{
			if (k.uMsg == WM_LBUTTONDOWN){
				show_books(sock);
				goto start;
			}
		}
		if (k.x >= 300 && k.y >= 350 && k.x <= 500 && k.y <= 400)
		{
			if (k.uMsg == WM_LBUTTONDOWN) {
				return;
			}
		}
	}
	//这里没有closegraph
}