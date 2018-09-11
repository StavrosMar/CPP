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

	//-//Insert Test - TODO - All but Nikos not found
	vector<string> test_insert{"s","anna","l","an","anna","ni","Nikos"};
	int i=0; 
	for (auto s : test_insert) {
		cout<<"***TestAdd : "<<s<<","<<i<<endl;
		patricia.insert(s,i);
		++i;
	}

	for (auto s : test_insert) {
		
		auto res{patricia.find(s)};
		cout<<"***Validation for \""<<s<<"\" = "<<res.second<<endl;
		
	}

	/*
	patricia.insert("s",18);   //01110011 
*/


	//Issue - when adding more than 2 - i can't find the intermediate ones

	/*auto res{patricia.find("ann")};
	cout<<"Result is :"<<res.second<<endl;*/

}