//basic initialation C++03
int n=0;
void*p=0;
char c='A';

int n(0); //same as int n=0;
double d(0.5);

//C++03 initialization of classes and objects
struct S1
{
explicit S1(int n, int m) : x(n), y(m){} //mem-init
private:
 int x, y;
};
S1 s(0,1); //object initializers enclosed in parentheses
S1 s2={0,1}; //compilation error

//C++03: POD arrays and structs are aggregates
int c1[2]={0,2};
char c2[]="message";
//or you can use the more verbose form:
char c3[]={'m','e','s','s','a','g','e','\0'};
struct S
{
int a,b; };
S s={0,1};
// array in a class
class C
{
int x[100];
C(); //no proper way to initialize x
};
// not even with container in stl  (c++03))
vector <string> vs;
vs.push_back("alpha");
vs.push_back("beta");
vs.push_back("gamma");

//C++11 uniform initializer
int n{}; //zero initialization: n is initialized to 0
int *p{}; //initialized to nullptr
double d{}; //initialized to 0.0
char s[12]{}; //all 12 chars are initialized to '\0'
string s{}; //same as: string s;
char *p=new char [5]{}; // all five chars are initialized to '\0'
// in class initialization for x as explained in earlier slides 
class C
{
int x;
public:
C() : x(7) {}
};
};
// some more in class member initialization
class C
{
string s("abc");
double d=0;
char * p {nullptr};
int y[5] {1,2,3,4};
public:
C();
};
// a more extensive example
class C2
{
string s;
double d;
char * p;
int y[5];
public:
C() : s("abc"), d(0.0), p(nullptr), y{1,2,3,4} {}
};
//Bear in mind that if the same data member 
//has both a class member initializer and a mem-init in the constructor, 
//the latter takes precedence.








































































//c++03
string a[] = { "foo", " bar" };       // ok: initialize array variable
vector<string> v = { "foo", " bar" }; // error: initializer list for non-aggregate vector
void f(string a[]);
f( { "foo", " bar" } );// syntax error: block as argument

int a = 2;              // ``assignment style''
int aa[] = { 2, 3 };    // assignment style with list
complex z(1,2);         // ``functional style'' initialization
x = Ptr(y);             // ``functional style'' for conversion/cast/construction

int a(1);	// variable definition
int b();	// function declaration
int b(foo);	// variable definition or function declaration


//c++11  
//The C++11 solution is to allow {}-initializer lists for all initialization:
	X x1 = X{1,2}; 
	X x2 = {1,2}; 	// the = is optional
	X x3{1,2}; 
	X* p = new X{1,2}; 
	struct D : X {
		D(int x, int y) :X{x,y} { /* ... */ };
	};
struct S {
   int a[3];
   S(int x, int y, int z) :a{x,y,z} { 
	/* ... */  
   }; // solution to old problem
};
/* Importantly, X{a} constructs the same value in every context, 
so that {}-initialization gives the same result in all places where 
it is legal. For example:
*/
	X x{a}; 
	X* p = new X{a};
	z = X{a};         // use as cast
	f({a} );           // function argument (of type X)
	return {a};       // function return value (function returning X)

