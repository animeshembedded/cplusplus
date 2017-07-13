#include<string>
class Circle
{
  public:
	Circle():pi(3.14159)
	{
		circleLabel = "Circle Noname";
		radius=100.57;
	}
	Circle(std::string l, double r):pi(3.145)
	{
		circleLabel = l;
		radius= r;
	}
	Circle(const Circle &rhs): pi(3.14)
	{
		circleLabel = rhs.circleLabel;
		radius = rhs.radius;	
	}
   private:
	std::string circleLabel;
	double radius;
	const double pi;
};
int main()
{
	Circle c1;// calls default ctor
	Circle c2("My Circle", 1002.0); // calls param ctor
	Circle c3 (c2); // calls copy con 
}	

