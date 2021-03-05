#include <iostream>
#include <time.h>
#include "Date.h"

using namespace std;
Date::Date()
{
	time_t timer;
	time(&timer);
	tm* t_tm = localtime(&timer);
	d=t_tm->tm_mday;
	m=t_tm->tm_mon+1;
	y=t_tm->tm_year+1900;
	isSet=0;
}
Date Date::operator++(int)
{
	d++;
	adjust();
	return *this; 
}

int Date::returnisSet()
{
	return isSet; 
} 

void Date::change(){
	if(isSet==0) isSet=1;
	else isSet=0; 
}

int Date::isLeapYear()
{
	int a=0;
	if(y%4==0&&y%100!=0||y%400==0)
		a=1;
	return a;
}
ostream & operator<<(ostream& str,Date& a)
{
	str<<a.y<<"/"<<a.m<<"/"<<a.d;
	return str;
}
void Date::adjust()
{
	int k;
	k=isLeapYear();
	int month[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
	while(d>month[k][m-1])
	{
		d-=month[k][m-1];
		m++;
		if(m>12)
		{
			y++;
			m-=12;
		}
		k=isLeapYear();
	}
}
