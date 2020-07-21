#include "book.h"

void start_menu() {
	cout << endl;
	cout << "				+------------------------------------------+" << endl << endl;
	cout << "				|            ����ͼ�����ϵͳ            |" << endl << endl;
	cout << "				|              [1] ����Ա��¼              |" << endl << endl;
	cout << "				|              [2]  ʦ����¼               |" << endl << endl;
	cout << "				|              [0]  �˳�ϵͳ               |" << endl << endl;
	cout << "				+------------------------------------------+" << endl;
}

void admin_op_menu() {
	cout << endl;
	cout << "				+------------------------------------------+" << endl << endl;
	cout << "				|                 �����嵥                 |" << endl << endl;
	cout << "				|              [1]  ����û�               |" << endl << endl;
	cout << "				|              [2]  ���ͼ��               |" << endl << endl;
	cout << "				|              [3]  ɾ���û�               |" << endl << endl;
	cout << "				|              [4]  ɾ��ͼ��               |" << endl << endl;
	cout << "				|              [5]  ��ѯ����ͼ��           |" << endl << endl;
	cout << "				|              [6]  ��ѯ�����û�           |" << endl << endl;
	cout << "				|              [0]  �˳�ϵͳ               |" << endl << endl;
	cout << "				+------------------------------------------+" << endl;
}

void user_op_menu() {
	cout << endl;
	cout << "				+------------------------------------------+" << endl << endl;
	cout << "				|                 �����嵥                 |" << endl << endl;
	cout << "				|              [1]  ��ѯָ��ͼ����         |" << endl << endl;
	cout << "				|              [2]  ��ѯ����ͼ��           |" << endl << endl;
	cout << "				|              [3]  �޸�����               |" << endl << endl;
	cout << "				|              [0]  �˳�ϵͳ               |" << endl << endl;
	cout << "				+------------------------------------------+" << endl;
}

void input_wrong() {
	cout << "�Ƿ����룡" << endl;
}

//���˷Ƿ��ַ�
int check(char* str, char c) {
	while (*str != '\0') {
		if (*str == c) {
			return 1;
		}
		else {
			str++;
		}
	}
	return 0;
}

//��ȡMD5()����
void getMD5(MYSQL *sock, const char *str) {
	char sqlbuf[200] = "SELECT MD5('";
	MYSQL_RES *result;
	MYSQL_ROW ROW(NULL);
	strcat_s(sqlbuf, str);
	strcat_s(sqlbuf, "')");
	mysql_query(sock, sqlbuf);
	result = mysql_store_result(sock);
	ROW = mysql_fetch_row(result);		
	mysql_free_result(result);
	strcpy_s(global_str, (char*)ROW[0]);
}

//����û�
void add_user(MYSQL *sock) {
	char sqlbuf[200] = "INSERT INTO reader(reader_id,reader_name,reader_pass) VALUES(";
	char id[70], name[70], pass[70],buf[70]="MD5('";
	
	strcat_s(sqlbuf, "'");

	TCHAR Tid[70];
	if (InputBox(Tid, 20, L"�������û�id", NULL, L"", 0, 0, false) == false)
		return;
	strcpy_s(id, ConvertLPWSTRToLPSTR(Tid));

	strcat_s(sqlbuf, id);
	strcat_s(sqlbuf, "',");

	strcat_s(sqlbuf, "'");

	TCHAR Tname[70];
	if (InputBox(Tname, 20, L"�������û�����", NULL, L"", 0, 0, false) == false)
		return;
	strcpy_s(name, ConvertLPWSTRToLPSTR(Tname));

	strcat_s(sqlbuf, name);
	strcat_s(sqlbuf, "',");

	TCHAR Tpass[70];
	if (InputBox(Tpass, 20, L"�������û�����", NULL, L"", 0, 0, false) == false)
		return;
	strcpy_s(pass, ConvertLPWSTRToLPSTR(Tpass));

	strcat_s(buf, pass);
	strcat_s(buf, "'))");
	strcat_s(sqlbuf, buf);

	if (mysql_query(sock, sqlbuf)) {
		printf("���ݻ�ȡʧ��!%s", mysql_error(sock));
		return;
	}

	mysql_commit(sock);
	HWND hWnd = GetHWnd();
	MessageBox(hWnd, L"��ӳɹ���", L"������ʾ", 0);
}

