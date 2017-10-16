
#include <bits/stdc++.h>
using namespace std;
/*
 * 
 */
int main(){
    int n;
    cin>>n;
	
    vector <string> order;
	map<string,int> count;
    
    for(int i = 0; i < n; i++){
        string name;
        cin>>name;
        order.push_back(name);
        
    }
	for(int i = n-1 ; i >= 0; i--){
		count[order[i]]++;
		if(count[order[i]] == 1){
			cout << order[i] << endl;

		}
	}

    return 0;
}