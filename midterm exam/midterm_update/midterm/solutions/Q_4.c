#include<stdio.h>

double opCalculate(double, double, char);   //處理二元運算
int optrPriority(char);                     //優先權處理，若stack頂端有優先權更高的operator，先處理，再PUSH進新的operator
int check_stack(int, int);                  //檢查stack的狀態，operator不可以比operand多
int check_divide0(double, char);            //檢查是否除0


int main(void)
{
    double operandStack[100];
    char operatorStack[100];
    int operandTop = -1, operatorTop = -1, i;
    int isInvalid = 0;              //用來檢查當下expression是否invalid
    int isDigitInBuffer = 0;        //SUM初始化皆為0，此flag用來確認是否為真的有吃到數字(該不該PUSH進stack)
    int char_count = 0;             //用來偵測第一個遇到的符號是否為- (unary minus)

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
        else if(ch == '\t' || ch == ' ')        //空白不影響結果
        {
            continue;
        }
        else    //其餘字元的出現，都當成invalid
        {
            isInvalid = 1;
            break;
        }

    }
    //數字結束後，沒有符號。若確認有數字input，將之PUSH進Stack
    if(isDigitInBuffer)
    {
        operandStack[++operandTop] = sum ;
    }

    //留在stack中，沒被處理完的部分
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
