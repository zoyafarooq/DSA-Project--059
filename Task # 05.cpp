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
		
		void insertAtEnd(int value){
			Node* newNode = new Node(value);
			if(head == nullptr) {
				head = newNode;
			}
			else{
				Node* temp = head;
				while (temp->next != nullptr)
				temp = temp->next;
				temp->next = newNode;
			}
		}
		
		void displayList(){
			Node* temp = head;
			cout << " Current List: ";
			while (temp != nullptr){
				cout << temp->data << " -> ";
				temp = temp->next;
			}
			
			cout << "NULL" << endl << endl;
		}
		
		void displayFirst(){
			if(head != nullptr)
				cout << "First node: " << head->data << endl;
			else
				cout << "List is empty." << endl;
		}
		
		void displayLast(){
			if(head == nullptr){
				cout << "List is empty." << endl;
				return;
			}
			
			Node* temp = head;
			while (temp->next != nullptr)
				temp = temp->next;
				
				cout << "Last node: " << temp->data << endl;
		}
		
		void displayNth(int position){
			if (position <= 0){
				cout << "Invalid position!" << endl;
				return;
			}
			
			Node* temp = head;
			int count = 1;
			
			
			while (temp != nullptr && count < position ){
				temp = temp->next;
				count++;
			}
			
			if(temp != nullptr)
				cout << "Node at Position" << position << ":" << temp->data << endl;
			else
				cout << "Position" << position << " is out of range!" << endl;	
			
		
			}
		
			void displayMiddle(){
				if (head == nullptr){
					cout << "List is empty." << endl;
					return;
				}
				
				Node* slow = head;
				Node* fast = head;
				
				while(fast != nullptr && fast->next != nullptr){
					slow = slow->next;
					fast = fast->next->next;
				}
				
				cout << "Middle node: " << slow->data << endl;
				
			}
			
	};
	
int main(){
	LinkedList list;
	
	list.insertAtEnd(10);
	list.insertAtEnd(20);
	list.insertAtEnd(30);
	list.insertAtEnd(40);
	list.insertAtEnd(50);
	
	list.displayList();
	
	list.displayFirst();
	list.displayLast();
	list.displayNth(3);
	list.displayMiddle();
	
	return 0;
}

