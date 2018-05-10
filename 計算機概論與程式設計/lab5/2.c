# include <stdio.h>

int main(void)
{
 char text,j,i,k;
 printf("Please enter text:");
 k='a';
 j='a'-1;
 text=getchar();
 while(text!='\n')
 {
   if(text>='a'&&text<='z')
   {
     for(i=k;i<=text;i=i+1)
     {
       if(i<text)
         printf("-");
       else if(i==text&&j<text)
       {
         printf("%c",text);
         j=text;
         k=text+1;
       }
       else
         break;
     }
   }

   text=getchar();
 }
 printf("\n");
 for(i='a';i<='z';i=i+1)
    putchar(i);

 return 0;
}
