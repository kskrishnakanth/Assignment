/*============================================================================================================================================================
nextpalindrome.c
KrishnaKanth K.S

Program to print the nearest palindrome number from 1 to 1000000000

PseudoCode
1. Get the input as string
2. rotate the digits of the number other than mean position
3. if number entered is greater than the entered one next palindrome is generated
4. else increment the mean elements and rotated.
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
char  mini(char c,char d) // find the min of mean position value for length = even
{
	char min;
	min = c;
	if(d<c)
	{
		min = d;
	}
	return min;
	
}
char * rotate(char *c,int diff,int l) // function to find mirror image
{
		int i,j;
		if(l%2!=0)
		{
			for(i=1,j=diff+1;c[j]!='\0';j++,i++)
			{
				c[j] = c[diff-i];
			}
		}
		else
		{ 
			for(i=0,j=diff+1;i<diff-1;j++,i++)
			{
				c[j] = c[diff-2-i];
			}
		}
		return c;
}
char * nextpal(char * val) 
{
	int l,diff,i,j,p;
	long long int val1,val2;
	val1 = calval(val);
	l = lenval(val);
	if(val1==9||val1==99||val1==999||val1==9999||val1==99999||val1==999999||val1==9999999||val1==99999999)// for special cases the number is set to the smallest length+1 number
	{
			val[0] = '1';
			for(i=1;val[i]!='\0';i++)
			{
				val[i] = '0';
			}
			val[l] = '0';
			val[l+1] = '\0';
			l= l+2;
			char * e = nextpal(val);
			return e;
			
	}
	char *d;
	diff = l/2; // for finding mean position
	if(l%2==0)
	{
		
		if(val[diff]!=val[diff-1])
		{
		char e = mini(val[diff],val[diff-1]);
		val[diff] = e;
		val[diff-1] = e;
		}
		d = rotate(val,diff,l);
		val2 = calval(d);
		while(val2<=val1)
		{
			
			val[diff] = val[diff]+1;
			val[diff-1] = val[diff];
			if(val[diff]>9+48) 
			{
			int i;
			val[0] = val[0] + 1;
			for(i=1;val[i]!='\0';i++)
			{
				val[i] = '0';
			}
			d = nextpal(val);
			break;
			}
			d = rotate(val,diff,l);
			val2 = calval(d);
		}
	}
	else
	{
		d = rotate(val,diff,l);
		val2 = calval(d);
		while(val2<=val1)
		{
			val[diff] = val[diff] + 1;
			if(val[diff]>9+48) 
			{
			val[0] = val[0] + 1;
			for(i=1;i<l;i++)
			{
				val[i] = '0';
			}
			d = nextpal(val);
			break;
			}
			d=rotate(val,diff,l);
			val2 = calval(d);
		}
	}
	return d;
}
int main()
{
	char val[14];
	scanf("%s",&val);
	if(lenval(val)==1&&val[0]<48+9)
	{
		val[0] = val[0] + 1;
		printf("val = %s\n",val);
	}
	else
	{
		printf("val = %s\n",nextpal(val));
	}
	return 0;
}
