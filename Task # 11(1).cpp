#include <iostream>
using namespace std;

class QueueArray {
	int arr[100];
	int front, rear;
	
	
 	public:
 		QueueArray(){
 			 front = rear =  -1;
 			 
		 }
		 
		 void enqueue(int val){
		 	if(rear == 99){
			 
		 		cout << " Queue overflow \n ";
		 		return;
		 }
		 
		 	if(front == -1) front = 0;
		 		arr[++rear] = val;
		 		cout << val << " enqueue to queue." << endl;
			 
		 }
		 
		 void dequeue(){
		 	if(front == -1 || front > rear){
			 
		 		cout << " Queue underflow \n ";
		 		return;
		 }
		 
		 cout << arr[front++] << " dequeue from queue." << endl;
		 
	}
	
		 
		 void display(){
		 	if(front == -1 || front > rear)
		 		cout << "Queue is empty! \n";
		 		return;
		 
		 		cout << " Queue: (Front to rear): ";
		 		for(int i = front; i <=rear; i++)
		 			cout << arr[i] << " ";
		 			cout << endl;
			 
		 }
		 
};

int main(){
	
		cout << " Queue with Aarry \n" ;
		QueueArray q1;
		q1.enqueue(10);
		q1.enqueue(20);
		q1.enqueue(30);
		q1.display();
		q1.display();
		q1.display();
		
		return 0;
}

