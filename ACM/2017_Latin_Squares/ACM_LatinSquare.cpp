// http://socalcontest.org/history/2017/SC2017ICPCProblems.pdf
// ACM 2017
// Problem 1
// Latin Squares

#include <iostream>

using namespace std;


bool isLatin(int **sqr, int n);
bool isReduced(int **sqr, int n);
int toNum(char c);

int main() {

    int n;      // Size of the square
    int **sqr;  // 2D square array
    bool latin = true; // Assume the square is latin
    bool reduced = true; // Assume the square is reduced

    cin >> n;

    // Get the input
    sqr = new int*[n];
    for (int i = 0; i < n; i++) {
        sqr[i] = new int[n];
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            
            sqr[i][j] = toNum(str[j]);
            cout << sqr[i][j];
        }
        cout << endl;
    }

    // Check whether the square is latin
    latin = isLatin(sqr, n);

    // Check whether the square is reduced
    if (latin) { // No need to check unless we know its not latin
        reduced = isReduced(sqr, n);
    }

    // Output result
    if (!latin) {
        cout << "No" << endl;
    } else if (reduced) {
        cout << "Reduced" << endl;
    } else {
        cout << "Not Reduced" << endl;
    }

    // Cleanup
    for (int i = 0; i < n; i++) {
        delete [] sqr[i];
    }
    delete [] sqr;

    return 0;
}

bool isLatin(int **sqr, int n) {
    // Check whether the square is latin
    for (int i = 0; i < n; i++) {
        bool *col = new bool[n];
        bool *row = new bool[n];
        for (int j = 0; j < n; j++) {
            col[j] = false;
            row[j] = false;
        }

        for (int j = 0; j < n; j++) {
            // Check for duplicate elements in the columns
            if (col[sqr[j][0]]) {
                // Duplicate
                return false;
            } else {
                col[sqr[j][0]] = true;
            }

            // Check for duplicate elements in the rows
            if (row[sqr[0][j]]) {
                // Duplicate
                return false;
            } else {
                row[sqr[0][j]] = true;
            }
        }

        // Cleanup
        delete [] col;
        delete [] row;
    }
    return true;
}

bool isReduced(int **sqr, int n) {
    for (int i = 0; i < n; i++) {
        if (sqr[0][i] != i || sqr[i][0] != i) {
            return false;
        }
    }
    return true;
}

int toNum(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    } else if (c >= '0' && c <= '9') {
        return c - '0';
    }
}

