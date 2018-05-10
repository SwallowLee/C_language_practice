# include<stdio.h>

int main(void)
{
    int i,sum,j,k;
    char hr[3],min[6],ch;
    printf("Enter a 12-hour time: ");
    ch=getchar();
    hr[0]=ch;
    i=1;
    while(ch!=':')
    {
        ch=getchar();
        hr[i]=ch;
        i++;
    }
    ch=getchar();
    min[0]=ch;
    j=1;
    while(ch!='\n')
    {
        ch=getchar();
        min[j]=ch;
        j++;
    }
    if(min[2]=='p'||min[2]=='P'||min[3]=='p'||min[3]=='P')
    {
        if(i==2)
        {
            if(hr[0]+2>'9')
            {
                hr[1]=hr[0]+2-10;
                hr[0]='2';
            }
            else
            {   hr[1]=hr[0]+2;
                hr[0]='1';
            }
            hr[2]=':';
        }
        else
        {
            sum=hr[0]*100+hr[1];
            sum=sum+102;
            hr[0]=sum/100;
            hr[1]=sum%100;
        }
    }
    for(k=0;k<3;k++)
        printf("%c",hr[k]);
    for(k=0;k<2;k++)
        printf("%c",min[k]);

    return 0;
}
