#include "functions.h"

template <class T> int factorial<T>::fac(int n){
   
   if(n!=1){
      return(n * factorial(n-1));
   }
   else return 1;
}
