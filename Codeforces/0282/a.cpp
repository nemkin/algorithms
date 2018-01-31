#include <iostream>
using namespace std;
int main () {
    int x=0, i,j, n;
    string a;
    cin>>n;
    getline(cin,a);
    for(i=0; i<n; i++) {
        getline(cin,a);
        for(j=0;j<a.length();j++){
            switch (a[j]) {
            case '+': x++; break;
            case '-': x--; break;
            }
        }
    }
    cout<<x/2;
    return 0;
}
