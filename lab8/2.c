# include<stdio.h>

char ch,string[100];
int i=0;
void word(int first);
void reverse(int first,int last);
int main(void)
{
    int j;
    printf("Please use '(' and ')' to mark reverse area, your input:\n");
    ch=getchar();
    while(ch!='\n')
    {
        if(ch!='(')
        {
            string[i]=ch;
            i++;
        }
        else
            word(i);
        if(ch!='\n')
            ch=getchar();
    }
    printf("Result:\n");
    for(j=0;j<i;j++)
        printf("%c",string[j]);
    return 0;
}
void word(int first)
{
    if(ch!='\n')
        ch=getchar();
    while(ch!=')')
    {
        if(ch=='(')
            word(i);
        else
        {
            string[i]=ch;
            i++;
        }
        ch=getchar();
    }
    reverse(first,i-1);
}
void reverse(int first,int last)
{
    int j,k=0;
    char rev[100];
    for(j=last;j>=first;j--)
    {
        rev[k]=string[j];
        k++;
    }
    k=0;
    for(j=first;j<=last;j++)
    {
        string[j]=rev[k];
        k++;
    }
}

