// Template Exercises 23
// Exercise 1 : Fix the errors and make a quick example

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
	Link<T>* head;
	Link<T>* pos;
public:
	List():head{NULL}, pos{NULL} {};
	List(const T& t) : head{new Link<T>{0,0,t}} {pos = head;};
	void print_all() const;

	~List() {delete head;};
	
};

template<typename T>
void List<T>::print_all() const
{
	for(Link<T>* p = head; p; p=p->suc)
		std::cout<<p->val<<std::endl;
}


class Rec {
public:	
        Rec(const std::string a,const std::string b) : name{a}, address{b} {};
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

int main() {
	
	List<int> li(23);
	
	Rec obj1("mana","pateras");
	
	List<Rec> lr(obj1);
	
	f(li,lr);
	return 0;
}
