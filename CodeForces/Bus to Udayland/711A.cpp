#include <bits/stdc++.h>
using namespace std;
/*
 * http://codeforces.com/problemset/problem/711/A
 */
int main() {
	int n=0;
	string in;
	string out;
	bool done = false;
	
    cin>>n;
	cin.ignore();
	
	for(int i=0;i<n;i++)
	{
		getline(cin,in);
		
		if(in[0]=='O' && in[1]=='O' && done == false)
		{
			// cout << "true\n";
			in[0]='+';
			in[1]='+';
			out+=in;
			done = true;
		}
		else if(in[3]=='O' && in[4]=='O' && done == false)
		{
			// cout << "true\n";
			in[3]='+';
			in[4]='+';
			out+=in;
			done = true;
		}
		else
		{
			out+=in;
		}
	}
	if(done) cout << "YES\n";
	else if(!done) {cout << "NO\n"; return 0;}
		
	//output
	int count = 0;
	for(int i =0;i<n*5;i++,count++)
	{
		if(count==5){ cout<<endl; count = 0; }
		cout << out[i];
				
	}
	
	return 0;
}