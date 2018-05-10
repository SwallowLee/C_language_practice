# include <stdio.h>

int main(void)
{
int i,j,a,b,k,l,m,ans,num;
printf("type the answer:");
scanf("%d",&ans);
printf("What's your input number? \n");
scanf("%d",&num);
while(ans!=num)
  {
   a=0;
   b=0;
   for(i=10;i!=100000;i=i*10)
    {
      k=(num%i-num%(i/10))/(i/10);
      l=(ans%i-ans%(i/10))/(i/10);
      if(k==l)a=a+1;
      else
      {
          for(j=10;j!=100000;j=j*10)
          {
              m=(ans%j-ans%(j/10))/(j/10);
              if(k==m&&l!=m)b=b+1;
          }
      }
    }
    printf("You get the %dA%dB \n",a,b);
   printf("What's your input number? \n");
   scanf("%d",&num);
  }
printf("You win this game!!");
return 0;
}
