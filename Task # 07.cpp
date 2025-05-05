#include <iostream>
using namespace std;

class Node{
	
	public:
		int data;
		Node* next;
		Node* prev;
		
		Node(int value) {
			data = value;
			next = nullptr;
			prev = nullptr;
		}
};

class DoublyLinkedList {
	private:
		Node* head;
		Node* tail;
		
	public:
		DoublyLinkedList(){
			head = nullptr;
			tail = nullptr;
		}
		
		void insertAtStart(int value) {
			Node* newNode = new Node(value);
			if(head == nullptr) {
				head = tail = newNode;
			}
			
			else{
				newNode->next = head;
				head->prev = newNode;
				head = newNode;
			}
			
			cout << " Insert at start: " << value << endl;
		}
		
		void insertAtEnd(int value) {
			Node* newNode = new Node(value);
			if(tail == nullptr) {
				head = tail = newNode;
			}
			
			else{
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}
			
			cout << "Insert at end: " << value << endl;
			
		}
		
		void insertAtPosition(int value, int position) {
			if(position <= 0){
				cout << "Invalid position!" << endl;
				return;
			}
			
			if(position == 1){
				insertAtStart(value);
				return;
			}
			
			Node* newNode = new Node(value);
			Node* temp = head;
			int count = 1;
			
			while (temp != nullptr && count < position - 1){
				temp = temp->next;
				count++;
			}
			
			if(temp == nullptr){
				cout << "Posiiton out of range. " << endl;
				delete newNode;
				return;
			}
			
			newNode->next = temp->next;
			newNode->prev = temp;
			
			if(temp->next != nullptr)
				temp->next->prev = newNode;
				
				temp->next = newNode;
				
				if(newNode->next == nullptr)
					tail = newNode;
					
				cout << "Inserted" << value << " ata position" << position << endl; 
			
		}
		
		
		void insertAtCenter(int value){
			int count = 0;
			Node* temp = head;
			
			while (temp != nullptr) {
				count++;
				temp = temp->next;
			}
			
			int midPos = (count / 2) + 1;
			insertAtPosition(value, midPos);
			cout << "Inserted" << value << "at center position" << midPos << endl;
			
		}
		
		void displayForward(){
			Node* temp = head;
			cout << "List (forward):" ;
			while(temp != nullptr) {
				cout << temp->data << "<->";
				temp = temp->next;
			}
			
			cout << "NULL" << endl;
		}
		
		void displayBackward(){
			Node* temp = tail;
			cout << "List (reverse): ";
			while (temp != nullptr) {
				cout << temp->data << "<->" ;
				temp = temp->prev;
			}
			
			cout << "NULL" << endl;
		}
};

int main (){
	DoublyLinkedList list;
	
	list.insertAtStart(10);
	list.insertAtEnd(20);
	list.insertAtEnd(30);
	list.insertAtPosition(15, 2);
	list.insertAtCenter(25);
	
	list.displayForward();
	list.displayBackward();
	
	return 0;
}

