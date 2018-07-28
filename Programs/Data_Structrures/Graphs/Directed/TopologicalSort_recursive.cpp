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
   static const int N = 5; //Number or Nodes
   stack<int> sta;
   array<int,N>     edgeTo;
   array<bool,N>    marked;
   vector<int> adj[N];
   //For Topological Sort
   array<bool,N>    onStack;
   bool hasCycle{false};
   queue<int> preOrder;
   

void dfs(int s) {

	  //-//CoreDFS
	  //s : origin
	  sta.push(s);
	
	  while (!sta.empty()) {
	      
	      s = sta.top();
	      onStack[s] = true;
	      sta.pop();
	   
	   	   preOrder.push(s);
	      if (!marked[s]) {
	          marked[s] = true;
	      }
	      
	      for (auto n : adj[s]) {
	
	      	   //For DAG
	   	   if (onStack[n] == true) {
	   	   		hasCycle = true;
	   	   }
	
	   	   if (marked[n] == false ) {
	              
	              marked[n] = true;
	              edgeTo[n] = s;
	              sta.push(n);
	          }
	      }
	  }

}

void initialise() {
    
    
    //Build Graph//p9
    	//create adjacency list
    int x{0}, y{0};
   
   	ifstream infile;
	infile.open("input.in");

    while (infile>>x>>y) {
        cout<<"Edge read : "<<x<<"  "<<y<<'\n';
        if (x<N && y<N) {
            adj[x].push_back(y);
        }
    }

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
   for ( int s{0} ; s<N ; ++s ) {
   
   		if (!marked[s]) {

			dfs(s);
			
		}
   }
  	
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
   
	//TODO - Topological sort 
   cout<<"### Topological Sort PreOrder ####"<<'\n';
   while (!preOrder.empty()) {

		cout<<preOrder.front()<<"~~";

		preOrder.pop();
   }
   cout<<'\n';
   return 0;
}


};

int main() {

TpSort tp;
tp.run();

}
