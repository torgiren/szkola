#include <stdio.h>
#include <stdlib.h>
struct tnode
{
	int value;
	struct tnode *next;
};
int dodaj_na_poczatek(struct tnode** head,int val);
void wypisz_liste(const struct tnode* head);
int main()
{
	struct tnode *head=0;
	dodaj_na_poczatek(&head,23);
	dodaj_na_poczatek(&head,13);
	dodaj_na_poczatek(&head,67);
	dodaj_na_poczatek(&head,3);
	dodaj_na_poczatek(&head,123);

	
	wypisz_liste(head);

	return 0;
};
int dodaj_na_poczatek(struct tnode** head,int val)
{
	struct tnode *tmp=malloc(sizeof(struct tnode));
	if(!tmp)	return 0;
	tmp->value=val;
	if(*head)
	{
		tmp->next=*head;
	};
	*head=tmp;
	return 1;
};
void wypisz_liste(const struct tnode* head)
{
	struct tnode *act=head;
	while(act)
	{
		printf("%d\n",act->value);
		act=act->next;
	};
};
