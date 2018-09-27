
#include <iostream> // input and output library
using namespace std;

// http://poj.org/problem?id=1936

int main(int argc, char** argv) {
    string first; // first string input
    string second; // second string input
    int counter = 0; // counter keep track of number of found characters 
    
    // current index to check from.. b/c we dont wanna recheck the entire second string
    int index = 0; 
    
    cin >> first >> second; // input
    
    // get size before loop... b/c efficiency
    int size1 = first.length(); 
    int size2 = second.length();
    
    for(int i = 0; i < size1; i++){ // loop through first string
        for(int j = index; j < size2; j++) { // loop through second string starting from check index
            if(first[i] == second[j]) { // compare character in first string to character in second string
                counter++;// increment counter b/c we found a match
                // set index to the current search index and add one b/c we don't wanna check against the previous comparison
                // e.x. without the j+1 this would work.
                // CSS CS 
                // 1st loop C vs C true
                // 2nd loop S vs C false
                // 3rd loop S vs S true
                // as you can see we are checking against the previous condition when we actually want to check with the next condition
                index = j+1; 
                break; // efficiency
            }
        }
    }
    if(counter == size1)cout << "Yes" << endl; // if the number of correct keys is equal to the number of characters, then the subsequence was found
    else cout << "No" << endl; // else no
    return 0; // Exit Stage Right! 
}

