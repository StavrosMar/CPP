// Template Exercises 23 book - 24 Exercises
// Exercise 2 - based on Exercise 1 working example
// Singly-linked instrusive

#include<iostream>

template<typename T>
class Link {
public:
	Link* suc;
	T val;
};

//My list
template<typename T>
class List{
public:
	//Constructor
	List():head{NULL} {};
	List(const T& t) {head = new Link<T>{0,t};};
	
	//Member functions
	void print_all() const;
	void add(const T* elem);
	void remove(const T* elem);

	Link<T>* head;
	
	//Destructor
	~List() {
	
	Link<T>* suc;
	for(Link<T>* p = head; p; p=suc) {
		std::cout<<"Deleting object with \" T Val \" equal to "<<p->val<<std::endl;
                suc=p->suc;
	        delete p;
	}
	};
	
};

template<typename T>
void List<T>::add(const T* elem) {
	
	//pos is not a member of the class - it is just defined here locally
	//the memory allocated is deleted by looping through all the elements of the list
	Link<T>* pos = new Link<T>;
	pos->suc = head;
	head = pos;
	head->val = *elem;
}

template<typename T>
void List<T>::remove(const T* elem) {

	// This is to remove the Element from the list (only the first encounter)
	Link<T>* pprev;
	pprev=NULL;
	int casse=0;
	for(Link<T>* p = head; p; p=p->suc) {
		if (*elem==p->val) {
			if (p==head) {
				head=head->suc;
			}
			else {
				pprev->suc = p->suc;
				casse=1;
			}
		}
	
		if (casse==1) {
			delete p;
			break;
		} else {
			pprev=p;
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
	
	List<int> li(23);
        
	int num1(43);
	int num2(243);
	li.add(&num1);
	li.add(&num2);


	Rec obj1("mana","lakones");
	Rec obj2("patrikas","latas");

	List<Rec> lr(obj1);
	lr.add(&obj2);
	
	f(li,lr);

	std::cout<<"****After Deletion*****"<<std::endl;
	li.remove(&num1);
	lr.remove(&obj1);
	f(li,lr);
	
	return 0;
}

/*
int main() {

	List<int> ptr1=aux();
//	std::cout<<"And the value \" T Val \" is"<<ptr1.head->val<<std::endl;
        
// ** Memory Management test ** //
// If the below is uncommented we should a get a double free corruption i.e. cannot deallocate the memory allocated to the address twice.
//	delete ptr1.head;
	
	return 0;

	
}*/
