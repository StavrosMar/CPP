<<<<<<< HEAD
// Test for pointers vs Arrays
=======
// PointerVSArray test
>>>>>>> c641dd1cdb0b7edab5d96331bf9066aa17dd0586

#include <iostream>

int main()
{

// stavros is actually a pointer pointing to the start of the array
 int stavros[3]={1,2,3};

// getting p to point to the same memory address as stavros - thus we can access it the same way as we do with stavros
 int* p=stavros;
 
 std::cout<< *stavros << std::endl;         //dereferencing the pointer
 std::cout<< *(stavros + 1) << std::endl;   //getting actually stavros[0+1] (as 0 is where stavros is pointing to)
 std::cout<< *(p + 1) << std::endl;
 std::cout<< stavros[1] << std::endl;
 std::cout<< p[1] << std::endl;
 
 return 0;
}
