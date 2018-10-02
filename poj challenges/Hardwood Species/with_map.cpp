

#include <iostream>
#include <map>
#include <iterator>

/*
Take in N trees and determine percentage of a forest that each tree accounts for 

src: http://poj.org/problem?id=2418

*/

int main(){
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
    return 0;
}