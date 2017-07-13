/*
Available since C
-----------------
void init(void);
void init(parms);
int  init(void);
double init( int , string );
int init(int known, ...);

C++ specifics:
------------------
1. default args
2. inline function
3. function overloading (compile time polymorphism )
   (constructor overloading, operator overloading) 	
*/
#include <iostream>
#include <cstring>
using namespace std;
struct List
{
	int id;
	char name[20];
	bool stat;
};
List oListSample;

void init_list(int i=0, const char *n="No name", bool s=false){
	oListSample.id =i;
	strcpy(oListSample.name, n);
	oListSample.stat = s;	
}
void printList(List *l)
{
	cout<<"List Details:\n";
	cout<<"Id: "<<l->id <<endl;
	cout<<"Name: "<<l->name <<endl;
	cout<<"stat: "<<l->stat <<endl;
}

struct Point
{
	int x;
	int y;
};
Point x1;

int Abs(int data){
	return data>0? data: -data;
}
inline void init_point(int x, int y)
{
	Abs(x);
	Abs(y); 
	//calling non inline function in an inline function
	// might not be accepted as inline function		
	x1.x = x;
	x1.y = y;
}

int main()
{
	init_point(12,40);  // jump 

#if 0
	init_list(0xFFFF, "Sample Name"); // all the deafult is used
	printList(&oListSample);
	// all pass
	init_list(0xFE, "List A", true);
	printList(&oListSample);
#endif
}






