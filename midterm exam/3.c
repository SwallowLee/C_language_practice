# include<stdio.h>
int bir_mon,bir_day,now_year,now_month,now_day;
bool birthday(void);
bool date(void);
int calculate(void);
int main(void)
{
    printf("Please input your birthday: ");
    scanf("%d/%d",bir_mon,bir_day);
    if(birthday()==false)
    {
        printf("Wrong birthday!");
        return 0;
    }
    printf("What's today's date? ");
    scanf("%d/%d/%d",year,month,day);
    if(wrong_date()==false)
    {
        printf("Wrong date!");
        return 0;
    }
    printf("You need to wait %d days for your birthday."calculate());
    return 0;
}
//calculate if the date of the birthday is true or not
bool birthday(void)
{
    if(bir_mon<=7)
    {
        if(bir_mon%2!=0)
        {
            if(bir_day>31)
                return false;
            else
                return true;
        }
        else if(bir_mon!=2)
        {
            if(bir_day>30)
                return false;
            else
                return true;
        }
        else
        {
            if(bir_day>29)
                return false;
            else
                return true;
        }
    }
    else if(bir_mon>7&&bir_mon<=12)
    {
        if(bir_mon%2!=0)
        {
            if(bir_day>30)
                return false;
            else
                return true;
        }
        else
        {
            if(bir_day>29)
                return false;
            else
                return true;
        }
    }
    else
        return false;
}
bool date(void)
{
    if(year<2015)
        return false;
    else if()
}
int calculate(void)
{

}
