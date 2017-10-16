//Exercise 3 Cuncurrency - Histogram
// Will perform an enhancement i.e. tThread processing

#include <thread>
#include <iostream>
#include <random>
#include <vector>



//My main
int main() {

	// Build a new interface for parallel processing maybe ???
		//std::thread t1{
		
	auto die = bind(normal_distribution<>{0,29}, default_random_engine{});
	
	std::vector<int> histo(30);
	for ( int i = 0; i!=200 ; ++i) {
	
		++histo[die()];
	};
	

}
	
	
	