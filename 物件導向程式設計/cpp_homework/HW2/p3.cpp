# include<iostream>
# include<string>
# include<string.h>
# include<map>

using namespace std;
int main(void)
{
    int price,i,j,kind,order,sum;
    char sentence[10000];
    string food;
    map<string,int> menu;
    map<string,int>::iterator it;
    cin>>kind>>order;
   for(i=0;i<kind;i++)//put kinds of food into maps
    {
        cin>>food;
        cin>>price;
        menu[food]=price;
        cout<<menu[food]<<endl;
    }
    for(i=0;i<order;i++)//calculate the price
    {
        sum=0;
        cin.getline(sentence,10000,'.');
        while(sentence[i]!='\0')
        {
            char item[20];
            for(j=0;sentence[i]!='\0'&&sentence[i]!=' '&&sentence[i]!='/n';i++,j++)
                item[j]=sentence[i];
            item[j]='\0';
            i++;
            for(it=menu.begin();it!=menu.end();it++)
                if(item==it->first)
                    sum+=menu[item];
            cout<<i<<item<<menu[item]<<endl;
            delete(item);
        }
        cout<<"Y"<<endl;
        cout<<sum<<endl;
    }
    return 0;
}
