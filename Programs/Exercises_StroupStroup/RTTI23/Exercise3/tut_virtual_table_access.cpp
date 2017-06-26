#include<iostream>
using namespace std;
 
class Base
{
public:
    virtual void display()  //virtual function
    {
        cout<<"\nBase : display()..";
    }
 
    virtual void goodMorning() //virtual function
    {
        cout<<"\nBase : Good morning..";
    }
};
 
class Derived:public Base
{
public:
    void display()  //virtual by default
    {
        cout<<"\nDerived : display()..";
    }
 
    //Derived does not override goodMorning()
};
 
int main()
{
    Derived d1;
    int *vptr=(int *)&d1;  //vptr points to Derived object
 
    //Virtual pointer is stored in first 2 bytes of object
    vptr=(int *)*vptr; //copy virtual pointer (first 2 bytes) into vptr
 
    //Now content of vptr is nothing but address of VTABLE
 
    //call display()
    ((void (*)()) *vptr )();  
    //*vptr is address of first virtual function in VTABLE viz. display()
//and we cast VPTR to a function pointer 
 
    ++vptr;  //move 2 bytes ahead
 
//access second function in Derived's VTABLE viz.Base::goodMorning()
    ((void (*)()) *vptr )();  
 
    return 0;
}
