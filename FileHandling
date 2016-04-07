#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct words
{
	char str[100];
	int count;
	struct words * next;
	
}*p,*q,*head,*t;
void sort() // function to sort words accoding to their frequency
{
	int temp;
	char temps[60];
	p=head;
	q=head->next;
	while(p->next!=NULL)
	{
			q=p->next;
			while(q!=NULL)
			{
				if(p->count<q->count)
				{
				
					temp=p->count;
					p->count=q->count;
					q->count=temp;
					strcpy(temps,p->str);
					strcpy(p->str,q->str);
					strcpy(q->str,temps);
				}
				q=q->next;
			}
		p=p->next;
	}
}
void insert(char *a) //used for inserting unique words in to the word structure otherwise count is incremented
{
	int flag=0;
	struct words * temp = (struct words *)malloc(sizeof(struct words));
	if(head==NULL)
	{
		strcpy(temp->str,a);
		temp->next=NULL;
		temp->count=1;
		head = temp;
		q=head;
	}
	else
	{
		p=head;
		while(p!=NULL)
		{
			if(strcmp(p->str,a)==0)
			{
				flag=1;
				p->count+=1; //to increment count
				break;
			}
			p=p->next;
		}
		if(flag==0) // if word is not present 
		{
			strcpy(temp->str,a);
			temp->count=1;
			temp->next=NULL;
			q->next=temp;
			q=q->next;
		}
	}
}
int wordify(char *str) // used separate words eg hello,there will be separated as hello and there it writtens the word count
{
	int i,j=0,strt=0,end,k=0,wc=0;
	for(i=0;str[i]!='\0';i++)
	{
		if (str[i]>=32&&str[i]<=47)
		{
			char * b = (char *)malloc(100);
			end = i-1;
			for(j=strt;j<=end;j++)
			{
					b[k]=str[j];
					k++;
			}
			b[k]='\0';
			strt = i+1;
			wc++;
			//printf("%s\n",b);
			insert(b);
			free(b);
			k=0;
			}
				
		}
		return wc;
}
int count=0;  // for counting number of letters
char * To_Lower(char *a,int alpha[]) // converts paragraph to lowecase and count the number of letters
{
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>=65&&a[i]<=90)
		{
			a[i]+=32;
			alpha[a[i]-97]+=1;
			count++;
			
		}
		else if(a[i]>=97&&a[i]<=122)
		{
			alpha[a[i]-97]+=1;
			count++;
		}
	}
	return a;
}
int symb_count(char *a) // count number of symbols
{
	int sc=0,i;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>=33&&a[i]<=47||a[i]==64)
		{
			sc++;
		}
	}
	return sc;
}
void frequent_letters(int lf[],int alpha[]) //sorting letters according to frequency
{
	int i,j,temp;
	for(i=0;i<26;i++)
	{
		for(j=i+1;j<26;j++)
		{
			if(lf[i]<lf[j])
			{
				temp=lf[i];
				alpha[j]=i+97;
				alpha[i]=j+97;
				lf[i]=lf[j];
				lf[j]=temp;
			}
		}
	}
}
void letters_not_used(int lf[])
{
	int i;
	printf("4.Letters not used : ");
	for(i=0;i<26;i++)
	{
		if(lf[i]==0)
		{
			printf("%c ",i+97);
		}
	}
	printf("\n");
}
int occured_once() // returns no of words occured only once
{
	int c=0;
	p=head;
	while(p->next!=NULL)
	{
		if(p->count==1)
		{
			c++;
		}
		p=p->next;
	}
	return c;
}
int main()
{
	FILE *fp;
	int i,sc=0,wc=0;
	int lf[26]={0},alpha[26]={0};
	char a,str[255];
	fp=fopen("ks.txt","r");
	fscanf(fp, "%[^\r]",str);
	char * a1 = strtok(str,"\n");
	while(a1!=NULL)
	{
		a1=To_Lower(a1,lf);
		sc+=symb_count(a1);
		wc+=wordify(a1);
		a1=strtok(NULL,"\n");
	}
	printf("1.Letter count = %d\n",count);
	printf("2.Symbol count = %d\n",sc);
	printf("3.Word Count = %d\n",wc);
	letters_not_used(lf);
	frequent_letters(lf,alpha);
	printf("5.Three Common letters are : %c,%c,%c\n",alpha[0],alpha[1],alpha[2]);
	sort();
	if(wc>=3)
	{
		printf("6.Top three Common words : ");
		p=head;
		for(i=0;i<3;i++)
		{
			printf("%s, ",p->str);
			p=p->next;
		}
		printf("\n");
	}
	printf("7.No.of Words Occured once : %d\n",occured_once());
	p=head;
    fclose(fp);
    return 0;
}
