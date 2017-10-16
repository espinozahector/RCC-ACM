
#include <bits/stdc++.h>
using namespace std;
/*
 * http://codeforces.com/problemset/problem/672/A
 */
int main() {
	string line;
	ostringstream oss;
	int n;
	cin >> n;
	
	if(n<10) cout << n << endl;
	else {
		for(int i=1;i<=n;i++){
			oss << i;
			line+= oss.str();
			oss.str("");
		}
		//cout << line << endl;
		cout << line[n-1] << endl;
	}
	return 0;
}