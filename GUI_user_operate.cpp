#include "book.h"

void GUI_user_operate(MYSQL *sock,char id[]) {
start:;
	initgraph(800, 250);

	IMAGE img;
	loadimage(&img, L".\\5.jpg", 800, 250);//�Ȱ�ͼƬ���ڹ�����Ŀ�£�ʹ��L+"����·��"
	putimage(0, 0, &img);

	setbkcolor(CYAN);
	settextcolor(BLUE);
	settextstyle(22, 0, _T("����"));


	setfillcolor(CYAN);

	fillroundrect(100, 50, 300, 100, 10, 10);
	fillroundrect(100, 150, 300, 200, 10, 10);
	fillroundrect(500, 50, 700, 100, 10, 10);
	fillroundrect(500, 150, 700, 200, 10, 10);


	outtextxy(125, 65, _T("��ѯָ��ͼ��"));
	outtextxy(125, 165, _T("��ѯ����ͼ��"));
	outtextxy(525, 65, _T("   �޸�����"));
	outtextxy(525, 165, _T("   �˳�ϵͳ"));


	MOUSEMSG k;
	while (true)
	{
		k = GetMouseMsg();

		//��ѯָ��ͼ��
		if (k.x >= 100 && k.y >= 50 && k.x <= 300 && k.y <= 100)
		{
			if (k.uMsg == WM_LBUTTONDOWN) {
				select_book(sock);
				goto start;
			}
		}

		//��ѯ����ͼ��
		if (k.x >= 100 && k.y >= 150 && k.x <= 300 && k.y <= 200)
		{
			if (k.uMsg == WM_LBUTTONDOWN){
				show_books(sock);
				goto start;
			}
		}
		
		//�޸�����
		if (k.x >= 500 && k.y >= 50 && k.x <= 700 && k.y <= 100)
		{
			if (k.uMsg == WM_LBUTTONDOWN){
				update_pass(sock,id);
				goto start;
			}
		}

		//�˳�ϵͳ
		if (k.x >= 500 && k.y >= 150 && k.x <= 700 && k.y <= 200)
		{
			if (k.uMsg == WM_LBUTTONDOWN)
				return ;
		}
		
	}
	//����û��closegraph
}