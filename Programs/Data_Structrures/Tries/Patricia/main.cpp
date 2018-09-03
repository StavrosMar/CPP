#include "patricia.h"
#include "util.h"

int main() {

	//Constructor - passed
	Node<int> a("lala",3);

	cout<<"\n\n";

	//bit_get Test -- passed
	for (int i{0}; i<24; i++) {
		cout<<bit_get("Nik",i);
		cout<<bit_get("Nikos",3);
	}

	cout<<"\n\n";
	return 0;
}
