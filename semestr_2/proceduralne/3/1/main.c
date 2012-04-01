#include <stdio.h>
int main()
{
	int x;
	for(x=0;x<100;x++)
	{
		char parzysta=1;
		if(x%2 || x==0)
		{
			continue;
		};
		if(parzysta)
		{
			printf("%d ",x);
		};
	};
	printf("\n");
	return 0;
};
