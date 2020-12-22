/*
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void main() {
	while (1) {
		//system("calc");//分类：同步，形式：每秒弹出一个，一个一个弹出,要等待上一个结束
		system("start calc");//分类：异步，形式：并行，每秒同时弹出多个，不需要等待上一个结束
		Sleep(1000); //1000是1秒
	}
}
*/