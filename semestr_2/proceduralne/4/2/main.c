#include <stdio.h>
int main()
{
	char napis[]="Kilka litereK w dlugim zdaniu.";
	int x=0;
	while(napis[x])
	{
		if(napis[x]>='a' && napis[x]<='z')
		{
			napis[x]-=32;
		}
		else if(napis[x]>='A' && napis[x]<='Z')
		{
			napis[x]+=32;
		};
		switch(napis[x])
		{
			case ' ':
				napis[x]='_';
				break;
			case '.':
				napis[x]='!';
				break;
		};
		x++;
	};
	printf("%s\n",napis);
	return 0;
};

