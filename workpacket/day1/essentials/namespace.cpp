#include <iostream>
using namespace std;
int data=1;
namespace MyDecl
{
	int data=2;
	void functionx(int x) { cout<<" in int form ovld\n";}
	void functionx()
	{
		data=0x55;
	}		
	struct Book
	{
		char name[50];
		int pages;
		double price;
	}cpp={"C++ Internals", 300, 24.5};
} 
void handleNamespaces()
{
	int data=3;
	using namespace MyDecl;  
//	using MyDecl::cpp;
	using MyDecl::functionx(int);

	functionx(); // is exposed 
	functionx(10); // is exposed 
 	MyDecl::data = 199;
	cout<< ::data  <<endl;   // anonymous scope resolution operator
	cout<< data  <<endl;  // always a local 
	cout<<"Book Details: ["<< MyDecl::cpp.name <<" - "<<MyDecl::cpp.pages << " - " << MyDecl::cpp.price <<endl;
}

int main()
{
handleNamespaces();
}

