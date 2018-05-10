# include<iostream>
# include<fstream>
# include<vector>
# include<string.h>

using namespace std;
int main(int argc,char* argv[])
{
    ifstream read,object;
    ofstream write;
    string str,file,put_in;
    vector<int> cnt;
    vector<string> buffer;
    bool num_exit,put_buffer,run;
    int i,j,k,num;
    char word,opera;

        read.open(argv[1],ios::in);
        //read str and file at one time
        read>>str;
	if(str=="exit")
	{
		cout<<"% exit"<<endl;
		return 0;
	}
        read>>file;
        object.open(file,ios::in);
        while(!read.eof())//what if cat before exit?
	{
	    run=false;
            //if the second word is not a file
            if(!object.is_open())
            {
                if(str!="cat"&&str!="removetag"&&str!="exit")
                {
		    cout<<"% "<<str<<endl;
                    cout<<"unknown command"<<endl;
		    str=file;
                }
                else // |
                {
                    put_buffer=false;
                    for(i=0;i<cnt.size();i++)
                    {
                        if(cnt[i]==0)
                        {
                            put_buffer=true;
                            break;
                        }
                    }
                    if(put_buffer==true)
                    {
			cout<<"% "<<str;
                        if(str=="cat")
                        {
			    run=true;
			    if(!read.eof())
                            	read>>opera;
			    if(opera=='>')
        	            {
                	        read>>file;
				cout<<" > "<<file<<endl;
                               	write.open(file,ios::out);
	                        write<<buffer[i];
				read>>str;
        	            }
                	    else if(opera=='|')
                            {
                               	num_exit=false;
	                        cin>>num;
				cout<<" |"<<num<<endl;
                	        for(j=0;j<cnt.size();j++)
                        	{
                               	    if(cnt[j]==num)
	                            {
					for(k=0;k<buffer[i].size();k++)
                	                {
						word=buffer[i][k];
						buffer[j].insert(buffer[j].end(),word);
	                                }
					num_exit=true;
                	                break;
                                    }
                               	}
	                        if(num_exit==false)
        	                {
                	            cnt.push_back(num);
                                    buffer.push_back(put_in);
                               	}
				read>>str;
	                    }
        	            else
                	    {
				if(!read.eof())
					read.putback(opera);
				cout<<endl;
                                cout<<buffer[i];
				read>>str;
                            }
                        }
                        else if(str=="removetag")
                        {
			    if(!read.eof())
                            	read>>opera;
                            if(opera=='>')
                            {
				run=true;
                                read>>file;
				cout<<" > "<<file<<endl;
                                write.open(file,ios::out);
                                for(j=0;j<buffer[i].size();j++)
                                {
                                    word=buffer[i][j];
                                    if(word!=61&&word!=43&&word!=44&&word!=39&&word!=92&&word!=34&&word!=33&&word!=45&&word!=59&&word!=40&&word!=41&&word!=46)
                                    {
                                        write<<word;
                                    }
                                }
				read>>str;
                            }
                            else if(opera=='|')
                            {
				run=true;
                                num_exit=false;
                                read>>num;
				cout<<" |"<<num<<endl;
                                for(j=0;j<cnt.size();j++)
                                {
                                    if(cnt[j]==num)
                                    {
					const char *point;
					point=buffer[i].data();
                                        for(k=0;k<buffer[i].size();k++)
                                        {
                                            word=point[k];
                                            if(word!=61&&word!=43&&word!=44&&word!=39&&word!=92&&word!=34&&word!=33&&word!=45&&word!=59&&word!=40&&word!=41&&word!=46)
                                            {
                                                buffer[j].insert(buffer[j].end(),word);
                                            }
                                        }
                                        num_exit=true;
                                        break;
                                    }
                                }
                                if(num_exit==false)
                                {
				    const char *point;
				    point=buffer[i].data();
				    put_in.clear();
				    cnt.push_back(num);
				    for(j=0;j<buffer[i].size();j++)
                                    {
                                        word=point[j];
                                        if(word!=61&&word!=43&&word!=44&&word!=39&&word!=92&&word!=34&&word!=33&&word!=45&&word!=59&&word!=40&&word!=41&&word!=46)
                                        {
                                            put_in.insert(put_in.end(),word);
                                        }
                                    }
                                    buffer.push_back(put_in);
                                }
				read>>str;
                            }
			    else
			    {
				if(!read.eof())
					read.putback(opera);
				cout<<endl;
				str=file;
			    }
                        }
                        else if(str=="exit")
                        {
                            cout<<"% exit"<<endl;
                            return 0;
                        }
                        buffer.erase(buffer.begin()+i);
			cnt.erase(cnt.begin()+i);
                    }
                    else//doesn't have input file
                    {
                        cout<<"% "<<str<<endl;
			str=file;
                    }
		    if(run=true)
                    	for(i=0;i<cnt.size();i++)
	            	{
	                 	cnt[i]--;
	            	}
                }
		if(str=="exit")
		{
			cout<<"% exit"<<endl;
			return 0;
		}
                read>>file;
                object.open(file,ios::in);
        	if(!object.is_open())
        	{
            		object.seekg(-file.size(),ios::cur);
        	}
            }
            else
            {
                if(str=="cat")
                {
		    run=true;
                    cout<<"% cat "<<file;
                    read>>opera;
                    if(opera=='>')
                    {
                        read>>file;
			cout<<" > "<<file<<endl;
                        ofstream write(file,ios::out);
                        object.get(word);
                        while(!object.eof())
                        {
                            write<<word;
                            object.get(word);
                        }
                    }
                    else if(opera=='|')
                    {
                        read>>num;
                        num_exit=false;
			cout<<" |"<<num<<endl;
                        //find if the repeated number exit
                        for(i=0;i<cnt.size();i++)
                        {
                            //exit->buffer has already exit
                            if(cnt[i]==num)
                            {
                                object.get(word);
                                while(!object.eof())
                                {
                                    buffer[i].insert(buffer[i].end(),word);
                                    object.get(word);
                                }
                                num_exit=true;
				break;
                            }
                        }
                        if(num_exit==false)
                        {
                            put_in.clear();
                            cnt.push_back(num);
                            object.get(word);
                            while(!object.eof())
                            {
                                put_in.insert(put_in.end(),word);
                                object.get(word);
                            }
                            buffer.push_back(put_in);
		        }
                    }
                    else
                    {
                        cout<<endl;
                        object.get(word);
			while(!object.eof())
                        {
			        cout<<word;
				object.get(word);
                        }
			read.putback(opera);
                    }
                }
                else if(str=="removetag")
                {
                    cout<<"% removetag "<<file;
                    read>>opera;
                    if(opera=='>')
                    {
			run=true;
                        read>>file;
                        write.open(file,ios::out);
			cout<<" > "<<file<<endl;
                        object.get(word);
                        while(!object.eof())
                        {
                            if(word!=61&&word!=43&&word!=44&&word!=39&&word!=92&&word!=34&&word!=33&&word!=45&&word!=59&&word!=40&&word!=41&&word!=46)
                            {
                                write<<word;
                            }
                            object.get(word);
                        }
                    }
                    else if(opera=='|')
                    {
			run=true;
                        num_exit=false;
                        read>>num;
			cout<<" |"<<num<<endl;
                        for(i=0;i<cnt.size();i++)
                        {
                            if(cnt[i]==num)
                            {
                                object.get(word);
                                while(!object.eof())
                                {
                                    if(word!=61&&word!=43&&word!=44&&word!=39&&word!=92&&word!=34&&word!=33&&word!=45&&word!=59&&word!=40&&word!=41&&word!=46)
                                    {
                                        buffer[i].insert(buffer[i].end(),word);
                                    }
                                    object.get(word);
                                }
                                num_exit=true;
                                break;
                            }
                        }
                        if(num_exit==false)
                        {
                            put_in.clear();
                            cnt.push_back(num);
                            object.get(word);
                            while(!object.eof())
                            {
                                if(word!=61&&word!=43&&word!=44&&word!=39&&word!=92&&word!=34&&word!=33&&word!=45&&word!=59&&word!=40&&word!=41&&word!=46)
                                {
                                    put_in.insert(put_in.end(),word);
                                }
                                object.get(word);
                            }
                            buffer.push_back(put_in);
                        }
                    }
                    else
                    {
                        cout<<endl;
                        read.putback(opera);
                    }
                }
                else if(str=="exit")
                {
                    cout<<"% exit"<<endl;
                    return 0;
                }
                else
                {
                    cout<<"% "<<str<<" "<<file;
                    read>>opera;
                    if(opera=='>'||opera=='|')
                    {
                        read>>file;
                        cout<<" "<<file<<endl;
                    }
                    else
                    {
                        cout<<endl;
                        read.putback(opera);
                    }
                    cout<<"unknown command"<<endl;
                }
		read>>str;
		if(str=="exit")
		{
			cout<<"% exit"<<endl;
			return 0;
		}
		put_buffer=false;
        	for(i=0;i<cnt.size();i++)
	        {
                        if(cnt[i]==0)
        	        {
	                    put_buffer=true;
                      	    break;
                        }
        	}
	        if(put_buffer==true)
                {
			cout<<"% "<<str;
	                if(str=="cat")
                      	{
			    if(!read.eof())
        	               	read>>opera;
			    if(opera=='>')
        	      	    {
                	        read>>file;
				cout<<" > "<<file<<endl;
        	                write.open(file,ios::out);
		                write<<buffer[i];
        	            }
                	    else if(opera=='|')
                            {
        	                num_exit=false;
		                cin>>num;
				cout<<" |"<<num<<endl;
                	        for(j=0;j<cnt.size();j++)
                        	{
        	               	    if(cnt[j]==num)
		                    {
					for(k=0;k<buffer[i].size();k++)
                	                {
						word=buffer[i][k];
						buffer[j].insert(buffer[j].end(),word);
		                        }
					num_exit=true;
                                	break;
                              	    }
                       	       	}
	                        if(num_exit==false)
        	                {
	               	            cnt.push_back(num);
                               	    buffer.push_back(put_in);
                       	       	}
	                    }
        	            else
	               	    {
				if(!read.eof())
					read.putback(opera);
				cout<<endl;
        	                cout<<buffer[i];
	                    }
                       	    read>>str;
                   	 }
        	         else if(str=="removetag")
	                 {
			    if(!read.eof())
                            	read>>opera;
        	            if(opera=='>')
	                    {
        	                read>>file;
				cout<<" > "<<file<<endl;
                               	write.open(file,ios::out);
                       	        for(j=0;j<buffer[i].size();j++)
                                {
        	                    word=buffer[i][j];
	                            if(word!=61&&word!=43&&word!=44&&word!=39&&word!=92&&word!=34&&word!=33&&word!=45&&word!=59&&word!=40&&word!=41&&word!=46)
                                    {
                                        write<<word;
                        	    }
                	        }
        	            }
	                    else if(opera=='|')
                            {
                       	        num_exit=false;
                                read>>num;
				cout<<" |"<<num<<endl;
	                        for(j=0;j<cnt.size();j++)
                              	{
                       	            if(cnt[j]==num)
                                    {
        	                        for(k=0;k<buffer[i].size();k++)
	                                {
                                      	    word=buffer[i][k];
                               	            if(word!=61&&word!=43&&word!=44&&word!=39&&word!=92&&word!=34&&word!=33&&word!=45&&word!=59&&word!=40&&word!=41&&word!=46)
                       	                    {
                                                buffer[j].insert(buffer[j].end(),word);
        	                            }
	                                }
                                       	num_exit=true;
                               	        break;
                       	            }
                                }
        	                if(num_exit==false)
	                        {
                              	    put_in.clear();
                       	            cnt.push_back(num);
                                    for(j=0;j<buffer[i].size();j++)
        	                    {
	                                word=buffer[i][j];
                               	        if(word!=61&&word!=43&&word!=44&&word!=39&&word!=92&&word!=34&&word!=33&&word!=45&&word!=59&&word!=40&&word!=41&&word!=46)
                      	                {
                                            put_in.insert(put_in.end(),word);
        	                        }
	                            }
                              	    buffer.push_back(put_in);
                       	        }
                            }
			    else
			    {
				if(!read.eof())
					read.putback(opera);
				cout<<endl;
			    }
                       	    read>>str;
                        }
        	        else if(str=="exit")
	                {
                      	    cout<<"% exit"<<endl;
                            return 0;
        	        }
			else
			{
			    read>>opera;
			    if(opera=='>'&&opera=='|')
			    {
				read>>file;
				cout<<" "<<opera<<file<<endl;
			    }
			    else
			    {
				read.putback(opera);
				cout<<endl;
			    }
			    cout<<"unknow command"<<endl;
			    read>>str;
			}
                        buffer.erase(buffer.begin()+i);
	        }
		if(run=true)
	        	for(i=0;i<cnt.size();i++)
	        	{
	            		cnt[i]--;
	        	}
		object.close();
		read>>file;
	        object.open(file,ios::in);
        	if(!object.is_open())
        	{
        	    read.seekg(-file.size(),ios::cur);
        	}
        }
    }
    return 0;
}
