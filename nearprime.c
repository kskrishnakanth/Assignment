#include<math.h>
int prime(int n);
int main()
{
	int n,i,flag,temp,val=1;
	scanf("%d",&n);
	if(n==1)
	{
		printf("Nearest prime  : %d\n",2);
	}
	else
	{
		temp=n;
		for(i=n+1;val==1;i++)
		{
			val = prime(i);
		}
		printf("Nearest prime is : %d\n",i-1);
		
	}
	return 0;
}
int prime(int n)
{
	int i,flag=0,cond;
	cond=sqrt(n);
	for(i=2;i<=cond;i++)
	{
		if(n%i==0)
		{
			flag++;
			break;
		}
	}
	return flag;

}
