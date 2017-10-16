/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 *
 * Created on March 17, 2016, 7:51 PM
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * http://codeforces.com/problemset/problem/96/A
 */
int main(int argc, char** argv) {
    string x = "";
    int counter=0;
    char which;
    int i=0;
    
    getline(cin,x);
    
    for(int i=0;i<x.size();i++){
        if(x[i]==which){
            counter++;
        }
        else if(x[i] != which){
            counter=1;
            which=x[i];
        }
        if(counter==7){
            cout<<"YES\n";
            return 0;
        }
        
    }
    cout<<"NO\n";
    
    return 0;
}

