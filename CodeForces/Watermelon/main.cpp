/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 3, 2016, 7:35 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int weight;
    cin>>weight;
    
    if(weight>2 && weight%2==0){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}

