#include<stdio.h>

int main(void)
{
    int num,i,j,x,y;
    char a[5][5];
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            a[i][j]='0';
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d,%d",&x,&y);
        if(x<0||x>=5||y<0||y>=5)
        {
            printf("wrong input, try again.\n");
            i=i-1;
        }
        else if(x>=1&&y>=1&&x<4&&y<4)
        {
            a[x][y]='x';
            if(a[x+1][y]!='x')
                a[x+1][y]=a[x+1][y]+1;
            if(a[x+1][y+1]!='x')
                a[x+1][y+1]=a[x+1][y+1]+1;
            if(a[x+1][y-1]!='x')
                a[x+1][y-1]=a[x+1][y-1]+1;
            if(a[x][y+1]!='x')
                a[x][y+1]=a[x][y+1]+1;
            if(a[x][y-1]!='x')
                a[x][y-1]=a[x][y-1]+1;
            if(a[x-1][y+1]!='x')
                a[x-1][y+1]=a[x-1][y+1]+1;
            if(a[x-1][y]!='x')
                a[x-1][y]=a[x-1][y]+1;
            if(a[x-1][y-1]!='x')
                a[x-1][y-1]=a[x-1][y-1]+1;
        }
        else if(y<1&&x>=1)
        {
            a[x][y]='x';
            if(a[x-1][y+1]!='x')
                a[x-1][y+1]=a[x-1][y+1]+1;
            if(a[x-1][y]!='x')
                a[x-1][y]=a[x-1][y]+1;
            if(a[x][y+1]!='x')
                a[x][y+1]=a[x][y+1]+1;
            if(a[x+1][y]!='x')
                a[x+1][y]=a[x+1][y]+1;
            if(a[x+1][y+1]!='x')
                a[x+1][y+1]=a[x+1][y+1]+1;
        }
        else if(y>=1&&x<1)
        {
            a[x][y]='x';
            if(a[x+1][y]!='x')
                a[x+1][y]=a[x+1][y]+1;
            if(a[x+1][y+1]!='x')
                a[x+1][y+1]=a[x+1][y+1]+1;
            if(a[x+1][y-1]!='x')
                a[x+1][y-1]=a[x+1][y-1]+1;
            if(a[x][y+1]!='x')
                a[x][y+1]=a[x][y+1]+1;
            if(a[x][y-1]!='x')
                a[x][y-1]=a[x][y-1]+1;
        }
        else if(y==0&&x==0)
        {
             a[x][y]='x';
             if(a[x+1][y]!='x')
                 a[x+1][y]=a[x+1][y]+1;
             if(a[x+1][y+1]!='x')
                 a[x+1][y+1]=a[x+1][y+1]+1;
             if(a[x][y+1]!='x')
                 a[x][y+1]=a[x][y+1]+1;
        }
        else if(x==4&&y<4)
        {
            a[x][y]='x';
            if(a[x][y+1]!='x')
                a[x][y+1]=a[x][y+1]+1;
            if(a[x][y-1]!='x')
                a[x][y-1]=a[x][y-1]+1;
            if(a[x-1][y+1]!='x')
                a[x-1][y+1]=a[x-1][y+1]+1;
            if(a[x-1][y]!='x')
                a[x-1][y]=a[x-1][y]+1;
            if(a[x-1][y-1]!='x')
                a[x-1][y-1]=a[x-1][y-1]+1;
        }
        else if(x<4&&y==4)
        {
            a[x][y]='x';
            if(a[x+1][y]!='x')
                a[x+1][y]=a[x+1][y]+1;
            if(a[x+1][y-1]!='x')
                a[x+1][y-1]=a[x+1][y-1]+1;
            if(a[x][y-1]!='x')
                a[x][y-1]=a[x][y-1]+1;
            if(a[x-1][y]!='x')
                a[x-1][y]=a[x-1][y]+1;
            if(a[x-1][y-1]!='x')
                a[x-1][y-1]=a[x-1][y-1]+1;
        }
        else if(x==4&&y==4)
        {
            a[x][y]='x';
            if(a[x][y-1]!='x')
                a[x][y-1]=a[x][y-1]+1;
            if(a[x-1][y]!='x')
                a[x-1][y]=a[x-1][y]+1;
            if(a[x-1][y-1]!='x')
                a[x-1][y-1]=a[x-1][y-1]+1;
        }

    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%c  ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
