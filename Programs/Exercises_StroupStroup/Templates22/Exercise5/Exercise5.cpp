// Templates 23 - Exercise 5 - sort 
// This is the sort converted to a templated version

#include<vector>
#include<iostream>
#include<iterator>
#include<algorithm>
#include<functional>


// namespace - sort to be used with function pointers as comp criteria
namespace fp {
	
	// sort
	template<typename T, bool (*f)(const T&, const T&)>       //!! F f instead of typename F. #Non-type template param
	void sort() {
		int a = 1;
		int b = 2;
		f(a,b);     //!! inline with the typedef above
	};
	
	// Comparison function : greater
	template<typename T>
	bool greater(const T &a,const T &b) {
	
		return (a > b) ? true : false;
	}
	
	// Comparison function : smaller
	template<typename T>
	bool smaller(const T &a, const T &b) {
	
		return (a < b) ? true : false;
	}

}

// namespace for sort to be used with function objects (as original sort is)
namespace fo {


	// Comparison function object: greater
	template<typename T>
	class greater {
		
	public:
	
		bool operator() (const T &a,const T &b) {
		
			return (a > b) ? true : false;
		}
	};

}

// main 
int main() {

	std::vector<int> vec0{1,2,3};

	// Testing funPointer fp:sort
	fp::sort<int,fp::greater<int>>;

	//Testing funObject fo:sort
	std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3}; 
	std::sort(s.begin(),s.end(),fo::greater<int>());
/*
	std::cout<< "The sorted vector is the following : " << std::endl;
	printVec( vec0.begin(), vec0.end() )<< std::endl;
*/	
}
