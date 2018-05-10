#include<iostream>
#include<stack>
#include<string>
int main()
{
	std::string s;
	std::stack<char> p; 
	while(std::cin>>s)
	{
             int i,palind=1;
	     for(i=0;s[i]!='\0';i++)
             {
	     	p.push(s[i]);
             }
             for(i=0;s[i]!='\0';i++)
             {
		if(p.top()!=s[i])
		{
		    palind=0;
		    break;
		}
		else
		    p.pop();
	     }
	     if(palind==0||i==1)	 //if the string is a palindrome 
		 std::cout<<"The string is not a Palindrome"<<std::endl;
		 
	     else //if the string is not a palindrome
		 std::cout<<"The string is a Palindrome"<<std::endl;
		
	}
	
	
	return 0;
}
