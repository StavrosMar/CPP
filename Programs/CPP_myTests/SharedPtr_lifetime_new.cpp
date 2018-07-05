#include <iostream>
#include <memory>

/*
*
*       Topics covered:
*                       1) Deleting object allocated with new 
                            where a shared_ptr to an object 
                            is included in the structure.
                            Result: the instance of this object is removed
                            and the use_count reduced.
*
*
*/

using namespace std;

template <class T> class Node {
public:
    std::shared_ptr<T> data;
    Node* next;
    Node(T const& data_):
    data(std::make_shared<T>(data_))
    {}
};


int main()
{
   Node<int>* head = new Node<int>(180);
  
  cout<<"Use count before s1: "<<head->data.use_count()<<'\n';
 
  shared_ptr<int> s1{head->data};
  
  cout<<"Use count after s1 :"<<s1.use_count()<<'\n';

  delete head;
  
  cout<<"Use count after deleting node :"<<s1.use_count()<<'\n';
  
  return 0;
}
