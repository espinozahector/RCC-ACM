#include<iostream>
using namespace std;

// https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/all-vowels-2/

bool abc[26] = {0}; //declare the array a-z and set them all equal to 0
int main() {
    int n = 0; // number of inputs
    cin>>n;
    
    string temp; // read in the whole string input
    cin>>temp;
    
	// loop through the entire string character by character
    for(int i = 0; i < n ;i++) { 
        abc[temp[i] - 'a'] = 1; // temp[i] is the character at that index - 'a' so that i turn the ascii character into an index from 0-25
		//abc is a boolean array so at a,e,i,o,u index set equal to true if found
	}
   
	//if a,e,i,o,u is all true than that means it holds all vowels 
    if(abc[0] && abc[4] &&abc[8] &&abc[14] &&abc[20])cout << "YES"<<endl;
    else cout << "NO" << endl;
    return 0;
}