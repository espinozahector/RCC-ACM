    
    #include <iostream>
    using namespace std;

    int reverseInt(int);// used in our mathematical solution
    
    //http://poj.org/problem?id=1504

    int main(){
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
    return 0;
}


int reverseInt(int num){// Takes in an integer and returns the input reversed
    int output = 0;// Holds output

    while(num != 0){// our num will reach 0 when we have finished reversing our number
        output *= 10;// Ill explain this loop with an example below
        output += num % 10;
        num /= 10;
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
