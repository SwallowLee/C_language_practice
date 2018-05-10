#include"oop_string.h"
#include<algorithm>
#include<functional>
#include<ctype.h>
#include<string>

using namespace std;
namespace oop{
  void reverse( std::string &str){
      int i,j;
      string re;
      for(i=0;str[i]!='/0';i++);
      for(i=i-1,j=0;i>=0;i--,j++)
        re[j]=str[i];
      for(i=0;i<=j;i++)
        str[j]=re[j];
  }

  void toUpperCase( std::string &str){
      int i;
      for(i=0;str[i]!='/0';i++)
        str[i]=toupper(str[i]);
  }

  void trim( std::string &str){
       int i,j;
       for(i=0;str[i]!='/0';i++);
       i--;
       if(str[0]==' ')
          for(j=1;j<=i+1;j++)
              str[j-1]=str[j];
       if(str[i]==' ')
          for(j=i-1;j>=0;j--)
              str[j+1]=str[j];
  }
};

