#include <stdio.h>
#include <stdlib.h>
struct node
{
	int key;
	struct node *next,*prev;
};
void print(struct node *start,int dir);
void dodaj(int key,struct node **head,struct node **tail);
void del(struct node *head);
int main()
{
	struct node *head=NULL,*tail=NULL;
	dodaj(2,&head,&tail);
	dodaj(31,&head,&tail);
	dodaj(4,&head,&tail);
	dodaj(21,&head,&tail);
	dodaj(8,&head,&tail);
	printf("\n");
	print(head,1);
	printf("\n");
	print(tail,-1);
	printf("\n");
	del(head);
	return 0;
};
void dodaj(int key,struct node **head,struct node **tail)
{

	struct node *tmp=malloc(sizeof(struct node));
	if(!tmp)
	{
		printf("problem z pamiecia\n");
		return;
	};
	tmp->next=NULL;
	tmp->prev=NULL;
	tmp->key=key;
	
	if(!*head)
	{
		*head=tmp;
		*tail=tmp;
	}
	else
	{
		tmp->next=*head;
		tmp->next->prev=tmp;
		*head=tmp;
	};
	printf("Node '%d' has been addes\n",tmp->key);
};
void print(struct node *start,int dir)
{
	struct node *act=start;
	printf("Key:\tPrev el;\tThis el:\tNext el:\n");
	while(act)
	{
		printf("%d\t%p\t%p\t%p\n",act->key,act->prev,act,act->next);
		act=(dir>0?act->next:act->prev);
	};
};
void del(struct node *head)
{
	struct node *tmp;
	struct node *tmp2;
	tmp=head;
	tmp2=tmp;
	while(tmp2)
	{
		tmp=tmp2;
		tmp2=tmp2->next;
		printf("deleting '%d' node\n",tmp->key);
		free(tmp);
	};
};
