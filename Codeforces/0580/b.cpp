#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {

    long long m, f;

} A;

bool cmp(A a, A b) {

    return (a.m < b.m);
}

int main() {

    long long n, d;
    cin>>n>>d;

    vector<A> a;
    a.resize(n);

    for(long long i=0; i<n; ++i) {

        cin>>a[i].m>>a[i].f;
    }

    sort(a.begin(), a.end(), cmp);


    long long msum = a[0].f;
    long long sum = a[0].f;
    long long i=0, j=0;

    // --- j ---- i ----
    while(i<n && j<n) {

        if( (a[i+1].m - a[j].m) < d ) {

             if( i == (n-1)) break;
             ++i;
             sum = sum + a[i].f;
        }

        else {

            if( j == (n-1)) break;
            ++j;
            sum = sum - a[j-1].f;

            if( i<j ) {

                i = j;
                sum = a[i].f; 
            }
        }

        if(msum < sum) msum = sum;
    }

    cout<<msum<<endl;

    return 0;
}
