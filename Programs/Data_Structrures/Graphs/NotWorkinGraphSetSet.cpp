// Example program
#include <iostream>
#include <string>
#include <set>

using namespace std;

template<class T> class DerivSet  {

public:

    T m_x;
    std::set<T> m_set;

    DerivSet(const T& xi, const set<T>& seti) : m_x{xi}, m_set{seti} {} ;
    DerivSet(const T& xi) : m_x{xi} {} ;
    
    /*
    constexpr bool operator==(const DerivSet& a) const {
        
        return { (m_x == a.m_x) && (m_set == a.m_set) };
    }
    */
    
    // Important - add const in the end otherwise - issue with qualifiers when loaded to insert for set - const correctness
    constexpr bool operator<(const DerivSet& a) const {
        return { (m_x < a.m_x) };
    }
    
    DerivSet insert(const T& yi)  {
        m_set.insert(yi);
        return *this;
    }
    
};


int main() {

int N, M, x, y, Q;

// Choosing set because of binary search tree efficiency 
set<DerivSet<int>> graph;

auto graphEnd{graph.end()};

cin >> N >> M ;

for (int i{0}; i < M; i++) {
    
    cout << "Enter nodes" << "\n" ;
    cin >> x >> y ;
    
    // Returns constant iterator - argggg - cannot manipulate from the outside
    auto it{(graph.find(DerivSet<int>(x)))};
    
    if ( it != graph.end() ) {
        graph.insert(DerivSet<int>{x}.insert(y));
    } else {
        
    }

    
    
   // auto subSetIter = graph.find(*insertedPair.first);
    
  //  subSetIter->insert(y);
    
    //insert(y);
    
    //.insert(y)
    //graph.insert(std::set<int>(y).insert(x));
}
/*
auto graphend(graph.end().end());


cin >> Q ;

for (int i{0}: i < Q; i++) {

    cin >> x >> y ;
    
    auto r1{graph.find(x).find(y)};
    auto r2{graph.find(y).find(x)};
    
    if (r1 != end ) {
        
        cout<< "YES" >> "\n";
    
    } else if (r2 != end) {
        
        cout<< "YES" >> "\n";
        
    } else {
        
        cout << "NO" << "\n";
    }
    
}
*/
}
