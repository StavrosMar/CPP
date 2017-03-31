// Exercise 1 - fix list and compare with compiler output

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
		std::cout<<p->val;
}


class Rec {
public:	
        Rec(const std::string a,const std::string b) : name{a}, address{b} {};
	std::string name;
	std::string address;
        
	friend std::ostream& Rec::operator<<(std::ostream &out, const Rec &dt) {

	   stream=name+"  |   "+address;
	   out<<stream;
	   return out;
        }

}

void f(const List<int>& li, const List<Rec>& lr)
{
	li.print_all();
//	lr.print_all();
}

int main() {
	
	List<int> li(23);
	
	Rec obj1("mana","pateras");
	
	List<Rec> lr(obj1);
	
       std::ostream lol;
       lol<<obj1;

	f(li,lr);
	return 0;
}
