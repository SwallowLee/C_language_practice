# include <stdio.h>

int main(void)
{int a,b,c;
printf("Please input a: ");
scanf("%d",&a);
printf("please input b: ");
scanf("%d",&b);
c=(b+1)/2+(b+1)%2-(a+1)/2;
printf("There are %d even numbers between %d and %d",c,a,b);
return 0;
}
