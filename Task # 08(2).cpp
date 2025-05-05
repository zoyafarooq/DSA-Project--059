#include <iostream>
using namespace std;

class DNode {
	public:
		int data;
		DNode* prev;
		DNode* next;
		
		DNode(int val) {
			data = val;
			prev = nullptr;
			next = nullptr;
		}
};


class DoublyLinkedList {
	public:
		DNode* head;
		DNode* tail;
		
		DoublyLinkedList(){
			
			head = nullptr;
			tail = nullptr;
		}
		
		void insertAtEnd(int val) {
			DNode* newNode = new DNode(val);
			if (head == nullptr)
				head = tail = newNode;
			else{
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}
		}
		
		void displayForward (){
			DNode* temp = head;
			cout << "Doubly Linked List (forward): ";
			while (temp != nullptr){
				cout << temp->data << "<->" ;
				temp = temp->next;
				
			}
			
			cout << " NULL \n ";
		}
		
		void merge(DoublyLinkedList& other){
			if(head == nullptr) {
				head = other.head;
				tail = other.tail;
			}
			
			else if (other.head != nullptr) {
				tail->next = other.head;
				other.head->prev = tail;
				tail = other.tail;
			}
			
			other.head = other.tail = nullptr;
		}
		
};


int main(){
	
	
	DoublyLinkedList dlist1, dlist2;
	dlist1.insertAtEnd(10);
	dlist1.insertAtEnd(20);
	dlist1.insertAtEnd(30);
	dlist1.insertAtEnd(40);
	
	cout << "\n Before merge (Doubly): \n";
	dlist1.displayForward();
	dlist2.displayForward();
	
	dlist1.merge(dlist2);
	
	cout << "After merge (Doubly): \n";
	dlist1.displayForward();
	
	return 0;
	
}
