/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <Windows.h>

void runmsg(void* p) {
	int* pint = p;
	char str[30] = {0};
	sprintf(str,"window%d",*pint);
	MessageBoxA(NULL,str,str,NULL);
}

void main() {
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	for (int i = 0; i < 10; i++) {
		//HANDLE是void*类型的数据
		//_beginthread返回值是线程的句柄，可以操作某个线程
	  HANDLE hd = _beginthread(runmsg, 0, &i);
	  WaitForSingleObject(hd,INFINITY);//等待同步 //_beginthread是创立异步（并行）线程和WaitForSingleObject组合实现把异步操作为同步，程序既有异步又有同步
	}
	getchar();
}

*/
