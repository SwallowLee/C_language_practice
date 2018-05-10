# include <stdio.h>

int main (void)
{
float lean,rate,payment,month,first,second,third;
printf("Enter amount of lean: ");
scanf("%f",&lean);
printf("Enter interest rate: ");
scanf("%f",&rate);
printf("Enter monthly payment: ");
scanf("%f",&payment);
month=(rate/100)/12;
first=lean+lean*month-payment;
second=first+first*month-payment;
third=second+second*month-payment;
printf("Balance remaining after first payment:%.2f\n",first);
printf("Balance remaining after second payment:%.2f\n",second);
printf("Balance remaining after third payment:%.2f\n",third);
return 0;
}
