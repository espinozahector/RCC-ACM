#include <iostream>

std::string parse(std::string);
bool isPalindrome(std::string);

int main(){
    std::string input = "";
    
    std::cin>>input;

    std::cout<<std::boolalpha<<isPalindrome(parse(input));

    return 0;
}

std::string parse(std::string input){
    int size = input.length();
    char shift = 'A' - 'a';
    std::string output = "";

    for(int i = 0; i < size; i++){
        if(input[i] >= 'A' && input[i] <= 'Z'){
            output += input[i] - shift;
        }
        else if(input[i] >= 'a' && input[i] <= 'z'){
            output += input[i];
        }
        else if(input[i] >= '0' && input[i] <= '9'){
            output += input[i]; 
        }
    }

    return output;
}

bool isPalindrome(std::string input){
    bool palindrome = true;
    int size = input.length();

    for(int i = 0; i < size / 2; i++){
        if(input[i] != input[size - i - 1]){
            palindrome = false;
            break;
        }
    }

    return palindrome;
}