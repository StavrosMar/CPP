#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Compare object for loading inside functions requiring that.
template<typename T> class CompStavros {

public:

    CompStavros() {
        // default constructor 
        cout<< "Creating Object of Type CompStavros" << std::endl;
    }

    bool operator()(const T& obj1, const T& obj2) {
        
        return ((obj1.second > obj2.second ) ? true : false);
        
    }
};

int main()
{
    priority_queue< pair<int,int>, std::vector< pair<int,int> >, CompStavros<pair<int,int>> > pq;
    
    vector<pair<int,int>> vp { {1,2}, {3,8}, {9,5}};
    
    //pushing Stuff inside the priority queue
    for (auto x : vp) {
        
        pq.push(x);
        
    }
    
    //While priority queue is not empty
    while (!pq.empty()) {
        
        cout<<"Top is :"<<pq.top().first << "\n";
        
        pq.pop();
        
    }
     
   return 0;
}
