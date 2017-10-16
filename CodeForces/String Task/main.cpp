#include <bits/stdc++.h>
using namespace std;

/*
 * http://codeforces.com/problemset/problem/118/A
 */
int main(int argc, char** argv) {
    string input;
    getline(cin,input);
    string output;
    
    char c;
    for(int i=0;i<input.size();i++){
        c = tolower(input[i]);
        
        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'y'){
            output+=".";
            output+=c;
        }
    }
    cout<<output<<endl;
    

    return 0;
}