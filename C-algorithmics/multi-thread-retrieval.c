#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h>

int isfind = 0;//0 found;1 cannot be found
int* pfind = NULL; //null cannot be found; or the address

struct inforstruct {
	int* pstart;//starting address
	int length;//length
	int findnum;//the data to look for
	int id;//thread number

};



void find(void* p) {
	struct infostruct *pinfo = (struct infostruct *)p;//attain argument address

	//retrieve specific memory
	printf("thread%d starts to look for the specific memory:",pinfo->id);//show thread starts
	for (int* px = pinfo->pstart; px < pinfo->pstart + pinfo->length; px++)
	{
		if (isfind==1)
		{
			printf("thread%d ends searching,other threads have been found",pinfo->id);
			_endthread();//exit
		}
		if (*px == pinfo->findnum) //judge whether equal
		{
			pfind = px;//return found address;
			isfind = 1;//set flag isfind to 'found'
			printf("thread%d ends search,found the specific memory %d,%p", pinfo->id,*px,px);//found
			_endthread();//exit the thread
		}
	}
	printf("thread%d ends search,cannot found the specific memory",pinfo->id);
}

void main() {
	int data[1000] = { 0 };
	for (int i = 999; i >= 0; i--) {
		data[i] = i;
	}


	system("pause");
}