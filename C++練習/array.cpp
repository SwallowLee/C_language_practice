# include<stdio.h>

void array(int a[])
{
	int i;
	for(i=0;i<5;i++)
	    a[i]=0;
}
int main(void)
{
	int i,a[5]={1,2,3,4,5};
	array(a);
	for(i=0;i<5;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
} 
