// This is an example of passing a function
// as a template parameter on a declaration (e.g. f ,g in do_work)

#include <iostream>

const char* f(int x) { return "skl"; }
const char* g(int x) { return "fsl"; }

// Take a look at : https://en.wikipedia.org/wiki/Typedef
typedef const char* (*F)(int);

template<F f> 
const char* do_work() 
{ 
    return f(7);
} 

int main()
{
    std::cout << do_work<*****f>() << '\n'
              << do_work<******g>() << '\n'; 
}
