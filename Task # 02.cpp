#include <iostream>
using namespace std;

int findMax(int arr[], int n){
	int maxVal = arr[0];
	
	for(int i = 1; i < n; i++){
		if(arr[i] > maxVal){
			maxVal = arr[i];
			
		}
	}
	
	return maxVal;
}

int main(){
	int arr[] = {10, 45, 32, 67, 23};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	int maxValue = findMax(arr, size);
	
	cout << " The maximum value in the array is:" << maxValue << endl;
	return 0;
}

