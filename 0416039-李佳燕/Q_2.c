# include <stdio.h>

int main(void)
{
int x1,x2,x3,a;
printf("Enter three value(x,x,x): ");
scanf("%d,%d,%d",&x1,&x2,&x3);
a=0;
if(x1>=x2&&x1>=x3&&a!=1)
  {
   if(x2>=x3)
      {printf("answer : %d , %d ,%d",x1,x2,x3);
      a=1;}
   else if(x1!=x2)
      {printf("answer : %d , %d ,%d",x1,x3,x2);
      a=1;}
  }
if(x2>=x1&&x2>=x3&&a!=1)
  {
  if(x1>=x3)
     {printf("answer : %d , %d ,%d",x2,x1,x3);
     a=1;}
  else if(x2!=x1)
     {printf("answer : %d , %d ,%d",x2,x3,x1);
     a=1;}
  }
if(x3>=x1&&x3>=x2&&a!=1)
  {
  if(x1>=x2)
     {printf("answer : %d , %d ,%d",x3,x1,x2);
     a=1;}
  else if(x3!=x1)
     {printf("answer : %d , %d ,%d",x3,x2,x1);
     a=1;}
  }
if(x1==x2&&x1==x3&&a!=1)
     printf("answer : %d , %d ,%d",x1,x2,x3);

return 0;
}
