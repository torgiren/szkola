#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <time.h>
using namespace std;
void *pr(void *ptr);
int main()
{
	pthread_t t1,t2;
	int ret1,ret2;
	ret2=pthread_create(&t2,NULL,pr,(void*)"2: ");
	ret1=pthread_create(&t1,NULL,pr,(void*)"1: ");
//	pthread_join(t1,NULL);
//	pthread_join(t2,NULL);
	getchar();
	return 0;
};
void *pr(void *ptr)
{
	int x=0;
	for(x=0;x<100;x+=1)
	{
		cout<<(char*)ptr<<"\t"<<x<<endl;
		usleep(rand()%1000);
	};
};
