# include <stdio.h>

int main(void)
{
int num,i,j,k,m,l,sum;
printf("Enter an integer >=0: ");
scanf("%d",&num);
while(num!=-1)
{
      j=1;
      i=10;
      sum=num%i;
      printf("%d",num%i);
      for(i=100;i<=num;i=i*10)
      {
          sum=sum+num%i;
          j=j+1;
          l=0;
          printf(" + ");
          for(k=i/10;k>0;k=k/10)
          {
              if(num%i<k)
                printf("0");
          }
          /*for(k=1;k<=i;k=k*10)
          {
              if((num%i)/k!=0)l=l+1;
          }
          printf("+ ");
          for(;l<j;l=l+1)
          {
              printf("0");
          }*/
        if(num%i!=0)
          printf("%d",num%i);

      }
      sum=sum+num;
      printf(" + %d = %d \n",num,sum);
      printf("Enter an integer >=0: ");
      scanf("%d",&num);



}

return 0;
}
