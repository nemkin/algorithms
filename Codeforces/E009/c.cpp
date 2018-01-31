#include <iostream>
#include <algorithm>
using namespace std;

bool cmp (string a, string b) {
    string c = a+b;
    string d = b+a;

    //cout<<c<<' '<<d<<' '<<c.compare(d)<<endl;

    return (c.compare(d)<0);
}

int main () {
    int n;
    cin>>n;
    string a[n];

    for(int i=0; i<n; ++i) {
        cin>>a[i];
    }

    sort(a, a+n, cmp);

    for(int i=0; i<n; ++i) {
        cout<<a[i];
    }
    cout<<endl;

    return 0;
}
