#include "book.h"

void user_operate(MYSQL *sock,char id[]) {
	int flag = -1;
	while (1) {
		user_op_menu();
		cin >> flag;
		if (flag == 0) {
			return;
		}
		else if (flag == 1) {
			select_book(sock);
		}
		else if (flag == 2) {
			show_books(sock);
		}
		else if (flag == 3) {
			update_pass(sock, id);
		}
		else {
			input_wrong();
		}

	}
}