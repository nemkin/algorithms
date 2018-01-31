#include <iostream>
using namespace std;
int main () {
    int n;
    cin>>n;
    long long p[n];
    string c;

    for(int i=0; i<n; ++i) {
        cin>>p[i];
    }

    cin>>c;

    long long current = 0;

    for(int i=0; i<n; ++i) {
        if(c[i] == 'B') current+=p[i];
    }

    long long currentback = current;
    long long maxstr = current;

    for(int i=0; i<n; ++i) {
        if(c[i] == 'A') {
            current += p[i];
        } else {
            current -= p[i];
        }

        if(maxstr < current) maxstr = current;
    }

    for(int i=n-1; 0<=i; --i) {
        if(c[i] == 'A') {
            currentback += p[i];
        } else {
            currentback -= p[i];
        }

        if(maxstr < currentback) maxstr = currentback;
    }

    cout<<maxstr<<endl;

    return 0;
}
