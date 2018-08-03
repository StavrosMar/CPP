#include <iostream>
#include <memory>

using namespace std;

/*
*
*   Topics covered: 
*                   1) What happens when assigning address of stack variable to a unique_ptr ?
*                   2) What happens when we delete the pointer managed by unique_ptr manually?
*
*/

int main()
{
    //Blow up 1
    int a{19};
    unique_ptr<int> ptr{&a}; //Blows up as expected since:
    //a is an automatic variable on the stack. unique_ptr 
    //uses delete as the default deleter which is for objects on the heap.
    //It is essentially equivalent to :  delete &a - segFault / invalid pointer is thrown;
     
    int* b = new int{12}; //Don't do that risky because of below.
    unique_ptr<int> ptr2{b};
    
    cout<<*ptr2<<'\n';
    
    //Blow up 2
    // delete b; //Blows up as expected:
    /* unique ptr is owing this space of memory 
    which means that when he goes out of scope, 
    he will attempt to delete / the contents in the memory address 
    fed when constructed : b. If we run delete before then there is nothing left for ~unique_ptr() to destroy so we get a double free error.*/
    
    
   return 0;
}
