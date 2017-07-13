// Define your own initializer_list constructor:
#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;
class MyArray {
   vector<int> m_vec;
   public:
   MyArray(const initializer_list<int>& v) {
      for (initializer_list<int>::iterator itr = v.begin(); itr!=v.end(); ++ itr)
         m_vec.push_back(*itr);
   }
   void printArray() {  
	cout<<__PRETTY_FUNCTION__<<endl;
	for(int i=0; i<m_vec.size(); ++i)
		cout<<m_vec[i]<<endl;
   }	 
};
// Automatic normal Initialization
class Rectangle {
   public:
   Rectangle(int height, int width, int length){ }
};
void draw_rect(Rectangle r){}
//int main() {}
int main()
{
draw_rect({5, 6, 9});  // Rectangle{5,6,9} is automatically called

MyArray va = {0, 2, 3, 4};
MyArray vb{0, 2, 3, 4};   // effectively the same

va.printArray();
vb.printArray();
}
// Note: use it with caution.
// 1. Not very readable, even with the help of IDE. Funcion name rarely indicates
//    the type of parameter the function takes.
// 2. Function could be overloaded with differenct parameter types.

