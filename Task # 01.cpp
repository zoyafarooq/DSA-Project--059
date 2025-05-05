#include<iostream>
Using namespace std;
int main(){
	int number = 10;
	int* ptr = &number;
	
	cout << "Original Value: " << number << endl;
	cout << "Value pointed to by ptr: " << *ptr << endl;
	
	*ptr = 25;
	
	cout << "/n Modifying through poniter: " << endl;
	cout << "New value of number: " << number << endl;
	cout << "Value pointed to by ptr: " << *ptr << endl;
	
	return 0;
}

