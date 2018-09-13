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
#include <map>

using namespace std;

//Elementary database record - 1 line.
//TODO - Variadic i.e. for an unlimited number of fields
// S is key type and T is the first field sitting under it.
//Compile time resolution
template<typename S, typename F1> class spair {
public:
	S _key; //Key 1
	F1 _f1; //Field 1
	spair(const S& k, const F1& f) : _key{k}, _f1{f}{};
	
	const S& key() const {
		return this->_key;
	}
	const F1& f1() const {
		return this->_f1;
	}
};

vector<spair<string,int>> loadData(const char* file,const size_t& nfields = 2) {

	std::vector<spair<string,int>> Db;
	ifstream f;
	f.open(file);
	
	//Scan every line
	std::string strline;
	while (getline(f,strline)) {
		cout<<"Parsing line:    "<<strline<<'\n';
		if (strline[0] == '#') {
			cout <<"Found Header"<<'\n';
		} else {
			
			//Split input line to a vector of parsed strings.
			//TODO - put it in a function ?
			vector<string> iargs; //Could convert this to array
			int it2{0};
			int it1{0};
			int length = strline.find_last_not_of(' ')+1;
			
			while (it2 != length) {
				it1 = strline.find_first_not_of(' ',it2);
				it2 = strline.find_first_of(' ',it1+1);
				(it2 < 0) ? it2 = length: 0;
				(it1 < 0) ? it1 = it2 : 0;
				
				string ss = strline.substr(it1,(it2-it1));
				if (ss.length()>0) {
					iargs.push_back(ss);
					cout<<"Adding =: "<<ss<<'\n';
				}
			}
			
			//Take all args and push them / convert them if needed to appropriate type.
			Db.push_back(spair<string,int>(iargs[0],stoi(iargs[1])));
			//-//
			/*TODO - cleaner
			
			//Generalization : Could do it with a visitor (?)
			for (auto a : args) {
				if (a.length()>0) {
					Db.push(a); //Need to define a class DataBase where the underlying structure is the vector i built			
				}
			}*/
		}
	}
	return Db; 
}

int main() {

	cout<<"Hello World"<<'\n';

	//loadData test - passed//
	auto Db = std::move(loadData("input.data"));
	
	//-//Validate data added//-//
	for (auto s : Db) {
		cout<<"Key is =: "<<s.key()<<endl;
		cout<<"Classement is =: "<<s.f1()<<" and +1 is =:" <<s.f1()+1<<endl;
	}

	//TODO - start indexing core.
	
	return 0;

}
