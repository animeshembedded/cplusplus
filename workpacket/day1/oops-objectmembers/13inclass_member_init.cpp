#include<iostream>
#include<string>
class MyValues
{
	public:
	void showValues();
	private:
	int day =5; 
	char month[4] = {"May"};
	int year=2015;
	const double pi=3.14159;
	static int objCount;
  // Arrays, Non-integral and non-const statics 
  // must be initialized externally:
  static const int scInts[];
  static const std::string cmd;;
};
int MyValues::objCount=0;

const int MyValues::scInts[]={1,2,3,4,5};
const std::string cmds[] ={ "active","standby","offline","onlne","down"};
void MyValues::showValues()
{
	int i;
	std::cout<<day<<"|"<<month<<"|"<<year<<"|"<<pi<<std::endl;
	std::cout<<"scInts:\n";
	for(i=0;i<5;++i)
		std::cout<<scInts[i]<<std::endl;
	
	for(i=0;i<5;++i)
		std::cout<<cmds[i]<<std::endl;
}
int main()
{
	MyValues oMyValues;
 	oMyValues.showValues();		
}	

