#include <iostream>
#include <cstring>
using namespace std;
class Date
{
	public:
		void setDate(int,const char*,int);    	// a mutator , setter function
		void showDate() const;	  		// a true accessor , getter function 
	private:
		int day;
		char month[4];
		int year;
};
void Date::setDate(int day,const char* m,int y)
{
	this->day=day;		// an explicit need for using a this pointer
	strcpy(month,m);
	year=y;
}
void Date::showDate() const  // logical const
{
	cout<<"The date is: "<<day<<"-"<<month<<"-"<<year<<endl;
}
int main()
{
	Date today
	
	today.setDate(26,"Nov", 2016);   	
	today.showDate();
}

