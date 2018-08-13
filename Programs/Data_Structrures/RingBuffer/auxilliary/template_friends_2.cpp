/*
*
*     Topics covered:
*                    1) Making all specialisations of the class friends of the class so that i write less code
*                       Similar / Extension of vol. 1 file...
*
*/

using namespace std;
#include <iostream>
template <class T,bool Const>
class A {
    //Making all template specialisations(private scope) visible to all
    template<class U,bool b> friend class A; //Note that here no :: is needed.
    int i;
  public:
    template <class U, bool b> void copy_i_from( const A<U,b> & a ){
        i = a.i;
    }
};

int main(void) {
    A<int,true> ai;
    A<double,false> ad;
    ai.copy_i_from(ad); 
    return 0;
}
