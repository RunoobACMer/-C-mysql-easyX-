#include "book.h"

void GUI_reader_login(MYSQL *sock) 
{ 
	while (1) 
	{
		char id[70], pass[70], real_pass[70];
		TCHAR Tid[70], Tpass[70];
		char sqlbuf[200] = "SELECT reader_pass FROM reader where reader_id = '";

		
		if (InputBox(Tid, 20, L"请输入用户id", NULL, L"", 0, 0, false) == false)
			return;

		if (InputBox(Tpass, 20, L"请输入用户密码", NULL, L"", 0, 0, false) == false)
			return;

		strcpy_s(id, ConvertLPWSTRToLPSTR(Tid));
		strcpy_s(pass, ConvertLPWSTRToLPSTR(Tpass));

		if (check(id, '#')) {
			HWND hWnd = GetHWnd();
			MessageBox(hWnd, L"您在输入非法字符！请重试！", L"运行提示", 0);
			return;
		}

		getMD5(sock, pass);
		strcpy_s(pass, global_str);

		strcat_s(sqlbuf, id);
		strcat_s(sqlbuf, "'");

		cout << "sqlbuf = " << sqlbuf << endl;
		cout << "pass = " << pass << endl;

		if (mysql_query(sock, sqlbuf)) 	{
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
			HWND hWnd = GetHWnd();
			MessageBox(hWnd, L"用户id不存在！", L"运行提示", 0);
			continue;
		}

		row = mysql_fetch_row(result);


		strcpy_s(real_pass, (char*)row[0]);

		mysql_free_result(result);

		if (!strcmp(real_pass, pass)) {
			HWND hWnd = GetHWnd();
			MessageBox(hWnd, L"成功登录用户账号！", L"运行提示", 0);
			GUI_user_operate(sock,id);
			break;
		}
		else {

			HWND hWnd = GetHWnd();
			MessageBox(hWnd, L"密码错误，任意键重试！", L"运行提示", 0);

			continue;
		}

	}
}