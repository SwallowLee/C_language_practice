# include<stdio.h>

int main(void)
{
  float num1,num2,num3,total;
  char oper1,oper2;
  printf("Enter an expression: ");
  scanf("%f%c%f%c%f",&num1,&oper1,&num2,&oper2,&num3);
  switch(oper1)
  {
    case '/':total=num1/num2;
            break;
    case '+':total=num1+num2;
            break;
    case '*':total=num1*num2;
            break;
    case '-':total=num1-num2;
            break;
  }
  switch(oper2)
  {
    case 47:total=total/num3;
            break;
    case 43:total=total+num3;
            break;
    case 42:total=total*num3;
            break;
    case 45:total=total-num3;
            break;
  }
  printf("Value of expression:%0.1f",total);
  return 0;
}