//���ͼ��
void add_book(MYSQL *sock) {
	char sqlbuf[200] = "INSERT INTO books(books_id,books_name) VALUES(";
	char id[70], name[70];
	

	strcat_s(sqlbuf, "'");

	TCHAR Tid[70];
	if (InputBox(Tid, 20, L"�����������", NULL, L"", 0, 0, false) == false)
		return;
	strcpy_s(id, ConvertLPWSTRToLPSTR(Tid));

	strcat_s(sqlbuf, id);
	strcat_s(sqlbuf, "',");

	strcat_s(sqlbuf, "'");

	TCHAR Tname[70];
	if (InputBox(Tname, 20, L"����������", NULL, L"", 0, 0, false) == false)
		return;
	strcpy_s(name, ConvertLPWSTRToLPSTR(Tname));

	strcat_s(sqlbuf, name);
	strcat_s(sqlbuf, "')");


	if (mysql_query(sock, sqlbuf)) {
		printf("���ݻ�ȡʧ��!%s", mysql_error(sock));
		return;
	}

	mysql_commit(sock);
	HWND hWnd = GetHWnd();
	MessageBox(hWnd, L"��ӳɹ���", L"������ʾ", 0);
}

//ɾ��ͼ��
void del_book(MYSQL *sock) {
	char sqlbuf[200] = "DELETE FROM books WHERE books_id = '";
	char id[70];
	TCHAR Tid[70];
	if (InputBox(Tid, 10, L"�������ɾ��ͼ�������", NULL, L"", 0, 0, false) == false)
		return;
	strcpy_s(id, ConvertLPWSTRToLPSTR(Tid));
	strcat_s(sqlbuf, id);
	strcat_s(sqlbuf, "'");
	cout << sqlbuf << endl;
	if (mysql_query(sock, sqlbuf)) {
		printf("���ݻ�ȡʧ��!%s", mysql_error(sock));
		return;
	}
	mysql_commit(sock);
	HWND hWnd = GetHWnd();
	MessageBox(hWnd, L"ɾ���ɹ���", L"������ʾ", 0);
}

//ɾ���û�
void del_user(MYSQL *sock) {
	char sqlbuf[200] = "DELETE FROM reader WHERE reader_id = '";
	char id[70];
	TCHAR Tid[70];
	if (InputBox(Tid, 10, L"�������ɾ���û�id", NULL, L"", 0, 0, false) == false)
		return;
	strcpy_s(id, ConvertLPWSTRToLPSTR(Tid));

	strcat_s(sqlbuf, id);
	strcat_s(sqlbuf, "'");
	cout << sqlbuf << endl;

	/*TCHAR temp[70];

	#ifdef UNICODE
		MultiByteToWideChar(CP_ACP, 0, sqlbuf, -1, temp, 1024);
	#else
		strcpy(tszWord, szWord);
	#endif
	outtext(temp);
	getchar();*/

	if (mysql_query(sock, sqlbuf)) {
		printf("���ݻ�ȡʧ��!%s", mysql_error(sock));
		return;
	}
	mysql_commit(sock);
	HWND hWnd = GetHWnd();
	MessageBox(hWnd, L"ɾ���ɹ���", L"������ʾ", 0);
}

//��ѯ����ͼ��
void show_books(MYSQL *sock) {
	initgraph(800, 400);

	char sqlbuf[200] = "SELECT * FROM books";
	if (mysql_query(sock, sqlbuf)) {
		printf("���ݻ�ȡʧ��!%s", mysql_error(sock));
		return;
	}

	MYSQL_ROW row;
	MYSQL_RES *result;
	if (!(result = mysql_store_result(sock))){
		printf("�����ȡʧ��!:%s", mysql_error(sock));
		return;
	}

	unsigned int Col_num = (unsigned int)mysql_num_fields(result);
	unsigned int Row_num = (unsigned int)mysql_num_rows(result);
	
	outtextxy(300, 50 , L"�����");
	outtextxy(400, 50 , L"����");

	for (unsigned int i = 0; i < Row_num; i++) {
		row = mysql_fetch_row(result);			//�Զ���ȡ��һ��
		for (unsigned int j = 0; j < Col_num; j++) {
			//printf("|%-15s", (char*)row[j]);

			TCHAR temp[70];

			#ifdef UNICODE
				MultiByteToWideChar(CP_ACP, 0, row[j], -1, temp, 1024);
			#else
				strcpy(tszWord, szWord);
			#endif
			if(j==0)
				outtextxy(300,i*50+100,temp);
			else if(j==1)
				outtextxy(400,i*50+100, temp);

		}
		
	}
	getchar();
	//printf("+---------------+---------------+\n");
	//printf("|ͼ�������     |ͼ����         |\n");
	//printf("+---------------+---------------+\n");
	//for (unsigned int i = 0; i < Row_num; i++) {
	//	row = mysql_fetch_row(result);			//�Զ���ȡ��һ��
	//	for (unsigned int j = 0; j < Col_num; j++) {
	//		printf("|%-15s", (char*)row[j]);
	//	}
	//	printf("|\n");
	//}
	//printf("+---------------+---------------+\n");
	mysql_free_result(result);
}

