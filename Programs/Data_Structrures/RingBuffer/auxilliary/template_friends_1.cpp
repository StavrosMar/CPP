/*
*
*     Topics covered:
*                    1) Making all specialisations of the class on the 2nd argument friends of the class so that i write less code
*                       It was needed for rg_iterator_Elegant to combine the code for const and non-const iterators.
*
*/

using namespace std;
#include <iostream>

template <class T,bool Const>
class A {
  
    //
    template<bool b> friend class ::A; // :: is needed here
    
    int i;
  public:
    template <bool b> void copy_i_from( const A<T,b> & a ){
        i = a.i;
        if (b == true) {
            cout<<"copying from object where b is true\n";
        } else {
            cout<<"copying from object where b is false\n";
        }
    }
};    

int main(void) {
    A<int,false> ai;
    //A<double,true> ad; //it does not compile - expected.
    A<int,true> at; //copying from object where b is true
    A<int,false> af; 
    ai.copy_i_from(at); //
    ai.copy_i_from(af);
    return 0;
}
