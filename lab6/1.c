# include <stdio.h>

int main(void)
{
 int j,i,k,l;
 char a[20],ch;
 i=0;
 scanf("%c",&a[0]);
 for(i=1;ch!='\n';i=i+1)
 {
    ch=getchar();
    a[i]=ch;
 }
 for(j=0;j<(i+1);j=j+1)
 {
    if((a[j]>='a'&&a[j]<='z')||(a[j]>='A'&&a[j]<='Z'))
    {
        l=j;
        for(k=(j+1);(a[k]>='a'&&a[k]<='z')||(a[k]>='A'&&a[k]<='Z');k=k+1)
        {
           j=k;
        }
        if(a[k]>='0'&&a[k]<='9')
         for(k=k-1;k>=l;k=k-1)
         {
             printf("%c",a[k]);
         }
        else
        {
            j=l;
            printf("%c",a[j]);
        }
    }
    else if(a[j]>='0'&&a[j]<='9')
      printf("_");
 }
 return 0;
}
