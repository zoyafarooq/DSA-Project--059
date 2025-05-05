#include <iostream>
using namespace std;

class Node {
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
		LinkedList() {
			head = nullptr;
		}
		
		void insertAtEnd(int value){
		Node* newNode = new Node(value);
		if(head == nullptr)
				head = newNode;
				
		else{
			Node* temp = head;
			while ( temp->next != nullptr)
				temp = temp->next;
				temp->next = newNode;
		}
	}
	
	void display(){
		Node* temp = head;
		cout << "Current List: ";
		while (temp != nullptr){
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		
		cout << "NULL" << endl << endl;
	}
	
	void deleteFirst(){
		if(head == nullptr){
			cout << "List is empty. Nothing to delete." << endl;
			return;
		}
		
		Node* temp = head;
		head = head->next;
		cout << "Deleted first node: " << temp->data << endl;
		delete temp;
		display();
	}
	
	void deleteLast(){
		if (head == nullptr) {
				cout << "List is empty. Nothing to delete." << endl;
				return;
			}
			
		if(head->next == nullptr) {
			cout << "Deleted ladt Node:"  << head->data << endl;
			delete head;
			head = nullptr;
			display();
			return;
		}
		
		Node* temp = head;
		while(temp->next->next != nullptr)
			temp = temp->next;
			
		cout << "Deleted last node: " << temp->next->data << endl;
		delete temp->next;
		temp->next = nullptr;
		display();
		
	}
	
	void deleteNth(int position) {
		if (head == nullptr || position <= 0){
		cout << "Invalid Position or Empty list." << endl;
		return;
		}
		
		if (position == 1){
			deleteFirst();
			return;
		}
		
		Node* temp = head;
		int count = 1;
		
		while (temp != nullptr && count < position - 1){
			temp = temp->next;
			count++;
		}
		
		if(temp == nullptr || temp->next == nullptr){
			cout << " Position out of range! " << endl;
			return;
		}
		
		Node* toDelete = temp->next;
		temp->next = temp->next->next;
		cout<< "Deleted node at posistion " << position << " : " << toDelete->data << endl;
		delete toDelete;
		display();
		
	}
	
	void deleteMiddle(){
		if( head == nullptr) {
			cout << "List id empty. Nothing to delete. " << endl;
			return;
		}
		
		if (head->next == nullptr) {
			cout << "Deleted middle node (only node):" << head->data << endl;
			delete head;
			head = nullptr;
			display();
			return;
		}
		
		Node* slow = head;
		Node* fast = head;
		Node* prev = nullptr;
		
		while (fast != nullptr && fast->next != nullptr ) {
			fast = fast->next->next;
			prev = slow;
			slow = slow->next;
		}
		
		cout << " Deleted middle node: " << slow->data << endl;
		prev->next = slow->next;
		delete slow;
		display();
	}
	
};


int main(){
	
	LinkedList list;
	
	list.insertAtEnd(10);
	list.insertAtEnd(20);
	list.insertAtEnd(30);
	list.insertAtEnd(40);
	list.insertAtEnd(50);
	
	list.display();
	
	list.deleteFirst();
	list.deleteLast();
	list.deleteNth(2);
	list.deleteMiddle();
	
	return 0 ;
	
}

