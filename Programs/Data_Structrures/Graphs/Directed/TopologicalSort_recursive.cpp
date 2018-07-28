/*
*
*   Topics covered:
*                1) DFS
*                2) Topological sort
*
*/

#include <iostream>
#include <vector>
#include <stack>
#include <array>
#include <fstream>
#include <queue>

using namespace std;

//Num of Nodes frozen - edges can be added removed etc.
//So use list or vector - passing size of graph as Template param
// Cannot have N as variable - need to be static for construction, or add as template parameter.
/*template <int N,typename T> class Graph {
private:
    
    vector<int> adj[N];

public:
 //   Graph( const int& iN) : N{iN} {};
   void addEdge();
   //void addNode(); - only 

};

template <int N, typename T> void Graph<N,T>::addEdge() {
    //
}
*/

class TpSort {

private:
   //-//DFS
   static const int N = 6; //Number or Nodes
   stack<int> sta;
   array<int,N>     edgeTo; //Not needed for the Sort, valid for 1 DFS
   array<bool,N>    marked;
   vector<int> adj[N];
	vector<int> indices;
   //For Topological Sort
   array<bool,N>    onStack;
   bool hasCycle{false};
   stack<int> tpOrder;
   


//Normally TpSort would take as an argument the Graph g - separate class
void initialise() {
    
    
    //Build Graph//p9
    	//create adjacency list
    int x{0}, y{0};
   
   	ifstream infile;
	infile.open("input.in");

    while (infile>>x>>y) {
        if (x<N && y<N) {
            adj[x].push_back(y);
			indices.push_back(x);
        }
    }
	for (int i=0; i<N ; ++i) {
			for (auto y : adj[i]) {
        		cout<<"Edge read : "<<i<<"  "<<y<<'\n';
			}
	}
}

void dfs(int s) {

	  //-//CoreDFS
	  
	  marked[s] = true;
	  onStack[s] = true;
	  
	  for (auto n : adj[s]) {
		 //For DAG
		 if (onStack[n] == true) {
	   	 	hasCycle = true;
	   	 }

	  	 if (!marked[n]) {
			edgeTo[n] = s;
			dfs(n);
		 }
	  }
	  onStack[s] = false;
	  tpOrder.push(s);
}

void isAcyclic() {
   // Accyclic Graph Check
   (hasCycle == false) ? cout<<"YAY! DAG"<<'\n' : cout<<"No DAG"<<'\n';
}

public:

	//Constructor 
	TpSort() {
   		marked.fill(false);
		onStack.fill(false);
		initialise();
	}

int run()
{
   //For Topological Sort, we run classic DFS node-times 
   // each time with different origin, since we need to find global
   // ordering.
   for ( int ind{0} ; ind < N; ++ind ) {
   
   		if (!marked[ind]) {
			dfs(ind);
		}
   }
  
   /*
   //DFS -  Follow the path to and edge.
   //Edge to node 5 test
   int node = 3;
   int temp{node};
   stack<int> order;
   
   while ( temp > 0) {
       order.push(temp);
       temp = edgeTo[temp];
   }
   while (!order.empty()) {
       cout<<"->"<<order.top();
       order.pop();
   }
   cout<<'\n';
   */

   this->isAcyclic();
   
	//Topological sort 
   cout<<"### Topological Sort PreOrder ####"<<'\n';
   while (!tpOrder.empty()) {

		cout<<tpOrder.top()<<"~~";

		tpOrder.pop();
   }
   cout<<'\n';
   return 0;
}


};

int main() {

TpSort tp;
tp.run();
}
