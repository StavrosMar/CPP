/*
*   Topics covered:behaviour
*                   1) Verify  when swapping two shared_ptrs.
*
*/

#include <iostream>
#include <memory>

using namespace std;

 shared_ptr<int> s1{new int(12)};

void test() {
    
    shared_ptr<int> s2;
    cout<<"In func - Before swap: s2 = "<<s2.use_count()<<'\n';
    s2.swap(s1);
    cout<<"In func - After swap: s1 = "<<s1.use_count()<<" , s2 = "<<s2.use_count()<<'\n';


}

int main()
{
  cout<<"In main - Before swap s1 "<<s1.use_count()<<'\n';
  test();
}
