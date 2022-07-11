#include<stdio.h>
#include<conio.h>

void see_record()
{
FILE *fp;
char name[20];
int found=0,total1=0,day,mon,year;
int n,total,tm_hour1,tm_min1,tm_sec1,tm_hour,tm_min,tm_sec,da_day,da_mon,da_year;

printf("Enter day(dd)\n");
scanf("%d",&day);
printf("Enter month(mm)\n");
scanf("%d",&mon);
printf("Enter year(yyyy)\n");
scanf("%d",&year);
fp=fopen("total_list.txt","r");
while(fscanf(fp,"%s %d %d %d:%d:%d %d:%d:%d %d-%d-%d\n",name,&n,&total,&tm_hour1,&tm_min1,&tm_sec1,&tm_hour,&tm_min,&tm_sec,&da_day,&da_mon,&da_year)!=EOF)

{
if(day==da_day && mon==da_mon && year==da_year)
{
found=1;
total1=total1+total;

printf("Name=%s\n ID=%d\namount=%d \ncheckin time=%d:%d:%d \ncheckout time=%d:%d:%d\n date=%d-%d-%d\n",name,n,total,tm_hour1,tm_min1,tm_sec1,tm_hour,tm_min,tm_sec,da_day,da_mon,da_year);
}
}
if(found!=0)
{
printf("\ntotal income is Rs %d",total1);
}
if(found!=1)
{
printf("not found\n");
}
fclose(fp);
}
