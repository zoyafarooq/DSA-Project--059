#include <iostream>
using namespace std;

class StackArray {
	private:
		int arr[100];
		int top;
		
	public:
		StackArray(){
			top = -1;
		}
		
		void push(int val) {
			if(top >= 99){
				cout << "Stack Overflow! " << endl;
				return;
			}
			
			arr[++top] = val;
			cout << val << "pushed to stack." << endl;
		}
		
		void pop(){
			if (top == -1){
				cout << "Stack Underflow! " << endl;
				return;
			}
			
			cout << arr[top--] << " popped from stack. " << endl;
		}
		
		void display() {
			if(top == -1){
				cout << "Stack is Empty! " << endl;
				return;
			}
			
			cout << "Stack ( Top to Bottom): " ;
			for (int i = top; i >=0; i--)
				cout << arr[i] << " " ;
				cout << endl;
		}
};


int main (){
	cout <<  " Stack using Array " << endl;
	StackArray s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.display();
	s1.pop();
	s1.display();
	
	return 0 ;
	
}
