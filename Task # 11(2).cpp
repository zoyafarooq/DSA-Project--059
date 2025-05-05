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

class QueueLinkedList {
	Node* front;
	Node* rear;
	
	public:
	    QueueLinkedList(){
			front = rear = nullptr;
		}
		
		void enqueue (int val){
			Node* newNode = new Node(val);
			if(rear == nullptr){
			
				front = rear = newNode;
			}
			else{
				rear->next = newNode;
				rear = newNode;
			}
			
			cout << val << " enqueue to queue." << endl;
		}
		
		
		void dequeue(){
			if(front == nullptr){
				cout << " Queue Undeflow\n ";
				return;
				
			}
			
			Node* temp = front;
			cout << front->data << "Dequeued: " << endl;
			front = front->next;
			if (front == nullptr) rear = nullptr;
			delete temp;
		}
		
		void display(){
			if (front == nullptr) {
				cout << "Queue is empty \n";
				return;
			}
		
			Node* temp = front;
			cout << "Queue: ";
			while(temp != nullptr){
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
};

int main (){
	
	cout << "Queue using Linked List ";
	QueueLinkedList q2;
	q2.enqueue(20);
	q2.enqueue(30);
	q2.enqueue(40);
	q2.display();
	q2.display();
	q2.display();
	
	return 0;
}
