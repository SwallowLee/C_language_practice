# include<stdio.h>
# include<stdlib.h>
# include<ctype.h>
struct string
{
    char alpha[150];
    struct string *next;
};
struct string *add(struct string *list,char ch[150])
{
    struct string *node;
    node=malloc(sizeof(struct string));
    strcpy(node->alpha,ch);
    node->next=list;
    return node;
}
int main(int argc,char *argv[])
{
    int i,j,num,exist=0,m=0;
    char filename[1000],ch[150];
    struct string *first=NULL,*cur;
    printf("How many files would you input: ");
    scanf("%d",&num);
    FILE *fp[num];
    for(i=0;i<num;i++)
    {
        printf("Please input file path: ");
        scanf("%s",&filename);
        fp[i]=fopen(filename,"r");
        if (fp[i] == NULL)
	        printf("Can't open %s\n", filename);
            while(1)
            {
                if (feof(fp[i]))
                {
                    fclose(fp[i]);
                    break;
                }
                fscanf(fp[i],"%s",&ch);
                for(j=0;ch[j]!='\0';j++)
                {
                    ch[j] = toupper(ch[j]);
                }
                for(cur=first;cur!=NULL;cur=cur->next)
                {
                    if(strcmp(cur->alpha,ch)==0)
                    {
                        exist=1;
                        break;
                    }
                }
                if(exist==0)
                {
                    first=add(first,ch);
                    m++;
                }
                else
                    exist=0;
            }
    }
    printf("There are %d different string in those files.",m);

    return 0;
}
