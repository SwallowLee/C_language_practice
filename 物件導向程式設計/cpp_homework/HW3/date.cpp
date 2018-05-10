# include<iostream>
# include "date.h"

using namespace std;
unsigned short int Date::getDate_data()const
{
	return Date_data;
}
unsigned short int Date::getDay()const
{
	int re,r;
	r=Date_data>>5;
	r=r<<5;
	re=Date_data-r;
	return re;
}
unsigned short int Date::getMon()const
{
	int re,re2,r;
	r=Date_data>>9;
	r=r<<9;
	re2=Date_data-r;
	re=re2>>5;
	return re;
}
unsigned short int Date::getYr()const
{
	int re;
	re=Date_data>>9;
	return re;
}
void Date::setDate(const short int& yr,const short int& mon,const short int& day)
{
	int num;
	short int r;
	r=yr%1000;
	Date_data=r;
	Date_data=Date_data<<4;
	r=mon;
	Date_data=Date_data+r;
	Date_data=Date_data<<5;
	r=day;
	Date_data=Date_data+r;
}
void Date::showDate()
{
	int yr,mon,day;
	yr=Date::getYr();
	yr=2000+yr;
	mon=Date::getMon();
	day=Date::getDay();
	cout<<yr<<" "<<mon<<" "<<day<<endl;
}
