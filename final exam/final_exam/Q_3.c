# include<stdio.h>
# include<stdlib.h>
# include<string.h>

struct student
{
    char name[150];
    float aver;
    struct student *next;
};
struct student *add_stud(struct classlist *list,char name[150],float aver)
{
    struct student *node;
    node=malloc(sizeof(struct student));
    strcpy(node->name,name);
    node->aver=aver;
    node->next=list;
    return node;
}

struct classlist
{
    char classname[150];
    float aver;
    struct classlist *next;
};
struct classlist *add(struct classlist *list,char name[150])
{
    struct classlist *node;
    node=malloc(sizeof(struct classlist));
    strcpy(node->classname,name);
    node->next=list;
    return node;
}

int main(void)
{
    struct classlist *first=NULL,*cur,*prev;
    struct student *node=NULL,*now,*now_prev;
    FILE *fp;
    int stud_num,score_num,i,j;
    char class_list[300],name[150],ch;
    printf("Please input class list path:");
    scanf("%s",&class_list);
    ch=getchar;
    fp=fopen(class_list,"r");
    if(fp==NULL)
        printf("Can't open the file!");
    while(!feof(fp))
    {
        fscanf(fp,"%s",&name);
        first=add(first,name);
    }
    fclose(fp);
    //count the average
    for(cur=first;cur!=NULL;cur=cur->next)
    {
        float class_aver=0;
        char name[100];
        FILE *fp;
        strcpy(name,cur->classname);
        for(i=0;name[i]!='\0';i++);
        name[i]='.';
        name[i+1]='t';
        name[i+2]='x';
        name[i+3]='t';
        name[i+4]='\0';
        fp=fopen(name,"r");
        if(fp==NULL)
            printf("Can't open the file!");
        fscanf(fp,"%d",&stud_num);
        fscanf(fp,"%d",&score_num);
        for(i=0;i<stud_num;i++)
        {
            char stu_nam[150];
            float stud_aver=0;
            fscanf(fp,"%s",&stu_nam);
            for(j=0;j<score_num;j++)
            {
                int stud_score;
                fscanf(fp,"%d",&stud_score);
                stud_aver=stud_aver+stud_score;
            }
            stud_aver=(float )stud_aver/score_num;
            class_aver=class_aver+stud_aver;
            node=add_stud(node,stu_nam,stud_aver);
        }
        class_aver=(float )class_aver/stud_num;
        cur->aver=class_aver;
        fclose(fp);
    }
    //compare best student
    char best_stud[150];
    float best_stud_aver;
    for(now=node,now_prev=NULL;now!=NULL;now_prev=now,now=now->next)
    {
        if(now_prev!=NULL)
            if(now_prev->aver>now->aver)
            {
                best_stud_aver=now_prev->aver;
                strcpy(best_stud,now_prev->name);
            }
            else
            {
                best_stud_aver=now->aver;
                strcpy(best_stud,now->name);
            }
    }
    printf("Best student: %s\n",best_stud);
    printf("Best student average score: %.2f\n",best_stud_aver);
    //compare best class
    char best_class[150];
    float best_class_aver;
    for(cur=first,prev=NULL;cur!=NULL;prev=cur,cur=cur->next)
    {
        if(prev!=NULL)
            if(prev->aver>cur->aver)
            {
                best_class_aver=prev->aver;
                strcpy(best_class,prev->classname);
            }
            else
            {
                best_class_aver=cur->aver;
                strcpy(best_class,cur->classname);
            }
    }
    printf("Best class: %s\n",best_class);
    printf("Best class average score: %.2f",best_class_aver);
    return 0;
}
