#include<stdio.h>
#include<conio.h>
#include<string.h>
void card_update1()
{
int n,a;

int money;

char ch;
FILE *fp,*fp1,*fp2;
int money1,n1,found=0;
printf("\nEnter Card ID\n");
scanf("%d",&n1);
fp2=fopen("temp.txt","a");
fp=fopen("card_registeration.txt","r");
while(fscanf(fp,"%s %s %s %d %d\n",name,date,mob,&money,&n)!=EOF)
{
if(n==n1)
{
found=1;

printf("Details are ::\n");
printf("Name:: %s\nAvailable amount:: %d\n",name,money);
fflush(stdin);
printf("If you want to add money then press<a>\nor Press other key to back\n");
scanf("%c",&ch);
if(ch=='a')
{
 printf("Enter amount to be added\n");
 scanf("%d",&money1);
 money=money+money1;
 fprintf(fp2,"%s %s %s %d %d\n",name,date,mob,money,n);

  printf("amount added\n");
 printf("current amount is %d",money);


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


