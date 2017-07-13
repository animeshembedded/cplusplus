#include <stdio.h>
#include <string.h>
struct Date
{
	void (*fp_setDate)(struct Date*, int , const char*, int);
	void (*fp_showDate)(struct Date*);
	int day;
	char month[4];
	int year;
};
typedef struct Date Date;
void setDate(Date *this, int d, const char* m, int y)
{
	this->day=d;
	strcpy(this->month,m);
	this->year =y;
}
void showDate(Date* this)
{
	printf("Date is now: [%d/%s/%d] \n", this->day, this->month, this->year);
}
int main()
{
	Date today;
	//this is what compiler generate in c++
	today.fp_setDate = setDate;
	today.fp_showDate = showDate;
	//this is what compiler generate in c++
	today.fp_setDate(&today, 24,"feb",2015); 
	today.fp_showDate(&today); 
}


