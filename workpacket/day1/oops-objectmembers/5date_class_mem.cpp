//can you extend this example with Time
#include <iostream>
#include <cstring>
using namespace std;
class Time{
	int hours;
	int minutes;
	int secods;
	public:
#if 0	
void showMinutes(void);
	void setMinutes(int);
	void setSecond(int);
	void setHours(int)
#endif
};
class Date
{
	public:
		Date();
		~Date();
		void setDate(int,const char*,int);    	// a mutator , setter function
		void showDate() const;	  		// a true accessor , getter function 
		static void showDateCount();	
		//static Time time;
	private:
		#ifdef EDIT_DAY
			mutable int day;
		#else
			int day;
		#endif
		char month[4];
		int year;
		static int dateCount;
};
//Linkage specification 
int Date::dateCount = 0;  //allocation and init 
Date::Date(){  ++dateCount; cout<< "ctor: The obj count = "<< dateCount<<endl;}
Date::~Date(){  --dateCount; cout<< "dtor: The obj count = "<< dateCount<<endl;}

void Date::showDateCount()
{
	cout<<"Date obj count = "<< dateCount <<endl;
}
void Date::setDate(int day,const char* m,int y)
{
	this->day=day;		// an explicit need for using a this pointer
	strcpy(month,m);
	year=y;
}
void Date::showDate() const  // logical const
{
	//day=1;
	//year=9999;
	cout<<"The date is: "<<day<<"-"<<month<<"-"<<year<<endl;
}
int main()
{
	Date today, temp, tomorrow;
	Date::showDateCount();
	today.setDate(26,"Nov", 2016);   	
	temp.setDate(30,"Jun", 2015);
	today.showDate();
	temp.showDate();
	tomorrow.showDate(); 
}


