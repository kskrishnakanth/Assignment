#include<stdio.h>
#include<malloc.h>
void copy(char * dest,char* src) // function to copy strings
{
		int i;
		for(i=0;src[i]!='\0';i++)
		{
			dest[i] = src[i];
		}
		dest[i] = '\0';
}
int main()
{
		char str[100];
		int i,j,flag=0,k=1,l1=1,l2=0,l3=0;
		char *c,*d,*e;
		scanf("%s",str);
		e = (char *)malloc(sizeof(str)); // allocating memory for string in which manipulation is performed.
		c = (char *)malloc(sizeof(str)); // allocating memory for copying the maximum substring having non repeated characters
		c[0]=str[0]; // intially i am storing the first character for src string
		c[1]='\0'; // for terminating inner for  loop
		for(i=1;str[i]!='\0';i++)
		{
			flag = 0;
			for(j=0;c[j]!='\0';j++)
			{
					if(c[j]==str[i])
					{
							flag=1;
							break;
					}
			}
			if(flag==0) // building the substring  with non repeated character
			{
					c[k] = str[i];                            
			    c[k+1] = '\0';
					k++;             
					l1++;                                        
			}
			else
			{
					if(l1>=l2) //l1 has length of current string constructed l2 is previous substring length initially l2 = 0
					{
							 copy(e,c); 
					     l3=l1;
			    }
			    l2=l1; 
					l1=1;
					c[0]=str[i];
					c[1]='\0';
					k=1;
			}
	
		} 
		printf("Longest substring : %s, length : %d\n",e,l3);
		return 0;
}
