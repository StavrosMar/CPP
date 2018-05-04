//This is a quick test / review for 
// virtual functions.
// Would just like to remember implementation after having learned java interfaces

#include<iostream>


class Interface {
public:

	virtual void printName() =0;
	//WARNING !!need Virtual Destructor otherwise it will not run the derived classes' destructors
	// Proof of concept that the delete operations directly a1,a2 work fine.
    ~Interface() { std::cout<<"Calling Interface destructor"<<std::endl; };

};


class ImplClass1 : public Interface {
 
 public:
    void printName() {
        
        std::cout<<"I am ImplClass 1"<<'\n';
    }
    
    ~ImplClass1() { std::cout<<"Calling ImplClass1 destructor"<<'\n';};
    
};

class ImplClass2 : public Interface {
 
 public:
    void printName() {
        
        std::cout<<"I am ImplClass 2"<<'\n';
    }
    
   ~ImplClass2() { std::cout<<"Calling ImplClass2 destructor"<<'\n';};
    
};

int main() {

    ImplClass1* a1 = new ImplClass1;
    Interface*  p1 = a1;
	p1->printName();
	
    ImplClass2* a2 = new ImplClass2;
    Interface*  p2 = a2;
	p2->printName();
	
    delete p1;
    delete p2;
   
    //WARNING - If I do not have a virtual destructor defined in the interface, then these deletions will pose no issue
    delete a1;
    delete a2;
   
    return 0;
}

