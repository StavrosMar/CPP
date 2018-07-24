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
    
    //Edges//
    //Input and create adjacency list
    int x{0}, y{0};
    int queries{N};
    
    cout<<queries<<'\n';
    
    while (!queries) {
        cin>>x>>y;
        cout<<"Input is :"<<x<<"  "<<y<<'\n';
        if (x<N && y<N) {
            adj[x].push_back(y);
        }
        
        --queries;
    }
    
    cout<<"Input ended"<<'\n';
   
   //DFS
   stack<int> sta;
   int s=0; //First edge
   sta.push(s);
   
   array<int,N>     edgeTo;
   array<bool,N>    marked;
   marked.fill(false);
   
   int count{0};
   if (sta.empty()==true) {
       cout<<"not empty"<<'\n';
   }

   while (!sta.empty()) {
       
       s = sta.top();
       sta.pop();
       
       //n is the index of 
       for (auto n : adj[s]) {
           if (marked[n] == false ) {
               
               marked[n] = true;
               edgeTo[n] = s;
               sta.push(n);
               ++count;
               cout<<count<<'\n';
           }
       }
   }
   
   //Edge to node 5
   
   int node = 5;
   int temp{node};
   
   // Second stack 
   stack<int> order;
   while ( temp > -1) {
       
       order.push(temp);
       temp = edgeTo[temp];
       
   }
  
   while (!order.empty()) {
       cout<<order.top()<<"->"<<'\n';
       order.pop();
   }
   //Topological sort 
   
   return 0;
}
