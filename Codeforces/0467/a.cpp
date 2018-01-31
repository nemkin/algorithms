#include <iostream>
using namespace std;
int main () {
    int n, s=0, p, q;
    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>p>>q;
        if(p+2<=q) ++s;
    }

    cout<<s;

    return 0;
}
