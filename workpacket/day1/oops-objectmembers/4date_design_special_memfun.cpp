#include <iostream>
#include <cstring>
using namespace std;
class Date
{
	public:
		Date();  // dfl ctor
		Date(int);  // dtor 
		Date(const Date &); //def copy con
		Date& operator=(const Date &); //def = operator
		Date(int, const char*);
		Date(int, const char*, int);
		~Date();
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
Date::Date(const Date &rhs) //def copy con
{
	day=rhs.day;
	strcpy(month,rhs.month);
	year=rhs.year;;
	cout<<"In copy con\n";
	
}
Date& Date::operator=(const Date &rhs) //def = operator
{
	day=rhs.day;
	strcpy(month,rhs.month);
	year=rhs.year;;
	cout<<"In = operator con\n";
	return *this;
	
}
Date::Date()
{
	day=1;
	strcpy(month,"Jan");
	year=1970;
	cout<<"In ctor\n";
}
Date::Date(int d)
{
	day=d;
	strcpy(month,"Jan");
	year=1970;
	cout<<"In single param ovld ctor\n";
}
Date::Date(int d, const char* m)
{
	day=d;
	strcpy(month,m);
	year=1970;
	cout<<"In double param ovld ctor\n";
}
Date::Date(int d, const char* m, int y)
{
	day=d;
	strcpy(month,m);
	year=y;
	cout<<"In 3  param ovld ctor\n";
}

Date::~Date()
{
	cout<<"In ~dtor\n";
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
Date systemDate; // default syntesized constructor is called that initilaizes the global and static objects to universal zero

static Date fileDate; 

void handleDateObjects()
{
	Date today;
	Date temp(30);
	Date tomorrow(27,"Nov");
	Date yesterday(26,"Nov",2016);
	Date newDate ( yesterday); // copy con
	//	lhs |    rhs
	newDate.showDate();
	Date *rtDate = new Date(29,"Nov", 2016); // callling 3 pard ovld ctor;
	rtDate->showDate();
			
	systemDate.showDate();
	fileDate.showDate();

	today.showDate();
	temp.showDate();

	temp = *rtDate;  // def = operator
	
	//temp.operator=(*rtdate);

	delete rtDate;
	
	tomorrow.showDate();
	yesterday.showDate();

}
int main()
{
	handleDateObjects(); 
	int status=1;

	while(status)
		cin>>status;
;	
//	today.setDate(26,"Nov", 2016);   	
//	temp.setDate(30,"Jun", 2015);
}

