/*
 * atomic_Stack.cpp
 *
 *  Created on: 1 Jul 2018
 *      Author: staurosmarinis
 *   
 *  Topics covered :
 *					1) Build a thread-safe lock-free stack using atomic operations.
 *					2) Using smart pointers for exception safety when copying
 */

#include <atomic>
#include <iostream>

using namespace std;

template <typename T> class lock_free_stack {

private:

	//Nodes for the stack/list
	struct Node {
		Node* next{nullptr}; // nullptr by default;
		T	  data;

		Node(const T& data) : data(data) {};
	};

	//head of the stack/list
	atomic<Node*> head{nullptr};

public:

	//Push elements into the stack.
	void push(const T& data) {
		Node* const new_node = new Node(data);
		new_node->next = head;
		//make the new node the updated head - synchronise with other threads as well.
		while(!head.compare_exchange_weak(new_node->next,new_node,memory_order_release));
	}

	//Pop top element from stack
	T pop() {

		//TODO - empty stack???
		//if (head!=nullptr) {
		Node* old_head = head.load();
		while(!head.compare_exchange_weak(old_head,old_head->next));
		auto result = old_head->data;
		//TODO:But somehow we must delete old_head
		// can't do the following  - maybe thre is another thread referring to him
		//	delete old_head;
		return result;

	}

};

int main() {

	lock_free_stack<int> sta;
	sta.push(12);
	sta.push(11);

	std::cout<<sta.pop()<<'\n';
	std::cout<<sta.pop()<<'\n';


};
