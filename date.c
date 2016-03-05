#include<stdio.h>
#include<malloc.h>
char months[12][10] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
char weekdays[7][10] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int monthoffsets[12] = {0,3,3,6,1,4,6,2,5,0,3,5};
struct date
{
	int year;
	int month;
	int day;
}*dt;
int getYear(struct date * dt)
{
	return dt->year;
}
int prevYear(struct date *dt)
{
	return dt->year-1;
}
char *  getDay(struct date *dt,char * str)
{
	int dayoffset,yearoffset,centuryoffset,monthoffset,offset;
	int year = dt->year;
	int month = dt->month;
	dayoffset = dt->day%7;
	int lsbs = calVal(str,2,3);
	if((isleapyear(year)==1)&&(month==1||month==2))
	{
		yearoffset = ((lsbs+(lsbs/4))%7)-1;
	}
	else
	{
		yearoffset = (lsbs+(lsbs/4))%7;
	}
 	centuryoffset = getcenturyoff(year);
 	monthoffset = monthoffsets[dt->month-1];
 	offset = dayoffset+monthoffset+yearoffset+centuryoffset;
 	offset = offset%7;
 	return weekdays[offset];
 	
}
int getcenturyoff(int year)
{
	if((year>=300&&year<=399)||(year>=700&&year<=799)||(year>=1500&&year<=1599)||(year>=1100&&year<=1199)||(year>=1900&&year<=1999))
	{
		return 0;
	}
	else if((year>=400&&year<=499)||(year>=800&&year<=899)||(year>=1200&&year<=1299)||(year>=1600&&year<=1699)||(year>=2000&&year<=2099))
	{
		return 6;
	}
	else if((year>=200&&year<=299)||(year>=600&&year<=699)||(year>=1000&&year<=1099)||(year>=1400&&year<=1499)||(year>=1800&&year<=1899))
	{
		return 2;
	}
	return 4;
}
int calVal(char* a,int str,int end)
{
	int i,j,val=0;
	for(i=str;i<=end;i++)
	{
		val = val*10+(a[i]-48);
	}
	return val;
}
char * getMonth(struct date *dt)
{
	return months[dt->month-1];
}
int getMonthVal(struct date *dt)
{
	return dt->month;
}
char * getPrevMonth(struct date *dt)
{
	int flag=0;
	if(dt->month-1==0)
	{
		return months[11];
	}
	return months[dt->month-2];
}
int  getDayVal(struct date *dt)
{
	return dt->day;
}
int getIndex(struct date *dt)
{
	int i,sum=0;
	int month = dt->month-1;
	int year = dt->year;
	for(i=0;i<month;i++)
	{
		sum = sum+days[i];
	}
	sum = sum + dt->day;
	if(isleapyear(year))
	{
		return sum+1;
	}
	return sum;
}
int isleapyear(int year)
{
	if(year%4==0||year%400==0)
	{
		return 1;
	}
	return 0;
}
struct date * daybefore(struct date *dt,int n)
{
	if(n<=dt->day)
	{
		dt->day=dt->day-n;
		if(dt->day==0)
		{
			if(isleapyear(dt->year)&&dt->month==3)
			{
				dt->day = days[dt->month-2]+1;
				dt->month  = dt->month-1;
			}
			else
			{
				dt->day = days[dt->month-2];
				if(dt->month==0)
				{
					dt->month=12;
				}
			}
		}
	}
	else
	{
		int years,flag=0;
		int count=0;
		n = n-dt->day;
		while(n>0)
		{
			count++;
			dt->month--;
			if(dt->month==0)
			{
				dt->month=12;
				dt->year--;
			}
			n = (isleapyear(dt->year)==1&&dt->month==2)?n-(days[dt->month-1]+1):n-days[dt->month-1];
		}
		dt->day = -n;
		if(count>12)
		{
			years = count/12;
			dt->year -=years;
		}
	}
	return dt;
}
int datediff(struct date * dt1,struct date * dt2)
{
	int count=0,i,num1,num2,val;
	if(dt1->year<dt2->year)
	{
		count = (isleapyear(dt1->year)==1)?366-getIndex(dt1):365-getIndex(dt1);
		printf("remaining count in entered year = %d\n",count);
		dt1->year++;
		for(i=dt1->year;i<dt2->year;i++)
		{
			count +=isleapyear(dt1->year)?366:355;
		}
		count+=getIndex(dt2);
		count-=dt1->day;

		return count;
	}
	else if(dt2->year<dt1->year)
	{
		count = (isleapyear(dt2->year)==1)?366-getIndex(dt2):365-getIndex(dt2);
		dt2->year++;
		for(i=dt2->year;i<dt2->year;i++)
		{
			count +=isleapyear(dt2->year)?366:355;
		}
		//count-=getIndex(dt2);
		count+=getIndex(dt1);
		count-=dt2->day;
		return count;
	}
	else
	{
		num1 = getIndex(dt1);
		num2 = getIndex(dt2);
		val = num1-num2;
		count = (val<0)?-val:val;
		return count;
	}
	
}
int main()
{
	struct date *temp,*temp2;
	char date[15];
	int n;
	dt = (struct date *)malloc(sizeof(struct date));
	printf("Enter the date in yyyy-mm-dd format\n");
	scanf("%s",date);
	dt->year  = calVal(date,0,3);
	dt->month = calVal(date,5,6);
	dt->day   = calVal(date,8,9);
	printf("The entered   year    is   :   %d\n",getYear(dt));
	printf("The previous  year    is   :   %d\n",prevYear(dt));
	printf("The name of the month is   :   %s\n",getMonth(dt));
	printf("The month in number   is   :   %d\n",getMonthVal(dt));
	printf("The previous  month   is   :   %s\n",getPrevMonth(dt));
	printf("The day  entered      is   :   %d\n",getDayVal(dt));
	printf("the day of the week   is   :   %s\n",getDay(dt,date));
	printf("the index of the year is   :   %d\n",getIndex(dt));
	printf("Enter N to get date before N days : ");
	scanf("%d",&n);
	temp = dt;
	temp=daybefore(temp,n);
	printf("%04d-%02d-%02d\n",temp->year,temp->month,temp->day);
	printf("Enter the date to find difference : ");
	temp2 = (struct date *)malloc(sizeof(struct date));
	scanf("%d-%d-%d",&temp2->year,&temp2->month,&temp2->day);
	printf("No of days in between two date : %d\n",datediff(dt,temp2));
	return 0;
}
