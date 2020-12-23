/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <process.h>


//单线程（此时只有主线程）
int mainA() {
	//system("title china world");
	
	int i = 0;
	while (1) {
		
		char str[40] = { 0 };
		sprintf(str,"title 当前时间第%d秒",i);
		system(str);

		i++;
		Sleep(1000);
		
	}
	system("pause");
}


//多线程
int i = 0;

void settime(void* p)
{
	while (1) {

		char str[40] = { 0 };
		sprintf(str, "title 当前时间第%d秒", i);
		system(str);

		i++;
		Sleep(1000);

	}
}



//实现时间和主程序分离，时间一直在更新，system("pause")一直在等待
void mainB()
{
	
	_beginthread(settime,0,NULL);

	system("pause");
}



void open_program(void *p) {
	while (1) {
		if (i == 3)
		{
			system("calc");
		}
		else if (i == 10)
		{
			system("notepad");
			_endthread(); // 线程结束
		}
		else if (i == 19)
		{
			system("tasklist & pause");
		}
		Sleep(1000);
	}
}


//让两个线程通过i来通信而且互不干涉
void main()
{

	_beginthread(settime, 0, NULL);
	_beginthread(open_program, 0, NULL);


	system("pause");
}

*/