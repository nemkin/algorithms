#include <iostream>
using namespace std;
int main () {
    int n, i, a, b, c, m=0;
    cin>>n;

    for(i=0; i<n; i++) {
        cin>>a>>b>>c;
        if(2<=a+b+c) m++;
    }

    cout<<m;
    return 0;
}
