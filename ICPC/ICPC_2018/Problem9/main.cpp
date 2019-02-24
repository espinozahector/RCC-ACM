#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;


int main() {
    map<char, float> prob;
    vector<string> plates;

    bool estim = true;
    cout << fixed << setprecision(3);

    while (!cin.eof()) {
        string str;

        getline(cin, str);

        if (str.empty()) {
            estim = false;
            continue;
        }

        if (estim) {
            string temp = str.substr(2);
            //prob.insert(str[0], atoi(temp.c_str()));
            //cout << temp << endl;

            prob[str[0]] = atof(temp.c_str());
        } else {
            plates.push_back(str);
        }
    }

    for (int i = 0; i < plates.size(); i++) {
        float p = 1.0f;
        for (int j = 0; j < plates[i].length(); j++) {


            if (prob.find(plates[i][j]) != prob.end()) {
                //cout << "Mult by " << prob[plates[i][j]] << endl;
                p *= prob[plates[i][j]];
            }
        }

        cout << p << endl;

    }


    return 0;
}