#include <iostream>
using namespace std;
int main() {
    int xt, yt, zt;
    int xs=0, ys=0, zs=0;
    int n;
    cin>>n;
    for(int i=0; i<n; ++i) {
        cin>>xt>>yt>>zt;
        xs+=xt;
        ys+=yt;
        zs+=zt;
    }

    if(xs == 0 && ys == 0 && zs ==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
