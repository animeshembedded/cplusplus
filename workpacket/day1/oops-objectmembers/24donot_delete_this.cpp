#include <iostream>
using namespace std; 
class Dummy{
  int m_value;
public:
  Dummy(int val) : m_value(val)
  {}
  void  destroy();
  void  displayValue();
  void  displayText();
};
void Dummy::destroy(){
  delete this;
}
void Dummy::displayValue(){
  std::cout << this->m_value << std::endl;
}
void Dummy::displayText(){
  std::cout << "Not accessing any member function" << std::endl;
}
int main(){
  Dummy * dummyPtr = new Dummy(5);
  dummyPtr->destroy();
  dummyPtr->displayText();
  //Calling this function can crash your application
  // because duppyPtr is already deleted.
  //dummyPtr->displayValue();
  /* Creating an object on stack and calling deleting this pointer
   * inside member finction will also crash the application
      Dummy obj;
      obj.destroy()*/
  return 0;
}

