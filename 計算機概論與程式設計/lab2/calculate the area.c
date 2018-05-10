#include <stdio.h>
#define p 3.14159
int main (void)
{
int r;
float a,b,area;
printf("Please enter r: ");
scanf("%d",&r);
a=(1.0/2.0)*r*(1.0/2.0)*r*p*(1.0/2.0);
b=a*(1.0/2.0)-(1.0/2.0)*r*(1.0/2.0)*r*(1.0/2.0);
area=r*r*p*(1.0/4.0)-a*2+b*4;
printf("The area of the shadowed part is %f",area);
return 0;
}
