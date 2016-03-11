#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;


}node;
node * head;
node *create()
{
	node *p;
	int x;
	scanf("%d",&x);
	if(x==-1)
	{
		return NULL;
	}
	p=(node*)malloc(sizeof(node));
	p->data=x;
	printf("Enter left child of %d: ",x);
	p->left=create();
	printf("Enter right child of %d: ",x);
	p->right=create();
	return p;


}
int ls=0,rs=0,val=0;
int sum(node *t)
{
	if(t==NULL)
	{
		return 0;
	}
	else
	{
		return sum(t->left)+t->data+sum(t->right);
	}
}
int sumtree(node *t) //address of root node is passed
{
	if(t!=NULL)
	{
		ls+=sum(t->left);
		rs+=sum(t->right);
		val = t->data;
		if(val==ls+rs)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
}

int main()
{
	int temp,sum;
	node *root,* head;
	printf("Enter data(-1 for nodata)\n");
	root=create();
	head = root;
	sum = root->data;
	if(sumtree(root)==1)
	{
		printf("True\n");
	}
	else
	{
		printf("False");
	}
	return 0;


}
