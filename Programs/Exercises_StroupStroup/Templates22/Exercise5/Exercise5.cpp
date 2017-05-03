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
	
		bool operator() (const T& a,const T &b) {
		
			return (a > b) ? true : false;
		}
	};

	// Sort Algorithm 
	template<typename T, typename RIter>		// RIter deducted directly from args
	void sort(const RIter &a, const RIter &b) {

		std::sort(a, b, T());

	}


}

// Very important to use & in the return -  ostream is non-copyable
template<typename C>
std::ostream& operator<<(std::ostream& os, const std::vector<C> &vec) {

	for ( auto x : vec ) {

		os<<x<<" ";
	}

	return os;

}

		

// main 
int main() {

	// Testing funPointer fp:sort
	fp::sort<int,fp::greater<int>>;

	//Testing funObject fo:sort
	std::vector<int> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3}; 
	
	//-//Testing fo::greater with std::sort
	std::sort(s.begin(),s.end(),fo::greater<int>());

	 //-//Testing fo::sort with std::greater
	
	fo::sort<std::greater<int>>(s.begin(),s.end());
	
	std::cout<<s<<std::endl;
	
	//-//Testing fo::sort with fo::greater
	
	std::vector<int> vecFOFull{10,4,5,100,200,2};
	
	fo::sort<fo::greater<int>>(vecFOFull.begin(),vecFOFull.end());
	
	std::cout<<vecFOFull<<std::endl;
}
