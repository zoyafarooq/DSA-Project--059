#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int value){
			data = value;
			next = nullptr;
			
		}
};

class LinkedList {
	private:
		Node* head;
		
	public:
		LinkedList(){
			head = nullptr;
			
		}
		
		void insertAtStart(int value) {
			Node* newNode = new Node(value);
			newNode->next = head;
			head = newNode;
			cout << " Inserted at start: " << value  << endl;
			display();
		}
		
		
		void insertAtEnd(int value ){
			Node* newNode = new Node(value);
			
			if(head == nullptr){
				head = newNode;
			}
			else{
				Node* temp = head;
				while (temp->next != nullptr) {
					temp = temp->next;
				}
				
				temp->next = newNode;
			}
			
			cout << " Insert at end: " << value <<  endl;
			display();
			
		}
		
		
		void display(){
			Node* temp = head;
			cout << " Current List: ";
			while (temp != nullptr){
				cout << temp->data << " -> ";
				temp = temp-> next;
			}
			
			cout << " NULL " << endl << endl;
		}		
};

int main(){
	LinkedList list;
	
	list.insertAtStart(10);
	list.insertAtEnd(20);
	list.insertAtStart(5);
	list.insertAtEnd(30);
	
	return 0;
}

