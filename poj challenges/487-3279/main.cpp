
#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
using namespace std;
const char NUM[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5',
					  '6', '6', -1, '6', '7', '7', '7', '8', '8', '8', '9', '9', '9', -1};
char numpad(char c) {
	return NUM[c - 65];
	
	/* 
	switch(c) {
		case 'A':
		case 'B':
		case 'C': return '2';
		case 'D':
		case 'E':
		case 'F': return '3';
		case 'G':
		case 'H':
		case 'I': return '4';
		case 'J':
		case 'K':
		case 'L': return '5';
		case 'M':
		case 'N':
		case 'O': return '6';
		case 'P':
		case 'R':
		case 'S': return '7';
		case 'T':
		case 'U':
		case 'V': return '8';
		case 'W':
		case 'X':
		case 'Y': return '9';
		default: return -1;
	} */
}
string clean(string s) {
	string temp = "";
	int counter = 0;
	for(int i =0; i < s.length();i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			temp+=s[i];
			counter++;
			if(counter == 3) temp+='-';
		}
		else if(s[i] >= 'A' && s[i] <= 'Z'){
			char c = numpad(s[i]);
			if (c == -1) continue;
			//cout << s[i] << " " << numpad(s[i]) << endl;
			temp += c;
			counter++;
			if(counter == 3) temp+='-';
		}
	}
	return temp;
}
int search (vector<string> &v, string s) {
	for(int i = 0; i < v.size(); i++) {
		if(v[i] == s) return i;
	}
	return -1;
}	

int main() {
	int n = 0;
	cin>>n;
	string input;
	vector<string> arr;
	vector<int> counts;
	for(int i = 0; i < n; i++) {
		cin>>input;
		string cleaned = clean(input);
		//cout << "cleaned: " << cleaned << endl;
		int index = search (arr, cleaned);
		if(index != -1) {
			counts[index]++;
		} else {
			//not found
			arr.push_back(cleaned);
			counts.push_back(1);
		}
		
	}
	vector<int>numbers;
	for(int i = 0; i < arr.size();i++) {
		string temp = arr[i];
		temp.erase (temp.begin()+3);
		stringstream geek(temp); 
		int x = 0;
		geek >> x;
		numbers.push_back(x);
	}
	for(int i = 0; i < arr.size();i++) {
		for(int j = i+1; j < arr.size();j++) {
			if(numbers[i] > numbers[j]) {
				
				//swap numbers
				int t = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = t;
				//swap count
				int tt = counts[i];
				counts[i] = counts[j];
				counts[j] = tt;
				//swap string
				string tacos = arr[i];
				arr[i] = arr[j];
				arr[j] = tacos;
			}
		}
	}
	for(int i =0; i < arr.size(); i++) {
			if(counts[i] > 1) cout << arr[i] << " " << counts[i] << endl;
	}
	return 0; 
}