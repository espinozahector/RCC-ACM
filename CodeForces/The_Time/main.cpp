/* 
 * File:   main.cpp
 * Author: Hector Espinoza
 * Created on March 3, 2016, 6:19 PM
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {

    string time;
    getline(cin,time);
    int minutes;
    cin>>minutes;
    
    string hour = "";
    string min = "";
    
    bool first = true;
    
    for(int i =0;i<time.length();i++){
        //pull apart the hour and minute
        if(time[i]!=':' && first==true){
            hour+=time[i];
        }
        if(time[i]==':'){
            first=false;
        }
        if(first==false && time[i]!=':'){
            min+=time[i];
        }
    }
    
//    cout << "Hour -> " << hour <<endl;
//    cout << "Min -> " << min <<endl;
    int newhour = atoi(hour.c_str());//Used to convert the string to an integer
    int newmin = atoi(min.c_str());
    newmin+=minutes;
    while(newmin>=60){
        newhour++;
        newmin=newmin-60;
    }
    while(newhour>=24){
        newhour=newhour-24;
    }
    
    if(newhour<10 && newmin<10){
        cout<<"0"<<newhour<<":"<<"0"<<newmin<<endl;
    }
    else if(newhour<10 && newmin>=10){
        cout<<"0"<<newhour<<":"<<newmin<<endl;
    }
    else if(newhour>=10 && newmin<10){
        cout<<newhour<<":"<<"0"<<newmin<<endl;
    }
    else if(newhour>=10 && newmin>=10){
        cout<<newhour<<":"<<newmin<<endl;
    }
        
//    cout<<"Time -> "<<newhour<<":"<<newmin<<endl;
    //Works but needs leading 0's thats the only problem!!!!!
    return 0;
}