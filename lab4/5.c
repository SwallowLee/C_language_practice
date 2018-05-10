# include <stdio.h>

int main(void)
{
 int n,i,j,a,b,c;
 printf("Please input n:");
 scanf("%d",&n);
 c=0;
 for(i=n;i<=(n+10);i++)
 {
     c=c+(2*i*(2*i+1)/2)*(2*i*(2*i+1)/2)+(2*i*(2*i+1)*(2*2*i+1)/6);
 }
 printf("c%d = %d \n",n,c);

return 0;
}
