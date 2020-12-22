/*
#include <stdio.h>
#include <windows.h>
#include <process.h>


//    void*p is a empty type of pointer and can store any type of address   
void runmsg(void* p) {
	MessageBoxA(NULL, "hello china", "hello world", NULL);

}


//multiple threads
void mainB() {
	
// _beginthread open one new thread 
	for (int i = 0; i < 5; i++) 
	{
		_beginthread(runmsg,0,NULL);
	}
	getchar();

}

//sing-thread:

void mainA() {

	MessageBoxA(NULL, "hello china", "hello world", NULL);
	MessageBoxA(NULL, "hello china", "hello world", NULL);
	MessageBoxA(NULL, "hello china", "hello world", NULL);
	MessageBoxA(NULL, "hello china", "hello world", NULL);
	printf("learn c concurrency\n");
	getchar();
	return;
}

*/