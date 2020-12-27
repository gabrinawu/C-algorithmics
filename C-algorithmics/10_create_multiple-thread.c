#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <time.h>
#include <windows.h>


CRITICAL_SECTION cs;//临界区 进入临界区的线程独享变量

int num = 0; //多线程发生冲突

DWORD WINAPI myfun(void* p)//DWORD类型是unsigned long代表编号；WINAPI表明线程可以被操作系统调用
{
	for (int i = 0; i < 100; i++)
	{
		EnterCriticalSection(&cs);//进入临界区
		num++;
		LeaveCriticalSection(&cs);//退出临界区
//		Sleep(10);//10ms
		return 0;
	}
}

void main()
{
	time_t start, end;
	time(&start);

	HANDLE hd[100];               //HANDLE类型是void* //线程数组，每个元素都是一个线程
	for (int i = 0; i < 100; i++) {
//		hd[i] = _beginthread(myfun, 0, NULL); //_beginthread的返回值是一个指针 //_beginthread只能互锁，但是会发生访问同一个变量时的冲突
		hd[i] = CreateThread(NULL,0,myfun,NULL,0,NULL);//第一个参数_In_opt_ LPSECURITY_ATTRIBUTE lpThreadAttributes表示附加信息，第二个参数 _In_ SIZE_T dwStackSize,
		//第三个参数_In_ LPTHREAD_START_ROUTINE lpStartAddress表示从哪个位置开始, _In_opt_ __drv_aliasesMem LPVOID lpParameter可以设置为NULL
		//_In_ DWORD dwCreationFlags可以设置为0, _Out_opt_ LPDWORD lpThreadId可以设置为NULL
		
		//WaitForSingleObject(hd[i],INFINITE);//等待一个线程结束   没有这个语句，会多线程冲突，结果不为10000，而且经常变化,时间不需要10*100*100/1000秒
	}
	WaitForMultipleObjects(100, hd, TRUE, INFINITE);//等待所有线程退出 TRUE等待全部 INFINITE一直等待下去

	time(&end);
	printf("\n%f", difftime(end, start));

	printf("\n%d", num);
	DeleteCriticalSection(&cs);//临界区是调用操作系统，让线程进入临界区，锁定变量
	system("pause");
}
