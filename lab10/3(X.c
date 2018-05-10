# include<stdio.h>

void find(char *pok,char *fir);

int main(void)
{
    char i,ch,first,ten,poker[55];
    printf("Please input cards on the board: ");
    for(i=0;ch!='\n';i++)
    {
        scanf("%c",ch);
        if(ch!=' ')
            poker[i]=ch;
        else
            i--;
    }
    printf("Please input the first card: ");
    scanf("%c",first);
    printf("The Best Sequence(length %d): %s");
    return 0;
}


