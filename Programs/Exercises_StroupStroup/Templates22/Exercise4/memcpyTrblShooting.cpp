// This is a program made to troubleshoot why memcpy is not working for long strings in my Exercise4.cpp example (explicit constructor)

#include <string.h>
#include <iostream>

int main ()
{
   
   const char* srv = "lalalal4444444444444442dddddddddddddddddddddddeeeeeeeeeeedddddddddddddddddd222222222444444444lalallalalalla";
   const char* destil;
   
   
   // sizeof is the size in bytes. The size in bytes is the one required by memcpy
   memcpy(&destil, &srv, sizeof(srv) );
   
   std::cout << destil << std::endl;
   
   typedef char typos;
   
   typos lola = "nikofl";
   typos* nikos{lola};
   
   std::cout << "The size of lola is :" << sizeof(lola) << std::endl;
   std::cout << "The size of nikos before copy is :" << sizeof(nikos) << std::endl;
   
   memcpy(nikos, lola, sizeof(lola));
   
   std::cout << "The size of double is " << sizeof(typos) << std::endl;
   std::cout << "The size of nikos after copy is :" << sizeof(nikos) << std::endl;
   
   std::cout << "The size of nikos after copy is :" << *(nikos+1) << std::endl;
   
   return 0;
}
