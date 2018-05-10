# include <stdio.h>
# include <ctype.h>

int main(void)
{
 int fir_cal=0,l,first=0,i,times,num=1,cal[26]={0},first_alpha[26]={0},next_alpha[26]={0},repeat[26]={0};
 char alpha,ch;
 printf("Please input texts(separate with comma):");
 i=1;
 times=0;
 ch=getchar;
 for(i=1;ch!='\n';i=i+1)
 {
    ch=toupper(ch);
    if(first==0)//統計第一個逗號前的字母
    {   for(alpha='A',num=0;alpha<='Z';alpha++,num++)
        {
            if(alpha==ch)
            {
                first_alpha[num]=1;
            }
        }
    }
    for(num=0;num<26;num++)//歸零
    {
        repeat[num]=0;
        next_alpha[num]=0;
    }
    if(ch==',')
    {
        first=1;
        times=times+1;
        ch=getchar();
        for(l=i+1;ch!=',';l++)//統計第二、三...個逗號前的字母
        {
            ch=toupper(ch);
            for(alpha='A',num=0;alpha<='Z';alpha++,num++)
            {
                if(alpha==ch) next_alpha[num]=1;
                if(first_alpha[num]==1&&next_alpha[num]==1&&repeat[num]==0)
                {
                    cal[num]=cal[num]+1;
                    repeat[num]=1;
                }
            }
            i=i+1;
            if(ch!='\n')
                ch=getchar();
            else break;
        }

    }
    if(ch!='\n'&&ch!=',')
        ch=getchar();
 }
    printf("Common Alphabets: ");//輸出
    for(alpha='A',num=0;alpha<='Z';alpha++,num++)
    {

        if(cal[num]==times&&cal[num]!=0)
        printf("%c ",alpha);
        if(next_alpha[num]==0)
            fir_cal=fir_cal+1;
    }
    if(fir_cal==26)//若沒有逗號
        for(alpha='A',num=0;alpha<='Z';alpha++,num++)
            if(first_alpha[num]==1)
               printf("%c ",alpha);

 return 0;
}
