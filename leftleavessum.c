#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;


}node;
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
int isleaf(node *t)
{
	if(t==NULL)
	{
		return 0;
	}
	else if(t->left==NULL&&t->right==NULL)
	{
		return 1;
	}
	return 0;
}
int sum1=0;
int leafsum(node *t)              //address of root node is passed
{
	if(t!=NULL)
	{
		if(isleaf(t->left))
		{
			sum1 = sum1 + t->left->data;
			printf("left leaves  are = %d\n",t->left->data);
		}
		else
		{
			leafsum(t->left);
			
		}
		leafsum(t->right);
	}
	return sum1;
}
int main()
{
	int sum;
	node *root;
	printf("Enter data(-1 for nodata)\n");
	root=create();
	printf("\n--------------------------------------------------------\n");
	sum=leafsum(root);
	printf("sum of left leaves = %d\n",sum);
	return 0;


}
