# include<stdio.h>

int main(void)
{
 int i,j,k,l,m,n,q,p,r,s,t;
 char ch,string[100],head[10],tail[10];
 printf("type text:");//��J�r��
 ch=getchar();
 string[0]=ch;
 for(i=1;string[i-1]!='\n';i++)
 {
    ch=getchar();
    string[i]=ch;
 }
 printf("type start:");//��J�_�l
 ch=getchar();
 head[0]=ch;
 for(j=1;head[j-1]!='\n';j++)
 {
    ch=getchar();
    head[j]=ch;
 }
 printf("type end:");//��J����
 ch=getchar();
 tail[0]=ch;
 for(k=1;tail[k-1]!='\n';k++)
 {
    ch=getchar();
    tail[k]=ch;
 }
 n=0;
 for(l=0,m=0;l<i;m=m+1)
 {
  if(string[l+m]==head[m])
       n=n+1;
  else n=0;
  if(n==j-1)//�_�l����
  {
     r=0;
     for(q=l,p=0;q<i;p++)
     {
         if(string[q+p]==tail[p])
            r=r+1;
         else r=0;
         if(r==k-1)//���ڧ���
         {
           for(s=l;s<=(q+p);s++)
           {
             printf("%c",string[s]);
           }
           printf("\n");
           r=0;
         }
         if(p==k-2)
         {
            p=-1;//�]�̫��٭n+1
            q=q+1;
         }
     }
  }
  if(m==(j-2))
  {
     l=l+1;
     m=-1;//�]�̫��٭n+1
  }
 }
 return 0;
}
