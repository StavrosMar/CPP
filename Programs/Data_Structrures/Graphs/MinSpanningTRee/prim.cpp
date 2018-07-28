/*
*
*   Topics covered:
*                1) Prims algorithm
*
*/

#include <iostream>
#include <vector>
#include <stack>
#include <array>
#include <fstream>
#include <queue>

using namespace std;

class Edge {
private: 
	int a,b;
	double w;
public:
	
	Edge(const int& a, const int& b,const double& weight) : a{a}, b{b}, w{weight} {};
	
	double weight() {
		return this->w;
	};

	int other(const int& t) {
		
		int k;

		if ( t == a ) {
			k = b;
		} else if ( t == b) {
			k = a;
		}

		return k;
	}
	
	//Operator necessary for comparing Edges on the priority queue.
	bool operator<(const Edge& e2) const {
		bool ret;

		if ( this->w < e2.w ) {
			ret = true;
		} else {
			ret = false;
		}
		return ret;
	}

};

class TpSort {

private:
   static const int N = 6; //Number or Nodes
   vector<Edge> adj[N];
   bool   marked[N];
   priority_queue<Edge> pq;
   
void initialise(const string& s) {
    //Build Graph//p9
    	//create adjacency list
    int x{0}, y{0};
	double w{0.0};
   
   	ifstream infile;
	infile.open(s);

    while (infile>>x>>y>>w) {
        cout<<"Edge read : "<<x<<"  "<<y<<"with weight"<<w<<'\n';
        if (x<N && y<N) {
            adj[x].push_back(Edge(x,y,w));
            adj[y].push_back(Edge(y,x,w));
        }
    }

}

void visitGraph(const int& v) {

	marked[v] = true;
	for (auto edge : adj[v]) {
		if (!marked[edge.other(v)]) {
			pq.push(edge);
		}
	}
}


public:

	//Constructor 
	TpSort(const string& s) {
		initialise(s);
	}

int run()
{
	return 0;	
}

};

int main() {

TpSort tp("input.in");
tp.run();

return 0;

}
