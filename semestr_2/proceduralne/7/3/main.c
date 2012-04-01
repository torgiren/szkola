#include <stdio.h>
void kopiuj(const char *srt,char *dst);
int main()
{
	char a[255],b[255];
	scanf("%s",a);
	kopiuj(a,b);
	printf("%s\n",b);
	return 0;
};
void kopiuj(const char *src, char *dst)
{
	while(*(dst++)=*(src++));
};
