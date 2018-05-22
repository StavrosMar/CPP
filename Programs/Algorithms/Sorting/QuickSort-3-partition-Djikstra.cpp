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

template <typename T> class Compare{

public:
	int operator()(const T& a, const T& b) const {
		
		int res{0};
		
		if (a < b) {
		
			res=-1;
		} else if (a > b) {
		 
		 	res=1;
		}
		
		return res;
	}
};
		

void sort(int* A, const int& lo, const int& hi) {
    
    if ( hi <= lo) { return;} 
    
    int lt{lo};
    int i{lo+1};
    int gt{hi};
    
    Compare<int> cmp;
	int res{0};
    while ( i <= gt ) {
    
    	res = cmp(A[i],A[lo]);
    	
    	cout<<"A[i]="<<A[i]<<"  A[lo]="<<A[lo]<<"\n";
    	    	
        if ( res < 0 ) {
        
        	cout<<"Entered neg"<<"\n";
            swap(A[i],A[lt]);
            ++i;
            ++lt;
            
        } else if (res > 0) {
        	cout<<"Entered pos"<<"\n";        
            swap(A[i],A[gt]);
            --gt;
            
        } else {
        	cout<<"Entered ++i"<<"\n";        
            ++i;
        }
        
    }
    
    sort(A,lo,lt-1);
    sort(A,gt+1,hi);

}

int main() {
    
    //Input
    const size_t sizeA{5};
    int A[sizeA]={11,90,76,89,7};
    
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
