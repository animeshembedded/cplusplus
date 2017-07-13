#include <iostream>
#include <cstring>
using namespace std;

class Point
{
	public:
	Point(int a=0, int b=0):x(a),y(b) 
	{}
	Point operator+(const Point &rhs);
	Point operator+(const int &rhs);
	void showPoints() const; 
	void operator++(int) ; //postfix
	void operator++(); //prefix
	private:
	int x,y;
	friend Point operator+(const int &lhs, const Point &rhs);
};
Point Point::operator+(const Point &rhs)
{
	cout<<"In obj=rhs form\n";
	Point t;
	t.x = x + rhs.x;
	t.y = y + rhs.y; 
	return t;
}
Point Point::operator+(const int &rhs)
{
	cout<<"In int=rhs form\n";
	Point t;
	t.x = x + rhs;
	t.y = y + rhs; 
	return t;
}
void Point::showPoints() const 
{
	cout<<"Points at ("<<x<<","<<y<<")\n";
}
//global overloaded + operator for lhs is not a c++ obj
Point operator+(const int &lhs, const Point &rhs)
{
	cout<<"In global overloaded + operator for lhs is not a c++ obj\n";
	Point t;
	t.x = lhs + rhs.x;
	t.y = lhs + rhs.y; 
	return t;
}
void Point::operator++(int)  //postfix
{
	cout<<"Post increment\n";
	x++;
	y++;
}
void Point::operator++() //prefix
{
	cout<<"Pre increment\n";
	++x;
	++y;
}

void overloadingDemo()
{
	Point origin;
	Point x1(2,4);
	Point x2(34,56);
	Point x3 = x1 + x2;
	x3.showPoints();
	//origin = x3 + 10;
	origin.operator+(10);
	origin.showPoints();
	x3 = 30 + origin;
	x3.showPoints();
	//++origin; 	
	origin.operator++();
	origin.showPoints();
	origin++;
	origin.showPoints();
}
int main()
{
	overloadingDemo();	
	return 0;
}
