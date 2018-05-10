#include <stdio.h>

int main (void)
{
float x1,y1,x2,y2,x3,y3,a,b,c,x4,y4;
printf("please find the line1 formula: y=ax+b\n");
printf("please input any point(x1,y1):\n");
printf("input x1:");
scanf("%f",&x1);
printf("input y1:");
scanf("%f",&y1);
printf("please input any point(x2,y2)\n");
printf("input x2:");
scanf("%f",&x2);
printf("input y2:");
scanf("%f",&y2);
a=(y1-y2)/(x1-x2);
b=y1-a*x1;
printf("this formula: y=%fx+%f\n",a,b);
printf("please input any point(x3,y3):\n");
printf("input x3:");
scanf("%f",&x3);
printf("input y3:");
scanf("%f",&y3);
printf("the line2 which contains (%.3f,%.3f) perpendicular to the line1.\n",x3,y3);
printf("please find the intersection point of line1 and line2:\n");
/*y=-1/a*x+c*/
/*y=ax+b*/
c=y3+1.0/a*x3;
x4=(c-b)/(a+1.0/a);
y4=a*x4+b;
printf("(%f,%f)",x4,y4);
return 0;
}
