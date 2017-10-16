
#include <bits/stdc++.h>
using namespace std;

typedef set<pair<int,string> >::iterator it;

/*
 * http://codeforces.com/problemset/problem/659/B
 */
 
int main(int argc, char** argv) {
    int n;//number of players
    int m;//number of regions
    string name;// name of the player
    
    cin>>n;
    cin>>m;
    
    set<pair<int,string> > s[m]; // points, name
    int reg, pt;
    
    for(int i=0;i<n;i++){
        cin>>name >> reg >> pt;
        s[reg-1].insert(make_pair(800-pt,name));
    }
    
    for(int i=0;i<m;i++){
        it f = s[i].begin();
        if(s[i].size() < 3){
            cout<<(*f).second<<" ";
            cout<<(*(++f)).second << endl;
        }
        else{
            it two = ++f;
            it three = ++f;
            if((*two--).first == (*three--).first){
                cout << "?" << endl;
            }
            else{
                cout<<(*two).second<<" ";
                cout<<(*(three)).second << endl;
            }

        }
    }
    
    return 0;
}