//RTTI23 - Exercise 2
//Illustration of constructor and destruction calls relative to RTTI

//<Details>



#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

namespace stavros {

	//* functions defined here *//

} 

class Frouto {
public:

	//Constructors
	Frouto() { std::cout<<"Constructing Frouto"<<std::endl; };

	//Destructors
	virtual	~Frouto() { std::cout<<"Destruction Frouto"<<std::endl; };

	//Functions
	virtual void print() { std::cout<<"----I am Frouto"<<std::endl;};

};

class GlykoFrouto : public virtual Frouto {
public:

	//Constructors
	GlykoFrouto() { std::cout<<"Constructing GlykoFrouto"<<std::endl;this->print(); };

	//Destructors
	~GlykoFrouto() { std::cout<<"Destruction GlykoFrouto"<<std::endl; };
	
	//Functions
//	 virtual void print() { std::cout<<"----I am GlykoFrouto"<<std::endl;};


};

class Banana : public virtual GlykoFrouto {
public:

	//Constructors
	Banana() { std::cout<<"Constructing Banana"<<std::endl;this->print(); };

	//Destructors
	~Banana() { std::cout<<"Destruction Banana"<<std::endl; };

	//Functions
	 void print() { std::cout<<"----I am Banana"<<std::endl;};

};

//class child one

//class child two

int main() {

std::cout<<"#### RTTI start #####"<<std::endl;

Frouto* frou = new Banana;
auto hand = dynamic_cast<Banana*>(frou);

if (hand == NULL) { std::cout<<"!!!Failed dynamic cast!!!"<<std::endl;};

delete frou;
	
//TEST1 - Sorting Matrices
	
	//-//Set-up
	
	
	//-//Calling point


	//-//Print results
	
//TEST1 - END

	return 0;

}
