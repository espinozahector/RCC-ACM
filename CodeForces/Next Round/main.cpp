#include <bits/stdc++.h>
using namespace std;
/*
 *http://codeforces.com/problemset/problem/158/A
 */
int main(){
	int n;
	cin >>n;
	int k;
	cin >> k;
	vector<int>scores;
	int s;
	for(int i=0;i<n;i++){
		cin>>s;
		scores.push_back(s);
	}
	int num = scores[k-1];
	int count=0;
	for(int i =0;i<n;i++){
		if(scores[i] != 0){
			if(scores[i]>=num)count++;
		}
	}
	
	cout << count <<endl;
	return 0;
}