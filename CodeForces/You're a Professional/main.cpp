
#include <bits/stdc++.h>

using namespace std;

/*
 * http://codeforces.com/problemset/problem/656/G
 */
int main(int argc, char** argv) {
    int frien,item,like;//number of friends,items,likes needed
	
	cin>>frien;
	cin>>item;
	cin>>like;
	int num=0;
	char array[frien][item];
	char inp;
	int total=0;
	for(int i = 0; i < frien; i++){
		for(int j=0;j<item;j++){
		cin>>inp;
		array[i][j]=inp;
		num++;
		}
	}
	int count=0;
	int bad=0;
	if(frien ==1){//single array
		for(int i=0;i<item;i++){
				// cout << array[i][0] << " ";
				if(array[0][i] == 'Y'){
					count++;
				}
		}
		total = count;
		
	}
	else{//multi dim
		for(int i = 0; i < item; i++){
			for(int j=0;j<frien;j++){
				// cout << array[i][j] << " ";
				
				if(array[j][i] == 'Y'){
					// cout << "yes : " << array[i][j] << " : " << i << " " << j << endl;
					count++;
				}
				else if(array[j][i] == 'N'){
					bad++;
				}
				if(bad == num){
					// cout << "here " << endl;
					total = 0;
					break;
				}
				if(count == like){
				count = 0;
				total++;
				break;
				}
			}
			// cout << i <<endl;
			count=0;
		}	
	}

	cout << total << endl;
    return 0;
}

