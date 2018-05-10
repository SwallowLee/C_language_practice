# include<stdio.h>

int main(void)
{
	int a[5]={0,1,2,3,4},*p;
	for(p=&a[0];p<&a[5];)
	{
		if(p==&a[0]);
		{
			*(p++);
     		printf("%d %d 0 p%d a%d %d %d\n",p,*p,&a[0],&a[1],a[0],a[1]);
		}
		if(p==&a[1]);
		{
			(*p)++;
			printf("%d %d 1 p%d a%d %d %d\n",p,*p,&a[1],&a[2],a[1],a[2]);
		    *p++;
		}
		if(p==&a[2])
		{
			*(++p);
			printf("%d %d 2 p%d a%d %d %d\n",p,*p,&a[2],&a[3],a[2],a[3]);
	    }
		if(p==&a[3])
		{
			++(*p);
			printf("%d %d 3 p%d a%d %d %d\n",p,*p,&a[3],&a[4],a[3],a[4]);
		}
	  return 0;  
	}
} 
