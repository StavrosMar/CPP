// Template Exercises 23 book - 24 Exercises
// Exercise 2 - based on Exercise 1 working example

#include<iostream>

template<typename T>
struct Link {
	Link* pre;
	Link* suc;
	T val;
};

//My list
template<typename T>
class List{
public:
	//Constructor
	List():head{NULL} {};
	List(const T& t) {head = new Link<T>{0,0,t};};
	
	//Member functions
	void print_all() const;
	void add(const T* elem);

	Link<T>* head;
	Link<T>* testLink;
	
	//Destructor
	~List() {
    	std::cout<<"Deleted head object with \" T Val \" equal to "<<head->val<<std::endl;
    	delete head;
    	
		};
	
};

template<typename T>
void List<T>::add(const T* elem) {
	
	//pos is not a member of the class - it is just defined here locally
	Link<T>* pos = new Link<T>;
	pos->suc = head;
	pos->pre = NULL;
	testLink = pos;
	head = pos;
	head->val = *elem;
	//memory managementfor pos for when
	//the list goes out of scope
	// 

}
/*
template<typename T>
void List<T>::add_original(const T* elem) {
	Link<T>* prev(pos);
	++pos;
	prev->suc = pos;
  	pos->pre = prev;
	pos->val = *elem;
	pos->suc = NULL;
}
*/

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

};

void f(const List<int>& li, const List<Rec>& lr)
{
	li.print_all();
	lr.print_all();
}

List<int> aux() {
	
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
	
	return li;
}

int main() {

	List<int> ptr1=aux();
	std::cout<<"And the value \" T Val \" is"<<ptr1.testLink->val<<std::endl;
//	delete ptr1.testLink;
	return 0;

	
}

