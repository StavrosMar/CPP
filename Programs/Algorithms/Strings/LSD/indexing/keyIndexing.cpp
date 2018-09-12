/*
*   Topics covered:
*                    1) Key indexing implemenation.
*						Serves as basis for LSD (and MSD)
*					 2) Parsing algorithm.
*                   
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//Elementary database record - 1 line.
//TODO - Variadic i.e. for an unlimited number of fields
// S is key type and T is the first field sitting under it.
template<typename S, typename T1> struct spair {
	S key; //Key 1
	T1 f1; //Field 1
};

vector<spair<string,int>>&& loadData(const char* file,const size_t& nfields = 2) {

	std::vector<spair<string,int>> Db;
	ifstream f;
	f.open(file);
	
	string key, strline;
	int    level;
	//Scan every line
	while (getline(f,strline)) {
		cout<<"Parsing line:    "<<strline<<'\n';
		if (strline[0] == '#') {
			cout <<"Found Header"<<'\n';
		} else {
			
			//Split input line to a vector of parsed strings.
			//TODO - put it in a function ?
			vector<string> args(nfields); //Could convert this to array
			int it2{0};
			int it1{0};
			int length = strline.find_last_not_of(' ')+1;
			
			while (it2 != length) {
				it1 = strline.find_first_not_of(' ',it2);
				it2 = strline.find_first_of(' ',it1+1);
				(it2 < 0) ? it2 = length: 0;
				(it1 < 0) ? it1 = it2 : 0;
				args.push_back(strline.substr(it1,(it2-it1)));
				cout<<"Adding =: "<<strline.substr(it1,(it2-it1))<<'\n';
			}
			
			//take all args and push them / convert them if needed to appropriate type.
			// Generalization : Could do it with a visitor (?)
			
			/*TODO - cleaner
			for (auto a : args) {
				if (a.length()>0) {
					Db.push(a); //Need to define a class DataBase where the underlying structure is the vector i built			
				}
			}*/

		}
	}
	return std::move(data); //Avoid expensive copies.
}

int main() {

	cout<<"Hello World"<<'\n';
	loadData("input.data");
	return 0;

}
