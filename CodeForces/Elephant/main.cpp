/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 17, 2016, 1:57 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int  n=12;
    int steps=0;
    while(n>5 ){
        n-=5;
        steps++;
    }
    if(n<=5){
        steps++;
    }
    cout<<steps<<endl;
    return 0;
}

