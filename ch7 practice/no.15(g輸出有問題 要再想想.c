# include<stdio.h>//maybe not support long double

int main(void)
{
 long double inter,total,i;
 printf("Enter a positive integer: ");
 scanf("%llf",&inter);
 total=1.0;
 for(i=inter;i>0;i=i-1)
 {
     total=total*i;
     printf("%llf\n",total);
 }
 printf("Factorial of %llf: %llf",inter,total);
 return 0;
}
