# include <stdio.h>

int main(void)
{int height=8,length=12,width=10,volume,weight,a;
 volume=height*length*width;
 weight=(volume+165)/166;
 printf("Dimensions:%dx%dx%d\n",length,width);
 /*若%d多於輸入的變數,則沒被指示為哪一個變數的%d=1999205194?若%d少於輸入的變數則不會有任何改變*/
 printf("Volume(cubic inches):%d\n",volume);
 printf("Dimensional weight(pounds):%d\n",weight);
 return 0;
}
