#include <iostream>
#include <ios>

/* Topic covered:
                1) C-style casting on Structures - triggered by UNIX socket programming interface
*/

using namespace std;

struct socketaddr_stav {
    unsigned long sa_family;
    unsigned long int   sa_int;
    char sa_data[9];
};

struct struct1 {
    unsigned short sin_family;
    char sin_zero[5];
    unsigned long sin_port;
    
};

int main()
{
   struct1 s1;
   s1.sin_family = 9;
   s1.sin_port = 51000;
   
   socketaddr_stav* stav = (socketaddr_stav*)&s1;
   
   cout<<stav->sa_family<<"\n";
   cout<<stav->sa_int<<"\n";
   
   cout<<"Addres of s1            :"<<(&s1)<<"\n"; // Same address as the first element in the structure
   cout<<"Addres of s1.sin_family :"<<(&s1.sin_family)<<"\n";
   cout<<"Addres of s1.sin_port   :"<<(&s1.sin_port)<<"\n";
   cout<<"Addres of s1.sin_zero   :"<<(&s1.sin_zero)<<"\n";

   
   cout<<"Size Of :"<<sizeof(char)<<"\n";

   return 0;
}
