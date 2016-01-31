#include<stdio.h>
float guess(int n);
int main()
{
	int n,i;
	float res,temp;
	scanf("%d",&n);
	res=guess(n);
	for(i=1;i<=5;i++)
	{
	   res=((res+(n/res)))/2;
	}
	printf("Square root = %f",res);
	return 0;
}
float guess(int n)
{
	int val=0,i;
	for(i=2;val<n;i++)
	{
		val=i*i;
		if(val>n)
		{
			break;
		}
	}
	return (i-1); // this returns the nearest  squareroot value of a perfect square number
}
