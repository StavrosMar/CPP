//RTTI23 - Exercise 4
//Mapping type_info --> Class functions

// Implemente unordered_map<type_index,My_info∗> (§35.5.4).

#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include "classes.cpp"

//Class My_info
class My_info {

	public:
		//Constructor
		My_info(const std::string& desc) : _description(desc) {};
		
		//Member functions
		std::string getDesc() {

			return _description;
		}

		//Correspondence with class member functions
		//...
		/////


	private:

		std::string _description{""};

};

int main() {


std::unordered_map<std::type_index,My_info*>  myMap;

//Build polymorphic objects
D d;
E e;

//Add class information
My_info info_D("Information about D function");
My_info info_E("Information about E function");

//Build mapping
//typeid is run statically as the type is known
myMap[std::type_index(typeid(D))] = &info_D;
myMap[std::type_index(typeid(E))] = &info_E;

//Test
Base* b = &d;
std::cout<<myMap[typeid(*b)]->getDesc()<<"\n";

	return 0;

}
