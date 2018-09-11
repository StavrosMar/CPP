#include "utils.h"

//Get the nth bit of the stream s	
//Validated
	 int bit_get(const char* str,const int& nn,const size_t nchars) {
		
		unsigned int n = abs(nn);
		unsigned int indx = n/BITS_ASCII;

		unsigned int bitmod = n%BITS_ASCII; // bit (0-7) ASCII
		auto bitmove = BITS_ASCII - (bitmod+1);
		auto bitmask = 1 << (bitmove);
		
		unsigned int bit{0}; //put zero if out-of-bounds
		if (indx < nchars) {
			bit = (bitmask & str[indx]) >> bitmove;
		};
		return bit;
	}

	//Utility functions
	//maybe make the below a friend i.e. generic function
	//Built it with std::strings  - could try char instead.
	int bit_diff(const string& s1, const string& s2) {

			const string* smlst;
			const string* lgst; //pointer to shortest and longest string
			if (s1.length() > s2.length()) {
				smlst = &s2;
				lgst = &s1;
			} else {
				smlst = &s1;
				lgst = &s2;
			}
			
			int indx{-1};
			bool flag{false};

			while (flag==false && indx<static_cast<int>(smlst->length())) {
				++indx;
				if (s1[indx]!=s2[indx]) {
					flag = true;
				}
			}

			int bitInd;
			if (flag) {
				int i{0};
				while(bit_get(&s1[indx],i)==bit_get(&s2[indx],i)) {
					++i;
				}
				bitInd = (indx)*BITS_ASCII+i; //(i+1-1)
			} else if ( !flag && (s1.length() != s2.length()) ) { //dissimilar sizes
				bitInd = (indx)*BITS_ASCII; // (-1+1)
			} else { 
				bitInd = -1; // same string
				//TODO - distinguish same string 
				// and not matching at all string ???
		}
			return bitInd;
	}

void test_unit_binUtil() {

//Bit utils tests - util.h
	const string s1{"nika"},s2{"nika"};

	//-//bit_get Test -- passed
	for (int i{0}; i<8*max(s1.length(),s2.length()); i++) {
		cout<<bit_get(&s1[0],i,s1.length())<<"  ";
	}
	cout<<"\n";
	for (int i{0}; i<8*max(s1.length(),s2.length()); i++) {
		cout<<bit_get(&s2[0],i,s2.length())<<"  ";
	}
	cout<<"\n";
	for (int i{0}; i<8*max(s1.length(),s2.length()); i++) {
		cout<<i<<"  ";
	}

	cout<<"\n\n";

	//bit_diff Test -- passed
	cout<<bit_diff(s1,s2)<<'\n';

}