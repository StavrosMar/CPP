#include <iostream>;

template <typename T>
class Mum {
public:
	Mum<T>* ptr;
};

template <typename T>
class Child : public Mum<T> {
//public:

};

int main() {

Mum<int>* himum;

Child<int>* hichild;

himum = hichild; //valid

//hichild = himum; //invalid

return 0;

//std::cout<<
}
