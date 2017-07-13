// initializer_list_class.cpp  
#include <initializer_list>  
#include <iostream>  
using namespace std;
void printIntsList(initializer_list<int> list)
{
	initializer_list<int>::iterator fi;
	for ( fi = list.begin(); fi!=list.end(); ++fi)
		cout<<*fi<<endl;
}
int main()  
{  
    using namespace std;  
    // Create an empty initializer_list c0  
    initializer_list <int> c0;  
    // Create an initializer_list c1 with 1 element  
    initializer_list <int> c1{ 3 };  
    // Create an initializer_list c2 with 5 elements   
    initializer_list <int> c2{ 5, 4, 3, 2, 1 };  
    // Create a copy, initializer_list c3, of initializer_list c2  
    initializer_list <int> c3(c2);  
    printIntsList(c0);	 
    printIntsList(c1);	 
    printIntsList(c2);	 
    printIntsList(c3);	 
    cout << endl;  
}  
