# include<stdio.h>
int len[20],s1[20],s2[20],s3[20];
void sort(int num);
int max(int num);
int min(int num);
int main(void)
{
    int j,i,k,m=0,n,yes,num;
    scanf("%d",&num);
    for(i=0;i<num;i++)
        scanf("%d",&len[i]);
    sort(num);
    for(i=0;i<num;i++)
    {
        for(j=i+1;j<num;j++)
        {
            for(k=j+1;k<num;k++)
                if(len[i]+len[j]>len[k])
                {
                    yes=0;
                    for(n=0;n<m;n++)
                    {
                        if(len[i]==s1[n]&&len[j]==s2[n]&&len[k]==s3[n])
                        {
                            yes=1;
                            break;
                        }
                    }
                    if(yes==0)
                    {
                        s1[m]=len[i];
                        s2[m]=len[j];
                        s3[m]=len[k];
                        m++;
                        printf("%d,%d,%d\n",len[i],len[j],len[k]);
                    }
                }
        }
    }
    printf("total:%d\n",m);
    m=max(m);
    printf("max:%d,%d,%d\n",s1[m],s2[m],s3[m]);
    m=min(m);
    printf("min:%d,%d,%d",s1[m],s2[m],s3[m]);
}

void sort(num)
{
    int i,j,re;
    for(i=0;i<num;i++)
        for(j=i+1;j<num;j++)
        {
            if(len[i]>len[j])
            {
                re=len[i];
                len[i]=len[j];
                len[j]=re;
            }
        }
}

int max(num)
{
    int area1,area2,i,m=0;
    float len1,len2;
    len1=(float)(s1[0]+s2[0]+s3[0])/2;
    area1=len1*(len1-s1[0])*(len1-s2[0])*(len1-s3[0]);
    for(i=1;i<num;i++)
    {
        len2=(float)(s1[i]+s2[i]+s3[i])/2;
        area2=len2*(len2-s1[i])*(len2-s2[i])*(len2-s3[i]);
        if(area2>area1)
        {
            area1=area2;
            m=i;
        }
    }
    return m;
}

int min(num)
{
    int area1,area2,i,m=0;
    float len1,len2;
    len1=(float)(s1[0]+s2[0]+s3[0])/2;
    area1=len1*(len1-s1[0])*(len1-s2[0])*(len1-s3[0]);
    for(i=1;i<num;i++)
    {
        len2=(float)(s1[i]+s2[i]+s3[i])/2;
        area2=len2*(len2-s1[i])*(len2-s2[i])*(len2-s3[i]);
        if(area2<area1)
        {
            area1=area2;
            m=i;
        }
    }
    return m;
}
