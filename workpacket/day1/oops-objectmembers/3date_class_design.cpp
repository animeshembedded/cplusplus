#include <iostream>
#include <cstring>
using namespace std;
class Date
{
	public:
		void setDate(int,const char*,int);    	// a mutator , setter function
		void showDate() const;	  		// a true accessor , getter function 
		static void showDateCount();	
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
void Date::setDate(int day,const char* m,int y)
{
	this->day=day;		// an explicit need for using a this pointer
	strcpy(month,m);
	year=y;
}
void Date::showDate() const  // logical const
{
	day=1;
	//year=9999;
	cout<<"The date is: "<<day<<"-"<<month<<"-"<<year<<endl;
}
int main()
{
	Date today, temp, tomorrow;
	
	today.setDate(26,"Nov", 2016);   	
	temp.setDate(30,"Jun", 2015);
	today.showDate();
	temp.showDate();
	tomorrow.showDate(); 
}

