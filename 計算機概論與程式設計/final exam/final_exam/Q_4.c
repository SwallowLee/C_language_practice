# include<stdio.h>
# include<stdlib.h>
# include<string.h>
struct word
{
    char words[100];
    struct word *next;
};
struct word *add(struct word *list,char name[150])
{
    struct word *node;
    node=malloc(sizeof(struct word));
    strcpy(node->words,name);
    node->next=list;
    return node;
};

int main(void)
{
    FILE *fp;
    struct word *first=NULL,*cur;
    int i=0;
    char name[300];
    pritnf("Please enter the filename of the compressed paragraph: ");
    scanf("%s",&name);
    fp=fopen(name,"r");
    while(!feof(fp))
    {
        fscanf("%s",&name);
        for(cur=first;cur!=NULL;cur=cur->next)
        {
            if(strcmp(cur->words,name)==0)

        }
        first=add(first,name);
    }

}
