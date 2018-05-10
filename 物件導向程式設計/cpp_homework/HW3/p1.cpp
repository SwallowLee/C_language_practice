# include<iostream>
# include<iomanip>

using namespace std;
int main(void)
{
	int num;
	while(!cin.eof())
	{
		cin>>num;
		if(!cin.fail())
		{
			cout<<hex<<num<<" "<<oct<<num<<endl;
		}
		else
		{
			cin.clear();
			cin.ignore(1,'\n');
			cout<<"not a number!"<<endl;
		}
	}
	return 0;
}
