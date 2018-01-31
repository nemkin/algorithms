#include <iostream>
#include <fstream>
#include <cmath>

#define IN "E.IN"

using namespace std;

bool primes[32000];
int numOfPrimes = 0;

int felbontasok(int n) {
    int acc = 0;

    for (int big = n/3;big<n;big++) {
        if (primes[big]) {
            for (int b = 3; b<big && b+big<n;b++) {
                if (primes[b] && primes[n-b-big] && n-b-big < b) {
                    acc++;
                }
            }
        }
    }

    return acc;
}

int main () {

//ofstream file ("primes.txt");
    int t,n;

    for (int i = 2; i< 32001;i++) {
        bool prim = 1;
        for (int k= 2; k<= sqrt(i) ; k++) {
            if (i % k == 0) {
                prim = 0;
                break;
            }
        }

            primes[i] = prim;

    }

    ifstream file (IN);
    file >> t;
    for (int i = 0;i < t ;i++) {
        file >> n;
        cout << felbontasok(n) << endl;
    }

    return 0;
}
