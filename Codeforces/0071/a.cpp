#include <iostream>
#include <string>

using namespace std;
int main () {
    int i, n;
    string a;
    cin>>n;

    for(i=0; i<n; i++) {
        cin>>a;
        if(a.length()<=10) cout<<a<<endl;
        else cout<<a[0]<<a.length()-2<<a[a.length()-1]<<endl;
    }

    return 0;
}
