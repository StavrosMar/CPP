#include "patricia.cpp"

int main() {

	//Constructor - passed
	Node<int> a("lala",3);

	//bit_get Test -- passed
	for (int i{0}; i<24; i++) {
		cout<<bit_get("Nik",i);
		cout<<bit_get("Nikos",3);
	}
	
	return 0;
}
