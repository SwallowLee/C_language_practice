# include<stdio.h>

int main(void)
{
 long long int inter,total,i;
 printf("Enter a positive integer: ");
 scanf("%lld",&inter);
 total=1;
 for(i=inter;i>0;i--)
 {
     total=total*i;
 }
  printf("Factorial of %lld: %lld",inter,total);
 return 0;
}
