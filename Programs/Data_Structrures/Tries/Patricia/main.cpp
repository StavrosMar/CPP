#include "patricia.cpp"

int main() {

	//Constructor - passed
	Node<int> a("lala",3);

	//bit_get Test -- passed
	for (int i{0}; i<24; i++) {
		cout<<Node<int>::bit_get("Nik",i);
	}

	return 0;
}
