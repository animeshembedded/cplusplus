#include <iostream>
#include <cstring>
#include <utility>
using namespace std;
void break_point();
class Sample
{
	public:
	void showData() 
	{ 
	  std::cout<<"data is now "<<data<<std::endl;
	}
	void setData(int x) { data =x;}
	private:
	int data;
};
int main()
{
	static Sample oSampleA, temp[10]; // def ctor
	Sample oSampleB (oSampleA); //def copy con

	Sample *pSampleC = new Sample(); 
	temp[0] =  *pSampleC; // def = operator

	oSampleA.showData();
	oSampleB.showData();
	pSampleC->showData();

	temp[2] = oSampleB;
	Sample oMovedC(std::move(temp[2]));

	temp[1]	= std::move(temp[0]);
	
	delete pSampleC; // must use to invoke dtor
	
	break_point();	
}
void break_point()
{
	std::cout<<"Enter 0 to exit >=1 to loop in!!: ";
	int quit=1;
	while( quit)
		std::cin>>quit;
}

