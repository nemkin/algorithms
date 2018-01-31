#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

#define IN "D.in"


using namespace std;

int main() {
    double quant, price;
    string line;

    double p, q;

    double units[201];
    double prices [201];

    ifstream file(IN);

    file >> q;
    file >> p;

    int i = 0;

    while (!file.eof()) {
        double unit, price;
        file >>unit;
        file >>price;

        if (price / unit <= p) {
            units[i] = unit;
            prices[i] = price;
            i++;
        }

    }



    double dp[10001];
    dp[0] = 0;

    for (int j = 1; j<=  round(100*q);j++) {
        double minP = dp[j-1] + p * 0.01;
        for (int k = 0; k<i ; k++) {
            int l = round(j - 100 * units[k]);

            if (l >= 0) {
                if (minP > (prices[k] + dp[l])) {
                        minP = (prices[k] + dp[l]);
                }
            }
        }

        dp[j] = minP;
    }

    int idx = round(100*q);
    cout << dp[idx];
    return 0;
}

