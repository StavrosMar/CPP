// *Using array<> operations instead of simple array
// *Using char as index on an array - implicit conversion to ascii
#include <iostream>
#include <string>
#include <array>


using namespace std;

int main()
{
  
  //256 because ASCII
  const int R{256},C{10};
  
  array<array<int,C>,R> arr;
  
  // Filling 2D array 
    // Classic way
  for (int i=0; i<R ; ++i) {
      arr[i].fill(3);
  }
    //Iterator way
  for (auto r : arr ) {
        r.fill(3);
  }
  
   
  string str{"Chou12*^%"};
  
  arr[67][4] = 180; 
  arr[104][4] = 30;
  arr[67][4] = 90;

  for (auto c : str) {
      
      cout<<"Casting char"<<c<<"to int is :"<<(int)c<<"\n";
      cout<<"Value is :"<<arr[c][4]<<"\n";
      
  }
 
}
