#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

template <class T> T calcDiff2(const T& f1,const T& f2) {
  
    
  
   T res = abs((f1-f2))^2;
    
   //std::cout<< "Res"<< res << "\n";
    
    return res;
    

 }
 
 template <class T> vector<T>& popVec(vector<T>& sums, const T& num, const T& prevnum,const T& f2, const T& prevf2) {
     
        int calc;
     
        calc = 1;               
        sums[0] +=calcDiff2(calc,f2/prevf2);
       // cout<<calcDiff2(calc,t) << std::endl;        

        calc = log2(num)/log2(prevnum);               
        sums[1] += calcDiff2(calc,f2/prevf2);
       
        calc = num/prevnum;               
        sums[2] += calcDiff2(calc,f2/prevf2);
                
        calc = num*log2(num)/ prevnum*log2(prevnum);               
        sums[3] += calcDiff2(calc,f2/prevf2);
        
        calc = num^2 / prevnum^2;               
        sums[4] += calcDiff2(calc,f2/prevf2);
            
        calc = (num^2)*log2(num) / (prevnum^2)*log2(prevnum);               
        sums[5] += calcDiff2(calc,f2/prevf2);
        
        calc = num^3 / prevnum^3;               
        sums[6] += calcDiff2(calc,f2/prevf2);
        
        calc = 2^num / 2^prevnum;               
        sums[7] += calcDiff2(calc,f2/prevf2);
     
        return sums;
     
 }
 
int main()
{
    // Maps an integer of the difference 
    map<int,string> diffMap { {0,"O(1)"}, {1,"O(log n)"}, {2, "O(n)"}, {3, "O(n logn)"}, {4, "O(n^2)"}, {5, "O(n^2 logn)"}, {6, "O(n^3)"}, {7, "O(2^n)"} };
    
    vector<int>  sums;
    sums.assign(8,0);
    
    int calc;
    
    int N;
    
    int num,prevnum,dx;
    int t,prevt,dy;
    int f2;
    
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
  
        cin >> num >> t;
        
        if (i !=0 ) {
            
            //dx = num - prevnum;
            //dy = t   - prevt;
            
            //f2 = dy/dx;
            
            sums = popVec(sums,num,prevnum,t,prevt);
            
        } else {
            prevnum = num;
            prevt   = t;
            
            
        }
        
    }
    
   //for_each (sums.begin(),sums.end(),[] (const int& n) { cout << n << "\n";});
 /*   
    for ( auto x : sums) {
        
        cout << x << "\n";
    }
*/    
    auto ind = std::distance(sums.begin(), std::min_element(sums.begin(), sums.end()) );
    
    cout << diffMap[ind] << "\n";
    
}
