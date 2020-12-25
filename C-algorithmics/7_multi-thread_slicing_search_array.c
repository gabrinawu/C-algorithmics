#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>

int isfind = 0;//0 found;1 cannot be found
int* pfind = NULL; //null cannot be found; or the address

struct infostruct {
	int* pstart;//starting address
	int length;//length
	int findnum;//the memory to look for
	int id;//thread number
};



void find(void* p) {
	struct infostruct* pinfo = (struct infostruct*)p;//attain argument address

	//retrieve specific memory
	printf("thread%d starts to look for the specific memory\n", pinfo->id);//show thread starts
	for (int* px = pinfo->pstart; px < pinfo->pstart + pinfo->length; px++)
	{
		if (isfind == 1)
		{
			printf("thread%d ends searching,other threads have been found\n", pinfo->id);
			_endthread();//exit
		}
		if (*px == pinfo->findnum) //judge whether equal
		{
			pfind = px;//return found address;
			isfind = 1;//set flag isfind to 'found'
			printf("thread%d ends search,found the specific memory %d,%p\n", pinfo->id, *px, px);//found
			_endthread();//exit the thread
		}
	}
	printf("thread%d ends search,cannot found the specific memory\n", pinfo->id);
}


//not the ideal case,the array length cannot be sliced equally
void main() {
	int data[1000] = { 0 };
	for (int i = 999; i >= 0; i--) {
		data[i] = i;
	}
	int threadnum;//thread amount
	scanf("%d",&threadnum);
	int tofindnum;//memory to find
	scanf("%d",&tofindnum);

	if (1000 % threadnum == 0) //sclice equally
	{
		//daynamically allocate array for multi-thread to send aurgument
		struct infostruct* pthread = malloc(sizeof(struct infostruct) * threadnum);
		for (int i = 0; i < threadnum; i++) {
			pthread[i].pstart = data + i * (1000 / threadnum);
			pthread[i].length = 1000/threadnum;
			pthread[i].id = i;
			pthread[i].findnum = tofindnum;//memory to search fo
			_beginthread(find,0,&pthread[i]);//send aurgument
		}
	}
	else 
	{
		struct infostruct* pthread = malloc(sizeof(struct infostruct)*threadnum);
		for (int i = 0; i < threadnum - 1; i++) {
			pthread[i].pstart = data + i * (1000 / (threadnum - 1));
			pthread[i].length = 1000 / (threadnum - 1);
			pthread[i].id = i;
			pthread[i].findnum = tofindnum;
		}
		{
			int i = threadnum - 1;
			pthread[i].pstart = data + 1000 / (threadnum - 1) * (threadnum - 1);
			pthread[i].length = 1000 - 1000 / (threadnum - 1) * (threadnum - 1);
			pthread[i].id = i;
			pthread[i].findnum = tofindnum;//memory to search

			_beginthread(find, 0, &pthread[i]);//send aurgument
		}
	
	}

	system("pause");
}

void main_ideal() {
	int data[1000] = { 0 };
	for (int i = 999; i >= 0; i--) {
		data[i] = i;
	}

	//int threadnum;

	struct infostruct myinfo[10];
	for (int i = 0; i < 10; i++) {
		myinfo[i].pstart = data + i * 100; //set address
		myinfo[i].length = 100;
		myinfo[i].id = i;
		myinfo[i].findnum = 767;
		_beginthread(find, 0, &myinfo[i]);//multiple-thread searching

	}

	system("pause");
}