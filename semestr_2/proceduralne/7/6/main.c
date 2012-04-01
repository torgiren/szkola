#include <stdio.h>
#include <string.h>
int main()
{
	char odst[]=" \n";
	char *ele;
	char wiersz[]="abc abd\nz";
	printf("%s\n",wiersz);

	int x=0;


	printf("%s\n",strtok(&wiersz[4]," "));
	printf("%d\n",strlen(wiersz));
	for(ele=strtok(wiersz,odst);ele!=NULL;x+=1+strlen(ele),ele=strtok(NULL,odst))
	{
		printf("x to: %d\n", x);
		printf("Kolejny ele to %s\n",ele);
	};

	return 0;
};
