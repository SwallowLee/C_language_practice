# include <stdio.h>

int main(void)
{
int x1,x2,x3;
float y,aver;
scanf("%d,%d,%d",&x1,&x2,&x3);
scanf("%f",&y);
aver=(x1+x2+x3)/3.0;
printf("The average number is %.3f\n",aver);
if(y>aver)
   printf("%.3f is greater than %.3f\n",y,aver);
else if(y==aver)
   printf("%.3f is equal to %.3f\n",y,aver);
else
   printf("%.3f is less than %.3f\n",y,aver);


return 0;
}
