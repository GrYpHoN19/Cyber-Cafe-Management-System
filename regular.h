#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include<string.h>
 void delete1(int a);
 void edit(int total1,int n1);
int m,h,f;
int n1;
void print_form1()
{
FILE *fp;
fp=fopen("print_form.txt","w");
fprintf(fp,"*******************************************************************");

fprintf(fp,"\n\n\t\t\tName:: %s",name);

fprintf(fp,"\n\t\t\tCard ID :: %d",n1);
fprintf(fp,"\n\t\t\tDate:: %s",date);
fprintf(fp,"\n\t\t\tCheckin time: %d:%d:%d\n",h,e,f);
fprintf(fp,"\t\t\tTHANK YOU\n");
fprintf(fp,"*******************************************************************");
fclose(fp);
}
void print_checkout_form1()
{
FILE *fp;
fp=fopen("print_form.txt","w");
fprintf(fp,"*******************************************************************");
fprintf(fp,"\n\n\t\t\tName:: %s",name);
fprintf(fp,"\n\t\t\tCard ID :: %d",n1);
fprintf(fp,"\n\t\t\tDate:: %s",date);
fprintf(fp,"\n\t\t\tCheckin time: %d:%d:%d\n",tm_hour1,tm_min1,tm_sec1);
fprintf(fp,"\n\t\t\tCheckout time: %d:%d:%d\n",a,b,c);
fprintf(fp,"\n\t\t\ttotal time is %d min\n",total/20);
fprintf(fp,"\ntotal amount is  Rs %d\n",total);
fprintf(fp,"\ncurrent amount is %d\n",m);
fprintf(fp,"\t\t\tTHANK YOU\n");
fprintf(fp,"*******************************************************************");

fclose(fp);
}
void checkin_card()
{
 FILE *fp,*fp1;

 int found=0;
 time_t t = time(NULL);
struct tm tm = *localtime(&t);

 fp1=fopen("card_registeration.txt","r");
 fp=fopen("irregular_cus.txt","a");
 printf("Enter card id::  ");
 scanf("%d",&n1);
 while(fscanf(fp1,"%s %s %s %d %d\n",name,date,mob,&money,&n)!=EOF)
 {
 if(n==n1)
 {
 found=1;
  printf("Name:: %s\nAvailable Amount:: %d",name,money);
  if(money<100)
  {
  printf("insufficient amount in account\n");
  }
  else
  {
	printf("\ncheckin time is : %d:%d:%d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
	 h=tm.tm_hour;
	 e=tm.tm_min;
	 f= tm.tm_sec;
	fprintf(fp,"%s %d %d:%d:%d\n",name,n,tm.tm_hour, tm.tm_min,tm.tm_sec);
	 print_form1();
	 printf("\nOpen \"Print_form.txt\" To print reciept");
  }
  }
  }

if(found!=1)
{
printf("error");
}
 fclose(fp);
 fclose(fp1);

}



void checkout_card()
{
FILE *fp,*fp1,*fp4;
int n1,found=0,hour,min;

time_t t = time(NULL);
struct tm tm = *localtime(&t);
fp=fopen("irregular_cus.txt","r");
fp1=fopen("total_list.txt","a");
printf("Enter customer ID\n");
scanf("%d",&n1);
while(fscanf(fp,"%s %d %d:%d:%d\n",name,&n,&tm_hour1,&tm_min1,&tm_sec1)!=EOF)
    {

     if(n1==n)
     {
       found=1;
printf("Name:: %s\n",name);
printf("\nCheckin time: %d:%d:%d\n",tm_hour1,tm_min1,tm_sec1);
printf("\nCheckout time: %d:%d:%d\n",tm.tm_hour,tm.tm_min,tm.tm_sec);
a=tm.tm_hour;
b=tm.tm_min;
c=tm.tm_sec;
if(tm_min1>tm.tm_min)
{
hour=tm.tm_hour-tm_hour1-1;
min=(60+tm.tm_min)-tm_min1;
total=((60*hour)+min)*10;
printf("\ntotal time is %d min\n",total/10);
printf("\ntotal amount is  Rs %d\n",total);
fprintf(fp1,"%s %d %d %d:%d:%d %d:%d:%d %02d-%02d-%04d\n",name,n,total,tm_hour1,tm_min1,tm_sec1,tm.tm_hour,tm.tm_min,tm.tm_sec,tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
print_checkout_form1();
printf("\nOpen \"Print_form.txt\" To print reciept");
fclose(fp1);
fclose(fp);
edit(total,n);
delete1(n);
print_checkout_form1();
printf("\nOpen \"Print_form.txt\" To print reciept");

}
if(tm_min1<=tm.tm_min)
{
hour=tm.tm_hour-tm_hour1;
min=tm.tm_min-tm_min1;
total=((60*hour)+min)*10;
printf("total time is %d min\n",total/10);
printf("total amount is Rs %d",total);
fprintf(fp1,"%s %d %d %d:%d:%d %d:%d:%d %02d-%02d-%04d\n",name,n,total,tm_hour1,tm_min1,tm_sec1,tm.tm_hour,tm.tm_min,tm.tm_sec,tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
fclose(fp1);
fclose(fp);
edit(total,n);
delete1(n);
print_checkout_form1();
printf("\nOpen \"Print_form.txt\" To print reciept");
}
}
 }
 if(found!=1)
 {
 printf("error");
 fclose(fp);
 fclose(fp1);
 }
}
void edit(int total1,int n1)
{
int n,a;
int money,total;
char ch;
FILE *fp,*fp1,*fp2;
int money1,found=0;
fp2=fopen("temp.txt","a");
fp=fopen("card_registeration.txt","r");
while(fscanf(fp,"%s %s %s %d %d\n",name,date,mob,&money,&n)!=EOF)
{
if(n==n1)
{
found=1;
 money=money-total1;

 if(money>=0)
 {
 fprintf(fp2,"%s %s %s %d %d\n",name,date,mob,money,n);
 printf("current amount is %d",money);
 m=money;
 }
 if(money<0)
 {
  money=total1-money;
  printf("please pay Rs %d more",money);
  money=0;
  fprintf(fp2,"%s %s %s %d %d\n",name,date,mob,money,n);
 printf("current amount is %d",money);
 //m=money;
 }
}
else
{
fprintf(fp2,"%s %s %s %d %d\n",name,date,mob,money,n);
}
}
fclose(fp);
fclose(fp2);
fp=fopen("card_registeration.txt","w");
fclose(fp);
fp=fopen("card_registeration.txt","a");
fp2=fopen("temp.txt","r");
while(fscanf(fp2,"%s %s %s %d %d\n",name,date,mob,&money,&n)!=EOF)
{
fprintf(fp,"%s %s %s %d %d\n",name,date,mob,money,n);
}
fclose(fp);
fclose(fp2);
fp2=fopen("temp.txt","w");
fclose(fp2);
if(found!=1)
{
 printf("records not found\n");
 }
 }
void delete1(int a)
{
FILE *fp2,*fp3;
int tm_sec1,tm_min1,tm_hour1;
fp2=fopen("irregular_cus.txt","r");
fp3=fopen("temp.txt","a");
while(fscanf(fp2,"%s %d %d:%d:%d\n",name,&n,&tm_hour1,&tm_min1,&tm_sec1)!=EOF)
{
if(n==a)
{
}
else
{
fprintf(fp3,"%s %d %d:%d:%d\n",name,n,tm_hour1,tm_min1,tm_sec1);
}
}
fclose(fp2);
fclose(fp3);
fp2=fopen("irregular_cus.txt","w");
fclose(fp2);
fp2=fopen("irregular_cus.txt","a");
fp3=fopen("temp.txt","r");
while(fscanf(fp3,"%s %d %d:%d:%d\n",name,&n,&tm_hour1,&tm_min1,&tm_sec1)!=EOF)
{
fprintf(fp2,"%s %d %d:%d:%d\n",name,n,tm_hour1,tm_min1,tm_sec1);
}
fclose(fp2);
fclose(fp3);
fp3=fopen("temp.txt","w");
fclose(fp3);
}

