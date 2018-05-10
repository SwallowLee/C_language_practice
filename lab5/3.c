# include <stdio.h>

int main(void)
{
 int sum,i,j,k;
 char ch;
 sum=0;
 i=1;
 k=0;
 printf("please input text:");
 ch=getchar();
 for(;ch!='\n';)
 {
     if((ch>='0')&&(ch<='9'))
     {
         k=k+(ch-'0');
         ch=getchar();
         for(;ch>='0'&&ch<='9'&&ch!='\n';)
         {
            k=k*10+(ch-'0');
              ch=getchar();
         }
     }
     sum=sum+k;
     if(ch!='\n')
       ch=getchar();
     k=0;
 }
 printf("Number sum of this text is %d.",sum);

 return 0;
}
