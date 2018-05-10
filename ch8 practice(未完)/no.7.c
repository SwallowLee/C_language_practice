# include<stdio.h>

int main(void)
{
  int a[5][5],i,j,num,row[5]={0},column[5]={0};
  for(i=0;i<5;i++)
  {
      printf("Enter row %d: ",(i+1));
      for(j=0;j<5;j++)
      {
          scanf("%d",&a[i][j]);
      }
  }
  printf("\nRow totals: ");
  for(i=0;i<5;i++)
  {
      for(j=0;j<5;j++)
      {
          row[i]=row[i]+a[i][j];
          column[j]=column[j]+a[i][j];
      }
      printf("%d ",row[i]);
  }
  printf("\nColumn totals: ");
  for(i=0;i<5;i++)
  {
      printf("%d ",column[i]);
  }
  return 0;
}
