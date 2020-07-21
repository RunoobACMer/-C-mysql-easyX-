#include "book.h"

void GUI_admin_login(MYSQL *sock)
{
	
	while (1) {
		char sqlbuf[200] = "SELECT admin_pass FROM admin where admin_id = '";
		TCHAR Tid[70], Tpass[70];
		char id[70], pass[70],real_pass[70];
		if (InputBox(Tid, 70, L"���������Աid", NULL, L"", 0, 0, false) == false)
			return;

		if (InputBox(Tpass, 20, L"���������Ա����", NULL, L"", 0, 0, false) == false)
			return;

		strcpy_s(id, ConvertLPWSTRToLPSTR(Tid));
		strcpy_s(pass, ConvertLPWSTRToLPSTR(Tpass));

		if (check(id, '#')) {
			HWND hWnd = GetHWnd();
			MessageBox(hWnd, L"��������Ƿ��ַ��������ԣ�", L"������ʾ", 0);
			return;
		}

		getMD5(sock, pass);
		strcpy_s(pass, global_str);

		strcat_s(sqlbuf, id);
		strcat_s(sqlbuf, "'");

		cout << "sqlbuf = " << sqlbuf << endl;
		cout << "pass = " << pass << endl;

		if (mysql_query(sock, sqlbuf)) {
			printf("���ݻ�ȡʧ��!%s", mysql_error(sock));
			HWND hWnd = GetHWnd();
			MessageBox(hWnd, L"���ݻ�ȡʧ��", L"������ʾ", 0);
			return;
		}

		MYSQL_RES *result;
		MYSQL_ROW row;

		if (!(result = mysql_store_result(sock))) {
			printf("�����ȡʧ��!:%s", mysql_error(sock));
			HWND hWnd = GetHWnd();
			MessageBox(hWnd, L"�����ȡʧ��", L"������ʾ", 0);
			return;
		}

		if (!mysql_num_rows(result)) {
			HWND hWnd = GetHWnd();
			MessageBox(hWnd, L"����Աid�����ڣ�", L"������ʾ", 0);
			continue;
		}

		row = mysql_fetch_row(result);


		strcpy_s(real_pass, (char*)row[0]);

		mysql_free_result(result);

		if (!strcmp(real_pass, pass)) {
			HWND hWnd = GetHWnd();
			MessageBox(hWnd, L"�ɹ���¼����Ա�˺ţ�", L"������ʾ", 0);
			GUI_admin_operate(sock);
			return;
		}
		else {

			HWND hWnd = GetHWnd();
			MessageBox(hWnd, L"���������������ԣ�", L"������ʾ", 0);

			continue;
		}
	}
}
