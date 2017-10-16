
#include <bits/stdc++.h>

using namespace std;
/*
 *http://codeforces.com/problemset/problem/669/A
*/
int main() {
	int stone=0;
	int count=0;
	
	cin>>stone;
	
	count = (stone/3) * 2;
	cout<<(stone%3?count+1:count)<<endl; 
	return 0;
}