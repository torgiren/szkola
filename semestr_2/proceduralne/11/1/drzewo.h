#include <stdlib.h>
struct tnode
{
	int value;
	struct tnode * left;
	struct tnode * right;
	struct tnode * parent;
};
struct tnode *CreateLeaf(int wartosc,struct tnode *parent)
{
	struct tnode *tmp=(struct tnode*)malloc(sizeof(struct tnode));
	if(!tmp)
	{
		return 0;
	};
	tmp->value=wartosc;
	tmp->parent=parent;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
};
int AddLeaf(int wartosc,struct tnode** root)
{
	if(!(*root))
	{
		printf("Dodaje do pustego\n");
		struct tnode *tmp=CreateLeaf(wartosc,NULL);
		if(!tmp)
		{
			return 0;
		};
		*root=tmp;
		return 1;
	}
	else
	{
		if(wartosc<((*root)->value))
		{
			if((*root)->left)
			{
				printf("do lewego podrzewa\n");
				return AddLeaf(wartosc,&((*root)->left));
			}
			else
			{
				printf("dodaje na lewo\n");
				(*root)->left=CreateLeaf(wartosc,*root);
				return (*root)->left?1:0;
			};
			
		}
		else
		{
			if((*root)->right)
			{
				printf("dodaje do prawego drzewa\n");
				return AddLeaf(wartosc,&((*root)->right));
			}
			else
			{
				printf("dodaje na prawo\n");
				(*root)->right=CreateLeaf(wartosc,*root);
				return (*root)->right?1:0;
				
			}
		};
	};

};
void print(struct tnode *root)
{
	if(!root) return;
	print(root->left);
	printf("%p\t%d\t%p\t%p\t%p\n",root,root->value,root->left,root->right,root->parent);
	print(root->right);
};
void print_pre(struct tnode *root)
{
	if(!root) return;
	printf("%p\t%d\t%p\t%p\t%p\n",root,root->value,root->left,root->right,root->parent);
	print_pre(root->left);
	print_pre(root->right);
};
void print_post(struct tnode *root)
{
	if(!root) return;
	print_post(root->left);
	print_post(root->right);
	printf("%p\t%d\t%p\t%p\t%p\n",root,root->value,root->left,root->right,root->parent);
};
struct tnode * find_min(struct tnode *root)
{
	if(!root) return 0;
	struct tnode *act=root;
	while(act->left)
	{
		act=act->left;
	};
	return act;
};
struct tnode *find_max(struct tnode *root)
{
	if(!(root->right)) return root;
	return find_max(root->right);
};
void del(struct tnode *root)
{
	if(root->left) del(root->left);
	if(root->right) del(root->right);
	printf("usuwam %p\t%d\n",root,root->value);
	free(root);
};
struct tnode *find(int wartosc,struct tnode *root)
{
	if(!root) return 0;
	if(root->value==wartosc) return root;
	if(root->value>wartosc)
	{
//		printf("szukam na lewo\n");
		return find(wartosc,root->left);
	}
	else
	{
//		printf("szukam na prawo\n");
		return find(wartosc,root->right);
	};

};
struct tnode *Succesor(struct tnode *root)
{
	printf("a\n");
	if(root->right)
	{
		return find_min(root->right);
	};
	printf("b\n");
	struct tnode *act;
	act=root;
	while(act==act->parent->left)
	{
		printf("ide do gory\n");
		act=act->parent;
		if(!(act->parent)) return 0;
	};
	return ;
};
