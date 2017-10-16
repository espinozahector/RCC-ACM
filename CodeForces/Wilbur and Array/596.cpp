#include<iostream>
using namespace std;
//http://codeforces.com/problemset/problem/596/B
int main() {
	int n;
	cin>>n;
	
	int temp;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> temp;
		arr[i] = temp;
	}
	
	int arr2[n];
	for(int i = 0; i < n; i++) arr2[i] = 0;
	int count = 0;
	for(int i = 0; i <n;i++) {
		do{
			if(arr2[i] < arr[i]) {
				for(int j = i; j<n;j++) {
					arr2[j]++;
					
				}
				count++;
			}
			if(arr2[i] > arr[i]) {
				for(int j = i; j<n;j++) {
					arr2[j] = arr2[j]-1;;
				}
				count++;
			}
		}while(arr2[i] != arr[i]);

		
	}
	
	//Print
	cout << "count = " << count << endl;
	cout << "Array = [";
	for(int i = 0; i <n;i++) {
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
	cout << "Array2 = [";
	for(int i = 0; i <n;i++) {
		cout << arr2[i] << " ";
	}
	cout << "]" << endl;
	return 0;
}