/*
 * assignementOperators_copy_move_inheritance.cpp
 *
 *  Created on: 9 May 2018
 *      Author: staurosmarinis
 *      Description : Assignement operations
 *      			- building custom constructor
 */

#include <iostream>
#include <initializer_list>
#include <new>

using namespace std;

int trh = 0;

//Just building a CompArray initialised by initiliaser_list for fun.
class CompArray{

private:
	int* t1;
	size_t sizeT;

public:


	//Need CUSTOM COPY Constructor!!! - if not DANGER!! the pointer value is copied instead of contents!!!!
	//TODO!!!!!


	CompArray(const size_t& i_size, const std::initializer_list<int>& i_list) : sizeT{i_size} {

		t1 = new int[sizeT];
		std::cout<<"Creating object for t1 on address:"<<t1<<endl;
		int i=0;
		for(auto x : i_list) {
			// or like that t1[i]= x;
			*(t1+i) = x;
			std::cout<<"Constructing"<<t1[i]<<"\n";
			++i;
		}

		if (trh ==1) {

			//throw std::runtime_error("Explicit Throw triggered");
		}

	};

	void printElements() {

		for(int i=0;i<sizeT;++i) {

			std::cout<<t1[i]<<" ";
		}

		std::cout<<endl;

	}

	~CompArray() { std::cout<<"Calling Destructor for t1 on address:"<<t1<<endl; delete t1;};
};

class Base {
private:
	CompArray* cmp;

public:

	Base(const initializer_list<int>& il) {

		cmp = new CompArray(il.size(), il);
		std::cout<<"Current Address CompArray:"<<cmp<<endl;
	}

	Base& operator=(const Base& b) {

			if (this != &b ){

				// If exception is thrown - issue in construction of CompArray
				// i.e. in the constructor call - i am covered.
				CompArray* cmp2;
				cmp2 = new CompArray(*b.cmp); //Custom CompArray Constructor ESSENTIAL!!!DANGER!!!

				std::cout<<"cmp2 construction successful - no Exception thrown"<<endl;

				//Deleting resources i.e. current cmp;
				delete this->cmp;
				std::cout<<"Deleting address"<<this->cmp<<"\n";

				//Make my cmp to point to the initially created object;
				cmp = cmp2;
				std::cout<<"Cmp=Cmp2 address after"<<this->cmp<<"\n";
			};

			return *this;
	};

	void print() const{
		cmp->printElements();
	}

	~Base() {delete cmp;};

};


class Deriv : public Base {

private:


public:

};

/*
int main() {

	std::initializer_list<int> il{1,2,3,4}, il2{6,6,6};

	Base b1{il}, b2{il2};

	b1.print();
	b2.print();

	std::cout<<"##### After executing assignement operator ####"<<"\n";

	b2 = b1;
	b1.print();
	b2.print();

	trh = 1;

	std::cout<<"##### Avant finir ####"<<"\n";

	return 0;

}
*/


