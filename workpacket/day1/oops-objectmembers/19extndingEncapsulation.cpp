#include <iostream>
using namespace std;
class Circle;
class Rect;
class ShapeCalculator
{
	public:
	void solveAreaofAllShapes(Circle &c, Rect &r);
	void foo();
};
class Rect
{
	public:
	Rect(int x=1,int y=1):l(x), b(x)
	{}
	private:
	int l,b;
	friend void calcAllShapesArea(Circle &c, Rect &r);
	friend class ShapeCalculator;
};
class Circle
{
	public:
	Circle(int r=1):pi(3.14159), radius(r)
	{	
	}
	private:
	int radius;
	const double pi;
	//friend class ShapeCalculator;

	friend void ShapeCalculator::solveAreaofAllShapes(Circle&,Rect&);

	friend void calcAllShapesArea(Circle &c, Rect &r);
};

void ShapeCalculator::solveAreaofAllShapes(Circle &c, Rect &r)
{
	double totalarea = 0.0;
	totalarea = c.pi * c.radius * c.radius  + r.l * r.b;   
	cout<<"solving in ShapeCalculator class : totalarea = "<<totalarea <<endl;
}
void ShapeCalculator::foo()
{
		Circle c;	
	//	c.radius = 9; // ??
}

void calcAllShapesArea(Circle &c, Rect &r)
{
	double totalarea = 0.0;
	totalarea = c.pi * c.radius * c.radius  + r.l * r.b;   
	cout<<"totalarea = "<<totalarea <<endl;
}
int main()
{
	Rect oRectX(100,40);
	Circle oCircleY(100); 
	calcAllShapesArea(oCircleY, oRectX);
	ShapeCalculator oShapeCalculator;
	oShapeCalculator.solveAreaofAllShapes(oCircleY, oRectX);
}

