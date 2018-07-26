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

using namespace std;

//Num of Nodes frozen - edges can be added removed etc.
//So use list or vector - passing size of graph as Template param
// Cannot have N as variable - need to be static for construction.
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

int main()
{
    
    const int N = 6; //Number or Nodes
    vector<int> adj[N];
    
    //Build Graph//
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

   //DFS
   stack<int> sta;
   int s=0;        //s : origin
   sta.push(s);
   
   array<int,N>     edgeTo;
   array<bool,N>    marked;
   marked.fill(false);
   
   while (!sta.empty()) {
       
       s = sta.top();
       sta.pop();
	
	if (!marked[s]) {
           marked[s] = true;
       }

       //n is the index of 
       for (auto n : adj[s]) {
           if (marked[n] == false ) {
               
               marked[n] = true;
               edgeTo[n] = s;
               sta.push(n);
           }
       }
   }
  	
   //DFS -  Follow the path to and edge.
   //Edge to node 5 test

   int node = 5;
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

   //TODO - Accyclic Graph Check

   //TODO - Topological sort 
   
   return 0;
}
