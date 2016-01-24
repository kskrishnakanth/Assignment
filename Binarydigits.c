#include<stdio.h>
int bindigit(int);
int count=0;
int main()
{
	int n;
	printf("\nEnter the number : ");
	scanf("%d",&n);
	printf("the no.of binary digits = %d",bindigit(n));
	return 0;
	
}
int bindigit(int num)
{
	if(num==0||num==1)
	{
		return 1;
	}
	else
	{
		while(num>0)
		{
			num=num/2;
			count++;
		}
		return count;
	}
}
