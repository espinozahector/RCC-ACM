#include <iostream>

int main(){
    const int SIZE = 26;

    std::string sentence;
    int sentLength = 0;
    int maxH = 0;

    int arr[SIZE];
    
    for(int i = 0; i < SIZE; i++){
        arr[i] = 0;
    }

    for(int i = 0; i < 4; i++){// input and counting of each character
        std::getline(std::cin, sentence);

        sentLength = sentence.length();// more efficient than putting temp.length() as the for-loop condition
        
        for(int j = 0; j < sentLength; j++){
            if(sentence[j] >= 'A' && sentence[j] <= 'Z'){// Dont process if the char is not a capital alpha character
                arr[sentence[j] - 'A']++;// A = 0, B = 1, C = 2, etc.. So if we have R, we can find its index in the array by subtracting A; 'R' - 'A' = 17 when A = 97 and R = 114
                if(arr[sentence[j] - 'A'] > maxH){// Find the max height used for printing later
                    maxH = arr[sentence[j] - 'A'];
                }
            }
        }
    }
    
    for(int i = 0; i < maxH; i++){// start at the top and work down
        for(int j = 0; j < SIZE; j++){// loop through all the characters
            if(arr[j] == maxH - i){// if the character has a current height equal to the current row height, print a *
                std::cout<<"* ";
                arr[j]--;// reduce the height so we can compare to current row height
            }
            else{
                std::cout<<"  ";
            }
        }
        std::cout<<std::endl;
    }
    std::cout<<"A B C D E F G H I J K L M N O P Q R S T U V W X Y Z "<<std::endl;
    
    return 0;
}
/*
http://poj.org/problem?id=2136

*/