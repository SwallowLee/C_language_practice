# include<stdio.h>

int main(void)
{
	int a[3][3],i,j,k=0;
	for(i=0;i<3;i++)
	    for(j=0;j<3;j++)
	    {
	    	a[i][j]=k;
	    	k++;
	    	printf("%d ",a[i][j]);
		}
	printf("yes");
	return 0;
 } 
