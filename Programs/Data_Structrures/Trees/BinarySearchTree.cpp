/*
*   Topics covered:
*                    1) Build a simple Binary Search Tree here.
*                       a) Add nodes
*                       b) Search nodes
*                       c) Free resources.
*                   
*   Ideas for the future:
*                    1) Multithreading - atomics and/or mutex.
*                    2) Alternative deletion - by element to avoid using vector.
*/

#include <iostream>
#include <vector>

using namespace std;


//To be used only by Dedro - could include it inside dedro;
template <class T> class Node {
public:
    Node(const T& in_data) : right{nullptr}, left{nullptr},data{in_data} {};

    Node* right;
    Node* left;
    T     data;
    
    ~Node() { right=nullptr; left=nullptr; std::cout<<"Calling Node destructor"<<'\n'; };
};

template <class T> class Dedro {
private:
    Node<T>* s;
    vector<Node<T>*> memory_list; //keep pointers for easy destruction.
public: 

    Dedro<T>() : s{nullptr} {}; //Needed, s points to whatever otherwise

    void addNode(const T& data) {
        //do this only if data does not exist in the tree.
        //-have to search first 
        Node<T>* new_node = new Node<T>(data);
        memory_list.push_back(new_node);
        
        if (s==nullptr) {
            s = new_node;
        } else {
            Node<T>* node = findNode(data);

            if (data > node->data) {
                node->right = new_node;
            } else if (data < node->data) {
                node->left = new_node;
            }
        }
    }
    
    //Checks if data exists in the structure.
    bool valueExists(const T& data) {
        Node<T>* node = findNode(data);
        
        bool a;
        (node->data == data) ? a=true : a=false;
        return a;
    }
    
    
    //Returns this or 1-level up node if data does not exist
    Node<T>* findNode(const T& data) {
        Node<T>* node = s;
        Node<T>* currnode;
        while (node != nullptr) {
            currnode = node;
            if (node->data == data) {
                return node;
            } else if (data > node->data) {
                node = node->right;
            } else if (data < node->data) {
                node = node->left;
            }
        }
        return currnode;
    }
    
    //Delete Dedro - destructor for dynamically allocated Nodes
    ~Dedro() {
        for (auto x : memory_list) {
            std::cout<<"Deleting memory on:"<<x<<'\n';
            delete x;
        }
    };
};

//Simple main validating functions
int main()
{
   Dedro<int> ded;
   ded.addNode(3);
   ded.addNode(5);
   
   std::cout<<"5 Exists? : "<< ded.valueExists(5)<<'\n';
   std::cout<<"9 Exists? :"<< ded.valueExists(9)<<'\n';
   
   return 0; 
}
