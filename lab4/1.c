# include <stdio.h>

int main(void)
{
int num,i,a,b;
printf("Enter a number:");
scanf("%d",&num);
while(num!=-1)
  {
   a=1;
   b=0;
   for(i=2;i<num;i++)
   {
    if(num%i==0) b=1;
    if(num%i!=0) a=a+1;
   }
if(b==1)printf("it is a composite number.\n\n");
if(a==num-1)printf("it is a prime number. \n\n");
printf("Enter a number:");
scanf("%d",&num);
}


return 0;
}
