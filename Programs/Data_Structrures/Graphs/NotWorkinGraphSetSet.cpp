
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <initializer_list>

using namespace std;

// My graph Structure
template < class T > class Graph {

private:
    // Choosing map and set because of tree search efficiency 
    map<int,set<int>> m_map;

public: 

    // Construct from initialiser_list
    Graph(const std::initializer_list<pair<T,T>>& init) { 
        
        for (auto p : init) {
            
            this->insert(p.first,p.second);
        }
    }

    void insert(const T& x, const T& y) {
     
          m_map[x].insert(y);
          m_map[y].insert(x);
        
    }
    
    bool exists(const T& x,const T& y) const {
    
        int flag(0);
        
        auto it1 = m_map.find(x);
        auto it2 = m_map.find(y);
    
        if ( it1 != m_map.end() ) {
        
            if ( it1->second.find(y) != it1->second.end() ) {
            
                flag = 1;
            }
    
        } else if ( it2 != m_map.end() ) {
        
            if ( it2->second.find(x) != it2->second.end() ) {
            
                flag = 1;
            }
        }
        
        return flag;
    }

};


//Driver Code
int main() {

int N, M, x, y, Q;

Graph<int> graph= { make_pair(1,2), make_pair(3,4) };

cin >> N >> M ;

for (int i{0}; i < M; i++) {
    
    cout << "Enter nodes" << "\n" ;
    cin >> x >> y ;
    
    graph.insert(x,y);
    
}

cout << "Give me Q queries" << "\n";
cin >> Q ; cin.ignore() ;

map<int,string> yesno{ make_pair(1,"YES"), make_pair(0,"NO")};


for (int i{0} ; i < Q; i++) {

    cout <<"Give nodes" << "\n";
    cin >> x >> y ;
    
    cout<< yesno[graph.exists(x,y)] << "\n";
    
}

}
