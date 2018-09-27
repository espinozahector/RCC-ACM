#include <iostream>

#include <map>
#include <iterator>

/*
Take in N trees and determine percentage of a forest that each tree accounts for 

src: http://poj.org/problem?id=2418

*/


void noMap();
void withMap();

int main(){
    noMap();
    //withMap();
    
    return 0;
}

void noMap(){
    ///// solving this problem with out using a map /////

    // Number of inputs therefore can also be used as population
    int n = 0;

    // temporary variable used when getting input
    std::string temp = "";

    // dynamic array to hold number of each tree
    int* numOfTrees = nullptr;

    // dynamic array to hold each unique name
    std::string* treeNames = nullptr;

    // input n
    std::cin>>n;

    // give our arrays a size
    numOfTrees = new int[n];
    treeNames = new std::string[n];

    // initialize our arrays
    for(int i = 0; i < n; i++){
        numOfTrees[i] = 0;
        treeNames[i] = "";
    }

    // get input and process it
    for(int i = 0; i < n; i++){
        std::cin>>temp;

        for(int j = 0; j < n; j++){
            if(treeNames[j] == ""){// if theres nothing here then we have gone through all the trees so make a new tree name
                treeNames[j] = temp;
                numOfTrees[j]++;
            }
            else if(treeNames[j] == temp){// if the input == a previously input tree, increse thats trees population
                numOfTrees[j]++;
            }
            else{// "error checking"
                std::cout<<"Fix your code!"<<std::endl;
                exit(1);
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(treeNames[i] != ""){// for all non empty positions, output the data
            std::cout<<treeNames[i]<<" "<<((numOfTrees / n) * 100)<<std::endl;
        }
        else break;
    }

    // clear up memory
    delete [] numOfTrees;
    delete [] treeNames;

}

void withMap(){
    ///// solving proble using a map /////

    // Number of inputs therefore can also be used as population
    int n = 0;        
    
    // temporary variable used when getting input
    std::string temp = "";

    //  tree name,   num of trees
    map<std::string, int> data;
    
    // need an iterator to index the map
    map<std::string, int>::iterator index;
    
    // input 
    for(int i = 0; i < n; i++){
        std::cing>>temp;
        data[temp]++;// map does the replica check on its own 
    }

    // output / processing
    for(index = data.begin(); index != data.end(); index++){
        std::cout<<index->first<<" "<<((index->second / n) * 100);
    }
}