#include <iostream>
#include <cstring>
using namespace std;
class Date
{
	public:
		Date();
		Date(const Date &);
		void setDate(int,const char*,int);
		Date& operator=(const Date&);
		void showDate();
		~Date();	
	private:
		int day;
		char month[4];
		int year;
};
Date::Date() //default ctor
{
	day=1;		// an explicit need for using a this pointer
	strcpy(month,"Jan");
	year=1970;
	cout<<"In default ctor\n";
}
Date::Date(const Date &rhs)
{
	day= rhs.day;		// an explicit need for using a this pointer
	strcpy(month,rhs.month);
	year=rhs.year;
	cout<<"In default copy con\n";
}	

Date& Date::operator =(const Date &rhs)
{
	day= rhs.day;		// an explicit need for using a this pointer
	strcpy(month,rhs.month);
	year=rhs.year;
	cout<<"In default = operator\n";
	return *this;
}
Date::~Date() //default ctor
{
	day=-1;		// an explicit need for using a this pointer
	strcpy(month,"");
	year=0;
	cout<<"In default dtor\n";
}
void Date::setDate(int day,const char* m,int y)
{
	this->day=day;		// an explicit need for using a this pointer
	strcpy(month,m);
	year=y;
}
void Date::showDate()
{
	cout<<"The date is: "<<day<<"-"<<month<<"-"<<year<<endl;
}
Date globalDate;
static Date fileScopeDate;
void handleDateObj()
{
	Date today, yesterday, tomorrow;
	/*globalDate.showDate(); fileScopeDate.showDate(); today.showDate();yesterday.showDate();tomorrow.showDate();*/
	today.setDate(1,"Jul", 2015);   			
	yesterday.setDate(30,"Jun", 2015);
	tomorrow.setDate(2,"Jul", 2015);
	
	today.showDate();
	yesterday.showDate();
	tomorrow.showDate(); 

	cout<< "Temps via copy con\n";
	Date temp (yesterday); // calls a def copy con  
	//Date temp = yesterday; // do not use this style of calling a copy con as it can cause confusion with = operation 
				// (uses implicit conversion to have this statement running)	
	temp.showDate();

	cout<< "Temps via = \n";
	temp = today;  // calls a def = operation 
	temp.showDate();
}
int main()
{

	int flag=1;
	while(1==flag)
	{
		handleDateObj();
		cout<<"Enter 0 to exit" ;
		cin>>flag;
	}
}

