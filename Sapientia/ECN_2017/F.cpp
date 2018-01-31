#include <iostream>
#include <cmath>
using namespace std;

unsigned int m_w = 11;
unsigned int m_z = 173;
unsigned int M = 2001;


unsigned int myrandom() {
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return ((m_z << 16) + m_w) % M;
}

int x[100008];
int y[100008];

bool volt[2000 * 2000 + 10000];
float maxdst = 100000;

int main(){

    for (int i=0; i<100000; i++) {
        unsigned int xx = myrandom();
        unsigned int yy = myrandom();

        if (volt[2000 * xx + yy]) {
            i--;
            continue;
        }

        x[i] = xx;
        y[i] = yy;

        volt[2000 * xx + yy] = true;


        if (xx < 200 || yy < 200 || xx > 1800 || yy > 1800 || 1) {
            for (int j=0; j<i; j++) {
                if ((xx - x[j]) * (xx - x[j]) + (yy - y[j]) * (yy - y[j]) < maxdst) {
                    maxdst = (xx - x[j]) * (xx - x[j]) + (yy - y[j]) * (yy - y[j]);
                }
            }
        }

    }

    cout <<(double)sqrt((double)maxdst) << endl;

    return 0;
}

