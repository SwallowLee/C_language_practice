# include <stdio.h>

int main(void)
{float a,c;
int b;
 printf("Enter a number:");
 scanf("%f",&a);
 b=a+0.5;
 c=a+0.005;
 printf("round to Integer :%d \n",b);
 printf("round to 2nd decimal place :%.2f \n",c);
 return 0;

}
