# include <stdio.h>

int main (void)
{
long int num,i,j,k,r,l,a,b,c,d;
printf("Please input a number: ");
scanf("%d",&num);
for(i=2;i<=num;i++)
{
    a=0;
    if(num%i==0)
        for(j=2;j<i;j++)
        {
            if(i%j==0)
                a=1;
        }
    else a=1;
    if(a==0)
    {
        b=0;
        for(k=i;k<=num;k=k*i)
        {
            if(num%k==0)
                b=b+1;
        }
        for(r=num;r>=2;r--)
        {
            c=0;
            if(num%r==0)
               for(l=2;l<r;l++)
               {
                   if(r%l==0)
                      c=1;
               }
            else c=1;
            if(c==0)break;
        }
        if(b>1&&i!=r)
            printf("%d ^ %d * ",i,b);
        else if(b>1&&i==r)
            printf("%d ^ %d ",i,b);
        else if(i!=r)
            printf("%d * ",i);
        else printf("%d ",i);
    }
}

return 0;
}
