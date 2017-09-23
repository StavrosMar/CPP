//RTTI23 - Exercise 4
//Mapping type_info --> Class functions

// Implemente unordered_map<type_index,My_info∗> (§35.5.4).

#include <iostream>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>


namespace stavros {

	//* functions defined here *//

} 


//Class My_info
class My_info {

	public:
		//Constructor
		My_info(const std::string& desc) : _description(desc) {};
		
		//Member functions
		std::string getDesc() {

			return _description;
		}


	private:

		std::string _description{""};


};

int main() {


std::unordered_map<std::type_index,My_info*>  myMap;

My_info myinfo1("Do something 1");
My_info myinfo2("Do something 2");

myMap[typeid(&myinfo1)] = &myinfo1;
myMap[typeid(&myinfo2)] = &myinfo2;

//TEST1 - Sorting Matrices
	
	//-//Set-up
	
	
	//-//Calling point


	//-//Print results
	
//TEST1 - END

	return 0;

}
