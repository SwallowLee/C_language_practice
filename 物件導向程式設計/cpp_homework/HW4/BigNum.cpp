# include<iostream>
# include "BigNum.h"

using namespace std;
BigNum::BigNum()
{
	size=0;
	number=new char[size];
}
BigNum::BigNum(int const input)
{
	int j,i,calculate=input;
	size=0;
	while(calculate>0)
	{
		size++;
		calculate=calculate/10;
	}
	calculate=input;
	char *replace=new char[size];
	number=new char[size];
	for(i=0;i<size;i++)
	{
		number[i]=calculate%10+'0';
		calculate/=10;
	}
	for(j=0,i=i-1;i>=0;i--,j++)
		replace[j]=number[i];
	for(i=0;i<size;i++)
		number[i]=replace[i];
}
BigNum::BigNum(const std::string &s)
	:size(s.length())
{
	number=new char[s.length()];
	for(int i=0;i<(signed int)s.length();i++)
		number[i]=s[i];
}
int BigNum::getSize() const
{
	return size;
}
BigNum BigNum::operator+(const BigNum &plu) const
{
	BigNum ans;
	int i,j,k,cir;
	if(number[0]!='-'&&plu.number[0]!='-')
	{
	    cir=0;
	    for(k=0,i=plu.size-1,j=size-1;i>=0&&j>=0;i--,j--,k++)
        {
            int plus_ans;
            plus_ans=plu.number[i]-'0'+number[j]-'0';
            if(plus_ans>9)
            {
                ans.number[k]=plus_ans%10+'0';
	        if(cir==1)
                    ans.number[k]+=1;
	        cir=1;
            }
            else
            {
                ans.number[k]=plus_ans+'0';
		if(cir==1)
                    ans.number[k]+=1;
		cir=0;
            }
        }
	if(cir==1)
	{
		ans.number[k]='1';
		k++;
	}
        if(j>=0)
            for(j=j;j>=0;j--)
            {
                ans.number[k]=number[j];
                if(cir==1)
                    ans.number[k]+=1;
                k++;
                cir=0;
            }
        else
            for(i=i;i>=0;i--)
            {
                ans.number[k]=plu.number[i];
                if(cir==1)
                    ans.number[k]+=1;
                k++;
                cir=0;
            }
        	char *real_ans=new char[k];
        	for(i=k-1,j=0;i>=0;i--,j++)
            		real_ans[j]=ans.number[i];
        	for(i=0;i<k;i++)
            		ans.number[i]=real_ans[i];
        	ans.size=k;
	}
	else if(number[0]!='-'&&plu.number[0]=='-')
    {
        BigNum re,re2;
        re.number=new char[size];
        re2.number=new char[plu.size-1];
        for(i=0;i<size;i++)
            re.number[i]=number[i];
        re.size=size;
      	for(i=0,j=1;j<plu.size;i++,j++)
            re2.number[i]=plu.number[j];
       	re2.size=plu.size-1;
       	ans=re-re2;
    }
    else if(number[0]=='-'&&plu.number[0]!='-')
    {
        BigNum re;
        re.number=new char[size-1];
        re.size=size-1;
        for(i=0,j=1;j<size;i++,j++)
            re.number[i]=number[j];
        ans=plu-re;
    }
    else//number[0]=='-'&&plu.number[0]=='-'
    {
        BigNum re,re2,re3;
        re.number=new char[size];
        re2.number=new char[plu.size];
        for(i=0,j=1;j<size;i++,j++)
           re.number[i]=number[j];
        re.size=size-1;
      	for(i=0,j=1;j<plu.size;i++,j++)
           re2.number[i]=plu.number[j];
       	re2.size=plu.size-1;
	ans=re+re2;
       	ans.size++;
        for(i=ans.size-1;i>0;i--)
            ans.number[i]=ans.number[i-1];
        	ans.number[0]='-';
    }
	return ans;
}
BigNum BigNum::operator-(const BigNum& minu) const
{
	BigNum ans;
	char *replac=new char[size];
	int i,j,k,m,possitive=0,negative=0;
	if(number[0]!='-'&&minu.number[0]!='-')
 	{
	        for(i=0;i<size;i++)
	            replac[i]=number[i];
	        if(size<minu.size)
          	    negative=1;
      		else if(size>minu.size)
           	    possitive=1;
       		else
        	{
        	    for(i=0;i<size;i++)
      		    	if(replac[i]>minu.number[i])
                    	{
				 possitive=1;
                	   	 break;
                    	}
         		else if(replac[i]<minu.number[i])
               		{
				 negative=1;
           	    		 break;
               		}
 	       	    if(i==size)
                    {
              	        ans.number[0]='0';
                     	return 0;
                    }
       	       }
 	       if(possitive==1)
               {
      		      for(j=0,i=minu.size-1,k=size-1;i>=0;i--,k--,j++)
               			 if(replac[k]>=minu.number[i])
                  			  ans.number[j]=replac[k]-minu.number[i]+'0';
               			 else
                		{
                 			   ans.number[j]=replac[k]-minu.number[i]+10+'0';
               			  	   for(m=k-1;m>=0;m--)
                 			        if(replac[m]>0)
                       			       		break;
						else
							replac[m]+=9;
               			           replac[m]-=1;
                		}
           	     if(size>minu.size)
              		   for(k=k;k>=0;k--,j++)
                		    ans.number[j]=replac[k];
        	}
     	        else if(negative==1)
        	{
       		     ans.number[0]='-';
         	     for(j=1,i=size-1,k=minu.size-1;i>=0;i--,j++)
                    	 if(minu.number[i]>=replac[i])
                   		 ans.number[j]=minu.number[k]-replac[i]+'0';
                 	 else
                     	 {
                       		 ans.number[j]=minu.number[k]-replac[i]+10+'0';
                 		 minu.number[k-1]-=1;
                     	 }
       		     if(minu.size>size)
           		     for(k=k;k>=0;k--,j++)
                		    ans.number[j]=minu.number[k];
        	}
        	char *real_ans=new char[j];
        	for(i=0,j=j-1;j>=0;j--,i++)
            		real_ans[i]=ans.number[j];
        	for(j=0;j<i;j++)
            		ans.number[j]=real_ans[j];
        	ans.size=j;
    	}
    	else if(number[0]!='-'&&minu.number[0]=='-')
    	{
        	BigNum re,re2;
        	re.number=new char[minu.size-1];
            re.size=minu.size-1;
            re2.number=new char[size];
            re2.size=size;
            for(i=0;i<size;i++)
                re2.number[i]=number[i];
            for(i=1,j=0;i<minu.size;j++,i++)
                re.number[j]=minu.number[i];
		ans=re2+re;
    	}
    	else if(number[0]=='-'&&minu.number[0]!='-')
    	{
      		BigNum re,re2,re3;
      		re.number=new char[size-1];
        	re.size=size-1;
            re2.number=new char[minu.size];
            re2.size=minu.size;
        	for(i=1,j=0;i<size;j++,i++)
                re.number[j]=number[i];
            for(i=0;i<minu.size;i++)
                re2.number[i]=minu.number[i];
        	ans=re+re2;
		ans.size++;
        	for(i=ans.size-1;i>0;i--)
           		ans.number[i]=ans.number[i-1];
        	ans.number[0]='-';
    	}
    	else//number[0]=='-'&&minu.number[0]=='-'
    	{
        	BigNum re,re2;
        	re.number=new char[size-1];
        	re.size=size-1;
        	for(i=1,j=0;i<size;j++,i++)
           		re.number[j]=number[i];
         	re2.number=new char[minu.size];
            	re2.size=minu.size-1;
        	for(i=1,j=0;i<minu.size;i++,j++)
                	re2.number[j]=minu.number[i];
        	ans=re2-re;
    	}
	return ans;
}
BigNum BigNum::operator*(const BigNum& times) const
{
	BigNum ans;
	int i,j,k,times_ans;
	if(number[0]!='-'&&times.number[0]!='-')
    	{
        	ans.number=new char[size+times.size+1];
        	for(i=0;i<size+times.size;i++)
            		ans.number[i]='0';
        	for(i=times.size-1;i>=0;i--)
        	{
            		for(j=size-1;j>=0;j--)
            		{
                		times_ans=(number[j]-'0')*(times.number[i]-'0');
                		if(i+j>0)
               	 		{
                    			if(times_ans<10)
                        			ans.number[i+j]+=times_ans;
                    			else
                    			{
                        			ans.number[i+j-1]+=times_ans/10;
                        			ans.number[i+j]+=times_ans%10;
                    			}
                    			if(ans.number[i+j]>'9')
                    			{
                        			ans.number[i+j-1]+=(ans.number[i+j]-'0')/10;
                        			ans.number[i+j]=((ans.number[i+j]-'0')%10)+'0';
                    			}
                		}
                		else
                		{
                    			if(times_ans>=10)
                    			{
                        			for(k=size+times.size;k>0;k--)
                            				ans.number[k]=ans.number[k-1];
                        			ans.number[0]=times_ans/10+'0';
                        			ans.number[1]+=times_ans%10;
                    			}
                    			else
                        			ans.number[i+j]+=times_ans;
                    			if(ans.number[1]>'9')
                    			{
                        			ans.number[0]+=(ans.number[1]-'0')/10;
                        			ans.number[1]=((ans.number[1]-'0')%10)+'0';
                    			}
                    			else if(ans.number[0]>'9')
                    			{
                        			for(k=size+times.size;k>0;k--)
                            				ans.number[k]=ans.number[k-1];
                       	 			ans.number[0]=(ans.number[1]-'0')/10+'0';
                        			ans.number[1]=((ans.number[1]-'0')%10)+'0';
                    			}
                		}
            		}
        	}
        	ans.size=size+times.size;
    }
    else if(number[0]!='-'&&times.number[0]=='-')
    {
        BigNum re,re2;
        re.number=new char(times.size-1);
        re.size=times.size-1;
        re2.number=new char(size);
        re2.size=size;
        for(i=1,j=0;i<times.size;j++,i++)
            re.number[j]=times.number[i];
        for(i=0;i<size;i++)
            re2.number[i]=number[i];
        ans=re2*re;
        ans.size++;
        for(i=ans.size-1;i>0;i--)
            ans.number[i]=ans.number[i-1];
        ans.number[0]='-';
    }
    else if(number[0]=='-'&&times.number[0]!='-')
    {
        BigNum re;
        re.number=new char(size-1);
        re.size=size-1;
        for(i=1,j=0;i<size;j++,i++)
            re.number[j]=number[i];
        ans=re*times;
        ans.size++;
        for(i=ans.size-1;i>0;i--)
            ans.number[i]=ans.number[i-1];
        ans.number[0]='-';
    }
    else//number[0]=='-'&&times.number[0]=='-'
    {
        BigNum re,re2;
        re.number=new char(size-1);
        re.size=size-1;
        for(i=1,j=0;i<size;j++,i++)
            re.number[j]=number[i];
        re2.number=new char(times.size-1);
        re2.size=times.size-1;
        for(i=1,j=0;i<times.size;j++,i++)
            re2.number[j]=times.number[i];
        ans=re*re2;
    }
	return ans;
}
BigNum &BigNum::operator++()
{
	int i;
	if(number[0]!='-')
    {
        if(number[size-1]=='9')
        {
            i=size-1;
            while(number[i]=='9')
            {
                number[i]='0';
                i-=1;
                if(i<0)
                    break;
            }
            if(i<0)
            {
                for(i=size;i>0;i--)
				number[i]=number[i-1];
                number[0]='1';
                size++;
            }
            else
                number[i]+=1;
        }
        else
            number[size-1]+=1;
    }
    else
    {
        if(number[size-1]=='0')
        {
            i=size-1;
            while(number[i]=='0')
            {
                number[i]='9';
                i-=1;
                if(i<=0)
                    break;
            }
            number[i]-=1;
        }
        else
            number[size-1]-=1;
	if(number[1]=='0')
		for(i=1;i<size-1;i++)
			number[i]=number[i+1];
	size--;
    }
	return *this;
}
BigNum BigNum::operator++(int)
{
	int i;
	BigNum temp;
	temp.number=new char[size];
	temp.size=size;
	for(i=0;i<size;i++)
		temp.number[i]=number[i];
	++*this;
	return temp;
}
BigNum operator+(const BigNum&  a,const int b)
{
	BigNum integer(b);
	return a+integer;
}
BigNum operator+(const int a,const BigNum& b)
{
	BigNum integer(a);
	return integer+b;
}
BigNum operator-(const BigNum& a,const int b)
{
	BigNum integer(b);
	return a-integer;
}
BigNum operator-(const int a,const BigNum& b)
{
	BigNum integer(a);
	return integer-b;
}
BigNum operator*(const BigNum& a,const int b)
{
	BigNum integer(b);
	return a*integer;
}
BigNum operator*(const int a,const BigNum& b)
{
	BigNum integer(a);
	return integer*b;
}
std::ostream &operator<<(std::ostream& output,const BigNum& ans)
{
	int i;
	if(ans.size!=0)
		for(i=0;i<ans.size;i++)
			output<<ans.number[i];
	else
		output<<"0";
	return output;
}
std::istream &operator>>(std::istream& input,BigNum& question)
{
	int i;
	cin.getline(question.number,300,'\n');
	for(i=0;question.number[i]!='\0';i++);
	question.size=i;
	return input;
}
