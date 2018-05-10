# include<stdio.h>
# include<stdlib.h>
# include<string.h>
struct word_list
{
    char alpha[30];
    struct word_list *next;
};
struct sentence
{
    char word[30];
    struct sentence *next;
};
struct reverse
{
    char word[30];
    struct reverse *next;
};
struct word_list *add(struct word_list *list,char word[100])
{
    struct word_list *new_node;
    new_node=malloc(sizeof(struct word_list));
    strcpy(new_node->alpha,word);
    new_node->next=list;
    return new_node;
}
struct sentence *add_word(struct sentence *list,char word[100])
{
    struct sentence *new_node;
    new_node=malloc(sizeof(struct sentence));
    strcpy(new_node->word,word);
    new_node->next=list;
    return new_node;
}
struct reverse *reverse_word(struct reverse *list,char word[100])
{
    struct reverse *new_node;
    new_node=malloc(sizeof(struct reverse));
    strcpy(new_node->word,word);
    new_node->next=list;
    return new_node;
}
int main(void)
{
    int i=0,j=0,k=0,p=0,m=0,number[300];
    char ch,word[100]={'\0'},num[2];
    struct word_list *first=NULL,*last,*cur;
    struct sentence *node=NULL,*now=NULL,*pre;
    struct reverse *re=NULL,*next_re;
    num[0]='0';
    printf("===========Input Paragraph===========\n");
    ch=getchar();
    while(ch!=0)
    {
        if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
        {
            word[i]=ch;
            i++;
        }
        else
        {
            if(word[0]!='\0')
            {
                p=0;
                for(last=NULL,cur=first;cur!=NULL;last=cur,cur=cur->next)
                {
                    j++;
                    if(strcmp(word,cur->alpha)==0)
                    {
                        if(last==NULL)
                            first=first->next;
                        else
                            last->next=cur->next;
                        free(cur);
                        first=add(first,word);
                        number[m]=j;
                        node=add_word(node,word);
                        m++;
                        j=0;
                        p=1;
                        break;
                    }
                }
                if(p==0)
                {
                    first=add(first,word);
                    node=add_word(node,word);
                    number[m]=0;
                    m++;
                    j=0;
                }
                for(k=0;k<i;k++)
                {
                    word[k]='\0';
                }
                word[0]=ch;
                node=add_word(node,word);
                number[m]=0;
                m++;
                i=0;
                word[0]='\0';
            }
            else
            {
                if(ch=='0')
                    break;
                word[0]=ch;
                node=add_word(node,word);
                number[m]=0;
                m++;
                word[0]='\0';
            }
        }
        ch=getchar();
    }
    printf("\n\n===========Output Paragraph===========\n");
    i=0;
    for(now=node;now!=NULL;now=now->next)
    {
        re=reverse_word(re,now->word);
    }
    for(next_re=re;next_re!=NULL;next_re=next_re->next)
    {
        if(number[i]!=0)
        {
            printf("%d",number[i]);
        }
        else
            printf("%s",next_re->word);
        i++;
    }
    system("pause");
    return 0;
}
