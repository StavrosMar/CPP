// This is an example of passing a function
// as a template parameter on a declaration (e.g. f ,g in do_work)

#include <iostream>

int f(int x) { return 2 * x; }
int g(int x) { return -3 * x; }

// Take a look at : https://en.wikipedia.org/wiki/Typedef
typedef int (*F)(int);

template<F f> 
int do_work() 
{ 
    return f(7);
} 

int main()
{
    std::cout << do_work<f>() << '\n'
              << do_work<g>() << '\n'; 
}
