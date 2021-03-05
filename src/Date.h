#pragma once
using namespace std;
class Date
{
	private: 
		int d,m,y;
		void adjust();
	public:
		int isSet; 
		Date();
		Date operator++(int);
		int returnisSet();
		void change();
		int isLeapYear();
		friend ostream &operator<<(ostream& str,Date& a);
};
