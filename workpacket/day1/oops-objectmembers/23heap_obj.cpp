// example 
#include <iostream>
#include <cstdlib>
using namespace std;
class Person
{           
        public:
        Person() {   
                cout<<"In deflt ctor\n";
                data = new char[20];
                strcpy(data,"sample data");
        }   
        void showdata() {   
                cout<<" data is now " << data <<endl;
        }   
        ~Person() {   
                cout<<"In dtor\n";
                delete []data;
        }   
        private:
        char *data;
};
int main() {
        Person *me ;

        me = (Person*)malloc(sizeof(Person));
        me->showdata(); //oops ??
        free(me);

        me = new Person;
        me->showdata();
        delete me;     

        me = new Person[10];
        for ( int i=0; i<10; ++i)
                me[i].showdata();
        delete []me;
}

