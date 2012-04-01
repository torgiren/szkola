#include <stdio.h>
int main(void){
	char tekst[] = "Dlugiwyrazonieznanejdlugosci";
	int dl;
	for(dl=0; tekst[dl];dl++);
	printf("D#ugosc #a#cucha: %s - > %d \n",tekst, dl);
	printf("%d\n",sizeof(tekst)-1);
	return 0;
}
