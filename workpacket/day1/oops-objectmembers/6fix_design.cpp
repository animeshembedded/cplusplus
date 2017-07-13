// we have a missing namespace person, can you build one for us?
#include <iostream>
#include "person"
using namespace std;
using namespace myperson;

Person::Person()
{
	PersonName = (char*)malloc(8);
	strcpy(PersonName,"NoName");
	PersonAge = 0;
	PersonID = 0;
	cout<<"Iniializing person defaults\n";
}
Person::Person(const char* name, int age, int id)
{
	PersonName = (char*)malloc(strlen(name)+1);
	strcpy(PersonName,name);
	PersonAge = age;
	PersonID = id;
	cout<<"Iniializing person defaults by explicit ctor\n";
}
Person::~Person()
{
	free(PersonName); 
	PersonAge = -1;
	PersonID = -1;
	cout<<"cleaning person defaults\n";
}
void Person::setName(const char *name)
{
	if ( strlen(name) > strlen(PersonName) )
	{
		free(PersonName);
		PersonName = (char*)malloc(strlen(name)+1);
	}	
	strcpy(PersonName,name);
}
void Person::setAge(const int &age)
{
	//age=99;
	PersonAge = age;
	//PersonID =-1;
} 
void Person::setID(int &id)
{
	PersonID =id;
}
void Person::getName()
{
	cout<<"Name: " << PersonName <<endl;
}
void Person::getAge() 
{
	PersonAge=-999;
	PersonID = 1223;
	cout<<"Age: " << PersonAge <<endl;
}
void Person::getID()
{
	cout<<"ID: " << PersonID <<endl;
} 
void showPersons(Person &person)
{
	person.getName();
	person.getAge();
	person.getID();
}
void design_aspects()
{
	int age=42;
	int id=23,did=100;
	Person me("Ani",age,id);
	Person deepak;
	
	deepak.setName("Deepau");
	deepak.setAge(age);
	deepak.setID(did);
	
	showPersons(me);
	showPersons(deepak);	
}
int main()
{
	design_aspects();
}
