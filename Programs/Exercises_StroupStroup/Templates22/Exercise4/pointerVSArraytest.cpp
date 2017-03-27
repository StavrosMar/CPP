#include <iostream>

int main() { 

	//int* ptr = new int[10];
	int ptr[10];
	ptr[0] = 12;
	ptr[1] = 13;
	std::cout<< "Value ptr = : "<< ptr <<std::endl;
	std::cout<< "Value *ptr = : "<< *ptr <<std::endl;
	std::cout<< "Value ptr[0] = :" << ptr[0] <<std::endl;
	std::cout<< "Value ptr[1] = :" << ptr[1] <<std::endl;
	std::cout<< "Value *(ptr+1) = :" << *(ptr+1) <<std::endl;
	return 0;
}
