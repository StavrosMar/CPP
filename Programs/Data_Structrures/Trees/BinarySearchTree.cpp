/*
*   Topics covered:
*                    1) Build a simple Binary Tree here.
*                    2) maybe add exception handling (based)
*                    3) maybe multithreading - atomics and/or mutex.
*
*/

#include <iostream>

using namespace std;


//To be used only by Dedro - could include it inside dedro;
template <class T> class Node {
public:
    Node(const T& in_data) : data{in_data} {};

    Node* right;
    Node* left;
    T     data;
};

template <class T> class Dedro {
private:
    Node<T>* s;
    
public: 

    Dedro<T>() : s{nullptr} {}; //Needed, s points to whatever otherwise

    void addNode(const T& data) {
        //do this only if data does not exist in the tree.
        //-have to search first 
        Node<T>* new_node = new Node<T>(data);
        
        if (s==nullptr) {
            s = new_node;
        } else {
            
            while 
            if (data > node->data) {
                node = node->right;
            } else if (data < node->data) {
                node = node->left;
            } else 
            
        }
        
    }
    
    void printS() {
        
        std::cout<<s->data<<"\n";
        
    }
    
    ~Dedro() { /* delete dedro;*/ };
    
};

int main()
{
   Dedro<int> ded;
   ded.addNode(3);
    
   
   ded.printS();
   
   return 0;
}
