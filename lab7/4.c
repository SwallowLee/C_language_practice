# include <stdio.h>
# include <stdbool.h>

int CAL_I(int size,int i);

int main(void)
{
  int size,i,j,m=1;
  printf("type square_size(odd):");
  scanf("%d",&size);

  /*make the square*/
  int a[size][size];
  bool exist[size][size];
  for(i=0;i<size;i++)
  {
      for(j=0;j<size;j++)
      {
          exist[i][j]=false;
      }
  }
  for(i=size-1;m<=size*size;)
  {
      for(j=(size)/2;m<=size*size;)
        {
            a[i][j]=m;
            m++;
            exist[i][j]=true;
            if(i+1<size&&j+1<size)
            {
                if(exist[i+1][j+1]==false)
                {
                    i=i+1;
                    j=j+1;
                }
                else i=CAL_I(size,i);
            }
            else if(i+1>=size)
            {
                if(j+1>=size)
                {
                    if(exist[0][0]==false)
                    {
                        j=0;
                        i=0;
                    }
                    else i=CAL_I(size,i);
                }
                else if(exist[0][j+1]==false)
                {
                    i=0;
                    j++;
                }
                else i=CAL_I(size,i);
            }
            else if(j+1>=size)
            {
                if(i+1<size)
                {
                    if(exist[i+1][0]==false)
                    {
                        i++;
                        j=0;
                    }
                    else i=CAL_I(size,i);
                }
            }
        }
  }
  for(i=0;i<size;i++)
  {
      for(j=0;j<size;j++)
      {
          printf("%3d",a[i][j]);
      }
      printf("\n");
  }
  printf("\n");

  /*add the row,column and cross*/
  int row[size],col[size],cross[2]={0,0};
  for(i=0;i<size;i++)
  {
      row[i]=0;
      col[i]=0;
  }
  for(i=0;i<size;i++)
  {
      for(j=0;j<size;j++)
      {
          row[i]=row[i]+a[i][j];
          col[j]=col[j]+a[i][j];
          if(i==j)
            cross[0]=cross[0]+a[i][j];
          if(i+j==size-1)
            cross[1]=cross[1]+a[i][j];
      }
  }

  /*print row*/
  int fail=0,count;
  for(i=0;i<size;i++)
  {
      count=0;
      for(j=0;j<size;j++)
      {
          count=count+1;
          if(row[i]==row[0]&&count!=size)
            printf("%3d+",a[i][j]);
          else if(row[i]==row[0]&&count==size)
            printf("%3d",a[i][j]);
          else
          {
              fail=1;
              break;
          }
      }
      if(fail==0)
        printf("=%d\n",row[i]);
      if(fail==1)
      {
          printf("Validation Failed");
          return 0;
      }
  }
  printf("\n");

  /*print column*/
  for(j=0;j<size;j++)
  {
      count=0;
      for(i=0;i<size;i++)
      {
          count=count+1;
          if(col[j]==row[0]&&count!=size)
            printf("%3d+",a[i][j]);
          else if(col[j]==row[0]&&count==size)
            printf("%3d",a[i][j]);
          else
          {
              fail=1;
              break;
          }
      }
      if(fail==0)
        printf("=%d\n",col[j]);
      if(fail==1)
      {
          printf("Validation Failed");
          return 0;
      }
  }
  printf("\n");

  /*print first cross*/
  count=0;
  for(i=0;i<size;i++)
  {
      for(j=0;j<size;j++)
      {
          if(cross[0]==row[0])
              if(i==j)
              {
                  if(count!=size-1)
                  {
                      count=count+1;
                      printf("%3d+",a[i][j]);
                  }
                  else printf("%3d",a[i][j]);
              }
          else if(cross[0]!=row[0])
          {
              fail=1;
              break;
          }
      }
      if(fail==1)
      {

          printf("Validation Failed");
          return 0;
      }
  }
  if(fail==0)
        printf("=%d\n",cross[0]);

  /*print second cross*/
  count=0;
  for(i=0;i<size;i++)
  {
      for(j=0;j<size;j++)
      {
          if(cross[1]==row[0])
            if(i+j==size-1)
            {
                  if(count!=size-1)
                  {
                      count=count+1;
                      printf("%3d+",a[i][j]);
                  }
                  else printf("%3d",a[i][j]);
            }
          else if(cross[1]!=row[1])
          {
              fail=1;
              break;
          }
      }
      if(fail==1)
      {
          printf("Validation Failed");
          return 0;
      }
  }
  if(fail==0)
  {
      printf("=%d\n",cross[0]);
      printf("\nValidation Successful");
  }
  return 0;
}

int CAL_I(int size,int i)
{
    if(i-1>=0)
    {
        i=i-1;
    }
    else
        i=size-1;
    return i;
}
