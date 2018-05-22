#include <iostream>
#include <string>
#include <random>

using namespace std;
//TODO : with iterators

void randomise (int* A, const size_t sizeA) {
    
    std::random_device rd;
    std::mt19937 bitGen(rd());
    std::uniform_int_distribution<> distr(0,sizeA-1);
     
    for (unsigned int i = sizeA-1 ; i<sizeA ; --i) {
        
        std::swap(A[i],A[distr(bitGen)]);
    }
        
}


void sort(int* A, const int& lo, const int& hi) {
    
    if ( hi <= lo) { return;} 
    
    int lt{lo};
    int i{lt+1};
    int gt{hi};
    
    while ( i <= gt ) {
    
        
        if (std::less<int>()(A[i],A[lo])) {
            swap(A[i++],A[lt++]);
        } else if (std::less<int>()(A[lo],A[i])) {
            swap(A[i],A[gt--]);
        } else {
            ++i;
        }
        
    }
    
    sort(A,lo,lt-1);
    sort(A,gt+1,hi);


}

int main() {
    
    //Input
    const size_t sizeA{10};
    int A[20]={112,90,76,73,60,32,23,12};
    
    //Randomisation
        //Array before
    for (unsigned int i = 0; i<sizeA ; ++i) {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
    
    randomise(A,sizeA);
        //Array after randomisation
    for (unsigned int i = 0; i<sizeA ; ++i) {
        cout<<A[i]<<" ";
    }
    cout<<"\n";
    
    //Run 3-way quicksort
    sort(A,0,sizeA-1);
    
        //Array after 3-way quicksort
    for (unsigned int i = 0; i<sizeA ; ++i) {
        cout<<A[i]<<" ";
    }
    
    return 0;
}
