# include<stdio.h>

int main(void)
{
    int sum=0,num;
    while(1)
    {
    scanf("%d",&num);
    while(num!=0)
    {
        sum=sum+num;
        //printf("%d %d",sum,num);
        scanf("%d",&num);
    }
    printf("The summation is %d\n\n",sum);
    sum=0;
    }
return 0;
}
