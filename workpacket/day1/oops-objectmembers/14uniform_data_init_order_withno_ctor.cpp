#include <iostream>
#include <string>
using namespace std;
class class_d {  
public:  
    float m_float;  
    string m_string;  
    wchar_t m_char;  
};  
int main()  
{  
    class_d d0{};  
    class_d d1{ 4.5 };  
    class_d d2{ 4.5, "string" };  
    class_d d3{ 4.5, "string", 'c' };  
  
//    class_d d4{ "string", 'c' }; // compiler error  
//    class_d d5("string", 'c', 2.0 }; // compiler error  
}   

