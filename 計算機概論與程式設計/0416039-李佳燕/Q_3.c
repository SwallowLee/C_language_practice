# include <stdio.h>

int main(void)
{
int a,b;
scanf("%d",&a);
if(a>127||a<0)
   printf("Error! It is not an 8 bit unsigned integer.");
else
   {
   b=0;
   if(a>=2*2*2*2*2*2&&((((((a/2)/2)/2)/2)/2)/2)%2==1)
      b=1000000;
   if(a>=2*2*2*2*2&&(((((a/2)/2)/2)/2)/2)%2==1)
      b=b+100000;
   if(a>=2*2*2*2&&((((a/2)/2)/2)/2)%2==1)
      b=b+10000;
   if(a>=2*2*2&&(((a/2)/2)/2)%2==1)
      b=b+1000;
   if(a>=2*2&&((a/2)/2)%2==1)
      b=b+100;
   if(a>=2&&(a/2)%2==1)
      b=b+10;
   if(a<2&&a!=0)
      b=1;
   else if(a>2&&a%2==1)
      b=b+1;
   printf("%.8d",b);
   }


return 0;
}
