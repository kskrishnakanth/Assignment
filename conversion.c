#include<stdio.h>
int main()
{
	int no,base,i,j;
	char num[50];
	printf("\nEnter the number : ");
	scanf("%d",&no);
	printf("\nEnter the base(2 to 36 only) : ");
	scanf("%d",&base);
	i=0;
	while(no>0)
	{
		num[i]=no%base;
		no=no/base;
		i++;
		
	}
	j=i-1;
	printf("\nThe converted number is  : ");
	while(j>=0)
	{
		if(num[j]<10)
		{
			printf("%d",num[j]);
		}
		else
		{
			printf("%c",num[j]+55);
		}
		j--;
	}
	return 0;
}
