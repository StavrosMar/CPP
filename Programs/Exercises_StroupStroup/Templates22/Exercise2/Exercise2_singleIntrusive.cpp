// Template Exercises 23 book - 24 Exercises
// Exercise 2 - based on Exercise 1 working example
// Singly-linked instrusive

//*******Na to kanw virtual class etsi wste oi pointer Link* na douleuoune 
// gia inherited objects. Check virtual notes
#include<iostream>

template<typename T>
class Link{
public:
       //Constructors 
       Link(T t) :  val{t}, suc{NULL} {};

       //Members
       Link<T>* suc;
       T val;
};


// Wrapper for conversion of any type
template<typename T>
class PatrikoMani : public Link<T>{
public:
//Constructors
      //**We do not need to construct base members - they will be constructed by Base (Link) .e.g for suc
    //    PatrikoMani(T t) : val{t} {};

    // Inheriting constructors from Link
  using Link<T>::Link;

//operators//

   //ostream operator//
friend std::ostream& operator<<(std::ostream &out, const PatrikoMani<T>& t) {
	
	std::string stream(t.val);
	out<<stream;
	
	return out;
};

};

//My list
template<typename T>
class List{

	Link<T>* head;
public:
        List<T>() : head{NULL} {};
	//Member functions
	void print_all() const;
	void add(Link<T>* elem);
	void remove(Link<T>* elem);	
	
};

template<typename T>
void List<T>::add(Link<T>* elem) {

    	elem->suc = head;
	
	head = elem;
	
//	std::cout<<head->suc->val<<std::endl;

}

template<typename T>
void List<T>::remove(Link<T>* elem) {

	for (Link<T>* p=head ; p ; p->suc) {
		if (p->suc == elem) {
			p->suc = elem->suc;
			break;
		}
	}
}


template<typename T>
void List<T>::print_all() const
{
	for(Link<T>* p = head; p; p=p->suc)
		std::cout<<p->val<<std::endl;
}


class Rec {
public:	
        Rec(const std::string a,const std::string b) : name{a}, address{b} {};
        Rec() :  name{""},address{""} {};
	std::string name;
	std::string address;
 

        // Define operator for ostream. friend is needed so that std::cout can access the object dt.	
	friend std::ostream& operator<<(std::ostream &out, const Rec &dt) {
           std::string stream(dt.name+"  |   "+dt.address);
	   out<<stream;
	   return out;
        };

	// Define equality operator
	bool operator==(Rec& obj) const;

};

bool Rec::operator==(Rec& obj) const {
	if (address == obj.address && name == obj.name) {
		return 1;
	} else {
		return 0;
	}
}

void f(const List<int>& li, const List<Rec>& lr)
{
	li.print_all();
	lr.print_all();
}

int main() {
	
	List<int> li;

	PatrikoMani<int> num1(21);
	PatrikoMani<int> num2(243);
	li.add(&num1);
	li.add(&num2);


	PatrikoMani<Rec> obj1(Rec("mana","lakones"));
	PatrikoMani<Rec> obj2(Rec("patrikas","latas"));

	List<Rec> lr;
	lr.add(&obj1);
	lr.add(&obj2);
	
	f(li,lr);

	std::cout<<"****After Deletion*****"<<std::endl;
	li.remove(&num1);
	lr.remove(&obj1);
	f(li,lr);

	return 0;
}
