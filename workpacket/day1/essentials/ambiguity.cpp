#include <iostream>
using namespace std;
int foo(int& rhs, bool)
{
	return rhs;	
}
int foo(int rhs)
{
	cout<<	"in val\n";
	return rhs;	
}
void a(char *x, ...)
{
}
void a(char *x, int y=0)
{
}
int main()
{
	int data=90;
	foo(data); //?
	a("one");//?
}
