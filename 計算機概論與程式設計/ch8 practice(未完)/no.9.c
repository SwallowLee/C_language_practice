# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <stdbool.h>

int main(void)
{
  bool exist[10][10];
  int direct,i=0,j=0,k,l,yes[4]={0,0,0,0};
  char alpha,a[10][10];
  for(k=0;k<10;k++)//initialize arrays a to be ','
  {
      for(l=0;l<10;l++)
        a[k][l]='.';
  }
  for(k=0;k<10;k++)//initialize array exist to be false
  {
      for(l=0;l<10;l++)
      {
        exist[k][l]=false;
      }
  }

  alpha='A';
  srand(/*(unsigned)*/time(NULL));
  a[0][0]='A';
  exist[0][0]=true;
  while(alpha<'Z')
  {
    direct=rand()%4;
    switch(direct)/*0:right 1:left 2:down 3:up*/
    {
      case 0:if((j+1)<10)
             {
                 if(exist[i][j+1])
                 {
                         yes[0]=1;
                     break;
                 }
                 else if(!exist[i][j+1])
                 {
                     alpha++;
                     j=j+1;
                     a[i][j]=alpha;
                     exist[i][j]=true;
                     yes[0]=0;
                     break;
                 }
             }
             else
             {
                 yes[1]=1;
                 break;
             }
      case 1:if((j-1)<10&&(j-1)>=0)
             {
                 if(exist[i][j-1])
                 {
                     yes[1]=1;
                     break;
                 }
                 else if(!exist[i][j-1])
                 {
                     alpha++;
                     j=j-1;
                     a[i][j]=alpha;
                     exist[i][j]=true;
                     yes[1]=0;
                     break;
                 }
             }
             else
             {
                 yes[1]=1;
                 break;
             }
      case 2:if((i+1)<10)
             {
                 if(exist[i+1][j])
                 {
                     yes[2]=1;
                     break;
                 }
                 else if(!exist[i+1][j])
                 {
                     alpha++;
                     i=i+1;
                     a[i][j]=alpha;
                     exist[i][j]=true;
                     yes[2]=0;
                     break;
                 }
             }
             else
             {
                 yes[1]=1;
                 break;
             }
      case 3:if((i-1)<10&&(i-1)>=0)
             {
                 if(exist[i-1][j])
                 {
                     yes[3]=1;
                     break;

                 }
                 else if(!exist[i-1][j])
                 {
                     alpha++;
                     i=i-1;
                     a[i][j]=alpha;
                     exist[i][j]=true;
                     yes[3]=0;
                     break;
                 }
             }
             else
             {
                 yes[1]=1;
                 break;
             }
    }
    if(yes[0]==1&&yes[1]==1&&yes[2]==1&&yes[3]==1)
        break;
  }
  for(k=0;k<10;k++)
  {
      for(l=0;l<10;l++)
      {
          printf("%c ",a[k][l]);
      }
      printf("\n");
  }
  return 0;
}
