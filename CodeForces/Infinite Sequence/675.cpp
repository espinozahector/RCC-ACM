#include <bits/stdc++.h>
using namespace std;
/*
 *
 */
int main(){
	int start;
	int fav;
	int inc;
	
	cin>>start>>fav>>inc;
	
	int i=start;
	if(inc == 1) {
		if(i <= fav){	
			cout << "YES" << endl;
			return 0;
		}
	}
	else if(inc == -1) {
		if(i >= fav){	
			cout << "YES" << endl;
			return 0;
		}
	}
	
	if(inc == 0) {
		if(i != fav) {
			cout << "NO" << endl;
			return 0;
		}
	}
	if(inc >= 0) {//positive
		while(i<=fav){
			//cout << i << endl;
			if(i==fav){cout << "YES\n"; return 0;}
			i+=inc;
		}
	}
	else if(inc <= 0) {//neg
		while(i >= fav){
			// cout << i << endl;
			if(i==fav){cout << "YES\n"; return 0;}
			i+=inc;
		}
	}
	
	
	cout << "NO\n";
	return 0;
}