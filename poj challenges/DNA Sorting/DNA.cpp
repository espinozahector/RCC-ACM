
#include <iostream>
#include <vector>
using namespace std;

// http://poj.org/problem?id=1007

int main() {
    int n,m;
    cin>>n;
    cin>>m;

    string dna [m];
    int val [m];
    for(int i = 0; i < m; i++) {
        dna[i] = "";
        val[i] = 0;
    }
    for(int  k = 0; k < m; k++) {
        string temp;
        int tot = 0;
        cin>>temp;
        dna[k] = temp;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(temp[i] > temp[j]) {
                    tot++;
                }
            }
        }
        val[k] = tot;
        tot = 0;
    }
    for(int  i = 0; i < m; i++) {
        for(int j = i+1; j < m; j++) {
            if(val[i] > val[j]) {
                int tt = val[i];
                val[i] = val[j];
                val[j] = tt;

                string ttt = dna[i];
                dna[i] = dna[j];
                dna[j] = ttt;
            }
        }
    }
    cout << endl;
    for(int  i = 0; i < m; i++) {
        cout << dna[i] << endl;
    }
    return 0;
}