#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;
};

struct Line {
    Point p1, p2;
};

Point toPoint(string str) {
    int ind = str.find(',');

    str.substr(0, ind);
}

Line toLine(string str) {

    Line l;
    int t = str.find(',');
    int ind = str.find(',', t + 1);
    l.p1 = toPoint(str.substr(0, ind));

    l.p2 = toPoint(str.substr(ind + 1));

}
int main() {
    string str;
    while (!cin.eof()) {
        getline(cin, str);

        int ind2 = 0;
        int ind = str.find(';');
        while (ind >= 0) {
            string s = str.substr(ind2, ind - ind2);
            Line l = toLine(s);

            ind2 = ind + 1;
            ind = str.find(';', ind + 1);
        }

    }
    return 0;
}