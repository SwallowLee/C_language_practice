#include <stdio.h>
int aa[100][100];
int row,col;
int combined(int num,int r,int c,int sum,int temp)
{
    if(num==sum)
    {
        printf("(");
        while(temp!=0)
        {
            if(temp%10!=0) printf("%d,",temp%10);
            temp=temp/10;
        }
        printf("\b)\n");
        return 1;
    }
    if(c>=col) return 0;
    return	combined(num,r,c+1,sum,temp*10)+combined(num,r,c+1,sum+aa[r][c+1],temp*10+aa[r][c+1]);
}
int main()
{
    int i=0,j,k;
    printf("sequence number:");
    scanf("%d",&row);
    printf("sequence size:");
    scanf("%d",&col);
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            scanf("%d",&aa[i][j]);
    for(i=0;i<row;i++)
    {
        printf("************************************\n");
        for(k=1;k<=row;k++)
        {
            for(j=0;j<col;j++)
            {
                if(k!=i+1)
                {
                    printf("seq%d[%d]<%d> are combined by seq%d:\n",i+1,j,aa[i][j],k);
                    if(combined(aa[i][j],k-1,-1,0,0)==0) printf("None\n");
                }
            }
            if(k!=i+1)
                printf("------------------------------\n");
        }
    }
    printf("************************************\n");
return 0;

}
