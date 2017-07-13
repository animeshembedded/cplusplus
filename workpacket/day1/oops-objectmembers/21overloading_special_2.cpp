#include <iostream>
#include <cstring>
#include <string>
#define ARR_INDEX_OUT_OF_BOUND 0xFF 
using namespace std;
class Max
{
	public:
	Max(int a=0, int b=0): l(a), r(b)
	{
	}
	int operator()(int a, int b)
	{
		l=a;
		r=b;
		return l>r?l:r;
	}
	private:
	int l,r;	
};
class List
{
	public:
	void setData(const int &index, const int &data);
	void showList() const;
	int getListSize(){ return size;}
	//int operator[](int index);	
	int& operator[](int index);	
	private:
	static const int size = 20;
	int array[size]={0}; // ok c++11 on wards
};
void List::setData(const int &index, const int &data){
	if (index>=0 && index < this->getListSize() )
	{
		array[index] = data;	
	}
	else
	cerr<<"Array index out of bounds\n";
}
void List::showList() const {
	cout<<"List of ints: (";
	int i;
	for (i=0;i<size; ++i)
		cout<<array[i]<<", ";
	cout<<")\n";
}
int& List::operator[](int index)
{
	return array[index]; // ain't checkin for out of bounds	
}	
#if 0
int List::operator[](int index)
{
	if ( index >=0 && index < this->getListSize() )
		return array[index]; // ain't checkin for out of bounds	
	else
		return ARR_INDEX_OUT_OF_BOUND;
}
#endif	
class Person
{
	public:
	Person(){ 
		age=0;
		name="No Name";
		qualificaton = "None";
		address =" None";
		phoneno = "None";
	}
	private:
	friend ostream& operator<<(ostream &lhs, const Person &rhs);
	friend istream& operator>>(istream &lhs, Person &rhs);
	int age;
	string name;
	string qualificaton;
	string address;
	string phoneno;
};
//overloading a global stream function
ostream& operator<<(ostream &lhs, const Person &rhs)
{
	cout<<"The Person\'s details: \n\t(";
	lhs<<rhs.age<<", ";
	lhs<<rhs.name<<", ";
	lhs<<rhs.qualificaton<<", ";
	lhs<<rhs.address<<", ";
	lhs<<rhs.phoneno<<")";
	cout<<endl;
	return lhs;
}  
istream& operator>>(istream &lhs, Person &rhs)
{
	cout<<"Enater the Person\'s details: \n";
	lhs>>rhs.age;
	lhs>>rhs.name;
	lhs>>rhs.qualificaton;
	lhs>>rhs.address;
	lhs>>rhs.phoneno;
	return lhs;
}  
void handleStreamOperators()
{
	Person animesh;
	cin>>animesh; 
	cout<<animesh<<endl;	
}
void handleSpecialOverloads()
{
	List ilist;  // ilist is an array 50 ints
	int i;
	for(i=0;i< ilist.getListSize(); i++)
		ilist.setData(i, 7 + i*i);
//	cout<< ilist[0] << endl;	
 	ilist[0] = 777;    // try to have this working
 	cout<< ilist[0] << endl;	
	//ilist.showList();
	
	Max mobj;

	cout<< mobj(134,34) <<endl;
	cout<< mobj(134,340) <<endl;
}
int main(){
	handleStreamOperators();
//	handleSpecialOverloads();
}

