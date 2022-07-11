
#include<stdio.h>
#include<conio.h>
#include "card.h"
#include "irregular.h"
#include "update.h"
#include "regular.h"
#include "see_record.h"
void main_module()
{
int n;
char ch;
do
{
printf("\t\t\t....................\n");
printf("\t\t\t|GrYpHoN Cyber Cafe|\n");
printf("\t\t\t....................\n");

printf("Press <1> Checkin to registered customer\n");
printf("Press <2> Checkout to registered customer\n");
printf("Press <3> Checkin to irregular customer\n");
printf("Press <4> Checkout to irregular customer\n");
printf("Press <5> Generate Card\n");
printf("Press <6> Update Card\t\t\tMin card Balance:: Rs 100.\n");
printf("Press <7> See datewise total income\n");
printf("Press <8> To Exit\t\t\tCHARGES:: Rs 10/Min\n");
printf("\nEnter choice:: ");
scanf("%d",&n);
switch(n)
{
case 1:
checkin_card();
break;
case 2:
checkout_card();
break;
case 3:
checkin_cus();
break;
case 4:
checkout_cus();
break;
case 5:
card_registeration();
break;
case 6:
card_update1();
break;
case 7:
see_record();
break;
case 8:
exit(0);
default:
printf("error");
}
fflush(stdin);
printf("\nPress any key  to back\n");
scanf("%c",&ch);
}
while(ch!=',');
}

