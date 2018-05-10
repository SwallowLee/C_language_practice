# include<stdio.h>
# include<string.h>

int main(void)
{
    int i,j,k,m,n,num,yes,p;
    const char minor[12][5]={'a','an','the','in','on','at','of','form','for','with','to','and'};
    printf("How many words in your article title? ");
    scanf("%d",&num);
    char str[num][100];
    printf("Please input your article title: ");
    for(i=0;i<num;i++)
    {
        scanf("%s",&str[i]);
       // printf("%s\n",str[i]);
    }
    for(i=0;i<num;i++)
    {
        //p=0;
        /*if(strcmp(str[i],minor[m])==0)
            yes=5;*/
        for(k=0;k<12;k++)
        {
            p=0;
            for(n=0;str[i][n]!='\0';n++)
                    if(str[i][n]>='A'&&str[i][n]<='Z')
                        str[i][n]=str[i][n]-'A'+'a';
            //printf("~\n");
            for(m=0;minor[k][m]!='\0';m++)
                if(str[i][m]==minor[k][m])
                {
                    p=1;
                  //printf("~~%s\n",str[i]);
                }
                else p=0;
            if(p==1)
            {
                //printf("QQ");
               // printf("%s\n",str[i]);

                      //printf("! %s",str[i]);
                break;
            }
        }
        for(j=0;str[i][j]!='\0';j++)
        {
            if(str[0][0]>='a'&&str[0][0]<='z')
                str[0][0]=str[0][0]-'a'+'A';
            else if(str[i][0]>='a'&&str[i][0]<='z'&&p!=1)
            {
                str[i][0]=str[i][0]-'a'+'A';
            }
            else if(str[i][j]>='A'&&str[i][j]<='Z')
            {
               // printf("%s\n",str[i]);
                str[i][j]=str[i][j]-'A'+'a';
                //printf("~%s\n",str[i]);
            }
            //printf("%s",str[i]);
        }
    }
    printf("Formatted title: %s",str[0]);
    for(i=1;i<num;i++)
        printf(" %s",str[i]);
    return 0;
}
