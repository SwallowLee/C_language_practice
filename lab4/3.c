# include <stdio.h>

int main(void)
{
int num,i,j,sum1,sum2,a;
for(;;)
{
  printf("Enter an integer >=0: ");
  scanf("%d",&num);
  i=1;
  sum1=num;
  printf("%d",num);
  for(i=2,j=10;j<=num;i++,j=j*10)
  {
    if(i%2==0)
    {
     sum1=sum1-(num-num%j)/j;
     printf(" - %d",(num-num%j)/j);
    }
    else
    {
     sum1=sum1+(num-num%j)/j;
     printf(" + %d",(num-num%j)/j);
    }
  }
  printf(" = %d \n",sum1);
  for(a=10;a<num;a=a*10){}
  if(num==a)
  {
      printf("%d",num/a);
      sum2=num/a;
      for(j=a/10;j>=1;j=j/10)
      {
          sum2=sum2+num/j;
          printf(" + %d",num/j);
      }
      printf(" = %d \n",sum2);
  }
  else
  {
      printf("%d",num/(a/10));
      sum2=num/(a/10);
      for(j=a/100;j>=1;j=j/10)
      {
          sum2=sum2+num/j;
          printf(" + %d",num/j);
      }
      printf(" = %d \n",sum2);
  }
}
return 0;
}
