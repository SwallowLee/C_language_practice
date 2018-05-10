# include<stdio.h>

int main(void)
{
 short int inter,total,i;
 printf("Enter a positive integer: ");
 scanf("%hd",&inter);
 total=1;
 for(i=inter;i>0;i--)
     total=total*i;
 printf("Factorial of %d: %d",inter,total);
 return 0;
}
