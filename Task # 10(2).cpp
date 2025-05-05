#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int val){
			data = val;
			next = nullptr;
		}
};


class StackLinkedList{
	private:
		Node* top;
		
	public:
		StackLinkedList(){
			top = nullptr;
		}
		
		
		void push(int val){
		Node* newNode = new Node(val);
			newNode->next = top;
			top = newNode;
			cout << val << " pushed to stack." << endl;
		}
		
		void pop (){
			if (top == nullptr){
				cout << "Stack Underflow! " << endl;
				return;
			}
			
			Node* temp = top;
			cout << top->data << "popped from stack." << endl;
			top = top->next;
		}
		
		void display(){
			if ( top == nullptr) {
				cout << "Stack is empty! " << endl;
				return;
			}
			
			Node* temp = top;
			cout << "Stack ( Top to Bottom):" ;
			while (temp != nullptr){
				cout << temp->data << " " ;
				temp = temp -> next;
			}
			
			cout << endl;
		}
};



int main(){
	cout << "\n Stack using Linked List " << endl;
	StackLinkedList s2;
	s2.push(100);
	s2.push(200);
	s2.push(300);
	s2.display();
	s2.pop();
	s2.display();
	
	return 0;
}

