#include <iostream>
using namespace std;
int main () {
    int g1=0, g2=0, g3=0, g4=0, n, i, t, r=0;
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>t;
        switch(t) {
            case 1: g1++; break;
            case 2: g2++; break;
            case 3: g3++; break;
            case 4: g4++; break;
        }
    }
    r=g4;

    r+=g3;
    if(g1<=g3) g1=0;
    else g1-=g3;

    r+=g2/2;

    if(g2%2) {
        if(g1<=2) r++;
        else {
            g1-=2;
            r++;

            r+=g1/4;
            if(g1%4) r++;
        }
    } else {
        r+=g1/4;
        if(g1%4) r++;
    }
    cout<<r;
    return 0;
}
