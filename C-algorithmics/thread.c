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
		_beginthread(runmsg, 0, &a[i]);
	}
	getchar();
}

*/