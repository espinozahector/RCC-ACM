/* 
 * File:   main.cpp
 * Author: rcc
 * Created on March 10, 2016, 2:59 PM
 */

#include <iostream>

using namespace std;

/*
 * http://codeforces.com/problemset/problem/651/A
 */
int main(int argc, char** argv) {
    
    int p1 = 0;
    int p2 = 0;
    int min = 0;
    cin>>p1;
    cin>>p2;
    while(p1!=0 && p2!=0){
        if(p1<2 && p2 <2){
            cout<<"0\n";
            return 0;
        }
        if(p1<p2 || p1==p2){
            p1++;
            p2-=2;
            min++;
        }
        else if(p1>p2){
            p2++;
            p1-=2;
            min++;
        }
    }
    cout<<min<<endl;
    return 0;
}

