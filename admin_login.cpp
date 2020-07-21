#include "book.h"

void admin_login(MYSQL *sock) {
	while (1) {
		char id[70], pass[70], real_pass[70];
		char sqlbuf[200] = "SELECT admin_pass FROM admin where admin_id = '";

		cout << "输入管理员id:" << endl;
		cin >> id;
		cout << "输入管理员密码:" << endl;
		cin >> pass;

		getMD5(sock, pass);
		strcpy_s(pass, global_str);

		strcat_s(sqlbuf, id);
		strcat_s(sqlbuf, "'");

		cout << "sqlbuf = " << sqlbuf << endl;
		cout << "pass = " << pass << endl;

		if (mysql_query(sock, sqlbuf)) {
			printf("数据获取失败!%s", mysql_error(sock));
			return;
		}

		MYSQL_RES *result;
		MYSQL_ROW row;

		if (!(result = mysql_store_result(sock))) {
			printf("结果获取失败!:%s", mysql_error(sock));
			return;
		}

		if (!mysql_num_rows(result)) {
			printf("该管理员id不存在\n");
			return;
		}

		row = mysql_fetch_row(result);


		strcpy_s(real_pass, (char*)row[0]);

		mysql_free_result(result);
		if (!strcmp(real_pass, pass)) {
			cout << "管理员成功登录！" << endl;
			admin_operate(sock);
			break;
		}
		else {
			cout << "密码错误，请重试！" << endl;
			continue;
		}

	}
}