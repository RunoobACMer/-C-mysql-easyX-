#include "book.h"

void admin_operate(MYSQL *sock) {
	int flag = -1;
	while (1) {
		admin_op_menu();
		cin >> flag;
		if (flag == 0) {
			return;
		}
		//添加用户
		else if (flag == 1) {
			add_user(sock);
		}
		//添加图书
		else if (flag == 2) {
			add_book(sock);
		}
		//删除用户
		else if (flag == 3) {
			del_user(sock);
		}
		//删除图书
		else if (flag == 4) {
			del_book(sock);
		}
		//查询所有图书
		else if (flag == 5) {
			show_books(sock);
		}
		//查询所有图书
		else if (flag == 6) {
			show_users(sock);
		}
		else {
			input_wrong();
		}
		
	}
}