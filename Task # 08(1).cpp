#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
		
		Node(int val){
			data = val;
			next = nullptr;
		}
		
};

class SinglyLinkedList {
	public:
		Node* head;
		
		SinglyLinkedList(){
			head = nullptr;
		}
		
		void insertAtEnd(int val){
			
			Node* newNode = new Node(val);
			if (head == nullptr)
				head == newNode;
				
			else{
				Node* temp = head;
				while (temp->next != nullptr)
					temp = temp->next;
					temp->next = newNode;
			}
			
		}
		
		void display() {
			Node* temp = head;
			cout << "Singly Linked List: ";
			while (temp != nullptr){
				cout << temp->data << " -> ";
				temp = temp->next;
			}
			
			cout << "Null\n";
		}
		
		void merge (SinglyLinkedList& other){
			if(head == nullptr){
				head = other.head;
				
			}
			else{
				Node* temp = head;
				while (temp->next != nullptr)
					temp = temp->next;
					temp->next = other.head;
			}
			
			other.head = nullptr;
		}
};


int main (){
	SinglyLinkedList list1, list2;
	list1.insertAtEnd(1);
	list1.insertAtEnd(12);
	list1.insertAtEnd(3);
	list1.insertAtEnd(4);
	
	cout << "Before marge(Singly):\n";
	list1.display();
	list2.display();
	
	list1.merge(list2);
	
	
	cout << "After merge (Singly): \n";

	
	return 0;
}

