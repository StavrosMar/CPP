#include<iostream>


int* aux(){

	// Example for when we declare a pointer handling object but after we replace the address it is pointing to.
	int* p = new int(10);
	int* lola=p;
	std::cout<<"Before Replacement :"<<*lola<<std::endl;
        //Declaring lola2 and making p point to lola2 now.	
	int lola2(24);
//       delete 	p;
	p = &lola2;
        return lola;
};

int main() {
        int* lola(aux());	
        // Valid - points to the memory initially pointed by p which has not been deallocated
	// (Because p in the function above is pointing to a completely different location now it does not mean that the memory it was initially pointing to has been deallocated)
	delete lola;
	std::cout<<"After Replacement :"<<*lola<<std::endl;

	// Test to validate that we will get a double free() error meaning that the memory has already been freed.
	delete lola;

	// Invalid because p is not on the free store
	int nikos(21);
	int* p=&nikos;
	delete p;

};
