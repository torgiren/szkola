#include <stdio.h>
int main(void){
	char a[]="123456789";
	printf("a->%s\n",a);
	int len=sizeof(a)-1;
	int x=0;
	while(x<len/2)
	{
		char tmp=a[x];
		a[x]=a[len-x-1];
		a[len-x-1]=tmp;
		x++;		
	}
	printf("a->%s\n",a);
	return 0;
}
