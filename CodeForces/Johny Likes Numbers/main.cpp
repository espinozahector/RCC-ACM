#include <iostream>

using namespace std;
/*
 * http://codeforces.com/problemset/problem/678/A
 */
int main() {
	int n ,k;
	cin>>n;
	cin>>k;
	int x = k;
	if(k == 1)
	{
		cout << n+1 << endl;
		return 0;
	}
	while(x <= n)
	{
		x+=k;
	}
	cout << x << endl;
	return 0;
}