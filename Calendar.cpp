/*
	Name:        Get Calendar of Any Year.
	Copyright: 
	Author:      YOGESH PUROHIT
	Date:        28/02/23 15:44
	Description: C PROGRAM
*/

#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int getfirstday(int x)
{
    int day;
    day=(((x - 1)*365)+((x - 1)/ 4 )-(( x - 1)/ 100)+((x)/400)+1)%7;
    return day;
}
int  main()
{
    int year,month,d,days,daysinmonth,startingday,weekday=0,n;
    char *monthsname[]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char *daysname[]={"Sun","Mon","Tue","Wed", "Thu", "Fri", "Sat"};
    int monthsday[]={31,28,31,30,31,30,31,31,30,31,30,31};
    system("cls");
    printf("\nEnter the Year to Find the Calendar:");
    scanf("%d",&year);
    if(year%4==0)
    {
    	monthsday[1]=29;
   	}
    startingday=getfirstday(year);
    for(month=0; month<12;month++)
    {
    	system("cls");
    	printf("\n\t            Calendar Of %d year             ",year);
    	printf("\n\n");
        daysinmonth=monthsday[month];
        printf("\n-------------------------------------%s-------------------------------------------\n\n",monthsname[month]);
        for(d=0;d<7;d++)
        {
            printf("%5s",daysname[d]);
        }
        printf("\n");
        for(weekday=0;weekday<startingday;weekday++)
        {
            printf("     ");
        }
        for(days=1;days<=daysinmonth;days++)
        {
            printf("%5d",days);
            if(++weekday>6)
            {
                printf("\n");
                weekday=0;
            }
            startingday=weekday;
        }
        printf("\n\nPress Any Key For next month");
        getch();
    }
    getch();
    return 0;
}
