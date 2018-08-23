#include <iostream>
#include <utility>

using namespace std;

/*
*
*   Topics covered :
*                   1) Building a Trie (based on Algorithms book)
*                   2) TODO - Manage memory using unique_ptr or shared_ptr for multithreading.
*
*/

//R is the alphabet size - R = 256 for our example
// Could be better to put it inside Trie - since trie is managing deletions in case i use new here for the alphabet table.
template <class T,int R> struct Nodee {
    T data;
    //Nodee* next[R]; // is this ok or do we need to allocate via new ??
    Nodee** next = new Nodee*[R]; // is this ok or do we need to allocate via new ?? 
};

template <class T, int R> class Trie {

public:
    //get T for the search key typed;
    std::pair<T,bool> get(const string&);
    
    //Put data to the trie
    void put(const string& key, const T&);
    
    
private:
    using Node = Nodee<T,R>;
    Node* root{nullptr};
    
    Node* get(Node* n, const string& key,const int& d) {
        
        if ( n == nullptr) {
            return nullptr;
        }
        
        if (d == key.length()) {
            return n;
        }
        
        get(n->next[key[d]], key, d+1);
    }
    
    Node* put(Node* n, const string& key, const T& data, const int& d) {
        
        if (n == nullptr) {
            n = new Node();
        }
        
        if (d == key.length()) {
            n->data = data;
        }
        
        auto c = key[d];
        n->next[c] = put(n->next[c], key, data , d+1);
    }

};


template <typename T, int R> std::pair<T,bool> Trie<T,R>::get(const string& key) {
    
    Node* n = get(root,key,0);
    
    std::pair<T,bool> p;
    
    if (n==nullptr) {
        p.first = 0;
        p.second = false;
    } else {
        p.first  = n->data;
        p.second = true;
    }
    
    return p;
}

template <typename T, int R> void Trie<T,R>::put(const string& key,const T& data) {
    put(root, key, data, 0);
}


int main()
{
    Trie<int,256> radixTrie;
    
    radixTrie.put("Nikolas",189);
    
    //auto p{radixTrie.get("Nikolas")};
   
  // cout<<p.second<<'\n';
   
   return 0;
}
