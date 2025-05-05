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


class LinkedList{
	private:
		Node* head;
		
	public:
		LinkedList(){
			head = nullptr;
		}
		
	void insertAtEnd(int value){
		Node* newNode = new Node(value);
		
		if(head == nullptr){
			head = newNode;
		}
		
		else{
			Node* temp = head;
			while (temp->next != nullptr){
				temp = temp->next;
			}
			temp->next = newNode;
		}
	}
	void insertAtPosition(int value, int position){
		Node* newNode = new Node(value);
		
		if (position == 1){
			newNode->next = head;
			head = newNode;
			cout << " Inserted" << value << " at position 1" << endl;
			display();
			return;
		}
		
		Node* temp = head;
		int count = 1;
		
		while(temp != nullptr && count < position - 1){
			temp = temp->next;
			count++;
		}
		
		if (temp == nullptr){
			cout << "Invalid position! Insertion failed." << endl;
			delete newNode;
			return;
		}
		
		newNode->next = temp->next;
		temp->next = newNode;
		
		cout << "Inserted" << value << "at position" << position << endl;
		display();
	}
	
	void display(){
		Node* temp = head;
		cout << "Current List: ";
		while (temp != nullptr) {
			cout << temp->data << "->";
			temp = temp->next;
		}
		
		cout << "NULL" << endl << endl;
	}
};


int  main(){
	LinkedList list;
	
	list.insertAtEnd(10);
		list.insertAtEnd(20);
			list.insertAtEnd(30);
			
	list.display();
	
	list.insertAtPosition(15, 2);
	list.insertAtPosition(5, 1);
	list.insertAtPosition(40, 6);
	list.insertAtPosition(100, 10);
	
	return 0;
}

