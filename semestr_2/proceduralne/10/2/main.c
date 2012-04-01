#include <stdio.h>
#include <stdlib.h>
struct tnode
{
	int value;
	struct tnode *next;
};
int dodaj_na_poczatek(struct tnode** head,int val);
void wypisz_liste(struct tnode* head);
void del_list(struct tnode **head);
int dodaj_na_koniec(struct tnode** head,int val);
int dodaj_do_posortowanej(struct tnode **head,int val);
struct tnode* znajdz(int val, struct tnode *head);
int usun(int val,struct tnode **head);

int main()
{
	struct tnode *head=0;
/*
	dodaj_na_poczatek(&head,23);
	dodaj_na_poczatek(&head,13);
	dodaj_na_poczatek(&head,67);
	dodaj_na_poczatek(&head,3);
	dodaj_na_poczatek(&head,123);
*/
/*
	dodaj_na_koniec(&head,23);
	dodaj_na_koniec(&head,13);
	dodaj_na_koniec(&head,67);
	dodaj_na_koniec(&head,3);
	dodaj_na_koniec(&head,123);
*/

	dodaj_do_posortowanej(&head,23);
	dodaj_do_posortowanej(&head,13);
	dodaj_do_posortowanej(&head,67);
	dodaj_do_posortowanej(&head,3);
	dodaj_do_posortowanej(&head,123);


	struct tnode *result=znajdz(8,head);

	if(result)
	{
		printf("znalazlem: element %d\n",result->value);
	}
	else
	{
		printf("Nie znalalzlem\n");
	};
	wypisz_liste(head);

	usun(123,&head);

	wypisz_liste(head);
	del_list(&head);
	wypisz_liste(head);
	return 0;
};
int dodaj_na_poczatek(struct tnode** head,int val)
{
	struct tnode *tmp=malloc(sizeof(struct tnode));
	if(!tmp)	return 0;
	tmp->value=val;
	tmp->next=NULL;
	if(*head)
	{
		tmp->next=*head;
	};
	*head=tmp;
	printf("dodalem na poczatek: %d\n",val);
	return 1;
};
void wypisz_liste(struct tnode* head)
{
	struct tnode *act=head;
	if(!act)
	{
		printf("lista jest pusta\n");
		return;
	}
	while(act)
	{
		printf("%d ",act->value);
		act=act->next;
	};
	printf("\n");
};
void del_list(struct tnode **head)
{
	if(*head)
	{
		printf("usuwam: %d\n",(*head)->value);
		struct tnode *tmp=(*head)->next;
		free(*head);
		del_list(&tmp);
	};
	*head=NULL;
};
int dodaj_na_koniec(struct tnode** head,int val)
{
//	printf("a");
	struct tnode *tmp=malloc(sizeof(struct tnode));
	if(!tmp)
	{
		return 0;
	};
	tmp->value=val;
//	printf("b");
	if(!*head)
	{
//		printf("b1");
		printf("dodaje do pustej listy: %d\n",val);
		*head=tmp;
		return 1;
	};
//	printf("c");

	struct tnode *act=*head;
	while(act->next) act=act->next;
	act->next=tmp;
	printf("dodaje na koniec: %d\n",val);

	return 1;

};
int dodaj_do_posortowanej(struct tnode **head,int val)
{
	struct tnode *act=*head;
	struct tnode *tmp=malloc(sizeof(struct tnode));
	if(!tmp) return 0;
	tmp->value=val;
	tmp->next=NULL;
	if(!(*head))
	{
		*head=tmp;
		return 1;
	};
	if(act->value>val)
	{
		tmp->next=(*head);
		*head=tmp;
		return 1;
	};
	while(act->next)
	{
		if(act->next->value>val)
		{
			tmp->next=act->next;
			act->next=tmp;
			return 1;
		};
		act=act->next;
	};
	act->next=tmp;
	return 1;


};
struct tnode* znajdz(int val, struct tnode *head)
{
	struct tnode *act=head;
	while(act)
	{
		if(act->value==val) return act;
		act=act->next;
	};
	return 0;
};
int usun(int val,struct tnode **head)
{
	struct tnode *result=znajdz(val,*head);
	if(!result) return 0;
	struct tnode *act=*head;
	if(result==*head)
	{
		struct tnode *tmp;
		tmp=act->next;
		free(*head);
		*head=tmp;
		return 1;
	};
	while(act->next!=result) act=act->next;
	struct tnode *tmp;
	tmp=result->next;
	free(result);
	act->next=tmp;
	return 1;
};
