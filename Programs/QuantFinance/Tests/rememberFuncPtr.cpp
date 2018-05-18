#include <iostream>
#include <map>
#include <string>
using namespace std;

//Remember function pointer

void fun1(const double& a) { cout<<"I am fun1"<<"\n"; };

/*
int main()
{
   //typedef for func ptr
   typedef void (*F)(const double&);

   map<string,F> m1{ {"fun1",fun1}  };
   m1["fun1"](3);

}
*/
