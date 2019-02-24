#include <iostream>
#include <vector>
#include <map>
using namespace std;

int NPRIMES = 239;
long long int PRIMES[] = { 1499, 1493, 1489, 1487, 1483, 1481, 1471, 1459, 1453, 1451, 1447, 1439, 1433, 1429, 1427, 1423, 1409, 1399, 1381, 1373, 1367, 1361, 1327, 1321, 1319, 1307, 1303, 1301, 1297, 1291, 1289, 1283, 1279, 1277, 1259, 1249, 1237, 1231, 1229, 1223, 1217, 1213, 1201, 1193, 1187, 1181, 1171, 1163, 1153, 1151, 1129, 1123, 1117, 1109, 1103, 1097, 1093, 1091, 1087, 1069, 1063, 1061, 1051, 1049, 1039, 1033, 1031, 1021, 1019, 1013, 1009, 997, 991, 983, 977, 971, 967, 953, 947, 941, 937, 929, 919, 911, 907, 887, 883, 881, 877, 863, 859, 857, 853, 839, 829, 827, 823, 821, 811, 809, 797, 787, 773, 769, 761, 757, 751, 743, 739, 733, 727, 719, 709, 701, 691, 683, 677, 673, 661, 659, 653, 647, 643, 641, 631, 619, 617, 613, 607, 601, 599, 593, 587, 577, 571, 569, 563, 557, 547, 541, 523, 521, 509, 503, 499, 491, 487, 479, 467, 463, 461, 457, 449, 443, 439, 433, 431, 421, 419, 409, 401, 397, 389, 383, 379, 373, 367, 359, 353, 349, 347, 337, 331, 317, 313, 311, 307, 293, 283, 281, 277, 271, 269, 263, 257, 251, 241, 239, 233, 229, 227, 223, 211, 199, 197, 193, 191, 181, 179, 173, 167, 163, 157, 151, 149, 139, 137, 131, 127, 113, 109, 107, 103, 101, 97, 89, 83, 79, 73, 71, 67, 61, 59, 53, 47, 43, 41, 37, 31, 29, 23, 19, 17, 13, 11, 7, 5, 3, 2 };

vector<long long int> getPrimes(long long int N) {
    long long int x = N;
    vector<long long int> ret;
    if (x == 0) return ret;

    long long int i = 0;

    while (x != 1) {
        if (i >= NPRIMES) break;

        if (x % PRIMES[i] == 0) {
            ret.push_back(PRIMES[i]);
            while(x % PRIMES[i] == 0) {
                x /= PRIMES[i];
            }

        }
        i++;
    }
    if (x != 1) {
        ret.push_back(x);
    }

    return ret;
}

long long int rad(long long int a, long long int b, long long int c) {
    long long int prod = 1;

    map<long long int, bool> multed;
    vector<long long int> P = getPrimes(a);
    for (long long int i = 0; i < P.size(); i++) {
        if (multed.find(P[i]) == multed.end()) {
            prod *= P[i];
            multed[P[i]] = true;
        }

    }

    P = getPrimes(b);

    for (long long int i = 0; i < P.size(); i++) {
        if (multed.find(P[i]) == multed.end()) {
            prod *= P[i];
            multed[P[i]] = true;
        }

    }

    P = getPrimes(c);

    for (long long int i = 0; i < P.size(); i++) {
        if (multed.find(P[i]) == multed.end()) {
            prod *= P[i];
            multed[P[i]] = true;
        }

    }

    return prod;
}

bool intersect(vector<long long int> Pa, vector<long long int> Pb) {
    for (int i = 0; i < Pa.size(); i++) {
        for (int j = 0; j < Pb.size(); j++) {
            if (Pa[i] == Pb[j])
                return true;
        }
    }
    return false;
}

int main() {
    long long int a, b, c;
    cin >> a >> b;
    while(!cin.eof()) {


        c = a + b;

        vector<long long int> Pa = getPrimes(a);
        vector<long long int> Pb = getPrimes(b);

        if (intersect(Pa, Pb)) {
            cout << "bad" << endl;
        } else {
            long long int r = rad(a, b, c);
            if (r == c) {
                cout << "equal" << endl;
            } else if (r > c) {
                cout << "greater" << endl;
            } else {
                cout << "less" << endl;
            }
        }
        cin >> a >> b;
    }


    return 0;
}

