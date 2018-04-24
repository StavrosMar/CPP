/* Building a graph with Adjacency list. 
    * Insert a Node : Logarithmic
	* Search for a Node : Logarithmic 
*/

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;

int main() {

int N, M, x, y, Q;

// Choosing map and set because of tree search efficiency 
map<int,set<int>> graph;


cin >> N >> M ;

for (int i{0}; i < M; i++) {
    
    cout << "Enter nodes" << "\n" ;
    cin >> x >> y ;
    
    graph[x].insert(y);
    graph[y].insert(x);
    
}

cout << "Give me Q queries" << "\n";
cin >> Q ;

for (int i{0} ; i < Q; i++) {

    cout <<"Give nodes" << "\n";
    cin >> x >> y ;
    
    string yesno{"NO"};
    
    auto it1 = graph.find(x);
    auto it2 = graph.find(y);
    
    
    if ( it1 != graph.end() ) {
        
        if ( it1->second.find(y) != it1->second.end() ) {
            
            yesno = "YES";
        }

    } else if ( it2 != graph.end() ) {
        
        if ( it2->second.find(x) != it2->second.end() ) {
            
            yesno = "YES";
        }
    }
    
    cout<< yesno << "\n";
    
}

}
