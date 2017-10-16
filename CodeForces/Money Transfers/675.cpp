#include <bits/stdc++.h>
using namespace std;
/*
 * Money Transfers
 * http://codeforces.com/problemset/problem/675/C
 */
 void print(vector<int> v)
 {
	for(int i=0;i<v.size();i++) cout << v[i]<<" ";
	cout << endl;
 }
 bool check(vector<int>v)
 {
	int counter=0;
	for(int i =0;i<v.size();i++)
	{
		if(v[i]==0) counter++;
	}
	if(counter==v.size()) return true;
	else return false;
 }
int main() {
	int n;//number of banks
	int in;//input
	vector<int>bank;
	vector<int>bank2;
	int loc;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>in;
		bank.push_back(in);
		bank2.push_back(in);
		if(in < 0) loc=i;
	}	
	int action=1;
	for(int i=0;i<n;i++)
	{
		if(bank[i] < 0)continue;
		if(bank[i]==0)continue;
		bank[i+1]+=bank[i];
		bank[i]=0;
		// print(bank);
		if(check(bank)==true) break;
		action++;
	}
	// cout << action << endl;
	// cout << "------------------------------------\n";
	int actions=1;
	int j;
	for(int i=0;i<n;i++)
	{
		j=i-1;
		if(j<0)j=bank2.size()-1;
		
		if(bank2[i] < 0)continue;
		if(bank2[i]==0)continue;
		
		bank2[j]+=bank2[i];
		bank2[i]=0;
		// print(bank2);
		if(check(bank2)==true) break;
		actions++;
	}
	// cout << actions << endl;
	if(action < actions) cout << action << endl;
	else if(action > actions) cout << actions << endl;
	else cout << action << endl;
	//Old way
	/*
	for(int i=0;i<bank.size();i++)
	{
		if(i==loc){i++; continue;}
		
		if(bank[i]==0){i++; continue;}
		else
		{
			if(i==bank.begin() && loc >=bank.size()/2)
			{
				//then i will go around the vector
				
			}
			if(loc < i)//go back
			{
				
			}
			if(loc >= i)// go forward
			{
				
			}
		}
		
		if(bank[loc]==0) break;
		print(bank);
		action++;
	}
	cout << action << endl;
	*/
	return 0;
}