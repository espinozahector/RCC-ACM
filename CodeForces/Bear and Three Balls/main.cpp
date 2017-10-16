#include <bits/stdc++.h>

using namespace std;
typedef set<int>::iterator iter;

/*
 * http://codeforces.com/problemset/problem/653/A
 */
int main(int argc, char** argv) {
    int n;
    cin>>n;
    int array[n];
    
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        array[i]=num;
    }
    
    set<int>x;
    for(int i=0;i<n;i++){
      x.insert(array[i]);  
    }
    int c=0;
    iter end=--x.end();
    iter j=++x.begin();
    j++;
    end--;
    for(iter i=x.begin(); i!=end;i++,j++) {
        
        if(*j-*i<=2){
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
    
//    for(iter i=x.begin(); i!=x.end();i++) {
//        cout<<*i<<endl;
//        cout<<i->first<<endl; // map
//    }
          
    return 0;
}