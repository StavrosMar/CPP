// Template Exercises 23 Book - 24 Exercises
// Exercise 4 - Started from scratch

#include <iostream>
#include <cstring>

//String class declaration


// My custom strlen
namespace srv {

template<typename C>
int strlen(const C* c, int maxLen = 100000000 ) {
	
	int i = 0;

	while ( (i + c) != NULL && i < maxLen ) {
		
		++i;

	}

	std::cout << "*i+x is equal to : " << c << std::endl;
	
	return i;

};

}

		


template<typename C>
class String {
public:
	//Constructors
	String() : sz{0}, ptr{ch} { ch[0] = 0; };
	String(const String<C>& obj) { copy_from(obj); }; // copy constructor
	String(String<C>&& obj)      { move_from(obj); }; // move constructor
	explicit String(const C* c) : sz{ int(std::strlen(c)) },  ptr{(sz<=short_max) ? ch : new C[sz+1]}, space{0} { std::memmove(ptr, c, sizeof(C)*(sz+1) );}

	//Operators
	String& operator=(const String<C>& x); // copy assignment
	String& operator=(String<C>&& x);     // move assignment

	C& operator[](int n) { return ptr[n]; } //unchecked elem access
	C operator[](int n) const { return ptr[n];}

   	C& at(int n) {check(n); return ptr[n];}
	C  at(int n) const { check(n); return ptr[n];}


	String& operator+=(const C c); //add c at the end

	const C* c_str() {return ptr;}
	const C* c_str() const {return ptr;}

	int size() const {return sz;}
	int capacity() const
	     { return (sz<=short_max) ? short_max : sz+space;}

        //Access functions
        const C* begin() const;
        const C* end() const;

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
	void move_from(String& );

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
//	std::strcpy(p,ptr);       //copy the value alt 1
	std::memmove(p,ptr,std::strlen(ptr)); // copy value alt 2
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
	
	std::cout << "** Copy executed to :**" << *this << std::endl;
}

  //move_from
template<typename C>
void String<C>::move_from(String<C>& x) {

	std::cout<< "** Move executed on : **" << x <<std::endl;

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
 //Access functions
template<typename C>
const C* String<C>::begin() const {
	
	return ptr;

}

template<typename C>
const C* String<C>::end() const  {
	
	return ptr+sz;

}

//Operator Declarations

template<typename C>
String<C>& String<C>::operator+=(const C c) {
      
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
std::ostream& operator<<(std::ostream& os, const String<C>& s) {
	
	for(auto x : s ) {   // in order auto to work String must have begin() and end() functions defined.
		os<<x;
		//std::cout<<s.begin[i]<<std::endl;
	}

	return os;
}

<<<<<<< HEAD
//template<typename C>
//String<C>& operator+=
=======
template<typename C>
String<C>& operator+=(String<C>& a, const String<C>& b) {
	
	for (auto ci : b) {

		a+=ci;
	}
	std::cout << "Kalestike" << std::endl;	
	return a;
}
>>>>>>> b968307f43411e924fc0a455ec5c7edd556044f9

template<typename C>
String<C> operator+(const String<C>& a, const String<C>& b) {
    
    String<C> res{a};
    res+=b;
    return res;
    
}

template<typename C>
String<C> operator+(const String<C>& a,const C& c) {
    
    String<C> res{a};
    res+=c;
    return res;
    
}

// Main - Entry point //
int main() {

//Test1 - String test for chars
	String<char> manika;
        manika+='8';	
        manika+='9';	

        std::cout<<manika<<std::endl;      
/*
//Test2 - String test for ints
	String<int> patrika;
        patrika+=1;	
        patrika+=2;	

        std::cout<<patrika<<std::endl;      
<<<<<<< HEAD
 //       std::cout<<*begin(manika)<<std::endl;      
 	
=======
 
// Test3 - += operator test for strings
        
	String<int> stavros;
	stavros+=4;
	patrika+=stavros;
        std::cout<<patrika<<std::endl;
*/
// Test 4a - copy from

	String<char> lola{manika};
	std::cout<< lola << std::endl;


// Test4 - + operator test for strings

	// We are passing an rvalue here manika+chara. 
	// ** compiler has copy elision by default ** (will not run move if not needed to)
	// ** if we want to disable it compile like the following : -fno-elide-constructors
	char chara = '8';
	std::cout<< "**** Before String / char concat call "<<std::endl;
	String<char> nikos(manika+chara);
	std::cout<< "##### After String / char concat call "<<std::endl;
        
	// same but validation on const chars e.g. 3 and that manika has not altered
	// throughout the operations
	String<char> maria(manika+'3');
	std::cout<< maria << std::endl;
	std::cout<< "Manika is " << manika << std::endl;

// Test5 - + for more than 1 strings
        std::cout<< (nikos + manika) << std::endl;


// Test6 - normal string
	
	//Constructor test
	String<char> pappous{"Ioannis Leftheriotis ths Annas kai tou Giorgi"}; // explicit C-style string constructor called
	std::cout << "Pappous = " << pappous << std::endl;


	//Operator += test
	nikos += String<char>{"abcdefghijklmnoprstuvwxyz"}; // Does not work because I have not provided an implicit constructor
	std::cout << nikos << "D" << std::endl;
	                        // from a C type string. so this would have been equivalent to nikos+= String("manika lola")


	return 0;
}
