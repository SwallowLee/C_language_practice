# include <stdio.h>
# include <ctype.h>

int main(void)
{
 int num,i;
 char c;
 i=0;
 printf("Please input shift: ");
 scanf("%d",&num);
 printf("Please input plain text: ");
 scanf(" %c",&c);
 while(c!='\n')
 {
       if(i==0)printf("Cipher text: ");
       i=i+1;
       if(c>='A'&&c<='Z')
          c=c-'A'+'a';
       if(c>='a'&&c<='z')
       {
           if((c+num)>='a'&&(c+num)<='z')
               putchar(c+num);
           else if((c+num)<='a')
               putchar(c+num+26);
           else if((c+num)>='z')
               putchar(c+num-26);

       }
       else
          putchar(c);
       c=getchar();
 }

 return 0;
}
