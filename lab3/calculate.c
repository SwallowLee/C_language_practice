# include <stdio.h>

int main(void)
{
float a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,sum,sub,mul;
float div,tal;
scanf("%1f%1f%1f%1f.%1f%1f%1f%1f",&a,&b,&c,&d,&e,&f,&g,&h);
scanf("%1f%1f%1f%1f.%1f%1f%1f%1f",&i,&j,&k,&l,&m,&n,&o,&p);
sum=a*1000+b*100+c*10+d+i*1000+j*100+k*10+l;
sub=(e*1000+f*100+g*10+h)-(m*1000+n*100+o*10+p);
mul=(c*1000+d*100+e*10+f)*(k*1000+l*100+m*10+n);

div=(a*1000+b*100+g*10+h)/(i*1000+j*100+o*10+p);
tal=sum+sub+mul+div;
printf("sum:%.0f\n",sum);
printf("sub:%.0f\n",sub);
printf("mul:%.0f\n",mul);
printf("div:%.2f\n",div);
printf("Encoding Result:%.2f",tal);
 return 0;

}
