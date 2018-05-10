# include<stdio.h>

int num,size,seq[10][10];

void cal(int se_num,int se_size);

int main(void)
{
    int i,j;
    printf("sequence number:");
    scanf("%d",&num);
    printf("sequence size:");
    scanf("%d",&size);
    for(i=0;i<num;i++)
        for(j=0;j<size;j++)
            scanf("%d",&seq[i][j]);
    printf("*****************************\n");
    for(i=0;i<num;i++)
    {
        for(j=0;j<size;j++)
        {
            cal(i,j);
        }
        printf("*****************************\n");
    }
    return 0;
}

void cal(int se_num,int se_size)
{

}
