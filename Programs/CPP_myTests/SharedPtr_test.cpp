#include <iostream>
#include <memory>
#include <thread>

/*
    Topics:
            1) Shared_ptr : Verify when the object goes out of scope - gets deleted.

*/

using namespace std;

template <typename T> class Base
{
private:
    T t;
    
public:
        Base(const T& t) : t{t} {};
        ~Base() { cout<<"calling destructor"<<'\n'; print();};

        void print() {
            
            cout<<t<<'\n';
        }
};

template<typename T> void keepSharedptrAlive(shared_ptr<T> sp) {
   // std::shared_ptr<Base<int>> lp = sp;
    std::this_thread::sleep_for(1s);
    cout<<"Threadfini"<<'\n';
}



int main()
{
   
   shared_ptr<Base<int>> sp{new Base<int>(19)};
   shared_ptr<Base<int>> p = sp;
   cout<<"usecount:"<<sp.use_count()<<'\n';
   //thread t1(keepSharedptrAlive<Base<int>>, sp);
   //t1.detach();
    cout<<"usecount:"<<sp.use_count()<<'\n';

   
   sp.reset(); // reducing user_count by 1 - one object handling this memory location is dead
   p.reset(); // p pointing to the same object / memory so pointer goes down to 0 and the destructor of Base is called
    cout<<"usecount:"<<sp.use_count()<<'\n';
  // sp.reset(new Base<int>(9));
   
   return 0;
}
