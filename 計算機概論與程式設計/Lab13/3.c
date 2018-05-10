# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct number
{
    int num;
    struct number *next;
    struct number *prev;
};

struct number *add(struct number *list,int add_num)
{
    struct number *new_node;
    new_node=malloc(sizeof(struct number));
    new_node->num=add_num;
    new_node->next=list;
    return new_node;
}

struct number *decrease(struct number *first)
{
    struct number *dele,*cur,*new_list=NULL,*another=NULL;
    int i=0;
    for(cur=first;cur!=NULL;cur=cur->next)
    {
        i++;
        first=add(first,cur->num);
    }
    dele=first;
    first=dele->next;
    free(dele);
    for(cur=first;cur!=NULL;cur=cur->next)
    {
        i--;
        if(i>0)
            another=add(another,cur->num);
    }
    return another;
}

int main(void)
{
    struct number *front,*rear=NULL,*cur;
    int num,i,m=0;
    front=rear;
    printf("input:");
    scanf("%d",&num);
    for(i=1;num!=0;i++)
    {
        if(num==-1)
        {
            if(front==rear)
            {
                printf("queue is underflow.\n");
                break;
            }
            else
                {
                    front=decrease(front);
                    i--;
                }
        }
        else if(i>5)
        {
            printf("queue is full.\n");
            break;
        }
        else
        {
            front=add(front,num);
            /*if(i==1)
            {
                front=rear;
                front->next=rear->next;
            }
            rear=rear->next;*/
        }
        printf("input:");
        scanf("%d",&num);
    }
    for(cur=front;cur!=NULL;cur=cur->next)
    {
        rear=add(rear,cur->num);
    }
    for(cur=rear;cur!=NULL;cur=cur->next)
    {
        printf("%-6d",cur->num);
    }
    return 0;
}
