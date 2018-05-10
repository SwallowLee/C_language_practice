# include <stdio.h>

int main(void)
{
int dollar,a,b,c,d;
printf("Enter a dollar amount: ");
scanf("%d",&dollar);
a=dollar/20;
b=(dollar-20*a)/10;
c=(dollar-20*a-10*b)/5;
d=dollar-20*a-10*b-5*c;
printf("$20 bills: %d\n",a);
printf("$10 bills: %d\n",b);
printf(" $5 bills: %d\n",c);
printf(" $1 bills: %d\n",d);
return 0;
}
