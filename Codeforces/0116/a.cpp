#include <iostream>
using namespace std;
int main () {
    int a, b, s = 0, n, maxs = 0;
    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>a>>b;
        s = s + b - a;
        if(maxs<s) maxs = s;
    }
    cout<<maxs;
    return 0;
}
