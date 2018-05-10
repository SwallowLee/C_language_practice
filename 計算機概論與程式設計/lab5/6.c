# include <stdio.h>

int main(void)
{
 long long chara,character;
 int digit;
 char ch;
 digit=0;
 chara=0;
 character=0;
 scanf(" %c",&ch);
 /*calculate the number of characters and digits*/
 while(ch!='\n')
 {
   if(ch>='0'&&ch<='9')
     digit=digit*10+(ch-'0');
   else if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
     {
      chara=chara*256+ch;
     }
   ch=getchar();
 }

 /*print digits*/
 printf("\n\ndigits:\n");
 printf("%d\n",digit);

 /*print charaters*/
 printf("characters:\n");
 for(;chara!=0;chara=chara/256)
 {
    character=character*256+chara%256;
 }
  for(;character!=0;character=character/256)
 {
    printf("%c",character%256);
 }
 return 0;
}
