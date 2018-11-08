/*
*
*
*   Topics covered : 1) Binary Search non recursive.
*                    2) Test on randomized data.
*                    3) Neat with lamda expressions.
*
*/

#include <iostream>
#include <array>
#include <random>
#include <algorithm>

using namespace std;

/* WARNING this is for Asceding order */
bool exists(const int* A, size_t sz, int x) {
    
    int hi = sz-1;
    int lo = 0;
    int mid;
    
    int cond = 1;
    
    bool found = false;
    
    int count{0};
    
    while (cond>0 && !found) {
        ++count;
        mid = (hi + lo) / 2; // Could take into account nature of data i.e. distribution
        if ( A[mid] == x) {
            found = true;
        } else if ( A[mid] < x) {
            lo = mid+1;
        } else {
            hi = hi-1;
        }
        cond = hi - lo +1;
    }
    
    cout<<"Array length "<<sz<<" items"<<endl;
    cout<<"Algorithm Run for "<<count<<" iterations"<<endl;
    
    return found;
}


int main()
{
    
    const int sz = 1000;
    int x = 50;
    
    // First create an instance of an engine.
    random_device rnd_device;
    // Specify the engine and distribution.
    mt19937 mersenne_engine {rnd_device()};  // Generates random integers
    uniform_int_distribution<int> dist {1, 100};
    
    //Build lamda
    auto gen_lamda = [&mersenne_engine, &dist]() -> int {return dist(mersenne_engine);};

    array<int,sz> A;
    //Fill array
    for (int i=0; i<sz ;++i) {
        A[i] = gen_lamda();
    }
    
    //Sort Array in asceding order (by default);
    std::sort(A.begin(),A.end());
    
    //Run function.
    exists(A.data(),sz,x) ? cout<<x<<" Value found in A"<<endl : cout<<x<<" Value NOT found in A"<<endl;
   
   return 0;
}
