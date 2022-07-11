#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include<string.h>
void random2();
void delet(int a);
int tm_sec1,tm_min1,tm_hour1,b,c,e,k,g,total;
void print_form()
{
char datestr[9];
FILE *f;
  _strdate(datestr);
  f=fopen("print_form.txt"
,"w");
fprintf(f,"*******************************************************************");

fprintf(f,"\n\n\t\t\tName:: %s",name);

fprintf(f,"\n\t\t\tCard ID :: %d",n);
fprintf(f,"\n\t\t\tDate:: %s",datestr);
fprintf(f,"\n\t\t\tCheckin time: %d:%d:%d\n",a,b,c);
fprintf(f,"\t\t\tTHANK YOU\n");
fprintf(f,"*******************************************************************");

fclose(f);
}
void print_checkout_form()
{
FILE *f;
char datestr[9];
  _strdate(datestr);
f=fopen("print_form.txt","w");
fprintf(f,"*******************************************************************");

fprintf(f,"\n\n\t\t\tName:: %s",name);

fprintf(f,"\n\t\t\tCard ID :: %d",n);
fprintf(f,"\n\t\t\tDate:: %s",datestr);
fprintf(f,"\n\t\t\tCheckin time: %d:%d:%d\n",a,b,c);
fprintf(f,"\n\t\t\tCheckout time: %d:%d:%d\n",e,k,g);
fprintf(f,"\n\t\t\ttotal time is %d min\n",total/10);
fprintf(f,"\n\t\t\ttotal amount is  Rs %d\n",total);
fprintf(f,"\t\t\tTHANK YOU\n");
fprintf(f,"*******************************************************************");
fclose(f);
}
void checkin_cus()
{
 FILE *fp;
 time_t t = time(NULL);
struct tm tm = *localtime(&t);

 fp=fopen("irregular_cus.txt","a");
 random2();
 printf("Enter name::  ");
 scanf("%s",name);
printf("checkin time is : %d:%d:%d\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
a=tm.tm_hour;
b= tm.tm_min;
c= tm.tm_sec;

printf("\nYour id is %d",n);
print_form();
printf("\nOpen \"print_form.txt\" file to print reciept\n");
fprintf(fp,"%s %d %d:%d:%d\n",name,n,tm.tm_hour, tm.tm_min,tm.tm_sec);
fclose(fp);
}

void random2()
{
FILE *fp1;
int c,n1;
int res,found=0;
time_t t = time(NULL);
struct tm tm = *localtime(&t);

fp1=fopen("irregular_cus.txt","r");

  for (c = 1; c <=1; c++)
  {
    n1 = rand() % 1000 + 5;
    }
    while(fscanf(fp1,"%s %d %d:%d:%d\n",name,&n, &tm.tm_hour, &tm.tm_min,&tm.tm_sec)!=EOF)
    {

     if(n1==n)
     {
     found=1;

    fclose(fp1);
    random2();
     break;
     }
     }
     if(found!=1)
     {
     n=n1;
    }

    fclose(fp1);
}
void checkout_cus()
{
FILE *fp,*fp1;
int n1,found=0,hour,min;

int tm_sec1,tm_min1,tm_hour1;
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
printf("Checkin time: %d:%d:%d\n",tm_hour1,tm_min1,tm_sec1);
printf("\nCheckout time: %d:%d:%d\n",tm.tm_hour,tm.tm_min,tm.tm_sec);
e=tm.tm_hour;
k=tm.tm_min;
g=tm.tm_sec;
if(tm_min1>tm.tm_min)
{
hour=tm.tm_hour-tm_hour1-1;
min=(60+tm.tm_min)-tm_min1;
total=((60*hour)+min)*10;
printf("\ntotal time is %d min\n",total/10);
printf("\ntotal amount is Rs %d\n",total);

fprintf(fp1,"%s %d %d %d:%d:%d %d:%d:%d %02d-%02d-%04d\n",name,n,total,tm_hour1,tm_min1,tm_sec1,tm.tm_hour,tm.tm_min,tm.tm_sec,tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
fclose(fp1);
print_checkout_form();
printf("\nOpen \"print_form.txt\" file to print reciept\n");
}
if(tm_min1<=tm.tm_min)
{
hour=tm.tm_hour-tm_hour1;
min=tm.tm_min-tm_min1;
total=((60*hour)+min)*10;
printf("\n total time is %d min\n",total/10);
printf("\n total amount is %d\n",total);
fprintf(fp1,"%s %d %d %d:%d:%d %d:%d:%d %02d-%02d-%04d\n",name,n,total,tm_hour1,tm_min1,tm_sec1,tm.tm_hour,tm.tm_min,tm.tm_sec,tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
fclose(fp1);
print_checkout_form();
printf("\nOpen \"print_form.txt\" file to print reciept\n");

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
void delet(int a)
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
