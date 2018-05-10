# include<stdio.h>
struct number
{
    int num;
    struct number *next;
};
struct number *add(struct number *list,int num)
{
    struct number *node;
    node=malloc(sizeof(struct number));
    node->num=num;
    node->next=list;
    return node;
}
int good_num(long long int num)
{
    struct number *first=NULL,*cur;
    int n,good=0;
    while(num>0)
    {
        n=num%1000;
        num=num/10;
        for(cur=first;cur!=NULL;cur=cur->next)
        {
            if(cur->num==n)
            {
        //        printf("%d\n",n);
                good=0;
                break;
            }
            else
                good=1;
        }
        if(good=1)
        {
            first=add(first,n);
        }
    }
    return good;
}
int ugly_num(long long int num)//lab4 2
{
    int two=0,three=0,five=0,number=0,wrong=1;
    long long int i,j;
    int a;
  //  printf("%d\n",num);
    while(num%2==0)
        num=num/2;
    while(num%3==0)
        num=num/3;
    while(num%5==0)
        num=num/5;
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

            if(i!=3&&i!=2&&i!=5)
            {
               wrong=0;
            //   printf("%d",i);
                break;
            }
        }
//        printf("%d\n",i);
    }
    /*if(number!=3)
        wrong=0;*/
    return wrong;
}
int main (void)
{
    int one=0,two=0,three=0,num=0,bad=0,good=0,ugly=0;
    long long int n=0;
    struct number *first=NULL;
    char ch;
    while(1)
    {
        printf("Enter an integer >=1:");
        scanf("%c",&ch);
        while(ch!='/n')
        {
            if(ch=='1'&&one==0)
            {
                one=1;
                num++;
            }
            if(ch=='5'&&two==0)
            {
                two=1;
                num++;
            }
            if(ch=='3'&&three==0)
            {
                three=1;
                num++;
            }
            if(num==3&&one==1&&two==1&&three==1)
                bad=1;
            if(ch!='\n')
                n=n*10+ch-'0';
            else
                break;
           // printf("%d\n",n);
            scanf("%c",&ch);
        }
        good=good_num(n);
        ugly=ugly_num(n);
        if(good==0)
            printf("Not Good, ");
        else
            printf("Good, ");
        if(bad==0)
            printf("Not Bad, ");
        else
            printf("Bad, ");
        if(ugly==0)
            printf("Not Ugly\n");
        else
            printf("Ugly\n");
        n=0;
        num=0;
        bad=0;
        one=0;
        two=0;
        three=0;
    }
    return 0;
}
