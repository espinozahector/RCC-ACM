
#include <iostream>
#include <set>
#include <iterator>

// http://poj.org/problem?id=1007

struct Test { 
    std::string id; 
    bool operator<(const Test& t) const
    { 
        return (sorty() < t.sorty()); 
    } 
    int sorty() const{
        int tot = 0;
        for(int i = 0; i < id.length(); i++) {
            for(int j = i + 1; j < id.length(); j++) {
                if(id[i] > id[j]) {
                    tot++;
                }
            }
        }
        return tot;
    }
}; 

int main() {
    
    int n,m;
    std::cin>>n>>m;

    std::set<struct Test> s;  

    for(int i = 0; i < m; i++) {
        Test t;
        string tt;
        std::cin>>tt;
        t.id = tt;
        s.insert(t);
    }
    std::cout << std::endl;
    for (std::set<struct Test>::iterator it = s.begin(); it != s.end(); it++) 
    { 
        std::cout << (*it).id << std::endl;  
    } 

    return 0;
}
