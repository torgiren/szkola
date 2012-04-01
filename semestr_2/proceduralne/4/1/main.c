#include <stdio.h>
int main()
{
	char samo1[]={'a','i','u','e','o'};
	char samo2[5]={0};
	int samo3=0;
	int spol=0;
	int wyr=0;
	char tekst[] = "Kilka literek w dlugim zdaniu.";
	int x=0;
	while(tekst[x])
	{
		switch(tekst[x])
		{
			case 'a':
				samo2[0]++;
				samo3++;
				break;
			case 'i':
				samo2[1]++;
				samo3++;
				break;
			case 'u':
				samo2[2]++;
				samo3++;
				break;
			case 'e':
				samo2[3]++;
				samo3++;
				break;
			case 'o':
				samo2[4]++;
				samo3++;
				break;
			default:
				if((tekst[x]!=' ') && (tekst[x]!='.'))
				{
					spol++;
				}
				else
				{
					wyr++;
				};
		};
		x++;
	};
	int i;
	for(i=0; i<5 ;i++)
			printf("%c -> %d razy\n", samo1[i], samo2[i]);
	printf("Samogloski -> %d razy\n", samo3);
	printf("Spolgloski -> %d razy\n", spol);
	printf("Wyrazy -> %d",wyr);


	printf("\n");
	return 0;
};
