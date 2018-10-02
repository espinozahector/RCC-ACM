#include <iostream> // input and output
#include <string> //needed for atoi and stoi
#include <algorithm> // needed for reverse
using namespace std;

//http://poj.org/problem?id=1504

void stringSolution();// solution using strings and built-in functions

void intSolution();// pure mathematical solution
int reverseInt(int);// used in our mathematical solution

int main() {
    return 0;
}

void stringSolution(){
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
}

void intSolution(){
    int n = 0;// number of reversals

    int first = 0;// first number input
    int second = 0;// second number input

    int total = 0;// holds our final total

    cin>>n;// input number of reversals

    for(int i = 0; i < n; i++){
        cin>>first;// input first number
        cin>>second;// input second number

        first = reverseInt(first);// set first equal to itself reversed
        second = reverseInt(second);// set second equal to itself reversed

        total = first + second;// add the two together

        total = reverseInt(total);// one final reversal to get our answer

        cout<<total<<endl;// print the output of our processing!
    }
}


int reverseInt(int num){// Takes in an integer and returns the input reversed
    bool negative = (num > 0)?(true):(false);// lets us know if the input is negative
    int output = 0;// Holds output
    
    if(negative){
        num *= -1;// our reverse algorithm only works for positive numbers, so we need to make our number
                  // positive to reverse, then make it negative again at the end
    }

    while(num != 0){// our num will reach 0 when we have finished reversing our number
        output *= 10;// Ill explain this loop with an example below
        output += num % 10;
        num /= 10;
    }

    if(negative){
        output *= -1;// if the input was negative, make the ouput negative
    }

    return output;// return the result of our loop processing 
}

/*
let num = 1234
let result = 0

the first step is to multiply result by 10, what this does is shift the number over, it will make more sense later

the second step is to add our number modded by 10 to the output, what mode 10 essentially does is get the last digit of the number

so 1234 % 10 = 4, now we take 4 and add it to our result

then we divide our input number by 10, what this does is shift the digits to the right and since its an integer, in c++ the last digit will get chopped off
so 1234 / 10 = 123

now we start over, we have 4 in our result and multiply it by 10, 4 * 10 = 40

now, 40 + 123 % 10 = 43 and it repeats until we have put all our digits into the result

output: 0 * 10 = 0
output: 0 + 1234 % 10 = 4
num: 1234 / 10 = 123

4 * 10 = 40
40 + 123 % 10 = 43
123 / 10 = 12

43 * 10 = 430
430 + 12 % 10 = 432
12 / 10 = 1

432 * 10 = 4320
4320 + 1 % 10 = 4321
1 / 10 = 0

since our num is now 0 the loop terminates
*/