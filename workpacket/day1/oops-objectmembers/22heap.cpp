#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;
int main()
{
	int *ip ;
	
	ip = (int*)malloc(sizeof(int));
	//use as long as ip is need by use
	//remove once donce	
	*ip = 0xFF;
	free(ip);
	// data are implicitly initialized 
	ip = new int(0xFF);
	//use as long as ip is need by use
	
	//remove once donce	
	delete ip; 

	ip = new int[10] {12,34,56,8,78,9, 34, 67, 677};
	// c++11 style

	//c++03 way of handling array list :-(	
	#if 1 
	int i=0;
	for( i=0; i< 10; ++i)
		*(ip+i) = i + i*i;
	#endif 
	for(int i=0; i< 9; ++i)
		cout<< *(ip+i) <<endl ;//= i + i*i;
			
	delete [] ip;
} 

