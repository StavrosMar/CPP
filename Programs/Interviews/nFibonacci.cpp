// Fibonnacci n series 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;



int main () {
    
    
    cout << " Give me iterations number" << "\n";
    
    int N;
    cin >> N ;
    
    int prevnum(0);
    int num(1);
    
    
    for (int i(0); i<=N ; ++i) {
        
        int fib= num + prevnum;
        
        cout << "Fib" << fib << "\n";
        
        prevnum = num;
        num = fib;
        
    }
    
    return 0;
}
