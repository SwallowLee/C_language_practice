#include<stdio.h>

double opCalculate(double, double, char);   //�B�z�G���B��
int optrPriority(char);                     //�u���v�B�z�A�Ystack���ݦ��u���v�󰪪�operator�A���B�z�A�APUSH�i�s��operator
int check_stack(int, int);                  //�ˬdstack�����A�Aoperator���i�H��operand�h
int check_divide0(double, char);            //�ˬd�O�_��0


int main(void)
{
    double operandStack[100];
    char operatorStack[100];
    int operandTop = -1, operatorTop = -1, i;
    int isInvalid = 0;              //�Ψ��ˬd��Uexpression�O�_invalid
    int isDigitInBuffer = 0;        //SUM��l�ƬҬ�0�A��flag�ΨӽT�{�O�_���u�����Y��Ʀr(�Ӥ���PUSH�istack)
    int char_count = 0;             //�ΨӰ����Ĥ@�ӹJ�쪺�Ÿ��O�_��- (unary minus)

    double sum = 0.0;
    char ch;

    for( i = 0 ; i < 100 ; i++)
    {
        operandStack[i] = 0.0;
        operatorStack[i] = '\0';
    }

    while((ch = getchar()) != '\n')
    {
        if( ch >= '0' && ch <= '9')
        {
            isDigitInBuffer = 1;
            char_count++;
            sum = sum * 10.0 + (double)(ch - '0');
        }
        else if( ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            if(char_count == 0 && ch == '-')
            {
                operandStack[++operandTop] = 0.0;
            }

            char_count++;
            if(isDigitInBuffer)
            {
                operandStack[++operandTop] = sum;
            }
            sum = 0.0;
            isDigitInBuffer = 0;
            while( operatorTop > -1 && optrPriority(operatorStack[operatorTop]) >= optrPriority(ch) )
            {
                if( !check_stack(operandTop, operatorTop) )
                {
                    isInvalid = 1;
                    break;
                }
                double op1 = operandStack[operandTop-1];
                double op2 = operandStack[operandTop];
                char optr = operatorStack[operatorTop];
                if( !check_divide0(op2, optr) )
                {
                    isInvalid = 1;
                    break;
                }

                operandTop -= 2;
                operatorTop -= 1;
                operandStack[++operandTop] = opCalculate(op1, op2, optr);
            }

            if(isInvalid)    break;
            operatorStack[++operatorTop] = ch;
        }
        else if(ch == '\t' || ch == ' ')        //�ťդ��v�T���G
        {
            continue;
        }
        else    //��l�r�����X�{�A����invalid
        {
            isInvalid = 1;
            break;
        }

    }
    //�Ʀr������A�S���Ÿ��C�Y�T�{���Ʀrinput�A�N��PUSH�iStack
    if(isDigitInBuffer)
    {
        operandStack[++operandTop] = sum ;
    }

    //�d�bstack���A�S�Q�B�z��������
    while( !isInvalid && (operandTop > -1 || operatorTop > -1))
    {
        if( !check_stack(operandTop, operatorTop) )
        {
            isInvalid = 1;
            break;
        }
        double op1 = operandStack[operandTop-1];
        double op2 = operandStack[operandTop];
        char optr = operatorStack[operatorTop];
        if( !check_divide0(op2, optr) )
        {
            isInvalid = 1;
            break;
        }

        operandTop -= 2;
        operatorTop -= 1;
        operandStack[++operandTop] = opCalculate(op1, op2, optr);
    }

    if(isInvalid)       printf("invalid expression!\n");
    else                printf("%.3lf\n", operandStack[0]);

    return 0;
}

double opCalculate(double op1, double op2, char optr)
{
    if(optr == '+')                     return (op1 + op2);
    else if(optr == '-')                return (op1 - op2);
    else if(optr == '*')                return (op1 * op2);
    else if(optr == '/')                return (op1 / op2);
}

int optrPriority(char optr)
{
    if(optr == '+' || optr == '-')      return 1;
    else if(optr == '*' || optr == '/') return 2;
}

int check_stack(int operandTop, int operatorTop)
{
    if(operandTop <= operatorTop)       return 0;
    else                                return 1;
}
int check_divide0(double op2, char optr)
{
    if(optr == '/' && op2 == 0.0)       return 0;
    else                                return 1;
}
