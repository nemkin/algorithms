#include <iostream>
using namespace std;
int main () {
    int n;
    cin>>n;
    unsigned long long res1=0, res2=0, tmp;
    for(int i=0; i<n; ++i) {
        cin>>tmp;
        res1 = res1 | tmp;
    }
    for(int i=0; i<n; ++i) {
        cin>>tmp;
        res2 = res2 | tmp;
    }
    cout<<res1+res2<<endl;
    return 0;
}
