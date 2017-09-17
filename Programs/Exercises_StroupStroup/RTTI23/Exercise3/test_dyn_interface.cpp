// test_dyn_interface 
// This is a test for checking dynamic cast on objects
// where the inner classes provide more virtual functions.

#include <iostream>
#include <string>


class Interface {
public :

	virtual ~Interface(){};

	virtual void func1() {
		std::cout<<"Func1 - do nothing"<<"\n";
	};
};

class Middle : public Interface {
public:

	virtual void func1() {

		std::cout<<"Func1-Middle"<<"\n";

	};
	
	virtual void func2() {

		std::cout<<"Func2"<<"\n";
	};

};


class A : public Middle {

	virtual void func2() {

		std::cout<<"Func2-A"<<"\n";
	};
	
	virtual void func3() {

		std::cout<<"Func3-A"<<"\n";
	};
};

class B : public Middle {

	
	virtual void func2() {

		std::cout<<"Func2-B"<<"\n";
	};
};

int main() {

//Build an A and a B object
A a;
B b;

Interface* inter{&a};

auto dyn_a{ dynamic_cast<A*>(inter) };
auto dyn_b{ dynamic_cast<B*>(inter) };

if ( dyn_a == NULL ) {

	std::cout<<"Dynamic cast Inter -> A failed"<<"\n";
} else {

	std::cout<<"Address of dyn_a is"<<dyn_a<<"\n";
};

if ( dyn_b == NULL ) {

	std::cout<<"Dynamic cast Inter -> B failed"<<"\n";
} else {

	std::cout<<"Address of dyn_b is"<<dyn_b<<"\n";
};

//Pointer tests
size_t* vptr = (size_t*)(inter);
int vlen{sizeof(vptr)/sizeof(vptr[0])};

vptr = (size_t*)*vptr;


vptr = vptr+2;
((void (*) () ) *vptr)();


//TODO - end pointer not NULL - must find a different way to terminate it.
for ( int i = 0; i <= vlen ; i++ ) {

	std::cout<<"Address of vptr+1 : "<<vptr+1<<"\n";
	vptr=vptr+1;
	((void (*) () ) *vptr)();

}

return 0;

}
