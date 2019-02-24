
#include <bits/stdc++.h>

using namespace std;
// typedef map<int,int>::iterator it;

/*
 *http://socalcontest.org/history/2015/problemset2015.pdf
*/
int main(){
	set<int>c;
	vector<pair<int,int> >coord;//grid
	char in;
	int x=1,y=1;
	// string line;
	int count=0;
	while(!cin.eof()){
		cin.get(in);
		if(in == 'x'){
			coord.push_back(make_pair(x,y));
		}
		x++;
		if(in == '\n'){
			y++;
			x=1;
		}
	}
	int a;
	int b;
	for(int i =0;i<coord.size()-1;i++){
		for(int j=i+1;j<coord.size();j++){
		a = (coord[i]).first - (coord[j]).first;
		b = (coord[i]).second - (coord[j]).second;
		if(a<0) a*=-1;//abs
		if(b<0) b*=-1;//abs
		c.insert(b+a);
		}
		
	}
	cout << c.size()  << endl;
	
	
	return 0 ;
}