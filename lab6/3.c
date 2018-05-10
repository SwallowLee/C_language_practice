# include <stdio.h>

int NumDigits(int a)
{
 if(a>=0&&a<=9)
 {
  return 1;
 }
 else if(a>=10&&a<=99)
 {
  return 2;
 }
 else if(a>=100&&a<=999)
 {
  return 3;
 }
 else if(a>=1000&&a<=9999)
 {
  return 4;
 }
 else if(a>=10000&&a<=99999)
 {
  return 5;
 }
 else if(a>=100000&&a<=999999)
 {
  return 6;
 }
}
int main(void)
{
 int x,a[6]={19730,2460,137,77,57,1};
 scanf("%d",&x);
 printf("%d",a[NumDigits(x)-1]);


 return 0;
}
