#include "book.h"

void admin_operate(MYSQL *sock) {
	int flag = -1;
	while (1) {
		admin_op_menu();
		cin >> flag;
		if (flag == 0) {
			return;
		}
		//����û�
		else if (flag == 1) {
			add_user(sock);
		}
		//���ͼ��
		else if (flag == 2) {
			add_book(sock);
		}
		//ɾ���û�
		else if (flag == 3) {
			del_user(sock);
		}
		//ɾ��ͼ��
		else if (flag == 4) {
			del_book(sock);
		}
		//��ѯ����ͼ��
		else if (flag == 5) {
			show_books(sock);
		}
		//��ѯ����ͼ��
		else if (flag == 6) {
			show_users(sock);
		}
		else {
			input_wrong();
		}
		
	}
}