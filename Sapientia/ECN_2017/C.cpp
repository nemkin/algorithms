#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

long long t[1<<22];
long long minstep[1<<22];

int main(){

    long long tc;
    cin>>tc;
    while (tc --> 0) {


        long long n;
        cin>>n;
        long long x[30], y[30];
        for (int i=0; i<n; i++) {
            cin>>y[i]>>x[i];
        }

      /*  for (int i=1; i< (1<<n); i++) {
            t[i] = 0;
            minstep[i] = 0;
        }*/

        t[0] = 0;
        for (int i=1; i< (1<<n); i++) {
            vector<long long> ones;
            long long sumx = 0;
            for (int j=0; j<20 && i >= (1<<j); j++) {
                if (i & (1<<j)) {
                    ones.push_back(j);
                    sumx += x[j];
                }
            }
            long long minv = 1LL<<50;
            for (int j = 0; j < ones.size(); j++) {
                if (t[(1<<ones[j]) ^ i] + sumx * sumx * 4 * y[ones[j]]  < minv) {
                    minv = (t[(1<<ones[j]) ^ i] + sumx * sumx * 4 * y[ones[j]]);
                    minstep[i] = ones[j];
                    //cout<<i<<" "<<j<<" | " << sumx<<" "<<ones[j]<<" ("<<ones.size()<<")\n";
                }
            }
            t[i] = minv;
            //cout<<"  t: " << i << "  " << t[i] << endl;
        }
        /*cout<<"minstep"<<endl;
        for (long long i=0; i<(1<<n); i++) {
            cout<<i<<" "<<minstep[i]<<endl;
        }
        cout << t[(1<<n) - 1] << endl;*/

        int p = (1<<n) - 1;
        vector<int> res;
        while (p>0) {
            res.push_back(minstep[p]+1);
            //cout << minstep[p]+1 <<" ";
            p = p ^ (1 << (minstep[p]));
            //cout<<p<<endl;
        }
        reverse(res.begin(), res.end());
        for (int i=0; i<res.size(); i++) {
            if (i>0)
                cout<<" ";
            cout<<res[i];
        }
        cout<<endl;
    }

    return 0;
}
/*

2
6 2 10 2 11 1 5 3 11 2 5 1 10
6 3 10 2 11 1 5 3 11 2 5 1 10

*/
