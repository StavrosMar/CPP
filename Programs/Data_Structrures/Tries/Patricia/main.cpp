#include "patricia.h"
#include "util.h"

int main() {

	//Running Unitary Tests utils.cpp
	/*test_unit_binUtil();

	//a) Constructor - passed
	Node<int> a("lala",3);
	*/
	//Patricia Tests
	//-//Construction test
	PTrie<int> patricia;

	//-//Insert Test

	patricia.insert("s",18);   //01110011 
	patricia.insert("a",121);  //01100001
	patricia.insert("b",124);  //01100010
	//patricia.insert("l",124);  //01101100 



	//Issue - when adding the 3rd one - i can't find the second one

	auto res{patricia.find("b")};
	cout<<"Result is :"<<res.second<<endl;

}