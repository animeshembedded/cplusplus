#include<iostream>
#include<cstring>
#include<new>
#include<cassert>
#include<cstdlib>
using namespace std;
class X{
public:
	static new_handler set_new_handler(new_handler p);					   
	static void* operator new(size_t size);
	static void operator delete(void* p);
private:
	static new_handler current;
};
new_handler X::current; // sets to 0(A null by default)
new_handler X::set_new_handler(new_handler p) {
	new_handler old = current;
	current = p;
	return old;
}
void * X::operator new(size_t size) {
	cout<<"IN our placememt form new\n";
	new_handler global = ::set_new_handler(current);
	void* memory;
	try {
		memory = ::operator new(size);
	}
	catch(bad_alloc a) {			
		set_new_handler(global);
		throw ;
	}
	::set_new_handler(global); // here we cani custom memory 
	return memory;
}
void X::operator delete(void* p) {
	cout<<"IN our placememt form delete\n";
	::operator delete (p);	
}
void no() {
	cerr<<"Unable to allocate Memory:-(\n"<<endl;
	abort();
}
int main(void) {
	void no();
	X::set_new_handler(no);
	X *p1 = new X[5];
	X *p2 = new X;
	X::set_new_handler(0);
	X* p3 = new X;
	cout<<"Hi"<<endl;
	delete []p1; delete p2; delete p3;
	return 0;
}


