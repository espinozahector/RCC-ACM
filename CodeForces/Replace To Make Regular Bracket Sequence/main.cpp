/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on March 24, 2016, 3:08 PM
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * http://codeforces.com/problemset/problem/612/C
 */
//[]]]
int main(int argc, char** argv) {
    string x;
    cin>>x;
    vector<char> left;
    int total=0;
    if(x[0]=='>' || x[0]=='}' || x[0]==']' || x[0]==')'){
        cout<<"Impossible\n";
        return 0;
    }
    if(x.size()%2!=0){
        cout<<"Impossible\n";
        return 0;
    }
    
    for(int i=0;i<x.size();i++){
        if(x[i]=='<' || x[i]=='{' || x[i]=='[' || x[i]=='('){
            left.push_back(x[i]);
        }
        else{
            if(left.size()==0 ){
                cout<<"Impossible\n";
                return 0;
            }
//            cout<<left[left.size()-1]<<endl;
            if(x[i]==')'){
                if(x[i]-left[left.size()-1]!=1){
                    total++;
                }
            }else if(x[i]-left[left.size()-1]!=2){
//                cout<<total<<endl;
                total++;
            }
            left.pop_back();
        }
        
    }
    if(left.size()!=0){
        cout<<"Impossible\n";
    }else{
        cout<<total<<endl;
    }
    
    return 0;
}

