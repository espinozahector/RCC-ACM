/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on March 23, 2016, 8:20 PM
 */

#include <bits/stdc++.h>

using namespace std;
typedef map<string,int>::iterator it;

/*
 * 
 */
int main(int argc, char** argv) {
    int n;
    vector <string> names;
    map<string,int>x;
    string name;
	
	cin>>n;
    
    for(int i =0;i<n;i++){
        cin>>name;
        names.push_back(name);
    }
    
    for(int i=0;i<n;i++){
            x[names[i]]++;
            if(x[names[i]]==1)cout<<"OK\n";
            else cout << names[i] << x[names[i]]-1 << endl;
    }
    
    return 0;
}

