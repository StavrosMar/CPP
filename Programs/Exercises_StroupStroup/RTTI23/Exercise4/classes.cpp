//Example virtual class structure 


class Base {

public:
	virtual ~Base() { std::cout<<"Calling virtual Base Destructor" <<"\n"; };
};

class D : public Base {
public:
	// func1
	void func1() {
	
		std::cout<<"D::func1"<<"\n";
	}
	// func2
	void func2() {
	
		std::cout<<"D::func2"<<"\n";
	}
};

class E : public Base {
public:
	// func3
	void func3() {
	
		std::cout<<"E::func3"<<"\n";
	}
	// func4
	void func4() {
	
		std::cout<<"E::func4"<<"\n";
	}

};

