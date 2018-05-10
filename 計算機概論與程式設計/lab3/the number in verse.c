# include <stdio.h>

int main(void)
{
int a,b;
printf("Please enter a number: ");
scanf("%d",&a);
b=a%10*100+(a-a%10)%100+(a-a%10-(a-a%10)%100)/100;
printf("This number in verse order is %d",b);

 return 0;

}
