
#include <bits/stdc++.h>

using namespace std;
typedef map<string,string>::iterator it;

int main(){
	map<string,string> x;//name, status
	vector<string>s;//status
	
	char in;
	string name;
	string stat;
	bool found=false;
	
	while(!cin.eof()){
		// \n
		cin.get(in);
		if(in == ':'){
			x[name]="";
			found = true;
		}
		if(found == false){
			name +=in;
		}
		if(in=='c' && found){
			x[name]=stat;
			s.push_back(stat);
		}
		if(in == '\n'){
			name="";
			stat="";
			found=false;
		}
		if(found){
			if(in=='u') stat+='a';
			else if(in=='m') stat+='b';
			else if(in=='w') stat+='c';
		}
	}
	string temp;
	for(int i=0;i<s.size();i++){
		for(int j=i+1;j<s.size();j++){
			if(s[i]>s[j]){
				temp = s[j];
				s[j] = s[i];
				s[i] = temp;
			}
		}
	}
	//for(int i=0;i<s.size();i++){
		//cout << s[i] << endl;
	//}
	for(int j=0;j<s.size();j++){
		for(it i=x.begin();i!=x.end();i++){
			if(i->second == s[j]){
				cout << i->first << endl;
			}
		}
	}
	
	return 0;
}