//��ѯ�����û�
void show_users(MYSQL *sock) {
	initgraph(800, 400);
	char sqlbuf[200] = "SELECT * FROM reader";
	if (mysql_query(sock, sqlbuf)) {
		printf("���ݻ�ȡʧ��!%s", mysql_error(sock));
		return;
	}

	MYSQL_ROW row;
	MYSQL_RES *result;
	if (!(result = mysql_store_result(sock))) {
		printf("�����ȡʧ��!:%s", mysql_error(sock));
		return;
	}

	unsigned int Col_num = (unsigned int)mysql_num_fields(result);
	unsigned int Row_num = (unsigned int)mysql_num_rows(result);

	outtextxy(150, 50, L"�û�id");
	outtextxy(300, 50, L"�û�����");
	outtextxy(400, 50, L"�û�����(�Ѽ���)");

	for (unsigned int i = 0; i < Row_num; i++) {
		row = mysql_fetch_row(result);			//�Զ���ȡ��һ��
		for (unsigned int j = 0; j < Col_num; j++) {
			//printf("|%-15s", (char*)row[j]);

			TCHAR temp[70];

			#ifdef UNICODE
				MultiByteToWideChar(CP_ACP, 0, row[j], -1, temp, 1024);
			#else
				strcpy(tszWord, szWord);
			#endif
			if (j == 0)
				outtextxy(100, i * 50 + 100, temp);
			else if (j == 1)
				outtextxy(300, i * 50 + 100, temp);
			else if(j==2)
				outtextxy(400, i * 50 + 100, temp);

		}

	}
	getchar();

	//printf("+---------------+---------------+--------------------------------+\n");
	//printf("|�û�id         |�û�����       |�û�����(�Ѽ���)                |\n");
	//printf("+---------------+---------------+--------------------------------+\n");
	//for (unsigned int i = 0; i < Row_num; i++) {
	//	row = mysql_fetch_row(result);			//�Զ���ȡ��һ��
	//	for (unsigned int j = 0; j < Col_num; j++) {
	//		printf("|%-15s", (char*)row[j]);
	//	}
	//	printf("|\n");
	//}
	//printf("+---------------+---------------+--------------------------------+\n");
	mysql_free_result(result);
}

//�޸�����
void update_pass(MYSQL *sock,char id[]) {
	char pass[70];
	char sqlbuf[200] = "UPDATE reader SET reader_pass = '";
	TCHAR Tpass[70];
	if (InputBox(Tpass, 10, L"������������", NULL, L"", 0, 0, false) == false)
		return;
	strcpy_s(pass, ConvertLPWSTRToLPSTR(Tpass));

	getMD5(sock, pass);			
	strcpy_s(pass,global_str);

	strcat_s(sqlbuf, pass);
	strcat_s(sqlbuf, "' WHERE reader_id = '");
	strcat_s(sqlbuf,id);
	strcat_s(sqlbuf,"'");

	if (mysql_query(sock, sqlbuf)) {
		printf("���ݻ�ȡʧ��!%s", mysql_error(sock));
		return;
	}
	mysql_commit(sock);
	HWND hWnd = GetHWnd();
	MessageBox(hWnd, L"���³ɹ���", L"������ʾ", 0);
}

//��ѯָ��ͼ����
void select_book(MYSQL *sock) {
	char name[70];
	TCHAR Tname[70];
	if (InputBox(Tname, 10, L"�������ѯͼ����", NULL, L"", 0, 0, false) == false)
		return;
	strcpy_s(name, ConvertLPWSTRToLPSTR(Tname));

	char sqlbuf[200] = "SELECT * FROM books WHERE books_name = '";
	

	strcat_s(sqlbuf, name);
	strcat_s(sqlbuf, "'");

	//cout << sqlbuf << endl;

	if (mysql_query(sock, sqlbuf)) {
		printf("���ݻ�ȡʧ��!%s", mysql_error(sock));
		return;
	}

	MYSQL_RES *result;
	MYSQL_ROW row;

	if (!(result = mysql_store_result(sock))) {
		printf("�����ȡʧ��!:%s", mysql_error(sock));
		return;
	}

	if (!mysql_num_rows(result)) {
		HWND hWnd = GetHWnd();
		MessageBox(hWnd, L"ͼ�鲻�ڹ��ڣ�", L"������ʾ", 0);

		return;
	}
	else {
		row = mysql_fetch_row(result);
		char temp[70] = "�����Ϊ��";
		strcat_s(temp, row[0]);
		TCHAR Trow[70];

		#ifdef UNICODE
			MultiByteToWideChar(CP_ACP, 0, temp, -1, Trow, 1024);
		#else
			strcpy(tszWord, szWord);
		#endif

		HWND hWnd = GetHWnd();
		MessageBox(hWnd,Trow, L"������ʾ", 0);	
	}
}