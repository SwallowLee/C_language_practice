# include<stdio.h>

int main(void)
{
    int i,a,result=1,north=2,west,b;
    char dir[100];
    gets(dir);
    for(i=0;dir[i]!='\0';i++)
    {
        if(dir[i]=='n')
        {
            if(dir[i+1]>='0'&&dir[i+1]<='9')
            {
                a=i%4;
                i++;
                if(a==2)
                {
                    result=7-result;
                    north=7-north;
                }
                if(a==3)
                {
                    b=north;
                    north=7-result;
                    result=b;
                }
                if(a==1)
                {
                    b=result;
                    result=7-north;
                    north=b;
                }
        else if(dir[i+1]<0)
              {
                  dir[i+1]=-dir[i+1];
                  a=i%4;
                i++;
                if(a==2)
                {
                    result=7-result;
                    north=7-north;
                }
                if(a==3)
                {
                    b=north;
                    north=7-result;
                    result=7-b;
                }
                if(a==1)
                {
                    b=result;
                    result=north;
                    north=7-b;
                }
              }
              else
              {
                  b=result;
                    result=north;
                    north=7-b;
              }
            }
        }
        if(dir[i]=='s')
        {
            if(dir[i+1]>='0'&&dir[i+1]<='9')
             {
                 a=i%4;
                i++;
                if(a==2)
                {
                    result=7-result;
                    north=7-north;
                }
                if(a==3)
                {
                    b=north;
                    north=7-result;
                    result=7-b;
                }
                if(a==1)
                {
                    b=result;
                    result=north;
                    north=7-b;
                }
              }
              else if(dir[i+1]<0)
              {
                  dir[i+1]=-dir[i+1];
                  a=i%4;
                i++;
                if(a==2)
                {
                    result=7-result;
                    north=7-north;
                }
                if(a==3)
                {
                    b=north;
                    north=7-result;
                    result=b;
                }
                if(a==1)
                {
                    b=result;
                    result=7-north;
                    north=b;
                }
              }
              else
              {
                  b=result;
                    result=north;
                    north=7-b;
              }
            }
        if(dir[i]=='w')
        {
            if(dir[i+1]>='0'&&dir[i+1]<='9')
            {
                a=i%4;
                i++;
                if(a==2)
                {
                    result=7-result;
                    north=7-north;
                }
                if(a==3)
                {
                    b=north;
                    north=7-result;
                    result=b;
                }
                if(a==1)
                {
                    b=result;
                    result=7-north;
                    north=b;
                }
              else if(dir[i+1]<0)
              {
                  dir[i+1]=-dir[i+1];
                  a=i%4;
                i++;
                if(a==2)
                {
                    result=7-result;
                    north=7-north;
                }
                if(a==3)
                {
                    b=north;
                    north=7-result;
                    result=7-b;
                }
                if(a==1)
                {
                    b=result;
                    result=north;
                    north=7-b;
                }
              }
              else
              {
                  b=result;
                    result=north;
                    north=7-b;
              }
            }
        }
    }
    printf("%d",result);
    return 0;
}
