// Templates 23 - Exercise 5 - sort 
// This is the sort converted to a templated version

#include<iostream>
#include<iterator>

// Class declarations

// Function declarations

// sort function template
	// Option 1 - using sort from std
void template<typename T>
sort(const iterator &a,const iterator &b) {

	// Cross fingers it works
	Comp criteria(&T); 
	
	// std::sort needs Compare type as input
	std::sort(&a, &b, &criteria);
	
}

// print function

void printVec( iterator a, iterator b) {
	
	for (auto i = a ; i != b ; ++i ) {
	
		std::cout<< "e" << *i << " ";
	}
	
	std::cout<< "\n" ;
	
}

// main 
int main() {

	std::vector<int> vec0{1,2,3};
	
		sort(vec0);
	
		std::cout<< "The sorted vector is the following : " << std::endl;
		printVec( vec0.begin(), vec0.end() )<< std::endl;
	
	}

}