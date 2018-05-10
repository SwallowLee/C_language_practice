# include<stdio.h>
# include<stdbool.h>
char par[2000];
int i;
void takeoff(int i,int k,int fir_pre);
bool pare(int j,char pre,char later,int fir_pre,char fir_later);
int main(void)
{
	bool valid;
	int j,k;
	char ch;
	for(i=0;ch!='\n';i++)
	{
		ch=getchar();
		par[i]=ch;
	}
	i=i-1;
	for(j=0;j<=i;j++)
    if(par[0]=='<')
	{
		valid=pare(1,'<','>',0,0);
	}
	else if(par[0]=='(')
	{
		valid=pare(1,'(',')',0,0);
	}
	else if(par[0]=='[')
	{
		valid=pare(1,'[',']',0,0);
	}
	else if(par[0]=='{')
	{
		valid=pare(1,'{','}',0,0);
	}
	if(par[0]=='>'||par[0]==')'||par[0]=='}'||par[0]==']')
	    valid=false;
	if(valid==false)
        printf("Invalid!");
    else if(par[0]=='('||par[0]=='{'||par[0]=='<'||par[0]=='[')
        printf("Invalid!");
    else
        printf("Valid!");
	return 0;
 }
 void takeoff(int k,int fir_pre)
 {
 	for(;fir_pre<i;fir_pre++)
 	{
 		par[fir_pre]=par[fir_pre+1];
 		if(fir_pre==i-1)
 		    break;
	}
	for(k=k-1;k<i;k++)
 	{
 		par[k]=par[k+1];
 		if(k==i-2)
 	        break;
	}
 }
 bool pare(int j,char pre,char later,int fir_pre,char fir_later)
 {
 	bool valid;
 	int k;
 	for(k=j;k<i;k++)
	{
	   	if(par[k]==later)
	   	{
	   		valid=true;
	   		takeoff(k,fir_pre);
	   		i=i-2;
	   		break;
		}
	    else
		    valid=false;
		if(par[k-1]==fir_later)
		{
			valid=false;
		}
		if(pre!='{')
		    if(par[k]=='{'||par[k]=='}')
		    {
			    valid=false;
			    break;
		    }
		if(par[k]=='<')
	    {
			valid=pare(k+1,'<','>',k,later);
			k--;
	    }
	    else if(par[k]=='(')
	    {
			valid=pare(k+1,'(',')',k,later);
	        k--;
		}
	    else if(par[k]=='[')
	    {
			valid=pare(k+1,'[',']',k,later);
	        k--;
		}
	    else if(par[k]=='{')
	    {
			valid=pare(k+1,'{','}',k,later);
	        k--;
		}
		if(valid==false)
		    break;
	}
	return valid;
 }
