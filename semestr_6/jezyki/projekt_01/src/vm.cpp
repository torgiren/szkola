/**
 * Wirtualna maszyna
 */
#include <iostream>
#include <stdio.h>
#include <fstream>
int main(int argc, char* argv[])
{
	if(argc<2)
	{
		fprintf(stderr,"Za mało parametrów.\nUżycie: %s <program>\n",argv[0]);
	};
	return 0;
};

