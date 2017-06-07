//RTTI23 - Exercise 2
//Illustration of constructor and destruction calls relative to RTTI

//<Details>



#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <typeinfo>

namespace stavros {

	//* functions defined here *//

} 

class Frouto {
public:

	//Constructors
	Frouto() { std::cout<<"Constructing Frouto"<<std::endl; this->print(); };

	//Destructors
	virtual	~Frouto() { std::cout<<"Destruction Frouto"<<std::endl; };

	//Functions
	virtual void print() { std::cout<<"I am frouto"<<std::endl; _a = 1; };

	//Members
	int _a;
};


class GlykoFrouto : public virtual Frouto {
public:

	//Constructors
	GlykoFrouto() { 
		std::cout<<"Constructing GlykoFrouto"<<std::endl; 
		
		
		//GlykoFrouto* ptr = dynamic_cast<GlykoFrouto*>(this);
		//ptr->print();
		
		ptr_glykoFrouto = dynamic_cast<GlykoFrouto*>(this) ;
		
		//std::cout<<"The most derived type is :"<<typeid(this).name()<<'\n';

		std::cout<<"GlykoFrouto : End of construction"<<std::endl; 
		this->print(); //BUT this is pointing to Banana - however Banana is not constructed yet so the virtual finds the latest one constructed which is here!!!!
		};

	//Destructors
	~GlykoFrouto() { std::cout<<"Destruction GlykoFrouto"<<std::endl; };
	
	//Functions
	void print() { std::cout<<"I am GlykoFrouto"<<std::endl; _a=2;};
	
	GlykoFrouto* ptr_glykoFrouto;
};

class Banana : public  GlykoFrouto {
public:

	//Constructors
	Banana() { 
	
		std::cout<<"Constructing Banana"<<std::endl; 
		std::cout<<"!!!Calling virtual Functions"<<std::endl;
		ptr_glykoFrouto->print(); //this is a Banana pointer afterall!!!
		dynamic_cast<Banana*>(ptr_glykoFrouto) == NULL ?
		std::cout<<"!!!Banana - Failed dynamic cast!!!"<<std::endl :
		std::cout<<"!!!Banana - Cast Successful!!!"<<std::endl;
	};

	//Destructors
	~Banana() { std::cout<<"Destruction Banana"<<std::endl; };

	//Functions
	 void print() { std::cout<<"----I am Banana"<<std::endl; _a=3;};

};

class Appricot : public virtual GlykoFrouto {
public:

	//Constructors
	Appricot() { std::cout<<"Constructing Appricot"<<std::endl; };

	//Destructors
	~Appricot() { std::cout<<"Destruction Appricot"<<std::endl; };

	//Functions
	 void print() { std::cout<<"----I am Appricot"<<std::endl;};

};

//class child one

//class child two

int main() {


//TEST1
std::cout<<"\n#### RTTI Example 1 #####\n"<<std::endl;

Frouto* frou_ban = new Banana;

std::cout<<"Value of _a After construction = "<<frou_ban->_a<<std::endl;

auto cast_1 = dynamic_cast<GlykoFrouto*>(frou_ban); //cast to GlykoFrouto - true as a casting from a Banana pointer to a Glykofrouto is valid

auto cast_2 = dynamic_cast<Banana*>(frou_ban);   //cast to Banana - true as frou is a Banana

if (cast_1 == NULL || cast_2 == NULL) { std::cout<<"!!!Banana - Failed dynamic cast!!!"<<std::endl;};
delete frou_ban;
//TEST1-END



//TEST2
std::cout<<"\n#### RTTI Example 2 #####\n"<<std::endl;

Frouto* frou_app = new Appricot;

auto cast_app = dynamic_cast<Banana*>(frou_app); //cast Appricot -> Banana - invalid
if ( cast_app == NULL) { std::cout<<"!!!Appricot - Failed dynamic cast!!!"<<std::endl;};

delete frou_app;
//TEST2-END

//TEST3
Frouto* frou_gl = new GlykoFrouto;

std::cout<<"\nFinalTest\n"<<std::endl;

frou_gl->print();
	
return 0;

}
