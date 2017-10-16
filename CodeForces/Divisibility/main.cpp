/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on February 29, 2016, 2:34 PM
 */

#include <iostream>
#include <cmath>
using namespace std;
/**
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {
    /*
     Find the number of k-divisible numbers on the segment [a, b]. 
     In other words you need to find the number of such integer 
     values x that a ≤ x ≤ b and x is divisible by k.
     */
    int k = 2,a = 0,b = 4;
    int common = 0;
    int total = 0;
    if(k==1)total=b-a+1;//Then k reads all the numbers
    else if(a<0 && b>-1){
//        cout<<"a<0\n";
        int high=b+1;
        if(abs(a)<b){//abs means (absolute value)
            common = abs(a);
        }
        else{
            common = b;
            high = abs(a)+1;
        }
        common++;
//        cout<<"common = "<<common<<endl;
        for(int i=1;i<common;i++){
            if(i%k==0)total++;
        }
        total*=2;
        total++;
//        cout<<"total = "<<total<<endl;
        for(int i=common;i<high;i++){
            if(i%k==0)total++;
        }
    }
    else{
        if(a<0 && b<0){
//            cout<<"both negative\n";
//            int temp=a;
//            a=b;
//            b=temp;
            a=a^b;
            b=a^b;
            a=a^b;
            a=abs(a);
            b=abs(b);
        }
//        cout<<"a"<<a<<"b"<<b<<endl;
        b++;
        for(int i = a;i<b;i++){
            if(i%k==0){
                total++;
            }
        }
    }
    cout << "Total -> " << total <<endl;
    
    return 0;
}

