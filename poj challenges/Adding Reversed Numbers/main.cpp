#include <iostream> // input and output
#include <string> //needed for atoi and stoi
#include <algorithm> // needed for reverse
using namespace std;

//http://poj.org/problem?id=1504

int main() {
    int n; //number of inputs
    int first; // first number to be inputed
    int second; // second number to be inputed
    
    cin>>n; // read in the number of inputs from the user
    for(int i = 0; i < n; i++) { // loop the corresponding amount
        //read in the first and second number every loop
        cin >> first; 
        cin >> second;
        
        string temp (to_string(first)); // convert the integers into a string in order to easily reverse
        string temp2 (to_string(second)); //convert the integers into a string in order to easily reverse
        
        reverse(temp.begin(),temp.end()); // reverse the string, needs to have a pointer to the beginning of the string and the end of the string
        reverse(temp2.begin(),temp2.end()); 

        int total = stoi (temp)+stoi (temp2); // stoi will convert a string into an integer. we are converting both string numbers to integers and taking the sum
        
        string temp3 = to_string(total); //we need to convert the total back into a string in order to reverse it easily
        reverse(temp3.begin(),temp3.end()); //reverse the string, easier as a string rather then an integer
        
        // finally convert the string into an integer, which covers the last condition.
        // in case there is trailing 0's it will be cut off
        cout << stoi(temp3) <<endl; 
    }
    return 0;
}