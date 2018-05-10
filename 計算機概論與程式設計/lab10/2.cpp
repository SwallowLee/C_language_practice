# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# include<time.h>


int main(void)
{
	int i,k=0,m=0,j=0,b,sum1=0,sum2=0;
	char ch,flower[11],num[11],ans1='y',ans2='y';
	char pla1_num[11],pla1_flow[11],pla2_num[11],pla2_flow[11];
	srand(time(NULL));
	for(i=0;i<10;i++)
	{
		ch=rand()%4+3;
		flower[i]=ch;
		ch=rand()%13+49;
		//printf("%c\n\n",a);
		num[i]=ch;
		if(ch=='1')
        {
            num[i]='A';
        }
        if(ch=='9'+1)
        {
            num[i]='0';
        }
        if(ch=='9'+2)
        {
            num[i]='J';
        }
        if(ch=='9'+3)
        {
            num[i]='Q';
        }
        if(ch=='9'+4)
        {
            num[i]='K';
        }
        printf("%c",flower[i]);
        if(num[i]!='0')
            printf("%c,",num[i]);
        else printf("10,");
    }
    printf("\n");
    if(num[j]=='0'||num[j]=='J'||num[j]=='Q'||num[j]=='K')
        sum1=sum1+10;
    else if(num[j]=='A')
        sum1=sum1+1;
    else
        sum1=sum1+num[j]-'0';
    pla1_flow[k]=flower[j];
    pla1_num[k]=num[j];
    k++;
    j++;
    if(num[j]=='0'||num[j]=='J'||num[j]=='Q'||num[j]=='K')
        sum2=sum2+10;
    else if(num[j]=='A')
        sum2=sum2+1;
    else
        sum2=sum2+num[j]-'0';
    pla2_flow[m]=flower[j];
    pla2_num[m]=num[j];
    m++;
    j++;
    while((ans1!='n'||ans2!='n')&&sum1<21&&sum2<21)
    {
        printf("player1 ,do you want a HIT?");
        scanf(" %c",&ans1);
        if(ans1=='y')
        {
            pla1_flow[k]=flower[j];
            pla1_num[k]=num[j];
            k++;
            if(num[j]=='0'||num[j]=='J'||num[j]=='Q'||num[j]=='K')
               sum1=sum1+10;
            else if(num[j]=='A')
               sum1=sum1+1;
            else
                sum1=sum1+num[j]-'0';
            j++;
        }
        if(ans1=='n')
            printf("Player 1 pass.\n");
        printf("player2 ,do you want a HIT?");
        scanf(" %c",&ans2);
        if(ans2=='y')
        {
            pla2_flow[m]=flower[j];
            pla2_num[m]=num[j];
            m++;
            if(num[j]=='0'||num[j]=='J'||num[j]=='Q'||num[j]=='K')
                sum2=sum2+10;
            else if(num[j]=='A')
                sum2=sum2+1;
            else
                sum2=sum2+num[j]-'0';
            j++;
        }
        if(ans2=='n')
            printf("Player 2 pass.\n");
       // printf("1 %d  2 %d",sum1,sum2);
    }
    if(sum1>sum2&&sum1<=21)
        printf("Result:\n\nplayer 1 wins!!!\n\n");
    else if(sum1<sum2&&sum2<=21)
        printf("Result:\n\nplayer 2 wins!!!\n\n");
    else if(sum1>sum2&&sum1>21&&sum2<=21)
        printf("Result:\n\nplayer 2 wins!!!\n\n");
    else if(sum1<sum2&&sum2>21&&sum1<=21)
        printf("Result:\n\nplayer 1 wins!!!\n\n");
    else if(sum1==sum2||(sum1>21&&sum2>21))
        printf("Result:\n\ntie!!!\n\n");
    printf("Player1:\n");
    for(i=0;i<k;i++)
    {
        printf("%c",pla1_flow[i]);
        if(pla1_num[i]!='0')
            printf("%c,",pla1_num[i]);
        else
            printf("10,");
    }
    printf("SUM =%d\n\n",sum1);
    printf("Player2:\n");
    for(i=0;i<m;i++)
    {
        printf("%c",pla2_flow[i]);
        if(pla2_num[i]!='0')
            printf("%c,",pla2_num[i]);
        else
            printf("10,");
    }
    printf("SUM =%d",sum2);
	return 0;
}
