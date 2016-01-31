#include<stdio.h>
#include<math.h>
int main() 
{
	int num,n,div,cond;
	scanf("%d",&num);
	n=num+1;
	cond=sqrt(n); // Initial Condition
	for(div=2;div<=cond;div++) //cond is not calculated here for efficiency.
	{
		if(n%div==0)
		{
			printf("n=%d ,div=%d\n",n,div);
			n++;
			div=1;
			cond=sqrt(n); // Condition is updated whenevere n changes
		}
	}
	printf("Nearest Prime number is : %d",n);	
	return 0;
}
