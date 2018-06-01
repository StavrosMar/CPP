// CODILITY demo test description

/* Write a function int solution(vector<int> &A) 

    that given an array A of N integers, returns the smallest 
    positive integer (greater than 0) that does not occur in A.
    
    For example fiven A=[1,3,6,4,1,2] the function should return 5.
                      A=[1,2,3]                                  1.
                      A=[-1,-3]                                  1.
                      
    N : [1....100k]
    A : [-1million, 1million]

Complexity: worst-case time complexity  O(N)
            worst-case sapce complexity O(N)
            (not counting the storage required for input args)
            
*/

//Some comments on the solution

/* We need for O(N) worst case time complexity,
   Any classical method of sorting the vector would take O(NlogN).
   We could use the first stage of Counting Sort but that would mean a penalty > O(N) in memory
   since the largest number of A is 1 order of magnitude larger than max N.
   
/ For the above reasons it would make sense to use a tree-like structure.
  Insertion and search take O(logN) time, space is at worst O(N) (duplicate keys are not saved) roughly which is pretty good.
  I could have used std::set instead of std::map below since we are not using the data stored under the keys.
*/

#include <map>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    map<int,int> myMap;
    
    for (auto x : A) {
        myMap[x] = x;
    }
    
    int res{1};
    
    if (prev(myMap.cend())->first > 0 && myMap.cbegin()->first == 1 ) {
        
        bool cond{true};
        
        auto it = next(myMap.begin(),1);
        
        while ( cond)  {
            
            if( (it->first - prev(it,1)->first) > 1 || it == myMap.end()) {
            
                cond = false;
                res = prev(it,1)->first+1;
            }
            ++it;
        }
    }
    
    return res;
}


//Unit Test
int main() {
    
    vector<int> A = {-11,5,4,5,6};
    int integro{solution(A)};
    
    cout<< integro <<"\n";
    
}
