# include <stdio.h>

int main(void)
{
float a1,x,y,a3,a4,ari,geo;
printf("Please input a1:");
scanf("%f",&a1);
printf("Please input a3:");
scanf("%f",&a3);
printf("Please input a4:");
scanf("%f",&a4);
x=a1+(a4-a3);
y=a1*(a4/a3);
ari=(a1+2*(a4-a3));
geo=(a1*(a4/a3)*(a4/a3));
if(a3==ari)
   printf("a2 is %.0f",x);
else if(a3==geo)
   printf("a2 is %.0f",y);

return 0;
}
