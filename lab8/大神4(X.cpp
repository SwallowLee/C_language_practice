# include<stdio.h>
# define STACK 1000000
long int top=0,up=0;
int array[STACK],a[STACK],way;
void calculate(int first,int second,int time,int i);
int main(void)
{
	int num,ways,i=0;
	while(1)
	{
		printf("How many CDs are there? ");
	    scanf("%d",&num);
	    calculate(num,num,0,i);
	    i=1; 
	    printf("There are %d ways to partition these %d CDs.\n\n",way,num);

	}
}

//detemine how many ways to partition CDs
void calculate(int first,int second,int time,int i)
{
	int k;
	if(i==1)
	{
		way=0;
		i=0;
	}
	if(first==0)
	{
		for(k=0;k<time;k++)
	    {
	    	printf("%d ",array[k]);
		}    
		way++;
	    printf("\n");
	}
	for(k=first;k>0;k--)
	{
		if(k<=second)
		{
			array[time]=k;
			calculate(first-k,k,time+1,i);
		}
	}
}
	
	/*int j,k,p,q;
	static int i=0,num=0,way=0,z=0,m=second,top=0,up=0;
	if(time==1)
	{
		way=0;
		top=0;
		up=0;
		z=0;
		i=0;
	}
	array[top]=second;
	printf("top %d array %d\n",top,array[top]);
	top=top+1;
	a[up]=first;
	printf("up %d a %d\n",up,a[up]);
	up=up+1;
	if(first-second==0)
	{ 
		printf("num %d top %d\n",num,top);
		way=way+1;
		k=top;
		q=i;
		printf("arr %d arr+1 %d a %d a+1 %d",array[i],array[i+1,a[i],a[i+1]]);
		if(array[i]!=array[i+1]&&a[i]==a[i+1])
		{
			i++;
			m--;
			num=0;
		}
		if(array[top]!=1&&a[i-1]-array[i-1]>0)
		    num=array[i]-1;
		else
		    num=0;
		printf("num %d\n",num);
		printf("i~%d\n",i);
		for(p=i;p<k;p++)
		{  // printf("~~~~a%d a-arr%d ",a[p],a[p+1]+array[p]);
		    if(a[p]==a[p+1]+array[p]||p+1==k)
		    {
		    	printf("top%d p%d %d ",top,p,array[p],a[p]);
		    	//printf("first %d",first);
				//first=first+a[p];
			}
			if(array[top]!=1||a[top]-array[top]!=0)
			{
				top=top-1;
		        up=up-1;
			}
			/*top=top+num-1;
			up=up+num-1;
		}
		printf("\n"); 
	}
	if(first-second>0)
	{
		num++;
		time=0;
		calculate(first-second,second,time);
	}
	if(second-1>0)
	{
		num++;
		time=0;
		calculate(first,second-1,time);
	}
	return way; 
}*/
