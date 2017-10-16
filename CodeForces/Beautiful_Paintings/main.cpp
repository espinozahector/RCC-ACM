/* 
 * File:   main.cpp
 * Author: rcc
 * Created on March 10, 2016, 7:55 PM
 */

#include <bits/stdc++.h>
using namespace std;
typedef map<int,int>::iterator it;
/*
 * http://codeforces.com/problemset/problem/651/B
 */

struct cmp{
	bool operator()(const pair<int,int>& left,const pair<int,int>& right) const{
		return left.second < right.second;
	}
};
int main(int argc, char** argv) {
    int n = 0;
    int num=0;
    int temp;
    map<int,int> mymap;
    int total=0;
    
    //Input N
    cin>>n;
    //Input n number of values
    for(int i=0;i<n;i++){
        cin>>num;
        mymap[num]++;
    }
    
    while(mymap.size()!=0){
        it small = min_element(mymap.begin(), mymap.end(),cmp());
        temp=small->second;
        total+=temp*(mymap.size()-1);
        mymap.erase(small);
        small = min_element(mymap.begin(), mymap.end(),cmp());
        while(small->second==temp){
            mymap.erase(small);
            small = min_element(mymap.begin(), mymap.end(),cmp());
        }
        for(it j=mymap.begin();j!=mymap.end();j++){
            //update the value
            j->second-=temp;
        }
        //1 1 1 2 2 3 3 4
        
        //1 2 3 4
        //1 2 3
        //1
    }
    cout<<total<<endl;
    return 0;
}
