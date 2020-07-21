#pragma once
#ifndef _book
#define _book

#include<iostream>
#include<cstdio>
#include<cstring>
#include<mysql.h>
#include <graphics.h>
#include <conio.h>
#include<windows.h>

using namespace std;

extern char global_str[70];

void start_menu();
void input_wrong();
void getMD5(MYSQL *sock, const char *str);
void admin_login(MYSQL *sock);
void reader_login(MYSQL *sock);
void admin_operate(MYSQL *sock);
void user_operate(MYSQL *sock,char id[]);
void admin_op_menu();
void user_op_menu();
void add_user(MYSQL *sock);
void add_book(MYSQL *sock);
void del_book(MYSQL *sock);
void del_user(MYSQL *sock);
void show_books(MYSQL *sock);
void show_users(MYSQL *sock);
void update_pass(MYSQL *sock,char id[]);
void select_book(MYSQL *sock);
void GUI_menu(MYSQL *sock);
void GUI_admin_login(MYSQL *sock);
char* ConvertLPWSTRToLPSTR(LPWSTR lpwszStrIn);
void GUI_reader_login(MYSQL *sock);
void GUI_admin_operate(MYSQL *sock);
void GUI_user_operate(MYSQL *sock,char id[]);
int check(char* str, char c);

#endif 