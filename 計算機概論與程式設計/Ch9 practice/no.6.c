# include <stdio.h>

int return_digit(int digit,int k)
{
  int i,n=0,times=1,num;
  for(i=1;digit/i>0;i=i*10)
      n=n+1;
  if(k>n)
      return 0;
  else
  {
      for(;k>0;k--)
      {
          times=times*10;
          num=digit%times-digit%(times/10);
      }
      num=num/(times/10);
      return num;
  }
}

int main(void)
{
  int digit,k;
  printf("digit");
  scanf("(%d,%d)",&digit,&k);
  printf("%d",return_digit(digit,k));
  return 0;
}
