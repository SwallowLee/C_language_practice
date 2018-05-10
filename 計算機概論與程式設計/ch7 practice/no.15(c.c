# include<stdio.h>

int main(void)
{
 long int inter,total,i;
 printf("Enter a positive integer: ");
 scanf("%ld",&inter);
 total=1;
 for(i=inter;i>0;i--)
     total=total*i;
 printf("Factorial of %d: %d",inter,total);
 return 0;
}
