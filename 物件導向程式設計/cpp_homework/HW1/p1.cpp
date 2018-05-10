# include <iostream>
# include <stack>
# include<stdio.h>

using namespace std;

int main(void)
{
    char opera;
    long long int signed num,first,second;
    stack<long long int signed> number;
    opera=getchar();
    while(opera!='\n')
    {
        if(opera=='i')
        {
            cin>>num;
            number.push(num);
        }
        else if(opera=='+'||opera=='-'||opera=='*'||opera=='/')
        {
            first=number.top();
            number.pop();
            second=number.top();
            number.pop();
            if(opera=='+')
                second=second+first;
            if(opera=='-')
                second=second-first;
            if(opera=='*')
                second=second*first;
            if(opera=='/')
                second=second/first;
            number.push(second);
        }
        opera=getchar();
    }
    cout<<number.top()<<endl;
    return 0;
}
