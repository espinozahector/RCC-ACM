#include <map>
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

struct image {
    string name;
    bool orphan = true;
};

int main() {
    map<string,image> images;

    set<string> images2;
    set<string> files;
    string input;

    bool isTop = true;
    do{
        getline(cin,input);

        if(input.empty()) {
            isTop = false;
            continue;
        }

        if(isTop) {
            image img;
            img.name = input;
            img.orphan = true;
            images[input] = img;
        } else {
            int count = 0;
            int index;
            for (int i = input.size() - 1; i >= 0; i--) {
                if (input[i] == '_') {
                    count++;
                    if (count >= 2) {
                        index = i;
                        break;
                    }
                }
            }

            string sub = input.substr(0, index);

            if (images.find(sub) == images.end()) {
                files.insert(input);
            } else {
                images[sub].orphan = false;
            }
        }
    }while(!cin.eof());

    for (map<string,image>::iterator it = images.begin(); it != images.end(); it++) {
        if (it->second.orphan == true) {
            images2.insert(it->second.name);
        }

    }

    for (set<string>::iterator it = files.begin(); it != files.end(); it++) {
        cout << "F " << *it << endl;
    }

    for (set<string>::iterator it = images2.begin(); it != images2.end(); it++) {
        cout << "I " << *it << endl;
    }

    if (files.empty() && images2.empty()) {
        cout << "No mismatches." << endl;
    }


    return 0;
}