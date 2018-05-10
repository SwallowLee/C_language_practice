# include <stdio.h>

int f(int a,int b)
{
  return a+b;
}
int main(void)
{
 int i,i1;
 double x,x1;
 i=f(83,12);
 x=f(83,12);
 i1=f(3.15,9.28);
 x1=f(3.15,9.28);
 printf("i %d\n",i);
 printf("x %f\n",x);
 printf("i1 %d\n",i1);
 printf("x1 %f\n",x1);
 printf("%d",f(83,12));
}
