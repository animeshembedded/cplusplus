#include <iostream>
using namespace std;
struct Point
{
	int x;
	int y;
};
static Point x1={0,0};
Point freturnValue()
{
	// local obj returns cannot be used after the call so a copy
	return x1;
}
Point* freturnAddress()
{
	return &x1; // ok because x1 is a global object
			// never return stack objects
}
Point& freturnRefrence()
{
	return x1; // ok because x1 is a global object
			// never return stack objects
}
void fvalue(Point rhs)
{
	rhs.x =100;
	rhs.y =200;
}
void faddress(Point *rhs)
{
	rhs->x =100;
	rhs->y =200;
}
void frefrence(Point &rhs)
{
	rhs.x =1000;
	rhs.y =2000;
}
void showPoints(const Point &rhs)
{
	cout<<"Points (x,y) at ("<<rhs.x<<","<<rhs.y<<")"<<endl;
}	
void handleRefrenceDemo()
{
	//independent refrence 
	int data=100, y=90;	
	int &r = data; // r is an alias to data
	++r;
	r = y;
	++r;
	// what is x and y after thie ?
	cout<<"X = "<<data<<" and Y = "<<y<<endl;
	fvalue(x1);
	showPoints(x1);	
	faddress(&x1);
	showPoints(x1);	
	frefrence(x1);  // note the call is similar as pass by value
	showPoints(x1);	

	Point t1 = freturnValue();
	t1.x = 788;
	showPoints(x1);
	Point *t2 = freturnAddress();
	t2->x=900;
	showPoints(x1);
	Point &t3 =  freturnRefrence();
	t3.x=800;
	showPoints(x1);	
}
int main()
{
	handleRefrenceDemo();
}
