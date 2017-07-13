
#include <iostream>
#include <new>
#include <cstring>
using namespace std;
class String {
	public:
	String();
	~String();
	String(const char *);
		
	private:
	char* data;
};
String::String() {
	data = new char[10];
	strcpy(data,"NoName");
}
String::~String() {
	delete []data;
}
String::String(const char *str) {
	data = new char [ strlen(str) +1];
	strcpy(data, str);
}
void shallow_deep() {
	String sa("Hello Here");
	String sb;
	
	sb = sa;

	String temp (sa);	
}
int main()
{
	shallow_deep();
	while(1)
	;
}
