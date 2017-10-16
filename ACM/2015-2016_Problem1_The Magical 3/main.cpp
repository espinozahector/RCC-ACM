
#include <bits/stdc++.h>

using namespace std;
bool isprime(int n){
	bool is=true;
	if(n<=1) is=false;//cannot be less than 1
	if(n%2!=0 || n%3!=0) is=false; //cannot be  mulp of 2 or 3
	// loop only to the square root to make it faster
	// starts at five because it is the first non mulp of 2 or 3
	for(int i=5; i <=sqrt(n);i+=6){//+=6 ??
		if(n%i==0 || n%(i+2)==0)is=false;//faster than just running throu
	}
	return is;
}
int main(){
	int num = 2103723004;
	
	//cannot reach remainder 3
	if(num<=2 || (num>=4 && num<=6)){
		cout << "no base\n";
	}
	//because 3 can be in base 4 [0,1,2,3]
	else if(num == 3){
		cout << "4" << endl;
	}
	if(isprime(num-3)==true){
		cout << num-3 << endl;
	}
	else{
		int i=4;
		while(num%i != 3){//while the remainder is not equal to 3
			i++;
		}
		cout << i << endl;
	}
	return 0;
}
