#include <iostream>
/*
*
*   Topics covered:
*                  1) Basic Factory class
                      SJPerfHouse is tuning cars 
*   
*/
using namespace std;

//Interface
class PerfComponent {
    
public:
    virtual void tune() = 0;
};

//Turbo
class Turbo : public PerfComponent {
    
public:
    void tune() {
        cout<<"Performance Tuning of turbo pressure"<<'\n';
    }
};

//Ignition
class Ignition : public PerfComponent {
    
public:
    void tune() {
        cout<<"Performance Tuning of ignitor advance"<<'\n';
    }
};

//Factory
    //TODO - Could make CreateComponent static | also memory management (?) - who is doing it.
class SJPerfHouse {
    
public:
    PerfComponent* CreateComponent(const string& s) {
        
        if(s=="Turbo") {
            return new Turbo();
        } else if (s=="Ignition") {
            return new Ignition();
        }
    }
    
};

int main()
{
   
   
}
   
