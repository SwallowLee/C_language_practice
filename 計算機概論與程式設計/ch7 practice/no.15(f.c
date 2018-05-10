# include<stdio.h>

int main(void)
{
 double inter,total,i;
 printf("Enter a positive integer: ");
 scanf("%lf",&inter);
 total=1;
 for(i=inter;i>0;i--)
     total=total*i;
 printf("Factorial of %f: %f",inter,total);
 return 0;
}
