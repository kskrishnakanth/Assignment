#include<stdio.h>
#include<malloc.h>
int strcmp1(char *a,char *b)
{
	int i,j;
	for(i=0,j=0;(a[i]!='\0'&&b[j]!='\0');i++,j++)
	{
		if(a[i]>b[j])
		{
				
				return 1;
				break;
		}
		else if(a[i]<b[j])
		{
				return -1;
				break;
		}
	}
	return 0;
}
int length(char *a)
{
	int i,l=0;
	for(i=0;a[i]!='\0';i++)
	{
		l++;
	}
	return l;
}
int main()
{
	int i,j,n,l1,l2;
	char *temp;
	scanf("%d",&n);
	char **a =  (char **)malloc(n*sizeof(char *));
	for(i=0;i<n;i++)
	{
		a[i] = (char *)malloc(sizeof(char));
	}
	for(i=0;i<n;i++)
	{
		scanf("%s",a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			l1 = length(a[i]);
			l2 = length(a[j]);
			if((l1>l2||l1==l2)&&strcmp1(a[i],a[j])>0)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				
			}
			
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%s\t",a[i]);
	}
	return 0;
}
