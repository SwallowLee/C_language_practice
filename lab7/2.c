# include<stdio.h>

int main(void)
{
 int p,n,m,l,j,i,N,K,A;
 printf("(N,K,A)=");
 scanf("%d,%d,%d",&N,&K,&A);
 int kill[N],people[N];
 for(i=0;i<N;i++)
 {
     people[i]=i+1;
     kill[i]=0;
 }
 j=0;
 m=0;
 for(n=0;kill[N-1]==0;)
 {
     if(people[n]!=0)
     {
         j++;
         if(j%K==0)//if it's time to kill,put the number of people into kill
         {
             kill[m]=people[n];
             m++;
             people[n]=0;
         }
     }
     if(n==N-1)//to write a circle,if i=end,i++=begin
     {
         for(n=0;n<N-m;n++)
         {
             if(people[n]!=0)
             {
                 break;
             }
         }
     }
     else n++;
 }
 for(;A>0;A--)
 {
     printf("last %d die is %d\n",A,kill[N-A]);
 }
 return 0;
}
