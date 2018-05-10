# include<stdio.h>
/*int *b,*c;*/
float s1[100],s2[100],s3[100];
int a[300];
int max(int tria);
int min(int tria); 
void sort(int num);
int main(void)
{
	int i,j,k,m,num,tria=0;
	printf("The number of sticks:");
	scanf("%d",&num);
	for(i=0;i<num;i++)
		scanf("%d",&a[i]);
	sort(num);
	for(i=0;i<num-1;i++)
	    for(j=i+1;j<num;j++)
			for(k=num-1;k>j;k--)
			{
				if(a[i]+a[j]>a[k])
				{
					s1[tria]=a[i];
					s2[tria]=a[j];
					s3[tria]=a[k];
					printf("Three sides of this triangle:%0.f,%0.f,%0.f\n",s1[tria],s2[tria],s3[tria]);
					tria++;
				}    
			}
	printf("\nYou can combine %d triangles.\n",tria);
	m=max(tria);
	printf("Three sides of the Max triangle: %0.f,%0.f,%0.f\n",s1[m],s2[m],s3[m]);
    m=min(tria);
    printf("Three sides of the Min triangle: %0.f,%0.f,%0.f\n",s1[m],s2[m],s3[m]);
	return 0;
}
void sort(int num)
{
	int i,re,j;
	for(i=0;i<num;i++)
	{
		if(i<num-1)
		    for(j=i;j<num;j++)
	        {
	    	    if(a[i]>a[j])
	    	    {
	    		    re=a[i];
	    		    a[i]=a[j];
	    		    a[j]=re;
			    }
		    }
	}
}
int max(int tria)
{
	float len1,len2,a1,a2;
	int m=0,i;
	len1=(s1[0]+s2[0]+s3[0])*0.5;
	a1=len1*(len1-s1[0])*(len1-s2[0])*(len1-s3[0]);
	for(i=1;i<tria;i++)
	{
		len2=(s1[i]+s2[i]+s3[i])*0.5;
	    a2=len2*(len2-s1[i])*(len2-s2[i])*(len2-s3[i]);
	    if(a1<a2)
	    {
	    	a1=a2;
	    	m=i;
	    }
	}
	return m;
}
int min(int tria)
{
	float len1,len2,a1,a2;
	int m=0,i;
	len1=(s1[0]+s2[0]+s3[0])*0.5;
	a1=len1*(len1-s1[0])*(len1-s2[0])*(len1-s3[0]);
	for(i=1;i<tria;i++)
	{
		len2=(s1[i]+s2[i]+s3[i])*0.5;
	    a2=len2*(len2-s1[i])*(len2-s2[i])*(len2-s3[i]);
	    if(a1>a2)
	    {
	    	a1=a2;
	    	m=i;
	    }
	}
	return m;
}
