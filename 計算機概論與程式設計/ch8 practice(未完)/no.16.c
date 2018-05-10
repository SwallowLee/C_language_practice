# include<stdio.h>
# include<ctype.h>

int main(void)
{
    int i=0,k=0,j,no=0,num[26]={0};
    char ch,word[100],se_word[100];
    printf("Enter first word: ");
    scanf("%c",&ch);
    while(ch!='\n')
    {
        tolower(ch);
        for(j=0;j<26;j++)
        {
            if(ch-'a'==j)
            {
                num[j]++;
             }
        }
        i++;
        scanf("%c",&ch);
    }
    printf("Enter second word: ");
    scanf("%c",&ch);
    while(ch!='\n')
    {
        tolower(ch);
        for(j=0;j<26;j++)
        {
            if(ch-'a'==j)
            {
                num[j]--;
            }
        }
        k++;
        scanf("%c",&ch);
    }
    for(j=0;j<26;j++)
    {
        if(num[j]!=0)
        {
            no=1;
            break;
        }
    }
    if(no==1)
        printf("The words are not anagrams.");
    else
        printf("The words are anagrams.");
    return 0;
}
