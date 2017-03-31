// Template Exercises 23 Book - 24 Exercises
// Exercise 4 - Started from scratch

#include <iostream>

//String class declaration
template<typename C>
class String {
public:
	//Constructors
	String() : sz{0}, ptr{ch} { ch[0] = 0; };
	explicit String<C>(const C*) {};
	String<C>(const String<C>& obj) { copy_from(obj); }; // copy constructor
	String<C>(String<C>&& obj)      { move_from(obj); }; // move constructor

	//Operators
	String& operator=(const String<C>& x); // copy assignment
	String& operator=(String<C>&& x);     // move assignment

	C& operator[](int n) { return ptr[n]; } //unchecked elem access
	C operator[](int n) const { return ptr[n];}

   	C& at(int n) {check(n); return ptr[n];}
	C  at(int n) const { check(n); return ptr[n];}


	String& operator+=(C c); //add c at the end

	const C* c_str() {return ptr;}
	const C* c_str() const {return ptr;}

	int size() const {return sz;}
	int capacity() const
	     { return (sz<=short_max) ? short_max : sz+space;}

        //Access functions
        const C* begin();
        const C* end();

	//Destructor
	~String() { if (short_max<sz) delete[] ptr;}
private:
	static const int short_max = 15; // for the short string optimization - (if sz < short_max then save stuff in the object of this class)
	int sz;
	C* ptr; // ptr points to sz Cs

	//union used for the short-string optimisation
        // only one of the two members will actually be valid at all times. (the one that was written last)
	union {
		int space;
		C ch[short_max+1];
	};

	//auxiliary member functions
        void check(int) const ;// range check function
	void copy_from(const String&);
	void move_from(String&& );

};

// Ancillary functions
template<typename C>
void String<C>::check(int n) const // range check
{
	if (n<0 || sz<=n)
		throw std::out_of_range("String::at()");
}

template<typename T>
T* expand(const T* ptr, int n) // expand into free store
{
	T* p = new T[n]; //allocate n positions to the free store
	*p = *ptr;       //copy the value
	return p;
}

  //copy_from : make *this a copy of x
template<typename C>
void String<C>::copy_from(const String<C>& x) {

	if (x.sz<=short_max) {
		memcpy(this,&x,sizeof(x)); // copy *this  - Book43.5
		ptr = ch;
	}
	else {                             //copy elements
		ptr = expand(x.ptr, x.sz+1);
		sz = x.sz;
		space = 0;
	}
}

  //move_from
template<typename C>
void String<C>::move_from(String<C>&& x) {

	if (x.sz<=short_max) {
		
		memcpy(this,&x,sizeof(x));
		ptr = ch;
	}
	else {

		ptr = x.ptr;
		sz = x.sz;
		space = x.space;
		x.ptr = x.ch;
		x.sz = 0;
		x.ch[0]=0;
	}
}

//Access function declarations
template<typename C>
const C* String<C>::begin() {
	
	return ptr;

}

template<typename C>
const C* String<C>::end() {
	
	return ptr+sz;

}

//Operator Declarations

template<typename C>
String<C>& String<C>::operator+=(C c) {
      
	if (sz == short_max) {
		
		int n = sz + sz + 2;
		ptr = expand(ptr,n);
		space = n-sz-2;

	}
	else if (short_max < sz) {
	
		if ( space == 0 ) {
			
			int n = sz+sz+2;
			C* p = expand(ptr,n);
			delete[] ptr;
			ptr = p;
			space = n-sz-2;
			
		}
		else 
		{
			--space;
		}
	}
	
	ptr[sz] = c; // Actuall assignement takes place;
	ptr[++sz] = 0;

	return *this;

}      

template<typename C>
String<C>&  String<C>::operator=(const String<C>& x) { // copy assignment

	if (this==&x) return *this; // dealing with self-assignment
	C* p = (short_max<sz) ? ptr : 0;
	copy_from(x);
	delete[] p;  //deletes memory allocate (if any) already for the current object. 
	return *this;

}

template<typename C>
String<C>& String<C>::operator=(String<C>&& x) { // move assignment

	if (this==&x) return *this; //dealing with self-assignment
	if (short_max<sz) delete[] ptr;
	move_from(x);
	return *this;

}

// Non member functions / operators

template<typename C>
std::ostream& operator<<(std::ostream& os, String<C>& s) {
	
	for(auto x : s ) {   // String must have begin() and end()
                             // for more  constPointersForLoop.cpp 
		os<<x;
	}

	return os;
}

template<typename C>
String<C>& operator+=(String<C>& a, const  String<C>& b) {
	
	for (auto ci : b) {

		a+=ci;
        }
	
	return a;
}

// Main - Entry point //
int main() {


//Test1 - String test for chars
	String<char> manika;
        manika+='8';	
        manika+='9';	

        std::cout<<manika<<std::endl;      

//Test2 - String test for ints
	String<int> patrika;
        patrika+=1;	
        patrika+=2;	

        std::cout<<patrika<<std::endl;      
 
// Test3 - += operator test for strings
        
	String<int> stavros;
	stavros+=4;
	patrika+=stavros;
        std::cout<<patrika<<std::endl;
	
	return 0;
}
