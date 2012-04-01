#include <stdio.h>
void odwroc(char *a);
int main()
{
	char napis[255];
	scanf("%s",napis);
	odwroc(napis);
	printf("%s\n",napis);
	return 0;
};
void odwroc(char *a)
{
	char *ost;
	for(ost=a;*ost;ost++);
	ost--;
	printf("ost->%c\n",*ost );
	while(a<ost)
	{
		char tmp=*a;
		*a++=*ost;
		*ost--=tmp;
	};
	
};
