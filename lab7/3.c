# include<stdio.h>

int main(void)
{
 int height,width,row,column,i,j;
 printf("Please input the height and width: ");
 scanf("%d %d",&height,&width);
 printf("Please input bomb position(row and column): ");
 scanf("%d %d",&row,&column);
 char a[height][width];
 for(i=0;i<(height);i++)
 {
     for(j=0;j<(width);j++)
     {    if(i==0||i==height-1||j==0||j==width-1)
            a[i][j]='#';
          else if(i==row&&j==column)
            a[i][j]='O';
          else if(i+j==(row+column))
            a[i][j]='X';
          else if((i-j)==(row-column))
            a[i][j]='X';
          else
            a[i][j]=' ';
     }

 }
 if(row>=(height-1)||column>=(width-1))
    printf("Wrong bomb position!");
 else
    for(i=0;i<(height);i++)
    {    for(j=0;j<(width);j++)
        {
            printf("%c",a[i][j]);
            printf(" ");
        }
        printf("\n");
    }
 return 0;
}
