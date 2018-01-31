#include <iostream>
using namespace std;
int main () {
    string a;
    string b;
    cin>>a>>b;
    int lth = a.length();
    if(lth!=b.length()) {
        cout<<"NO"<<endl;
        return 0;
    }

    for(int i=0; i<lth; i++) {
        if(a[i] != b[lth-1-i]) {
            cout<<"NO"<<endl;
            return 0;
        }

    }
    cout<<"YES"<<endl;
    return 0;
}
