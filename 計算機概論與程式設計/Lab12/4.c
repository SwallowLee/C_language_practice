# include<stdio.h>
# include<stdlib.h>
# include<string.h>

typedef struct tree
{
    char name[50];
    struct tree *p1,*p2;
}tree;
tree *add(tree *addhere,char name[50])
{
    addhere=malloc(sizeof(tree));
    strcpy(addhere,name);
    addhere->p1=NULL;
    addhere->p2=NULL;
    return addhere;
}
tree *search(tree *list,char findthis[50])
{
    if(strcmp(list->name,findthis)==0)
        return list;
    else
    {
        tree *p;
        if(list->p1!=NULL)
            p=search(list->p1,findthis);
        else p=NULL;
        if(p==NULL&&list->p2!=NULL)
            p=search(list->p2,findthis);
        return p;
    }
}

void add_family(tree *list,tree *addthis)
{
    tree *p=search(list,addthis->name);
    p->p1=add(p->p1,addthis->p1->name);
    p->p2=add(p->p2,addthis->p2->name);
}

void show(tree *list,char name[50])
{
    tree *p=search(list,name);
    if(p==NULL)
    {
    	printf("Not find!");
    	return;
    }
    if(p->p1!=NULL&&p->p2!=NULL)
    {
        printf("%-8s p1:%-13s p2:%s\n",p->name,p->p1->name,p->p2->name);
        show(p->p1,p->p1->name);
        show(p->p2,p->p2->name);
    }
    else
        printf("%-8s p1:No Data       p2:No Data\n",p->name);

}

int main(void)
{
    struct tree *root,*cur,*find;
    char name[50],ch;
    printf("root name: ");
    scanf("%s",&name);
    root=add(root,name);
    while(1)
    {
        printf("name parent1 parent2: ");
        scanf("%s",&name);
        if(name[0]=='!')
            break;
        cur=add(cur,name);
        scanf("%s",&name);
        cur->p1=add(cur->p1,name);
        scanf("%s",&name);
        cur->p2=add(cur->p2,name);
        find=search(root,cur->name);
        if(find==NULL)
            printf("Not find!!\n");
        else
            add_family(root,cur);
    }
    while(1)
    {
        printf("\nshow who's ancestors: ");
        scanf("%s",&name);
        if(name[0]=='!')
            break;
        else
		    show(root,name);
    }

    return 0;
}
