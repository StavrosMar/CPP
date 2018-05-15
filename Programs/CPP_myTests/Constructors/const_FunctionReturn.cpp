#include <iostream>

/* Topics covered
    
    1) const on return of a function

*/

template <typename T> class A {
    
public:

    /*  const used in the return value to deal with assigning the value to a const object on main for example.
        Equivalent to having 2 functions, one for const and another
        one for non-const objects.
    */
    const A& getA() const& {
        
        return *this;
    }
    
};

int main() {
    
    A<int> a,c;
    
    //const A& in return value so we can bind it to constant b.
    const A<int> b = a.getA();
    
    return 0;
    
}
