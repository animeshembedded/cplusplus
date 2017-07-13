#include<string>
class Date
{
  public:
	Date(int d, std::string m, int y):day(d),month(m),year(y)  
	{
	}
	Date(std::string m, int d, int m)
	{
		month = m;
		day = d;
		year =y;	
		}
   private:
	int day;
	string month;
	int year;
};
int main()
{
	Date today1( 5,"May",2017);
	Date today2( "May",5,2017);
}	

