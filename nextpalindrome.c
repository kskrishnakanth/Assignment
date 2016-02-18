/*============================================================================================================================================================
nextpalindrome.c
KrishnaKanth K.S

Program to print the nearest palindrome number from 1 to 1000000000

PseudoCode
1. Get the input as string
2. place the first character of input to the last
3. if number entered is greater than the entered one next palindrome is generated
4. else increment the mean elements by one to form the mirror image.
5. if mean elements > 9 then val is set  the value  to the smallest length+1 no and steps 1 to 4 are repeated


==============================================================================================================================================================*/

#include<stdio.h>
long long int calval(char * c) // it returns the integer value of the string entered
{
	long long  int val1=0,i;
		for(i=0;c[i]!='\0';i++)
	{
		val1 = val1*10+(c[i]-48);
		
	}
	return val1;
}
int lenval(char *c) // it returns the length of the string which is used in manipulation
{
	int i;
	for(i=0;c[i]!='\0';i++)
	{
		
	}
	return i;
}
char * nextpal(char *c,int l,long long int val1)
{
	int diff,flag=0;
	long long int val2;
	val2 = calval(c);
	if(l%2==0) // if the number entered has even no of digits
	{
		//4-1,4-2, 6-2,6-3, 8-3,8-4
		//length of number -> meanpos-1,meanpos to modify
	diff = l/2; // mean positions to increment
	while(val2<=val1)
	{
		c[diff] =  	c[diff]+1;
		c[diff-1] = c[diff]; // even length number will have two  mean digits
		if(c[diff]>9+48) // if mean pos number becomes greater than 9 set the value as  digit to lowest length+1 number
		{
			flag = 1;
			int i;
			c[0] =  c[0] + 1;
			for(i=1;c[i]!='\0';i++)
			{
				c[i] = '0';
			}
			val1 = calval(c);
			c[l-1] = c[0];
			c = nextpal(c,l,val1);
			
		}
		if(flag==1)
		{
			break;
		}
		val2 = calval(c);
	}
	return c;
	}
	else
	{
	  //3->1 5-2, 7-3,9-4,11->5  
	  //length of string ->position to modify
	  	diff = (int)l/2;
	  	while(val2<=val1)
	  	{
	  		c[diff] = c[diff]+1;
	  		if(c[diff]>9+48)
			{
				flag = 1;
				int i;
				c[0] =  c[0] + 1;
				for(i=1;c[i]!='\0';i++)
				{
					c[i] = '0';
				}
				val1 = calval(c);
				c[l-1] = c[0];
				c = nextpal(c,l,val1);
			}
			if(flag==1)
			{
				break;
			}
			val2 = calval(c);
		}	
	  return c;
}
}
int main()
{
	int l,i;
	long long int v;
	char val[20],*d;
	scanf("%s",val);
	l = lenval(val);
	v = calval(val);
	if(v<9)
	{
		printf("next palindrome = %d\n",v+1);
	}
	else
	{
		if(v==9||v==99||v==999||v==9999||v==99999||v==999999||v==9999999||v==99999999)// for special cases the number is set to the smallest length+1 number
		{
			val[0] = '1';
			for(i=1;val[i]!='\0';i++)
			{
				val[i] = '0';
			}
			val[l] = '0';
			val[l+1] = '\0';
			l = l+1;
		}
	
		val[l-1] =  val[0];
		d = nextpal(val,l,v);
		printf("next pal = %s\n",d);
	}
	return 0;
}
