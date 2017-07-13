/*  Uniform Initialization */
// C++ 03
#include <iostream>
#include <string>
using namespace std;
class Person {     // Aggregate class or struct
   public:
      int age;
      string name;
};
// C++ 11 extended the scope of curly brace initialization
class Device {
   public:
      Device(int){}	
      Device(int id, string name) {}
};
class MyDevice {
   public:
   int devid;                                // 3rd choice
   MyDevice(int a) {                            // 2nd choice
      devid = a;
   }
   MyDevice(const initializer_list<int>& vec) { // 1st choice
      devid = *(vec.begin());      
   }
};
int main()
{
  Person  Henry = {5, "Henry"};   // Aggregate Initialization
  Device d1 = {1234, "Evalution"}; 
  Device d2{3};
  MyDevice mydev1 = {0x1};
  MyDevice mydev2 (0x2);
  MyDevice mydev3 {0x3};
}
/* Uniform Initialization Search Order:
 * 1. Initializer_list constructor
 * 2. Regular constructor that takes the appropriate parameters.
 * 3. Aggregate initializer.
 */


