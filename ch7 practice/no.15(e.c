# include<stdio.h>

int main(void)
{
 float inter,total,i;
 printf("Enter a positive integer: ");
 scanf("%f",&inter);
 total=1;
 for(i=inter;i>0;i--)
     total=total*i;
 printf("Factorial of %f: %f",inter,total);
 return 0;
}
