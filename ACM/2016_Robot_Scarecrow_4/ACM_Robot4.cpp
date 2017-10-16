#include<iostream>

using namespace std;

int main() {
	
	int N; //Number of post
	int C; //Number of commands
	int P; //Specific post
	
	N=10;
	C=9;
	P=2;
	// cin>>N;
	// cin>>C;
	// cin>>P;
	int counter=0;
	int post=1;
	for(int i=0;i<C;i++) {
		int temp = 1;
		cin>>temp;
		if(temp==1) {
			post++;
		}else if(temp==0) {
			
		}else if(temp==-1) {
			post--;
			if(post<=0)post=N;
		}
		if(post == P) counter++;
	}
	cout << "counter: " << counter << endl;
	
	return 0;
	
}