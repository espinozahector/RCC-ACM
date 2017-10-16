#include <bits/stdc++.h>
using namespace std;
/*
 * http://codeforces.com/problemset/problem/673/A
 */
int main()
{
	int n;
	cin >> n;
	
	int t, a=0;
	
	for(int i = 0; i < n; i++)
	{
		cin >> t;
		if(t - a > 15) {cout<< a + 15 <<endl; return 0;}
		a = t;
	}
	
	if(t + 15 > 90) cout<< 90 <<endl;
	else cout<< t + 15 <<endl;
	
	return 0;
}