# include <stdio.h>

int main(void)
{
 int num,a[num],i,j,k;
 scanf("%d",&num);
 for(i=0;i<num;i=i+1)
 {
    scanf("%d",&a[i]);
 }
 printf("\n");
 j=num-1;
 for(k=0;k<=num-1;k=k+1)
 {
    /*printf("k:%d\n",k);
    printf("j:%d\n",j);*/
    for(i=k;i<=j;i=i+1)
    {
       /*printf("i:%d\n",i);*/
       printf("%d ",a[i]);
    }
    printf("\n");
    for(i=j;i>=(k+1);i=i-1)
    {
        /*printf("i2:%d\n",i);*/
        printf("%d ",a[i]);
    }
    printf("\n");
    j=j-1;
 }
 return 0;
}
