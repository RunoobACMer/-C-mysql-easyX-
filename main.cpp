#include "book.h"

char global_str[70];

int main() {
	MYSQL *sock, mysql;
	mysql_init(&mysql);
	//����mysql��¼��Ϣ
	const char *host = "127.0.0.1";
	const char *user = "root";
	const char *pass = "080035";
	const char *db = "hrbustbookmanagement";

	if (!(sock = mysql_real_connect(&mysql, host, user, pass, db, 3306, 0, 0))) {
		cout << "mysql connect failed!" << endl;
	}
	else {
		cout << "mysql connect success!" << endl;
	}

	mysql_query(&mysql, "set names gbk");//�������
	mysql_autocommit(sock, 0);

	//-------------------------------
	
	/*char id[70] = "Zhang";
	GUI_user_operate(sock,id);*/

	/*GUI_admin_operate(sock);*/
	GUI_menu(sock);

	//-------------------------------
	//int flag = 1;
	//while (1) {
	//	start_menu();
	//	cin >> flag;
	//	//����Ա��¼
	//	if (flag == 0)
	//		return 0;
	//	else if (flag == 1) {
	//		admin_login(sock);
	//	}
	//	//�û���¼
	//	else if (flag == 2) {
	//		reader_login(sock);
	//	}
	//	else {
	//		input_wrong();
	//	}
	//}
	return 0;
}