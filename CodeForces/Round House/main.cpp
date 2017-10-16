
#include <bits/stdc++.h>
using namespace std;
/*
 *http://codeforces.com/problemset/problem/659/A
 */
int main(){
	int n;
	int a;
	int b;
	cin>>n>>a>>b;
	//100 1 -1

	int steps=0;
	int i=a;
	if(b==0){
		cout << a << endl;
		return 0;
	}
	
	if(b<0){
		b=-b;
		while(steps != b){
			if(i==0)i=n;
			steps++;
			i--;
		}
	}
	else if(b>=0){
		while(steps != b){
			//cout << i << endl;
			if(i==n) i=0;
			steps++;
			i++;
		}
	}
	if(i==0) cout << n << endl;
	else cout << i << endl;
	return 0;
}