#include <iostream>

using namespace std;

void swap(char* x, char* y) {
    
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
    
}

void permutations(char *a,const int& l,const int& r) {
    
    if ( l == r) {
        
        cout<< a << "\n";
        
    } else {
        
        for (int i=l ; i<=r; i++ ) {
        
            swap( (a+l), (a+i));    
             permutations(a, l+1, r);
            swap( (a+l), (a+i));
        }
    }
    
}


int main() {
    

   cout << "Provide string" << endl; 
   
   std::string istr;
   
   cin >> istr;
   
   permutations(&istr[0],0,istr.size()-1);
   
   return 0;
}
