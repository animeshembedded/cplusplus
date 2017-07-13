#include <iostream>
#include <cstring>
using namespace std;

#include "tcp"
#include "ip"
using namespace INET_IPV4;
int main()
{
	
	
	strcpy(tcpheader.buffer, "Dummy TCP Buffer");
	strcpy(ipheader.buffer, "Dummy TCP Buffer");

	cout<< INET_IPV4::tcpheader.buffer <<endl;

	namespace inet = INET_IPV4;

	cout << inet::tcpheader.buffer <<endl;	
}	
