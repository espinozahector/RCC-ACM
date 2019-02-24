#include <iostream>
#include <list>

using namespace std;

int main() {
    list<unsigned long long int> primes;
    primes.push_back(2);
    unsigned long long int n;
    cin >> n;
    for (unsigned long long int i = 3; i < n; i++) {
        int prime = true;

        for (list<unsigned long long int>::iterator it = primes.begin(); it != primes.end(); it++) {
            if (i % *it == 0) {
                //cout << "Prime: " << *it << " Not Prime: " << i << endl;
                prime = false;
                break;
            }
        }

        if (prime) {
            primes.push_front(i);
            //cout << i << endl;
        }

    }

    for (list<unsigned long long int>::iterator it = primes.begin(); it != primes.end(); it++) {
        cout << *it << ", ";
    }

    cout << "Count " << primes.size() << endl;

    cout << endl;
    return 0;
}