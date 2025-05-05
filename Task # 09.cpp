#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int val) {
			data = val;
			next = nullptr;
		}
		
};


class CircularLinkedList{
	
	private:
		Node* head;
		
	public:
		CircularLinkedList(){
			head = nullptr;
		}
		
		
		void insertAtStart(int val){
			Node* newNode = new Node(val);
			if (head == nullptr) {
				head = newNode;
				newNode->next = head;
			}
			
			else {
				Node* temp = head;
				while (temp->next != head)
				temp = temp -> next;
				
				
				newNode->next = head;
				temp->next = newNode;
				head = newNode;
			}
			
			cout << " Inserted at Start: " << val << endl;
		}
		
		void insertAtEnd(int val) {
			Node* newNode = new Node(val);
			if (head == nullptr){
				head = newNode;
				newNode->next = head;
			}
			else{
				Node* temp = head;
				while (temp->next != head)
					temp = temp->next;
					
					temp->next = newNode;
					newNode->next = head;
			}
			
			cout << "Inserted at end: " << val << endl;
		}
		
		
		void insertAtPosition(int val, int pos){
			if (pos <= 0){
				cout << "Invalid position!" << endl;
				return;
			}
			
			if(pos == 1){
				insertAtStart(val);
				return;
			}
			
			Node* newNode = new Node(val);
			Node* temp = head;
			int count = 1;
			
			while(count < pos - 1 && temp->next != head){
				temp = temp ->next;
				count++;
			}
			if (count < pos - 1){
				cout << "Position out of range." << endl;
				return;
			}
			
			newNode->next = temp->next;
			temp->next = newNode;
			cout << "Inserted " << val << "at position " << pos << endl;
			
		}
		
		void insertAtCenter(int val){
			int len = 0;
			Node* temp = head;
			if (head == nullptr){
				insertAtStart(val);
				return;
			}
			
			do {
				len++;
				temp = temp->next;
			}
			while (temp != head);
			int mid = (len / 2) + 1;
			insertAtPosition(val, mid) ;
			cout << "Inserted at center position: " << mid << endl;
		} 
		
		void didsplayForward(){
			if (head == nullptr) {
				cout << " List is empty. " << endl;
				return;
			}
			
			Node* temp = head;
			cout << "Circular List (forward): ";
			do{
				cout << temp->data << "->" ;
				temp = temp ->next;
			
			} while (temp != head);
			 cout << "(back to head)" << endl;
		}
		
		void displayReverseHelper (Node* current, Node* start){
			if(current->next != start)
				displayReverseHelper(current->next, start);
				cout << current->data << "<-" ;
		}
		
		void displayReverse(){
			if (head == nullptr){
				cout << "List is empty." << endl;
				return;
			}
			
			cout << "Circular List (reverse): ";
			displayReverseHelper(head, head);
			cout << "(back to back)" << endl;
		}
		
};


int main (){
	CircularLinkedList clist;
	
	clist.insertAtStart(10);
	clist.insertAtEnd(20);
	clist.insertAtEnd(30);
	clist.insertAtPosition(15, 2);
	clist.insertAtCenter(25);
	
	
	return 0;
}

